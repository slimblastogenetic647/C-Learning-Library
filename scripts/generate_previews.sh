#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

VENV_PY="$ROOT/scripts/.venv/bin/python3"

have_silicon() { command -v silicon >/dev/null 2>&1; }

# Pillow is required to merge code + output into one image (always).
ensure_pillow() {
  if python3 -c "import PIL" >/dev/null 2>&1; then
    echo "python3"
    return
  fi
  if [[ -x "$VENV_PY" ]] && "$VENV_PY" -c "import PIL" >/dev/null 2>&1; then
    echo "$VENV_PY"
    return
  fi
  echo "Creating local venv for Pillow (preview merge + fallback rendering)..." >&2
  python3 -m venv "$ROOT/scripts/.venv"
  "$ROOT/scripts/.venv/bin/pip" install -q pillow
  echo "$VENV_PY"
}

PYTHON="$(ensure_pillow)"

SILICON_THEME="OneHalfDark"
SILICON_BG="#0D1117"
SILICON_PAD=32

render_code_png() {
  local src="$1" dest="$2"
  if have_silicon; then
    silicon "$src" -o "$dest" \
      --theme "$SILICON_THEME" \
      --background "$SILICON_BG" \
      --pad-horiz "$SILICON_PAD" \
      --pad-vert "$SILICON_PAD" \
      --font "JetBrains Mono" 2>/dev/null \
      || silicon "$src" -o "$dest" \
        --theme "$SILICON_THEME" \
        --background "$SILICON_BG" \
        --pad-horiz "$SILICON_PAD" \
        --pad-vert "$SILICON_PAD" \
        --font "Hack" 2>/dev/null \
      || silicon "$src" -o "$dest" \
        --theme "$SILICON_THEME" \
        --background "$SILICON_BG" \
        --pad-horiz "$SILICON_PAD" \
        --pad-vert "$SILICON_PAD"
  else
    "$PYTHON" "$ROOT/scripts/render_text_png.py" "$src" "$dest" --title "$(basename "$src")"
  fi
}

# Program stdout/stderr is plain text; silicon often cannot highlight it (no "txt" grammar).
render_output_png() {
  local txt="$1" dest="$2"
  "$PYTHON" "$ROOT/scripts/render_text_png.py" "$txt" "$dest" --title "stdout / stderr"
}

echo "Building examples..."
make all

TMP_DIR="$(mktemp -d)"
trap 'rm -rf "$TMP_DIR"' EXIT
TMP_CODE="$TMP_DIR/code.png"
TMP_OUTIMG="$TMP_DIR/out.png"
TMP_RUN="$TMP_DIR/run.txt"

shopt -s nullglob
for src in topics/*/*.c; do
  dir="$(dirname "$src")"
  base="$(basename "$src" .c)"
  binexe="$ROOT/bin/$base"
  prev="$dir/previews"
  mkdir -p "$prev"

  rm -f "$prev/code_${base}.png" "$prev/output_${base}.png"

  echo "Preview: $src"
  render_code_png "$src" "$TMP_CODE"

  if [[ -f "$binexe" ]]; then
    "$binexe" >"$TMP_RUN" 2>&1 || true
  else
    printf '%s\n' "(no binary: run make all)" >"$TMP_RUN"
  fi

  render_output_png "$TMP_RUN" "$TMP_OUTIMG"
  "$PYTHON" "$ROOT/scripts/combine_preview.py" "$TMP_CODE" "$TMP_OUTIMG" "$prev/preview_${base}.png"
done

echo "Done. One combined image per example: topics/*/previews/preview_<name>.png"
