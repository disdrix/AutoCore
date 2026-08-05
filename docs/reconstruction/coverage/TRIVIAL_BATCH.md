# Trivial-batch accounting

Some Ghidra functions are **compiler / runtime machinery**, not game logic. For coverage criterion 1 they are accounted as `trivial-batch` via durable batch ledgers under `docs/reconstruction/coverage/`. They are **not** dual-reviewed managers and do **not** require full `raw` + annotated + clean + function-record reconstruction.

## What counts as trivial-batch

| Class | Name pattern | Reason | Ledger |
|-------|--------------|--------|--------|
| SEH unwind helpers | `Unwind@*` | MSVC structured-exception-handling unwind thunks | [`trivial_batch_unwind.jsonl`](trivial_batch_unwind.jsonl) |
| SEH catch helpers | `Catch@*` | MSVC catch-block entry helpers | [`trivial_batch_unwind.jsonl`](trivial_batch_unwind.jsonl) |
| Pure import thunks | (IAT / import stubs when batch-accounted) | Jump-to-import only; no local game logic | (separate ledger when emitted) |

## Policy

- **Accounted for coverage:** yes — status `trivial-batch` with a batch ledger row is a valid criterion-1 accounting (see [`COVERAGE_LEDGER.md`](../COVERAGE_LEDGER.md)).
- **Full dual-reviewed reconstruction:** no — do not spend dual-review or manager write-up effort on these.
- **Do not claim `full_coverage: true`** until every address in the Ghidra function set is either `full` / `reviewed` / `trivial-batch` (or other approved terminal status) with artifacts or batch ledger entry.

## Unwind / Catch batch (this pass)

Source: names in [`inventory.jsonl`](inventory.jsonl) starting with `Unwind@` or `Catch@`.

| Metric | Count |
|--------|------:|
| `Unwind@*` | 7837 |
| `Catch@*` | 671 |
| **Total this batch** | **8508** |

Each row in `trivial_batch_unwind.jsonl`:

```json
{"addr": "0x........", "name": "Unwind@........", "status": "trivial-batch", "reason": "SEH unwind/catch helper"}
```

## Notes

- Inventory listing may be incomplete relative to Ghidra’s full function count; this batch covers only rows present in `inventory.jsonl` with those name prefixes.
- Pure import thunks are the same *coverage class* but are tracked separately when a dedicated import-thunk ledger is written.
- Updating inventory `status` fields for these addresses is optional housekeeping; the durable account is the batch JSONL + this note.
