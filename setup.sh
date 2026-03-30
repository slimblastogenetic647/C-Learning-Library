#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$ROOT"

pass() { echo "  ✅ $1"; }
fail() { echo "  ❌ $1"; }

echo ""
echo "C Learning Library — setup"
echo "--------------------------"

GCC_OK=0
MAKE_OK=0
SILICON_OK=0
PIL_OK=0

if command -v gcc >/dev/null 2>&1; then
  pass "gcc found ($(gcc --version | head -1))"
  GCC_OK=1
else
  fail "gcc not found"
  echo "     macOS: xcode-select --install"
  echo "     Debian/Ubuntu: sudo apt install build-essential"
  echo "     Windows: install MSYS2 or Visual Studio Build Tools with clang/gcc"
fi

if command -v make >/dev/null 2>&1; then
  pass "make found"
  MAKE_OK=1
else
  fail "make not found (install build-essential / Xcode CLT)"
fi

if command -v silicon >/dev/null 2>&1; then
  pass "silicon found (PNG code previews)"
  SILICON_OK=1
else
  fail "silicon not found (optional: brew install silicon / cargo install silicon)"
  if [[ "$(uname -s)" == "Darwin" ]] && command -v brew >/dev/null 2>&1; then
    read -r -p "Install silicon with Homebrew now? [y/N] " ans || true
    if [[ "${ans:-}" =~ ^[Yy]$ ]]; then
      brew install silicon && SILICON_OK=1 && pass "silicon installed"
    fi
  fi
fi

if python3 -c "import PIL" >/dev/null 2>&1; then
  pass "Pillow available (optional; make preview can also create scripts/.venv)"
  PIL_OK=1
else
  pass "Pillow not in system Python (OK — \`make preview\` auto-creates scripts/.venv with Pillow)"
  PIL_OK=1
fi

echo ""
echo "Summary"
echo "-------"
echo "  gcc:     $([[ $GCC_OK -eq 1 ]] && echo OK || echo missing)"
echo "  make:    $([[ $MAKE_OK -eq 1 ]] && echo OK || echo missing)"
echo "  silicon: $([[ $SILICON_OK -eq 1 ]] && echo OK || echo optional)"
echo "  pillow:  $([[ $PIL_OK -eq 1 ]] && echo OK || echo optional for previews)"

echo ""
if [[ $GCC_OK -eq 1 && $MAKE_OK -eq 1 ]]; then
  echo "You're ready. Run \`make run-all\` to see every example."
else
  echo "Fix the missing tools above, then run \`make run-all\`."
  exit 1
fi
echo ""
