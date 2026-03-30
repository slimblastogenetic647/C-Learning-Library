#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

make all >/dev/null

banner() {
  echo ""
  echo "================================================================================"
  echo " $1"
  echo "================================================================================"
}

for chapter in $(ls -d topics/*/ 2>/dev/null | sort); do
  name="$(basename "$chapter")"
  banner "$name"
  for src in $(ls "$chapter"/*.c 2>/dev/null | sort); do
    base="$(basename "$src" .c)"
    echo ""
    echo "---- $base ----"
    "./bin/$base"
    echo ""
  done
done

echo "Tour complete."
