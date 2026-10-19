#!/usr/bin/env bash
set -u
HOME_GW="${1:-192.168.0.1}"
IF=en0
DONGLE_MAC="dc:84:3:eb:8:cb"
cd "$(dirname "$0")/.."
TS=$(date +%Y%m%d_%H%M%S)
LOG="captures/wireless/wifi_session_$TS.log"
exec >"$LOG" 2>&1
echo "start $(date), waiting to leave home gateway $HOME_GW"

gw() { route -n get default 2>/dev/null | awk '/gateway/{print $2}'; }

away=0
for i in $(seq 1 300); do
  g=$(gw)
  if [ "$g" = "$HOME_GW" ]; then away=0; else away=$((away+1)); fi
  [ $away -ge 5 ] && break
  sleep 1
done
echo "off home network since $(date), waiting 20s for link"
sleep 20
say "Spojen, skupljam podatke"

D="captures/wireless/smartbox_link_$TS"
mkdir -p "$D"
ifconfig $IF >"$D/ifconfig_en0.txt" 2>&1
MY4=$(ipconfig getifaddr $IF)
echo "my ipv4: $MY4"
case "$MY4" in 192.168.200.*) ;; *) echo "not on smartbox subnet, abort"; say "Nisi na smartbox mrezi"; exit 1 ;; esac

nmap -n -sn 192.168.200.0/24 >"$D/nmap_sweep.txt" 2>&1
ping6 -c 3 -I $IF ff02::1 >"$D/ping6_allnodes.txt" 2>&1
arp -an -i $IF >"$D/arp.txt" 2>&1
ndp -an | grep "%en0" >"$D/ndp.txt" 2>&1
DONGLE4=$(arp -an -i $IF | awk -v m="$DONGLE_MAC" '$4==m{gsub(/[()]/,"",$2);print $2}' | head -1)
DONGLE6=$(ndp -an | awk -v m="$DONGLE_MAC" '$2==m && $1 ~ /^fe80/ && $1 ~ /%en0/ {print $1}' | head -1)
echo "dongle ipv4=${DONGLE4:-?} ipv6=${DONGLE6:-?}"

if [ -n "$DONGLE4" ]; then
  nmap -n -Pn -sV "$DONGLE4" >"$D/nmap_sV.txt" 2>&1
  nmap -n -Pn -p- -T4 "$DONGLE4" >"$D/nmap_alltcp.txt" 2>&1
  for p in 80 8080 8000 8888; do curl -s -m 5 -D - -o "$D/http_${p}_body.html" "http://$DONGLE4:$p/" >"$D/http_${p}_headers.txt" 2>&1; done
  curl -sk -m 5 -D - -o "$D/https_body.html" "https://$DONGLE4/" >"$D/https_headers.txt" 2>&1
fi
if [ -n "$DONGLE6" ]; then
  nmap -6 -n -Pn -p- -T4 -e $IF "${DONGLE6%%%*}" >"$D/nmap6_alltcp.txt" 2>&1
fi
( dns-sd -B _services._dns-sd._udp local. >"$D/mdns_services.txt" 2>&1 & p=$!; sleep 6; kill $p )
echo "done $(date)"
osascript -e 'display notification "Vrati Wi-Fi na <home-wifi>" with title "SmartBox skripta gotova" sound name "Glass"'
say "Gotovo. Vrati wifi."
