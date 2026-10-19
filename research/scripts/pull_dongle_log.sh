#!/usr/bin/env bash
set -u
cd "$(dirname "$0")/.."
H=192.168.200.1
TS=$(date +%Y%m%d_%H%M%S)
TAG="${1:-dbg$TS}"
D="captures/wireless/log_$TS"
exec >"$D.log" 2>&1
echo "waiting to join SmartBox (192.168.200.x)..."
for i in $(seq 1 3600); do
  case "$(ipconfig getifaddr en0 2>/dev/null)" in 192.168.200.*) break ;; esac
  sleep 1
done
sleep 3
say "Spojen na dongl"
mkdir -p "$D"
# sanity: web server reachable?
curl -s -m 8 -o "$D/getversion.txt" "http://$H/cgi-bin/getversion.cgi"
# pull the log bundle (read-only GET); the logID is just a name
curl -s -m 60 -D "$D/minizip.headers" -o "$D/${TAG}.bin" "http://$H/cgi-bin/minizip.cgi?logID=${TAG}&"
echo "--- minizip headers ---"; cat "$D/minizip.headers"
echo "--- file ---"; ls -la "$D/${TAG}.bin"; xxd "$D/${TAG}.bin" | head -3
# if it's a zip, list contents
if head -c2 "$D/${TAG}.bin" | grep -q PK; then
  echo "looks like a zip"; unzip -l "$D/${TAG}.bin"
fi
echo "done $(date)"
say "Gotovo. Vrati wifi."
