"""Write batch decompile JSON from MCP file or stdin-like path, emit units."""
from __future__ import annotations
import json
import sys
from pathlib import Path

ROOT = Path("docs/reconstruction/coverage")
sys.path.insert(0, str(ROOT))
from emit_units_industrial import write_unit, load_names  # type: ignore

def main() -> int:
    if len(sys.argv) < 3:
        print("usage: save_emit_batch.py <batch_id> <json_path>")
        return 2
    batch_id = sys.argv[1]
    src = Path(sys.argv[2])
    data = json.loads(src.read_text(encoding="utf-8"))
    # normalize keys
    batch = {}
    for k, v in data.items():
        a = str(k).lower().replace("0x", "").strip()
        batch[f"0x{a.zfill(8)}"] = v
    out = ROOT / f"tmp_batch_{batch_id}.json"
    out.write_text(json.dumps(batch, ensure_ascii=False), encoding="utf-8")
    parts = ROOT / "_parts" / batch_id
    parts.mkdir(parents=True, exist_ok=True)
    for addr, code in batch.items():
        (parts / f"{addr[2:]}.c").write_text(code.strip() + "\n", encoding="utf-8")
    name_map = {}
    for np in [ROOT / "named_not_yet_reconstructed.jsonl", ROOT / "high_priority_named.jsonl"]:
        name_map.update(load_names(np))
    results = []
    for addr, code in batch.items():
        if str(code).strip():
            results.append(write_unit(addr, code, name_map, "unknown", False))
    ledger = ROOT / "emit_ledger.jsonl"
    with ledger.open("a", encoding="utf-8") as f:
        for r in results:
            f.write(json.dumps(r) + "\n")
    new_raw = sum(1 for r in results if r["new_raw"])
    print(f"{batch_id}: units={len(results)} new_raw={new_raw}")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
