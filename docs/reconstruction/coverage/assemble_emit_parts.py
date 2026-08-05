"""Assemble fragment parts into batch JSON and emit units industrial."""
from __future__ import annotations
import json
import sys
from pathlib import Path

ROOT = Path("docs/reconstruction/coverage")
sys.path.insert(0, str(ROOT))
from emit_units_industrial import write_unit, load_names  # type: ignore

def assemble_and_emit(batch_id: str, force: bool = False) -> dict:
    parts = ROOT / "_parts" / batch_id
    if not parts.is_dir():
        raise SystemExit(f"missing parts dir {parts}")
    batch = {}
    for p in sorted(parts.glob("*.c")):
        addr = "0x" + p.stem.lower().replace("0x", "")
        # normalize to 0x00aabbcc
        addr = f"0x{addr[2:].zfill(8)}"
        batch[addr] = p.read_text(encoding="utf-8")
    out = ROOT / f"tmp_batch_{batch_id}.json"
    out.write_text(json.dumps(batch, ensure_ascii=False), encoding="utf-8")
    name_map = {}
    for np in [
        ROOT / "named_not_yet_reconstructed.jsonl",
        ROOT / "high_priority_named.jsonl",
    ]:
        name_map.update(load_names(np))
    results = []
    for addr, code in batch.items():
        if code.strip():
            results.append(write_unit(addr, code, name_map, "unknown", force))
    ledger = ROOT / "emit_ledger.jsonl"
    with ledger.open("a", encoding="utf-8") as f:
        for r in results:
            f.write(json.dumps(r) + "\n")
    new_raw = sum(1 for r in results if r["new_raw"])
    new_clean = sum(1 for r in results if r["new_clean"])
    print(f"{batch_id}: units={len(results)} new_raw={new_raw} new_clean={new_clean}")
    for r in results:
        flag = "NEW" if r["new_raw"] else "keep"
        print(f"  {flag} {r['stable']} {r['name']} [{r['system']}]")
    return {"batch": batch_id, "units": len(results), "new_raw": new_raw, "new_clean": new_clean}

if __name__ == "__main__":
    ids = sys.argv[1:] or []
    totals = {"units": 0, "new_raw": 0, "new_clean": 0}
    for bid in ids:
        s = assemble_and_emit(bid)
        totals["units"] += s["units"]
        totals["new_raw"] += s["new_raw"]
        totals["new_clean"] += s["new_clean"]
    print("TOTAL", totals)
