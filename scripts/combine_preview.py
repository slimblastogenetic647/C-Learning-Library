#!/usr/bin/env python3
"""
Stack a code screenshot above a program-output screenshot with a labeled divider.
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

try:
    from PIL import Image, ImageDraw, ImageFont
except ImportError:
    print("combine_preview.py: install Pillow (see scripts/render_text_png.py)", file=sys.stderr)
    sys.exit(1)

BG = (13, 17, 23)
SUB = (139, 148, 158)
SEP = (48, 54, 61)
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


def scale_to_width(img: Image.Image, target_w: int) -> Image.Image:
    if img.width == target_w:
        return img
    ratio = target_w / img.width
    h = max(1, int(img.height * ratio))
    return img.resize((target_w, h), Image.Resampling.LANCZOS)


def combine(code_png: Path, output_png: Path, dest_png: Path) -> None:
    code = Image.open(code_png).convert("RGB")
    out = Image.open(output_png).convert("RGB")
    w = max(code.width, out.width)
    code_s = scale_to_width(code, w)
    out_s = scale_to_width(out, w)

    top_pad = 8
    bar_h = 2
    gap = 14
    label_h = 26
    font = load_font(15)
    dummy = Image.new("RGB", (1, 1))
    dr = ImageDraw.Draw(dummy)
    bbox = dr.textbbox((0, 0), "Program output", font=font)
    label_h = max(label_h, bbox[3] - bbox[1] + 4)

    h = code_s.height + top_pad + bar_h + gap + label_h + gap + out_s.height
    canvas = Image.new("RGB", (w, h), BG)
    y = 0
    canvas.paste(code_s, (0, y))
    y += code_s.height + top_pad
    draw = ImageDraw.Draw(canvas)
    draw.rectangle([0, y, w, y + bar_h], fill=SEP)
    y += bar_h + gap
    draw.text((16, y), "Program output", fill=SUB, font=font)
    y += label_h + gap
    canvas.paste(out_s, (0, y))

    dest_png.parent.mkdir(parents=True, exist_ok=True)
    canvas.save(dest_png, "PNG")


def main() -> None:
    ap = argparse.ArgumentParser(description="Combine code PNG + output PNG.")
    ap.add_argument("code_png", type=Path)
    ap.add_argument("output_png", type=Path)
    ap.add_argument("dest_png", type=Path)
    args = ap.parse_args()
    combine(args.code_png, args.output_png, args.dest_png)


if __name__ == "__main__":
    main()
