"""Stamp inventory.jsonl status from function records / trivial batches.

full        — function record (or raw+clean) exists
trivial-batch — Unwind@/Catch@ or already trivial / import thunk ledger
none        — still need reconstruction

Usage:
  python docs/reconstruction/coverage/stamp_inventory_status.py
"""
from __future__ import annotations

import json
from pathlib import Path

ROOT = Path("docs/reconstruction")
INV = ROOT / "coverage" / "inventory.jsonl"
FUNCS = ROOT / "functions"
RAW = ROOT / "raw"
TB_UNWIND = ROOT / "coverage" / "trivial_batch_unwind.jsonl"
TB_IMPORTS = ROOT / "coverage" / "trivial_batch_imports.jsonl"
TB_THUNKS = ROOT / "coverage" / "trivial_batch_thunks.jsonl"


def load_have() -> set[str]:
    have: set[str] = set()
    for p in FUNCS.glob("aa_*.md"):
        parts = p.stem.split("_")
        if len(parts) >= 2:
            have.add("0x" + parts[1].lower())
    for p in RAW.glob("aa_*.md"):
        if p.name.endswith(".annotated.md"):
            continue
        parts = p.stem.split("_")
        if len(parts) >= 2:
            have.add("0x" + parts[1].lower())
    return have


def load_trivial_addrs() -> set[str]:
    out: set[str] = set()
    for path in (TB_UNWIND, TB_IMPORTS, TB_THUNKS):
        if not path.exists():
            continue
        for line in path.read_text(encoding="utf-8").splitlines():
            if not line.strip():
                continue
            try:
                r = json.loads(line)
            except json.JSONDecodeError:
                continue
            a = (r.get("addr") or r.get("address") or "").lower()
            if a:
                if not a.startswith("0x"):
                    a = "0x" + a.zfill(8)
                out.add(a)
    return out


def main() -> int:
    have = load_have()
    trivial_extra = load_trivial_addrs()
    rows = []
    status: dict[str, int] = {}
    for line in INV.read_text(encoding="utf-8").splitlines():
        if not line.strip():
            continue
        r = json.loads(line)
        a = r["addr"].lower()
        n = r.get("name") or ""
        if n.startswith("Unwind@") or n.startswith("Catch@"):
            r["status"] = "trivial-batch"
        elif a in trivial_extra and a not in have:
            r["status"] = "trivial-batch"
        elif a in have:
            r["status"] = "full"
        elif r.get("status") == "trivial-batch":
            r["status"] = "trivial-batch"
        elif r.get("status") == "reviewed":
            r["status"] = "reviewed"
        else:
            r["status"] = "none"
        status[r["status"]] = status.get(r["status"], 0) + 1
        rows.append(r)
    INV.write_text(
        "\n".join(json.dumps(x, ensure_ascii=False) for x in rows) + "\n",
        encoding="utf-8",
    )
    accounted = sum(status.get(k, 0) for k in ("full", "reviewed", "trivial-batch"))
    print(json.dumps({"status": status, "have_units": len(have), "accounted": accounted, "total": len(rows)}, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
