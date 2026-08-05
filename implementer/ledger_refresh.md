# Ledger refresh (OWN: docs honesty)

**Date:** 2026-07-29  
**Scope:** `docs/reconstruction/COVERAGE_LEDGER.md` + `docs/reconstruction/coverage/progress.json` only. No WORK_QUEUE.

## Shell counts used

| Metric | Count |
|--------|------:|
| `functions/aa_*.md` | 17291 |
| `raw/aa_*.md` | 34431 |
| `reconstructed-exact/*.cpp` | 26167 |
| `reviews/*.md` | 1296 |
| Dual A `A_aa_*.md` | 586 |
| Dual B `B_aa_*.md` | 586 |
| Dual depth unique VA (A+B) | ~573 |
| `inventory.jsonl` lines | 25664 |
| Inventory `full` | 17156 |
| Inventory `trivial-batch` | 8508 |
| Inventory `none` | 0 |
| `trivial_batch_unwind.jsonl` lines | 8508 |
| Ghidra total | 26256 |
| Gap (unlisted) | 592 |

## Honesty written into ledger/progress

- **Terminal full coverage = false** until every of 26256 is full/reviewed/trivial-batch/deferred-low.
- **`progress.json` `full_coverage: true`** = inventory **ACCOUNTED** on listed 25664 rows only (`none=0`); **not** dual complete; **not** terminal complete.
- Dual depth **≪ 26256** documented explicitly (~573–586).
- Status codes table **kept** in COVERAGE_LEDGER.
- Tests require `full_coverage` True, `inventory_accounted` True, `none=0` — those flags preserved; note strengthened so stamp ≠ terminal dual.

## Not done

- No WORK_QUEUE / RESUME edits.
- No inventory rebuild; no Launcher.
- Did not claim dual complete.
