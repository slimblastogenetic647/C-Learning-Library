#!/usr/bin/env python3
"""
Render plain text (source or program output) to a PNG for preview fallbacks
when silicon is not installed. Requires Pillow: pip install pillow
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

try:
    from PIL import Image, ImageDraw, ImageFont
except ImportError:
    print("render_text_png.py: install Pillow: python3 -m pip install pillow", file=sys.stderr)
    sys.exit(1)

BG = (13, 17, 23)  # #0D1117
FG = (201, 209, 217)  # GitHub-ish light gray
PAD = 32
LINE_HEIGHT = 22
FONT_CANDIDATES = (
    "JetBrainsMono-Regular.ttf",
    "JetBrains Mono.ttf",
    "Hack-Regular.ttf",
    "Menlo.ttc",
    "Courier New.ttf",
    "Courier.ttc",
)


def load_font(size: int) -> ImageFont.FreeTypeFont | ImageFont.ImageFont:
    import os

    dirs = [
        Path("/Library/Fonts"),
        Path("/System/Library/Fonts"),
        Path("/System/Library/Fonts/Supplemental"),
        Path(os.path.expanduser("~/Library/Fonts")),
    ]
    for name in FONT_CANDIDATES:
        for d in dirs:
            p = d / name
            if p.exists():
                try:
                    return ImageFont.truetype(str(p), size=size)
                except OSError:
                    continue
    return ImageFont.load_default()


def text_to_png(text: str, out_path: Path, title: str | None = None) -> None:
    lines = text.expandtabs(4).splitlines()
    if title:
        lines = [f"// {title}", ""] + lines

    font = load_font(14)
    dummy = Image.new("RGB", (1, 1))
    draw = ImageDraw.Draw(dummy)

    max_w = 0
    for line in lines:
        bbox = draw.textbbox((0, 0), line, font=font)
        max_w = max(max_w, bbox[2] - bbox[0])

    width = max(400, max_w + 2 * PAD)
    height = max(120, PAD * 2 + len(lines) * LINE_HEIGHT)

    img = Image.new("RGB", (width, height), BG)
    draw = ImageDraw.Draw(img)
    y = PAD
    for line in lines:
        draw.text((PAD, y), line, fill=FG, font=font)
        y += LINE_HEIGHT

    out_path.parent.mkdir(parents=True, exist_ok=True)
    img.save(out_path, "PNG")


def main() -> None:
    p = argparse.ArgumentParser(description="Render text file to PNG (Pillow fallback).")
    p.add_argument("input", type=Path, help="Input text file")
    p.add_argument("output", type=Path, help="Output .png path")
    p.add_argument("--title", help="Optional title line at top")
    args = p.parse_args()
    text = args.input.read_text(encoding="utf-8", errors="replace")
    text_to_png(text, args.output, title=args.title)


if __name__ == "__main__":
    main()
