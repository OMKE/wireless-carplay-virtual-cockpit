#!/usr/bin/env bash
set -u
cd "$(dirname "$0")/.."
H=192.168.200.1
D="captures/wireless/webui/getversion_$(date +%Y%m%d_%H%M%S)"
exec >"$D.log" 2>&1
for i in $(seq 1 300); do
  case "$(ipconfig getifaddr en0)" in 192.168.200.*) break ;; esac
  sleep 1
done
sleep 5
say "Spojen"
mkdir -p "$D"
curl -s -m 15 -D "$D/getversion.headers" -o "$D/getversion.txt" "http://$H/cgi-bin/getversion.cgi"
curl -s -m 15 -o "$D/language.json" "http://$H/language.json"
ls -la "$D"
say "Gotovo. Vrati wifi."
