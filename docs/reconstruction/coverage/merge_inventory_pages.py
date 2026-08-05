"""Merge inventory_pages/*.jsonl into inventory.jsonl and update progress.json."""
from __future__ import annotations

import json
from pathlib import Path

ROOT = Path("docs/reconstruction/coverage")
PAGES = ROOT / "inventory_pages"
OUT = ROOT / "inventory.jsonl"
PROGRESS = ROOT / "progress.json"


def main() -> int:
    rows: dict[str, dict] = {}
    # keep existing statuses if present
    if OUT.exists():
        for line in OUT.read_text(encoding="utf-8").splitlines():
            if not line.strip():
                continue
            r = json.loads(line)
            rows[r["addr"].lower()] = r

    page_files = sorted(PAGES.glob("page_*.jsonl"))
    for pf in page_files:
        for line in pf.read_text(encoding="utf-8").splitlines():
            if not line.strip():
                continue
            r = json.loads(line)
            addr = r["addr"].lower()
            if addr in rows:
                # preserve status/name upgrades
                prev = rows[addr]
                if prev.get("status") not in (None, "none") and r.get("status") in (None, "none"):
                    r["status"] = prev["status"]
                if prev.get("name") and (
                    not r.get("name") or str(r.get("name", "")).startswith("FUN_")
                ):
                    r["name"] = prev["name"]
            rows[addr] = r

    ordered = sorted(rows.values(), key=lambda x: int(x["addr"], 16))
    with OUT.open("w", encoding="utf-8") as f:
        for r in ordered:
            f.write(json.dumps(r) + "\n")

    progress = {}
    if PROGRESS.exists():
        progress = json.loads(PROGRESS.read_text(encoding="utf-8"))
    progress["inventory_listed"] = len(ordered)
    progress["inventory_pages"] = len(page_files)
    progress["full_coverage"] = False
    progress["updated"] = __import__("datetime").date.today().isoformat()
    # counts of artifacts
    recon = Path("docs/reconstruction")
    progress["function_records"] = len(list((recon / "functions").glob("aa_*.md")))
    progress["raw_captures_approx"] = len(list((recon / "raw").glob("aa_*.md")))
    progress["reconstructed_exact_approx"] = len(
        list((recon / "reconstructed-exact").glob("*.cpp"))
    )
    progress["reviews_approx"] = len(list((recon / "reviews").glob("*.md")))
    PROGRESS.write_text(json.dumps(progress, indent=2) + "\n", encoding="utf-8")
    print(f"merged {len(ordered)} inventory rows from {len(page_files)} pages")
    print(f"function_records={progress.get('function_records')}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
