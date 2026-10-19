#!/usr/bin/env bash
set -u
# Flash a firmware tar to the Smart Box 6081 via its own web updater.
# Replicates the browser flow: chunked POST /cgi-bin/downfile.cgi, then (only with --commit)
# submition.cgi + reboot.cgi. Read-only up to --commit (upload+md5 check but no install).
#
# usage: flash_dongle.sh <tar> [name] [--commit]
#   <tar>   firmware tar to send
#   name    filename the dongle stores/installs (default: basename of tar)
#   --commit  actually install (submition + reboot). Without it: upload+verify only.
TAR="${1:?usage: flash_dongle.sh <tar> [name] [--commit]}"
NAME="${2:-}"; case "${2:-}" in --commit) NAME=""; COMMIT=1;; esac
COMMIT="${COMMIT:-0}"; [ "${3:-}" = "--commit" ] && COMMIT=1
[ -z "$NAME" ] && NAME="$(basename "$TAR")" && NAME="${NAME%.tar}"
H=192.168.200.1
IF=en0
CHUNK=10240
cd "$(dirname "$0")/.."
TS=$(date +%Y%m%d_%H%M%S)
D="captures/wireless/flash_$TS"; mkdir -p "$D"
LOG="$D/flash.log"; exec > >(tee "$LOG") 2>&1

[ -f "$TAR" ] || { echo "no such tar: $TAR"; exit 1; }
MD5=$(md5 -q "$TAR"); SIZE=$(wc -c <"$TAR")
NCH=$(( (SIZE + CHUNK - 1) / CHUNK ))
echo "tar=$TAR name=$NAME size=$SIZE md5=$MD5 chunks=$NCH commit=$COMMIT"

echo "waiting for dongle network 192.168.200.x ..."
for i in $(seq 1 3600); do case "$(ipconfig getifaddr $IF 2>/dev/null)" in 192.168.200.*) break;; esac; sleep 1; done
case "$(ipconfig getifaddr $IF 2>/dev/null)" in 192.168.200.*) ;; *) echo "not on dongle net, abort"; say "Nisi na dongl mrezi"; exit 1;; esac
curl -s -m 8 -o "$D/getversion_before.txt" "http://$H/cgi-bin/getversion.cgi" && echo "reachable; version before:" && grep -i version "$D/getversion_before.txt" | head -2
say "Spojen, saljem firmware"

tmp=$(mktemp -d)
i=0; ok=1
while [ $i -lt $NCH ]; do
  dd if="$TAR" of="$tmp/part" bs=$CHUNK skip=$i count=1 2>/dev/null
  if [ $i -eq 0 ]; then fn="${NAME}.0";
  elif [ $i -eq $((NCH-1)) ]; then fn="${NAME}:${MD5}.2";
  else fn="${NAME}.1"; fi
  resp=$(curl -s -m 30 -F "chunk=@$tmp/part;filename=${fn};type=application/octet-stream" "http://$H/cgi-bin/downfile.cgi")
  case "$resp" in
    *success*) : ;;
    *) echo "chunk $i FAILED resp: $resp"; ok=0; break ;;
  esac
  if [ $i -eq $((NCH-1)) ]; then echo "last chunk resp: $resp"; fi
  i=$((i+1))
  [ $((i % 20)) -eq 0 ] && echo "  sent $i/$NCH"
done
rm -rf "$tmp"
[ $ok -eq 1 ] && echo "upload done ($NCH chunks)" || { echo "upload failed"; say "Slanje palo"; exit 1; }

if [ "$COMMIT" = "1" ]; then
  echo "COMMIT: submition + reboot"
  curl -s -m 30 "http://$H/cgi-bin/submition.cgi?filename=${NAME}&"; echo
  sleep 1
  curl -s -m 10 "http://$H/cgi-bin/reboot.cgi"; echo
  say "Firmware poslan, dongl se restartuje"
else
  echo "DRY-RUN: not installing (no --commit). If last-chunk said 'file check success', the dongle accepted and md5-verified the image."
  say "Provjera gotova"
fi
echo "done $(date)"
