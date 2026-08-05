# Coverage honesty — wave 3 (2026-07-29)

| Field | Value |
|-------|-------|
| Wave | wave 3 — coverage honesty note (OWN ONLY) |
| Date | 2026-07-29 |
| Method | Live shell counts under workspace `C:\Users\josh\Documents\GitHub\AutoCore` |
| Scope | Report only — **no** `WORK_QUEUE` / `RESUME` edits |

## Shell counts (do not invent)

| Metric | Count | How counted |
|--------|------:|-------------|
| `docs/reconstruction/functions/aa_*.md` | **17277** | `Get-ChildItem … -Filter "aa_*.md" -File` on `functions/` |
| A dual files `reviews/A_aa_*.md` | **560** | `Get-ChildItem … -Filter "A_aa_*.md" -File` on `reviews/` |
| Unique A dual VAs (from `A_aa_*` names) | **547** | Hex8 extracted from filename `A_aa_XXXXXXXX…`; unique |
| B dual files `reviews/B_aa_*.md` | **560** | Same filter for `B_aa_*.md` |
| Unique B dual VAs | **547** | Hex8 from `B_aa_XXXXXXXX…`; unique |
| VAs with both A and B dual files | **547** | Intersection of unique A/B address sets |
| Short-form `reviews/a_<hex8>.md` | **35** | `^a_[0-9a-fA-F]{8}\.md$`; **all** map into the same 547 VAs (0 extra) |
| VAs with multiple `A_aa_*` files | **12** | Group-by address; explains 560 − 547 = 13 extra A files |

### A duals (headline)

- **A dual file count: 560** (`A_aa_*.md`)
- **A dual unique addresses: 547**
- Pair coverage: every unique A VA has a matching B dual file (0 only-A / 0 only-B among `A_aa_` / `B_aa_` sets)

## Deep dual estimate ≪ 26256

| Reference | Value |
|-----------|------:|
| Ghidra function count | **26256** (`coverage/progress.json` → `function_count_ghidra`; ledger 2026-07-23) |
| Dual-file paired VAs (A∩B) | **547** |
| Deep dual-reviewed units (priority / three-rep quality class) | **≪ 26256** — order of **hundreds** at dual-file depth, **not** full-binary depth |

**Honesty statement:** Even counting every VA that has dual-review *files* (~547), deep dual-reviewed coverage is **far below** the Ghidra function population (**26256**). Function records on disk (**17277** `functions/aa_*.md`) are **not** the same as dual-reviewed depth. Do **not** equate bulk plates, inventory status `full`, or function-record count with deep dual verification.

Approximate ratios (shell, this pass):

| Ratio | Value |
|-------|------:|
| Dual-paired VAs / Ghidra functions | 547 / 26256 ≈ **2.1%** |
| Function records / Ghidra functions | 17277 / 26256 ≈ **65.8%** |

## Inventory stamp note

Source: `docs/reconstruction/coverage/inventory.jsonl` + `docs/reconstruction/coverage/progress.json` (updated **2026-07-28**).

| Stamp field | Value |
|-------------|------:|
| `inventory.jsonl` line count | **25664** |
| Status `full` | **17156** |
| Status `trivial-batch` | **8508** |
| Status other / `none` | **0** (shell Counter on jsonl) |
| Sum (`full` + `trivial-batch`) | **25664** = listed total |
| Ghidra `function_count_ghidra` | **26256** |
| Gap (Ghidra − inventory listed) | **592** (inventory export field ≠ live Ghidra count) |
| `progress.json` note | `INVENTORY ACCOUNTED 25664/25664: full=17156 reviewed=0 trivial-batch=8508 none=0` |
| `inventory_accounted` | `true` |
| `full_coverage` in progress.json | `true` (**inventory-accounted only** — not deep dual complete) |

### Stamp ≠ dual depth

1. **Inventory stamp ACCOUNTED 25664/25664** means every *listed inventory row* has status `full` or `trivial-batch`.
2. That stamp **does not** mean every address is dual-reviewed, runtime-verified, or bit-exact vs retail.
3. `progress.json` itself records **`reviewed=0`** in the inventory status breakdown while dual files exist under `reviews/` — inventory codes track plate/account class, not dual A/B depth.
4. Ghidra still reports **26256** functions; listed inventory is **25664**. Neither number is a deep dual count.
5. Cold resume rule (parent / ACTIVE_WORK): **deep duals ≪ 26256**; claim **inventory stamp ≠ full dual depth**.

## What this wave must not claim

- That **17277** function records = reconstruction complete
- That **25664** inventory-accounted = full binary dual depth
- That **547** dual-paired VAs close the **26256** function goal
- That `progress.json` `"full_coverage": true` means deep dual complete (it means inventory rows are stamped, not dual-verified)

## Refresh recipe (next honesty pass)

```powershell
# From repo root
(Get-ChildItem docs\reconstruction\functions -Filter aa_*.md -File).Count
(Get-ChildItem docs\reconstruction\reviews -Filter A_aa_*.md -File).Count
# Unique A VAs + A∩B: extract hex8 from A_aa_/B_aa_ names, Sort-Object -Unique, intersect
(Get-Content docs\reconstruction\coverage\inventory.jsonl | Measure-Object -Line).Lines
```

## Related

- Partition: `reviews/WAVE_2026-07-29_wave3_partition_map.md`
- Ledger (stale artifact table vs live counts — trust shell above): `COVERAGE_LEDGER.md`
- Machine stamp: `coverage/progress.json`, `coverage/inventory.jsonl`
- Parent honesty lines: `ACTIVE_WORK.md`, `CHANGE_LOG.md` (wave 3 launch)
)
