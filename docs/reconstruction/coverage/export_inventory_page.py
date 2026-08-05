"""Append inventory page results JSON into coverage/inventory_pages/."""
from __future__ import annotations

import json
import sys
from pathlib import Path

OUT = Path("docs/reconstruction/coverage/inventory_pages")


def main() -> int:
    if len(sys.argv) < 3:
        print("usage: export_inventory_page.py <offset> <results.json>")
        return 2
    offset = int(sys.argv[1])
    data = json.loads(Path(sys.argv[2]).read_text(encoding="utf-8"))
    OUT.mkdir(parents=True, exist_ok=True)
    results = data.get("results", data if isinstance(data, list) else [])
    path = OUT / f"page_{offset:05d}.jsonl"
    with path.open("w", encoding="utf-8") as f:
        for r in results:
            addr = r.get("address") or r.get("addr")
            name = r.get("name")
            if not addr:
                continue
            hexpart = str(addr).lower().replace("0x", "").zfill(8)
            rec = {
                "addr": f"0x{hexpart}",
                "name": name,
                "status": "none",
                "xref_count": r.get("xref_count"),
                "isThunk": r.get("isThunk"),
            }
            f.write(json.dumps(rec) + "\n")
    print(f"wrote {path} lines={len(results)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
