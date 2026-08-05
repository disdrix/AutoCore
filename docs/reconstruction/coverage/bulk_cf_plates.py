"""Inject English control-flow bullet plates into reconstructed-exact units from raw pseudocode structure.

Does not invent semantic names. Extracts if/while/for/switch/call patterns from raw ```c blocks.

Targets FUN_*.cpp by default; use --glob Named_CalleeOf_*.cpp for callee-driven renames.

Usage:
  python docs/reconstruction/coverage/bulk_cf_plates.py [--limit N] [--min-addr HEX] [--max-addr HEX]
  python docs/reconstruction/coverage/bulk_cf_plates.py --glob Named_CalleeOf_*.cpp --limit 2000
"""
from __future__ import annotations

import argparse
import re
from pathlib import Path

ROOT = Path("docs/reconstruction")
CLEAN = ROOT / "reconstructed-exact"
RAW = ROOT / "raw"

CALL_RE = re.compile(r"\b([A-Za-z_][\w:]*)\s*\(")
CTRL_RE = re.compile(r"\b(if|while|for|switch|do|return|goto)\b")
# FUN_XXXXXXXX or trailing _XXXXXXXX.cpp (Named_CalleeOf_* / other named units)
ADDR_FUN_RE = re.compile(r"FUN_([0-9a-fA-F]{8})")
ADDR_TRAIL_RE = re.compile(r"_([0-9a-fA-F]{8})\.cpp$", re.I)


def extract_addr(filename: str, head: str = "") -> str | None:
    m = ADDR_FUN_RE.search(filename)
    if m:
        return m.group(1).lower()
    m = ADDR_TRAIL_RE.search(filename)
    if m:
        return m.group(1).lower()
    if head:
        m = re.search(r"aa_([0-9a-f]{8})", head, re.I)
        if m:
            return m.group(1).lower()
        m = re.search(r"Address:\s*0x([0-9a-f]{8})", head, re.I)
        if m:
            return m.group(1).lower()
    return None


def extract_code(raw_text: str) -> str:
    m = re.search(r"```c\n(.*?)```", raw_text, re.S)
    return m.group(1) if m else raw_text


def summarize(code: str, max_bullets: int = 12) -> list[str]:
    bullets: list[str] = []
    lines = [ln.strip() for ln in code.splitlines() if ln.strip()]
    # size hint
    bullets.append(f"Body size: ~{len(lines)} non-empty decompiler lines.")
    # control keywords frequency
    ctrl_counts: dict[str, int] = {}
    for ln in lines:
        for m in CTRL_RE.finditer(ln):
            ctrl_counts[m.group(1)] = ctrl_counts.get(m.group(1), 0) + 1
    if ctrl_counts:
        parts = ", ".join(f"{k}×{v}" for k, v in sorted(ctrl_counts.items(), key=lambda x: -x[1])[:8])
        bullets.append(f"Control keywords: {parts}.")
    # top calls (skip types/keywords)
    skip = {
        "if", "while", "for", "switch", "return", "sizeof", "void", "int", "char",
        "undefined", "undefined1", "undefined2", "undefined4", "undefined8",
        "uint", "byte", "bool", "float", "double", "long", "short", "true", "false",
        "operator_new", "operator_delete", "operator_new__", "operator_delete__",
    }
    calls: dict[str, int] = {}
    for ln in lines:
        for m in CALL_RE.finditer(ln):
            name = m.group(1)
            if name in skip or name.startswith("local_") or name.startswith("param"):
                continue
            if name in ("__thiscall", "__fastcall", "__cdecl", "__stdcall"):
                continue
            calls[name] = calls.get(name, 0) + 1
    top = sorted(calls.items(), key=lambda x: (-x[1], x[0]))[:8]
    if top:
        bullets.append("Notable callees: " + ", ".join(f"{n}×{c}" if c > 1 else n for n, c in top) + ".")
    # string literals
    strs = re.findall(r'"((?:[^"\\]|\\.){3,60})"', code)
    if strs:
        uniq = []
        for s in strs:
            if s not in uniq:
                uniq.append(s)
            if len(uniq) >= 4:
                break
        bullets.append("Strings: " + "; ".join(f'\"{s}\"' for s in uniq) + ".")
    # early returns
    ret_n = sum(1 for ln in lines if ln.startswith("return") or " return " in f" {ln}")
    if ret_n:
        bullets.append(f"Return sites: {ret_n}.")
    return bullets[:max_bullets]


def inject_plate(text: str, block: str) -> str:
    """Insert CF plate after PURPOSE (auto) comment run, else at file start."""
    if "PURPOSE (auto):" in text:
        idx = text.find("PURPOSE (auto):")
        pos = idx
        while True:
            nl = text.find("\n", pos)
            if nl < 0:
                break
            if text[nl + 1 :].startswith("//"):
                pos = nl + 1
                continue
            end = nl + 1
            while end < len(text) and text[end] == "\n":
                end += 1
            return text[:end] + block + text[end:]
        return block + text
    return block + text


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--limit", type=int, default=500)
    ap.add_argument("--min-addr", default="00000000")
    ap.add_argument("--max-addr", default="ffffffff")
    ap.add_argument(
        "--glob",
        default="FUN_*.cpp",
        help="Filename glob under reconstructed-exact (default FUN_*.cpp; use Named_CalleeOf_*.cpp)",
    )
    args = ap.parse_args()
    lo = int(args.min_addr, 16)
    hi = int(args.max_addr, 16)
    n = 0
    for clean in sorted(CLEAN.glob(args.glob)):
        if n >= args.limit:
            break
        try:
            text = clean.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        if "READABILITY (auto CF):" in text or "READABILITY:" in text:
            continue
        addr = extract_addr(clean.name, text[:900])
        if not addr:
            continue
        val = int(addr, 16)
        if val < lo or val > hi:
            continue
        raws = [r for r in RAW.glob(f"aa_{addr}_*.md") if not r.name.endswith(".annotated.md")]
        code = ""
        if raws:
            try:
                code = extract_code(raws[0].read_text(encoding="utf-8", errors="replace"))
            except OSError:
                code = ""
        if not code:
            # fall back to clean body
            code = text
        bullets = summarize(code)
        block = "// READABILITY (auto CF):\n" + "\n".join(f"//  - {b}" for b in bullets) + "\n\n"
        text = inject_plate(text, block)
        try:
            clean.write_text(text, encoding="utf-8")
        except OSError:
            continue
        n += 1
    print(f"cf_plated={n} glob={args.glob} range={args.min_addr}-{args.max_addr}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
