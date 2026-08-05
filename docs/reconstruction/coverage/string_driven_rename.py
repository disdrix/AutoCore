"""String-driven renames: scan raw captures for informative literals and emit better-named clean copies.

Does not delete FUN_*.cpp originals. Writes AliasName.cpp with stable-id header.

Usage:
  python docs/reconstruction/coverage/string_driven_rename.py [--limit N] [--dry-run]
"""
from __future__ import annotations

import argparse
import re
from pathlib import Path

ROOT = Path("docs/reconstruction")
RAW = ROOT / "raw"
CLEAN = ROOT / "reconstructed-exact"
FUNC = ROOT / "functions"

STR_RE = re.compile(r'"((?:[^"\\]|\\.){4,80})"')
SKIP = {
    "true", "false", "null", "%s", "%d", "%f", "\n", "\r\n",
    "assert", "error", "warning", "debug", "info",
}


def sanitize(s: str) -> str:
    s = re.sub(r"[^A-Za-z0-9_]+", "_", s)
    s = re.sub(r"_+", "_", s).strip("_")
    if not s or s[0].isdigit():
        s = "S_" + s
    return s[:48]


def score_string(s: str) -> int:
    sl = s.lower()
    score = 0
    for kw, w in (
        ("auth", 8), ("login", 8), ("mission", 10), ("objective", 10),
        ("inventory", 10), ("equip", 8), ("skill", 9), ("quickbar", 9),
        ("drive", 8), ("steer", 7), ("combat", 7), ("xp", 6),
        ("packet", 6), ("dialog", 7), ("npc", 5), ("vehicle", 6),
        ("server", 5), ("client", 4), ("response", 4), ("request", 4),
        ("palantir", 3), ("vog", 2),
    ):
        if kw in sl:
            score += w
    if "/" in s or "\\" in s:
        score += 2  # path
    if s.isupper() and "_" in s:
        score += 3  # enum-like
    if len(s) < 6:
        score -= 3
    return score


def best_name_from_code(code: str, addr_hex: str) -> tuple[str, str] | None:
    strings = STR_RE.findall(code)
    scored: list[tuple[int, str]] = []
    for s in strings:
        s2 = bytes(s, "utf-8").decode("unicode_escape", errors="ignore") if "\\" in s else s
        if s2.lower() in SKIP:
            continue
        if all(c in ".-_/\\" or c.isdigit() for c in s2):
            continue
        sc = score_string(s2)
        if sc >= 4:
            scored.append((sc, s2))
    if not scored:
        return None
    scored.sort(key=lambda x: (-x[0], -len(x[1])))
    best = scored[0][1]
    # Prefer last path component for source paths
    if "\\" in best or "/" in best:
        best = re.split(r"[\\/]", best)[-1]
        best = re.sub(r"\.(cpp|h|hpp|c)$", "", best, flags=re.I)
    name = sanitize(best)
    if name.startswith("FUN_") or len(name) < 4:
        return None
    # Prefix domain
    bl = best.lower()
    if any(k in bl for k in ("mission", "objective", "quest", "dialog", "npc")):
        prefix = "Mission_"
    elif any(k in bl for k in ("skill", "cast", "quickbar", "cooldown")):
        prefix = "Skill_"
    elif any(k in bl for k in ("inventory", "equip", "grab", "drop", "cargo", "item")):
        prefix = "Inv_"
    elif any(k in bl for k in ("drive", "steer", "throttle", "handbrake", "vehicle")):
        prefix = "Drive_"
    elif any(k in bl for k in ("auth", "login", "protocol", "account")):
        prefix = "Auth_"
    else:
        prefix = "Named_"
    # Always suffix address so class-string collisions (gfxDevice, etc.) stay unique
    full = f"{prefix}{name}_{addr_hex}"
    if full == f"FUN_{addr_hex}":
        return None
    return full, best


def _primary_human_addrs() -> set[str]:
    """Addresses already owned by a non-FUN_*.cpp clean file (Stable/Address header)."""
    addrs: set[str] = set()
    stable = re.compile(r"Stable(?:\s*ID)?\s*:\s*aa_([0-9a-f]{8})", re.I)
    for p in CLEAN.glob("*.cpp"):
        if p.name.startswith("FUN_"):
            continue
        head = p.read_text(encoding="utf-8", errors="replace")[:1800]
        m = stable.search(head)
        if m:
            addrs.add(m.group(1).lower())
            continue
        m2 = re.search(r"_([0-9a-f]{8})\.cpp$", p.name, re.I)
        if m2:
            addrs.add(m2.group(1).lower())
            continue
        m3 = re.search(r"Address:\s*0x([0-9a-f]{8})", head, re.I)
        if m3:
            addrs.add(m3.group(1).lower())
    return addrs


def _unique_name(base: str, addr_hex: str) -> str:
    """Avoid collisions: first claim gets base; later addrs get _<addr> suffix."""
    if not (CLEAN / f"{base}.cpp").exists():
        return base
    # If existing file is already this address, keep base
    existing = CLEAN / f"{base}.cpp"
    head = existing.read_text(encoding="utf-8", errors="replace")[:1200]
    if f"aa_{addr_hex}" in head or f"0x{addr_hex}" in head.lower() or f"FUN_{addr_hex}" in head:
        return base
    with_addr = f"{base}_{addr_hex}"
    if not (CLEAN / f"{with_addr}.cpp").exists():
        return with_addr
    n = 2
    while (CLEAN / f"{with_addr}_{n}.cpp").exists():
        n += 1
    return f"{with_addr}_{n}"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--limit", type=int, default=200)
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()

    already = _primary_human_addrs()
    renames: list[tuple[str, str, str]] = []
    for raw in sorted(RAW.glob("aa_*.md")):
        if raw.name.endswith(".annotated.md"):
            continue
        if len(renames) >= args.limit:
            break
        m = re.match(r"aa_([0-9a-f]{8})_(.+)\.md$", raw.name, re.I)
        if not m:
            continue
        addr_hex, cur = m.group(1).lower(), m.group(2)
        if not cur.startswith("FUN_"):
            continue
        if addr_hex in already:
            continue
        text = raw.read_text(encoding="utf-8", errors="replace")
        # extract code block
        cm = re.search(r"```c\n(.*?)```", text, re.S)
        code = cm.group(1) if cm else text
        res = best_name_from_code(code, addr_hex)
        if not res:
            continue
        base_name, evidence = res
        newname = _unique_name(base_name, addr_hex)
        # Idempotent: skip if chosen path already present for this addr
        if (CLEAN / f"{newname}.cpp").exists():
            already.add(addr_hex)
            continue
        renames.append((addr_hex, newname, evidence))
        already.add(addr_hex)  # reserve within this batch

    print(f"candidates={len(renames)}")
    for addr_hex, newname, evidence in renames:
        print(f"0x{addr_hex} -> {newname}  ({evidence[:60]})")
        if args.dry_run:
            continue
        # Prefer existing clean body
        old_clean = CLEAN / f"FUN_{addr_hex}.cpp"
        if not old_clean.exists():
            # try any FUN matching
            cands = list(CLEAN.glob(f"FUN_{addr_hex}*.cpp"))
            old_clean = cands[0] if cands else None
        if old_clean and old_clean.exists():
            body = old_clean.read_text(encoding="utf-8")
            body = re.sub(rf"FUN_{addr_hex}", newname, body)
            if "String-driven rename evidence" not in body:
                body = body.replace(
                    "Behavioral notes:",
                    f"Behavioral notes:\n * String-driven rename evidence: \"{evidence}\"\n *",
                    1,
                )
            # Ensure Stable ID present for later primary-addr scans
            if f"aa_{addr_hex}" not in body[:500]:
                body = (
                    f"// {newname}\n// Stable ID: aa_{addr_hex}\n// Address: 0x{addr_hex}\n"
                    + body
                )
        else:
            body = (
                f"// {newname}\n// Stable ID: aa_{addr_hex}\n// Address: 0x{addr_hex}\n"
                f"// Evidence string: {evidence}\n"
                f"// See raw aa_{addr_hex}_*\n"
            )
        (CLEAN / f"{newname}.cpp").write_text(body, encoding="utf-8")
        # function record alias note
        for fp in FUNC.glob(f"aa_{addr_hex}_*"):
            t = fp.read_text(encoding="utf-8")
            if newname not in t:
                t = t.replace(
                    "## Purpose",
                    f"## Alias\n\nHuman name: `{newname}` (from string `{evidence}`)\n\n## Purpose",
                    1,
                )
                fp.write_text(t, encoding="utf-8")

    print(f"wrote={0 if args.dry_run else len(renames)}")
    return 0



if __name__ == "__main__":
    raise SystemExit(main())
