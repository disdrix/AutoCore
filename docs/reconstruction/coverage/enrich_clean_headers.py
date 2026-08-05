"""Add a readable plate comment block to FUN_*.cpp clean units that still lack purpose notes.

Scans matching raw for string literals and injects a PURPOSE section at top of clean file.
Does not invent control flow.

Usage:
  python docs/reconstruction/coverage/enrich_clean_headers.py [--limit N] [--prefix HEX2]
  --prefix 00 processes only FUN_00*.cpp etc for safe parallel shards.
"""
from __future__ import annotations

import argparse
import re
from pathlib import Path

ROOT = Path("docs/reconstruction")
CLEAN = ROOT / "reconstructed-exact"
RAW = ROOT / "raw"

STR_RE = re.compile(r'"((?:[^"\\]|\\.){3,100})"')


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--limit", type=int, default=500)
    ap.add_argument("--prefix", default="", help="2-hex digit prefix of FUN_XXXXXXXX name")
    args = ap.parse_args()
    n = 0
    skipped = 0
    if args.prefix:
        pattern = f"FUN_{args.prefix.lower()}*.cpp"
    else:
        pattern = "FUN_*.cpp"
    for clean in sorted(CLEAN.glob(pattern)):
        if n >= args.limit:
            break
        # quick skip: only read first 1KB
        try:
            with clean.open("r", encoding="utf-8", errors="replace") as f:
                head = f.read(1200)
        except OSError:
            continue
        if "PURPOSE (auto):" in head:
            skipped += 1
            continue
        m = re.search(r"FUN_([0-9a-fA-F]{8})", clean.name)
        if not m:
            continue
        addr = m.group(1).lower()
        strings: list[str] = []
        raws = [r for r in RAW.glob(f"aa_{addr}_*.md") if not r.name.endswith(".annotated.md")]
        if raws:
            try:
                rt = raws[0].read_text(encoding="utf-8", errors="replace")
            except OSError:
                rt = ""
            for s in STR_RE.findall(rt):
                if len(s) >= 4 and s not in strings:
                    strings.append(s)
                if len(strings) >= 8:
                    break
        purpose_lines = [
            f"// PURPOSE (auto): Scaffold unit for FUN_{addr} @ 0x{addr}",
            f"// Stable ID: aa_{addr}",
        ]
        if strings:
            purpose_lines.append("// Embedded strings (evidence for future rename):")
            for s in strings[:6]:
                purpose_lines.append(f'//   - "{s[:90]}"')
        else:
            purpose_lines.append(
                "// No high-value strings recovered; name via xrefs/callers in follow-up."
            )
        purpose_lines.append(
            "// Readability: control flow preserved from Ghidra decompile; types tentative."
        )
        purpose = "\n".join(purpose_lines) + "\n\n"
        try:
            text = clean.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        if "PURPOSE (auto):" in text:
            skipped += 1
            continue
        if text.startswith("// ==="):
            parts = text.split("\n\n", 1)
            if len(parts) == 2:
                text = parts[0] + "\n\n" + purpose + parts[1]
            else:
                text = purpose + text
        else:
            text = purpose + text
        try:
            clean.write_text(text, encoding="utf-8")
        except OSError:
            continue
        n += 1
    print(f"enriched={n} skipped_already={skipped} prefix={args.prefix or '*'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
