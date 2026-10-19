#!/usr/bin/env bash
set -u
cd "$(dirname "$0")/.."
H=192.168.200.1
TS=$(date +%Y%m%d_%H%M%S)
D="captures/wireless/webui/static_$TS"
LOG="$D.log"
exec >"$LOG" 2>&1
echo "waiting for 192.168.200.x"
for i in $(seq 1 300); do
  case "$(ipconfig getifaddr en0)" in 192.168.200.*) break ;; esac
  sleep 1
done
sleep 5
say "Spojen"
mkdir -p "$D"
curl -s -m 15 -D "$D/index.headers" -o "$D/index.html" "http://$H/"
for a in $(grep -oE '(src|href)="[^"]+\.(js|css)[^"]*"' "$D/index.html" | sed -E 's/^(src|href)="//; s/"$//' | sort -u); do
  case "$a" in http*) continue ;; esac
  f="$D/$(echo "${a#/}" | tr '/' '_')"
  curl -s -m 15 -o "$f" "http://$H/${a#/}"
  echo "got $a -> $f"
done
ls -la "$D"
echo "done $(date)"
say "Gotovo. Vrati wifi."
