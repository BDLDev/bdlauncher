#!/bin/bash
set -euo pipefail
function die() {
    echo >&2 "$@"
    exit 1
}
function skip() {
    echo >&2 "$@"
    exit 0
}
function make_new() {
    echo " CRATNEW $src -> $tgt.new"
    cp "$src" "$tgt.new"
    exit 0
}

[ "$#" -eq 2 ] || die "2 argument required, $# provided"
src="$1"
tgt="$2"
if [[ -f "$tgt" && ${FORCE:-0} != 1 ]]; then
    cmp --silent "$src" "$tgt" && skip " SKIPPED $src" || make_new
fi
echo " INSTALL $src"
mkdir -p $(dirname "$tgt")
cp "$src" "$tgt"