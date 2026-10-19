#!/usr/bin/env bash
set -eu
SRC="${1:?usage: repack_firmware.sh <dir-with-5-files> <out.tar>}"
OUT="${2:?output tar path}"; case "$OUT" in /*) ;; *) OUT="$PWD/$OUT";; esac
ORDER="libSdAuto.so libSdCommon.so libSdSampleRate.so libSdUtils.so sdDongle"
for f in $ORDER; do [ -f "$SRC/$f" ] || { echo "missing $SRC/$f" >&2; exit 1; }; done
chmod 777 "$SRC"/*.so "$SRC/sdDongle"
( cd "$SRC" && tar --format gnutar --numeric-owner --uid 0 --gid 0 -cf "$OUT" $ORDER )
echo "wrote $OUT"
echo "size: $(wc -c <"$OUT")"
echo "md5 : $(md5 -q "$OUT")"
echo "sha256: $(shasum -a 256 "$OUT" | awk '{print $1}')"
