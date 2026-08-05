"""Build partitioned address worklists for parallel reconstruction agents."""
from __future__ import annotations

import json
from pathlib import Path

ROOT = Path("docs/reconstruction/coverage")
INV = ROOT / "inventory.jsonl"
FUNCS = Path("docs/reconstruction/functions")
OUT = ROOT / "worklists"


def main() -> int:
    have: set[str] = set()
    for p in FUNCS.glob("aa_*.md"):
        parts = p.stem.split("_")
        if len(parts) >= 2:
            have.add("0x" + parts[1].lower())

    named: list[dict] = []
    funs: list[dict] = []
    for line in INV.read_text(encoding="utf-8").splitlines():
        if not line.strip():
            continue
        r = json.loads(line)
        a = r["addr"].lower()
        if a in have:
            continue
        n = r.get("name") or ""
        if n.startswith("Unwind@") or n.startswith("Catch@"):
            continue
        if not n.startswith("FUN_") and not n.startswith("__"):
            named.append(r)
        else:
            funs.append(r)

    OUT.mkdir(parents=True, exist_ok=True)
    for old in OUT.glob("*.txt"):
        old.unlink()

    def write_batches(rows: list[dict], prefix: str, nbatches: int, size: int) -> int:
        written = 0
        for i in range(nbatches):
            chunk = rows[i * size : (i + 1) * size]
            if not chunk:
                break
            addrs = ",".join(r["addr"] for r in chunk)
            body = addrs + "\n" + "\n".join(f"{r['addr']} {r['name']}" for r in chunk) + "\n"
            (OUT / f"{prefix}_{i:03d}.txt").write_text(body, encoding="utf-8")
            written += 1
        return written

    # Cover all remaining: ~20 per batch; size batches to exhaust funs/named
    n_named = write_batches(named, "named_hl", max(40, (len(named) + 15) // 16), 16)
    n_fun = write_batches(funs, "fun_bulk", max(80, (len(funs) + 19) // 20), 20)
    priority = [
        r
        for r in named
        if any(
            x in (r.get("name") or "").lower()
            for x in (
                "killxp",
                "combat",
                "award",
                "give",
                "mission",
                "skill",
                "inventory",
                "equip",
                "drive",
                "steer",
                "xp",
                "credit",
                "cast",
                "quickbar",
                "objective",
                "dialog",
                "input",
            )
        )
    ]
    n_pri = write_batches(priority, "priority", 30, 12)

    print(f"have_units={len(have)} named_remaining={len(named)} fun_remaining={len(funs)}")
    print(f"batches named_hl={n_named} fun_bulk={n_fun} priority={n_pri}")
    print(f"priority_rows={len(priority)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
