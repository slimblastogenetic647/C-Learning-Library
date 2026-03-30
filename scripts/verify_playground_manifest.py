#!/usr/bin/env python3
"""
Fail CI if playground.html MANIFEST paths are missing on disk or BAKED keys diverge.
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
HTML = ROOT / "playground.html"


def main() -> int:
    if not HTML.is_file():
        print("error: playground.html not found", file=sys.stderr)
        return 1

    text = HTML.read_text(encoding="utf-8")

    m_manifest = re.search(
        r"const\s+MANIFEST\s*=\s*\[(.*?)\];",
        text,
        re.DOTALL,
    )
    if not m_manifest:
        print("error: could not find MANIFEST block", file=sys.stderr)
        return 1

    manifest_paths = sorted(
        set(re.findall(r'path:\s*"([^"]+\.c)"', m_manifest.group(1)))
    )

    m_baked = re.search(
        r"const\s+BAKED\s*=\s*\{(.*?)\n\};",
        text,
        re.DOTALL,
    )
    if not m_baked:
        print("error: could not find BAKED block", file=sys.stderr)
        return 1

    baked_keys = sorted(
        set(re.findall(r'^\s*"([^"]+\.c)":', m_baked.group(1), re.MULTILINE))
    )

    missing_files = [p for p in manifest_paths if not (ROOT / p).is_file()]
    if missing_files:
        print("error: MANIFEST paths missing on disk:", file=sys.stderr)
        for p in missing_files:
            print(f"  - {p}", file=sys.stderr)
        return 1

    set_m, set_b = set(manifest_paths), set(baked_keys)
    if set_m != set_b:
        only_m = sorted(set_m - set_b)
        only_b = sorted(set_b - set_m)
        print("error: MANIFEST paths and BAKED keys must match exactly", file=sys.stderr)
        if only_m:
            print("  in MANIFEST but not BAKED:", only_m, file=sys.stderr)
        if only_b:
            print("  in BAKED but not MANIFEST:", only_b, file=sys.stderr)
        return 1

    print(f"ok: {len(manifest_paths)} examples, files exist, MANIFEST == BAKED")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
