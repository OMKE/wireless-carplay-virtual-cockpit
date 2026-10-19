#!/usr/bin/env bash
set -u
TARGET="${1:-}"
OUT="captures/wireless/network_$(date +%Y%m%d_%H%M%S)"
mkdir -p "$OUT"
run() { local name="$1"; shift; { echo "\$ $*"; "$@"; } >"$OUT/$name.txt" 2>&1; echo "[+] $name"; }

run route    route -n get default
run arp      arp -a
run ifconfig ifconfig
run hwports  networksetup -listallhardwareports
run wifiinfo networksetup -getinfo Wi-Fi
run ipsummary ipconfig getsummary en0

GW=$(route -n get default 2>/dev/null | awk '/gateway/{print $2}')
echo "gateway=$GW" | tee "$OUT/gateway.txt"
if [ -z "$TARGET" ]; then
  echo "No target given. Re-run with the Smart Box IP once confirmed: $0 <SMARTBOX_IP>"
  exit 0
fi
if [ "$TARGET" != "$GW" ]; then
  echo "Target $TARGET is not the current gateway ($GW). Refusing to scan." >&2
  exit 1
fi

run ping      ping -c 3 "$TARGET"
run arp_target arp -n "$TARGET"
run http      curl -sv --max-time 10 -D - "http://$TARGET/"
run https     curl -svk --max-time 10 -D - "https://$TARGET/"

( dns-sd -B _services._dns-sd._udp local. >"$OUT/mdns_services.txt" 2>&1 & p=$!; sleep 8; kill $p ) ; echo "[+] mdns_services"

if command -v nmap >/dev/null; then
  run nmap_sV   nmap -sV -Pn "$TARGET"
  run nmap_allt nmap -p- -Pn -T4 "$TARGET"
else
  echo "nmap not installed; skipped port scan"
fi
echo "Output in $OUT"
