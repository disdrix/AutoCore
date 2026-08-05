"""Xref/callee-driven renames: alias FUN_* still without a human Named_ name.

Scans clean Client_*, CVOG*, Auth_* units for call-site FUN_0xXXXXXXXX / FUN_XXXXXXXX
identifiers. For each callee that still only has FUN_<addr>.cpp (no primary human
alias), writes Named_CalleeOf_<parent>_<addr>.cpp with plate "Callee of <parent>".

Does not delete FUN_*.cpp originals. Limit default 200.

Usage:
  python docs/reconstruction/coverage/callee_driven_rename.py [--limit N] [--dry-run]
"""
from __future__ import annotations

import argparse
import re
from collections import defaultdict
from pathlib import Path

ROOT = Path("docs/reconstruction")
CLEAN = ROOT / "reconstructed-exact"
FUNC = ROOT / "functions"

# Callee tokens in decompiler / clean bodies
FUN_RE = re.compile(r"\bFUN_(?:0x)?([0-9a-fA-F]{8})\b")

# Parent clean sources that seed the xref scan (include multi-hop Named_ aliases)
PARENT_GLOBS = (
    "Client_*.cpp",
    "CVOG*.cpp",
    "Auth_*.cpp",
    "AuthClient_*.cpp",
    "Named_*.cpp",
    "Mission_*.cpp",
    "Skill_*.cpp",
    "Inv_*.cpp",
    "Drive_*.cpp",
)

# Prefer these parent prefixes when a callee has multiple callers
PARENT_PRIORITY = (
    "Client_",
    "CVOG",
    "Auth_",
    "AuthClient_",
    "Named_",
    "Mission_",
    "Skill_",
    "Inv_",
    "Drive_",
)


def _stem_parent(path: Path) -> str:
    """Human parent stem without trailing _<8hex> address suffix when present."""
    stem = path.stem
    m = re.search(r"_([0-9a-f]{8})$", stem, re.I)
    if m:
        # Keep address-suffixed parent only if base is empty-ish; else drop suffix
        base = stem[: m.start()]
        if base and not base.startswith("FUN_"):
            return base
    return stem


def _parent_rank(name: str) -> tuple[int, int, str]:
    """Lower rank = better parent for CalleeOf naming."""
    for i, pref in enumerate(PARENT_PRIORITY):
        if name.startswith(pref):
            return (i, len(name), name)
    return (len(PARENT_PRIORITY), len(name), name)


def _primary_human_addrs() -> set[str]:
    """Addresses already owned by a non-FUN_*.cpp clean file."""
    addrs: set[str] = set()
    stable = re.compile(r"Stable(?:\s*ID)?\s*:\s*aa_([0-9a-f]{8})", re.I)
    for p in CLEAN.glob("*.cpp"):
        if p.name.startswith("FUN_"):
            continue
        try:
            head = p.read_text(encoding="utf-8", errors="replace")[:1800]
        except OSError:
            continue
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


def _fun_clean_path(addr_hex: str) -> Path | None:
    """Locate FUN_<addr>.cpp (optional 0x prefix variants)."""
    for name in (f"FUN_{addr_hex}.cpp", f"FUN_0x{addr_hex}.cpp"):
        p = CLEAN / name
        if p.exists():
            return p
    cands = list(CLEAN.glob(f"FUN_{addr_hex}*.cpp"))
    if cands:
        return cands[0]
    cands = list(CLEAN.glob(f"FUN_0x{addr_hex}*.cpp"))
    return cands[0] if cands else None


def _collect_parents() -> list[Path]:
    seen: set[str] = set()
    out: list[Path] = []
    for g in PARENT_GLOBS:
        for p in sorted(CLEAN.glob(g)):
            if p.name.startswith("FUN_"):
                continue
            key = p.name.lower()
            if key in seen:
                continue
            seen.add(key)
            out.append(p)
    return out


def _scan_callees(parents: list[Path]) -> dict[str, set[str]]:
    """addr_hex -> set of parent stems that call it."""
    callees: dict[str, set[str]] = defaultdict(set)
    for parent in parents:
        parent_name = _stem_parent(parent)
        if parent_name.startswith("FUN_"):
            continue
        try:
            text = parent.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        for m in FUN_RE.finditer(text):
            addr = m.group(1).lower()
            # Skip self-ref if somehow named FUN_ in body as parent address
            callees[addr].add(parent_name)
    return callees


def _pick_parent(parents: set[str]) -> str:
    return sorted(parents, key=_parent_rank)[0]


def _better_name(parent: str, addr_hex: str, all_parents: set[str]) -> str:
    """Named_CalleeOf_<parent>_<addr>, truncated parent if needed for path safety."""
    # Prefer short-ish parent; Windows path headroom
    p = re.sub(r"[^A-Za-z0-9_]+", "_", parent)
    p = re.sub(r"_+", "_", p).strip("_")
    if len(p) > 48:
        p = p[:48].rstrip("_")
    base = f"Named_CalleeOf_{p}_{addr_hex}"
    # Multi-caller note is only in plate, not filename (keep stable single parent)
    _ = all_parents
    return base


def _unique_path(base: str, addr_hex: str) -> str:
    if not (CLEAN / f"{base}.cpp").exists():
        return base
    existing = CLEAN / f"{base}.cpp"
    try:
        head = existing.read_text(encoding="utf-8", errors="replace")[:1200]
    except OSError:
        head = ""
    if f"aa_{addr_hex}" in head or f"0x{addr_hex}" in head.lower() or f"FUN_{addr_hex}" in head:
        return base
    with_n = f"{base}_2"
    n = 2
    while (CLEAN / f"{with_n}.cpp").exists():
        n += 1
        with_n = f"{base}_{n}"
    return with_n


def _build_alias_body(old_clean: Path, newname: str, addr_hex: str, parent: str, n_callers: int) -> str:
    body = old_clean.read_text(encoding="utf-8", errors="replace")
    # Rename primary symbol occurrences of this FUN only
    body = re.sub(rf"\bFUN_{addr_hex}\b", newname, body)
    body = re.sub(rf"\bFUN_0x{addr_hex}\b", newname, body, flags=re.I)

    plate_note = f"Callee of {parent}"
    if n_callers > 1:
        plate_note += f" (+{n_callers - 1} other named callers)"

    if "Callee of " not in body[:2500]:
        if "Behavioral notes:" in body:
            body = body.replace(
                "Behavioral notes:",
                f"Behavioral notes:\n * {plate_note}\n * Xref/callee-driven rename (parent seed scan)\n *",
                1,
            )
        elif "PURPOSE (auto):" in body:
            body = body.replace(
                "PURPOSE (auto):",
                f"PURPOSE (auto): {plate_note}\n// PURPOSE (auto):",
                1,
            )
        else:
            body = (
                f"// {newname}\n// Stable ID: aa_{addr_hex}\n// Address: 0x{addr_hex}\n"
                f"// {plate_note}\n"
                + body
            )

    # Ensure title / stable id in header block when present
    body = re.sub(
        rf"^// FUN_{addr_hex}\s*$",
        f"// {newname}",
        body,
        count=1,
        flags=re.M,
    )
    if f"aa_{addr_hex}" not in body[:600]:
        body = (
            f"// {newname}\n// Stable ID: aa_{addr_hex}\n// Address: 0x{addr_hex}\n"
            f"// {plate_note}\n"
            + body
        )
    elif plate_note not in body[:800]:
        # Insert plate under Stable line if possible
        body = re.sub(
            rf"(// Stable(?:\s*ID)?\s*:\s*aa_{addr_hex}\s*\n)",
            rf"\1// {plate_note}\n",
            body,
            count=1,
            flags=re.I,
        )
    return body


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--limit", type=int, default=200)
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()

    parents = _collect_parents()
    already = _primary_human_addrs()
    callees = _scan_callees(parents)

    # Rank candidates: more named parents first, then lower address
    candidates: list[tuple[int, str, str, set[str]]] = []
    for addr, pset in callees.items():
        if addr in already:
            continue
        if not _fun_clean_path(addr):
            continue
        parent = _pick_parent(pset)
        candidates.append((-len(pset), addr, parent, pset))

    candidates.sort(key=lambda t: (t[0], t[1]))

    renames: list[tuple[str, str, str, int]] = []
    for _neg_n, addr, parent, pset in candidates:
        if len(renames) >= args.limit:
            break
        if addr in already:
            continue
        base = _better_name(parent, addr, pset)
        newname = _unique_path(base, addr)
        dest = CLEAN / f"{newname}.cpp"
        if dest.exists():
            # Already emitted for this addr
            already.add(addr)
            continue
        renames.append((addr, newname, parent, len(pset)))
        already.add(addr)

    print(f"parents_scanned={len(parents)}")
    print(f"unique_fun_callees_seen={len(callees)}")
    print(f"candidates={len(renames)}")
    for addr, newname, parent, n in renames:
        print(f"0x{addr} -> {newname}  (parent={parent}, callers={n})")
        if args.dry_run:
            continue
        old = _fun_clean_path(addr)
        if not old:
            continue
        body = _build_alias_body(old, newname, addr, parent, n)
        (CLEAN / f"{newname}.cpp").write_text(body, encoding="utf-8")
        # function record alias note (best-effort)
        for fp in FUNC.glob(f"aa_{addr}_*"):
            try:
                t = fp.read_text(encoding="utf-8", errors="replace")
            except OSError:
                continue
            if newname in t:
                continue
            if "## Purpose" in t:
                t = t.replace(
                    "## Purpose",
                    f"## Alias\n\nHuman name: `{newname}` (callee of `{parent}`)\n\n## Purpose",
                    1,
                )
            else:
                t = f"## Alias\n\nHuman name: `{newname}` (callee of `{parent}`)\n\n" + t
            fp.write_text(t, encoding="utf-8")

    print(f"wrote={0 if args.dry_run else len(renames)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
