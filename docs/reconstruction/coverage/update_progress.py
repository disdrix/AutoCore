"""Refresh coverage/progress.json from filesystem + inventory."""
from __future__ import annotations

import json
from datetime import date
from pathlib import Path

ROOT = Path("docs/reconstruction")
COV = ROOT / "coverage"
PROG = COV / "progress.json"


def main() -> int:
    prog = {}
    if PROG.exists():
        prog = json.loads(PROG.read_text(encoding="utf-8"))
    inv = COV / "inventory.jsonl"
    listed = sum(1 for line in inv.read_text(encoding="utf-8").splitlines() if line.strip())
    # Inventory status histogram
    status_counts: dict[str, int] = {}
    inv_path = COV / "inventory.jsonl"
    if inv_path.exists():
        for line in inv_path.read_text(encoding="utf-8").splitlines():
            if not line.strip():
                continue
            try:
                st = json.loads(line).get("status", "none")
            except json.JSONDecodeError:
                st = "none"
            status_counts[st] = status_counts.get(st, 0) + 1
    none_n = status_counts.get("none", 0)
    full_n = status_counts.get("full", 0)
    reviewed_n = status_counts.get("reviewed", 0)
    trivial_n = status_counts.get("trivial-batch", 0)
    accounted = full_n + reviewed_n + trivial_n
    inventory_accounted = listed == 25664 and none_n == 0 and accounted == listed

    prog.update(
        {
            "program": "autoassault.exe",
            "image_base": "0x400000",
            "function_count_ghidra": 26256,
            "inventory_source_total_field": 25664,
            "inventory_listed": listed,
            "function_records": len(list((ROOT / "functions").glob("aa_*.md"))),
            "raw_captures_approx": len(list((ROOT / "raw").glob("aa_*.md"))),
            "reconstructed_exact_approx": len(
                list((ROOT / "reconstructed-exact").glob("*.cpp"))
            ),
            "reviews_approx": len(list((ROOT / "reviews").glob("*.md"))),
            "inventory_pages": len(list((COV / "inventory_pages").glob("page_*.jsonl"))),
            "systems_mapped": 4,
            "bit_for_bit_deferred": True,
            "inventory_status": status_counts,
            "inventory_accounted": inventory_accounted,
            # full_coverage: every inventory addr is full/reviewed/trivial-batch
            "full_coverage": inventory_accounted,
            "priority_focus": [
                "missions-progression",
                "skills-abilities",
                "inventory-transfer",
                "input-drive-control",
            ],
            "updated": date.today().isoformat(),
        }
    )
    tb = prog.get("trivial_batch_count", trivial_n)
    if inventory_accounted:
        named_clean = len(
            [
                p
                for p in (ROOT / "reconstructed-exact").glob("*.cpp")
                if not p.name.startswith("FUN_")
            ]
        )
        prog["named_clean_aliases_approx"] = named_clean
        prog["note"] = (
            f"INVENTORY ACCOUNTED {accounted}/{listed}: full={full_n} reviewed={reviewed_n} "
            f"trivial-batch={trivial_n} none=0. Units ~{prog['function_records']} records; "
            f"named clean aliases ~{named_clean}. FUN_* PURPOSE+CF plates complete. "
            f"Bit-for-bit vs retail EXE DEFERRED. Semantic rename depth continues."
        )
    else:
        prog["note"] = (
            f"Inventory listed {listed}/{prog['inventory_source_total_field']}. "
            f"Units ~{prog['function_records']} records / ~{prog['raw_captures_approx']} raw. "
            f"status={status_counts}. NOT complete until every addr is full/reviewed/trivial-batch."
        )
    PROG.write_text(json.dumps(prog, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(prog, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
