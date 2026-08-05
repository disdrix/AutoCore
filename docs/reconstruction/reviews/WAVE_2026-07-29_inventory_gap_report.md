# WAVE 2026-07-29 — Inventory gap report (26256 vs 25664)

| Field | Value |
|-------|-------|
| Date | 2026-07-29 |
| Program | `autoassault.exe` (image base `0x400000`) |
| Method | `list_functions_enhanced` paged (offset/limit 0/10000, 10000/10000, 20000/10000); cross-check `list_methods` end page |
| Inventory | `docs/reconstruction/coverage/inventory.jsonl` (`addr` field) |
| Scratch export | `C:\Users\josh\AppData\Local\Temp\grok-goal-09ea1b2de129\implementer\missing_addrs.txt` |
| Inventory rewrite | **No** — not merged into `inventory.jsonl` |

## Counts

| Metric | Count | Source |
|--------|------:|--------|
| **ghidra_count (documented / ledger)** | **26256** | `COVERAGE_LEDGER.md` / `progress.json` `function_count_ghidra` (stamped 2026-07-23) |
| **ghidra_count (live remeasure)** | **25666** | `list_functions_enhanced` page lengths 10000 + 10000 + 5666; unique addresses 25666 |
| **inventory_count** | **25664** | line count + unique `addr` in `inventory.jsonl` |
| **claimed gap** (ledger arithmetic) | **592** | `26256 − 25664` |
| **live gap** (Ghidra ∖ inventory) | **2** | `25666 − 25664` |
| Inventory ∖ Ghidra (extra rows) | **0** | every inventory `addr` exists in live enhanced list |
| Live thunks (`isThunk=true`) | **258** | all non-external |
| Live externals (`isExternal=true`) | **0** | `search_functions_enhanced is_external=true` → total 0 |

### Page log (`list_functions_enhanced`)

| offset | limit | returned `count` / len |
|-------:|------:|------------------------:|
| 0 | 10000 | 10000 |
| 10000 | 10000 | 10000 |
| 20000 | 10000 | 5666 |
| **sum** | | **25666** |

Cross-check: `list_methods` offset 25600 limit 100 returned 66 names → total **25666**.

## Sample address comparison

Inventory head/tail samples are present in live Ghidra:

| inventory `addr` | in Ghidra enhanced? |
|------------------|---------------------|
| `0x00401000` (`FUN_00401000`) | yes |
| `0x00401030` (`FUN_00401030`) | yes |
| `0x009c5c70` (`FUN_009c5c70`) | yes |
| `0x009c5cf0` (`FUN_009c5cf0`) | yes |

Only addresses in live Ghidra but **not** in inventory:

| addr | name | isThunk | isExternal |
|------|------|---------|------------|
| `0x00512bb0` | `Skill_SiblingCastClearPredicate_INFERRED` | false | false |
| `0x005532e0` | `Skill_ValidateTarget_HBSkillListener` | false | false |

Both are **non-thunk, non-external**, skill-domain renames (not import stubs / SEH Unwind@/Catch@).

## Inventory composition (context)

| status | count |
|--------|------:|
| `full` | 17156 |
| `trivial-batch` | 8508 |
| **total** | **25664** |

Name classes (approx): FUN_* 16466, Unwind@ 7837, Catch@ 671, named 634, thunk-named 56. Inventory `isThunk=true` field sparsely populated (41) vs live thunk flag 258 — field completeness issue, not the gap driver.

## Hypothesis

### Why ledger still says 26256 / gap 592

1. **`function_count_ghidra: 26256` is a stale stamp (2026-07-23).** Live Ghidra enumeration via MCP (`list_functions_enhanced` + `list_methods`) is **25666**, not 26256. Difference **590** (`26256 − 25666`).
2. **The claimed 592-gap is almost entirely that stamp drift**, not 592 missing inventory rows. Live set difference is **2** addresses.
3. **Not explained by “externals omitted from inventory”:** live enhanced list has **0** external functions; filtering externals would not create a 592-row hole.
4. **Not explained by “thunks omitted from inventory”:** live thunks = 258 and inventory already contains many thunk / Unwind / Catch entries; extra inventory rows vs Ghidra = 0 (inventory ⊆ live Ghidra).
5. **Plausible origins of the stale 26256 figure (unproven):** prior program analysis state (more function creations), a different listing API/path that double-counted or included non-function symbols, or a one-time count that was never revalidated after auto-analysis / cleanup. Current tools do not return 26256.
6. **The residual live gap of 2** is consistent with **post-export renames / late function definitions** in the skill subsystem (`Skill_*` names) that never got a merge pass into `inventory.jsonl`.

### What the gap is *not*

- Not “inventory is 592 rows short of live Ghidra.”
- Not a bulk external/thunk filter (externals=0; thunks already largely listed).

## Next action to export / close missing

1. **Treat live ghidra_count as 25666** until a re-stamp of `progress.json` / `COVERAGE_LEDGER.md` is approved (out of scope of this report unless a separate meta pass updates stamps).
2. **Merge the 2 missing VAs into inventory** (safe append-only merge; do not rewrite existing rows):
   - `0x00512bb0` — `Skill_SiblingCastClearPredicate_INFERRED`
   - `0x005532e0` — `Skill_ValidateTarget_HBSkillListener`
   - Suggested row skeleton: `{"addr":"0x00…","name":"…","status":"none"}` then promote via normal artifact pipeline, or stamp `full` only if three representations already exist.
3. **Re-export verification:** re-run paged `list_functions_enhanced` (or `list_methods` total) → set-diff vs inventory `addr` → expect **gap 0**.
4. **Optional full re-export:** dump full enhanced list to JSONL (scratch already has `ghidra_functions_enhanced.jsonl`) and rebuild inventory from that if a clean rebaseline is preferred over a 2-row append.
5. **Do not** keep using **592** as the operational missing-addr worklist size; use **2** (live) or re-stamp Ghidra count first.

## Artifacts produced

| Path | Contents |
|------|----------|
| `docs/reconstruction/reviews/WAVE_2026-07-29_inventory_gap_report.md` | this report |
| scratch `missing_addrs.txt` | 2 missing VAs + names + flags |
| scratch `ghidra_functions_enhanced.jsonl` | full live enhanced dump (25666 lines) |

## Bottom line

| | |
|--|--|
| **ghidra_count (ledger)** | 26256 |
| **ghidra_count (live)** | **25666** |
| **inventory_count** | **25664** |
| **gap (live)** | **2** |
| **gap (claimed arithmetic)** | 592 (stale numerator) |
| **hypothesis** | Stale Ghidra total; residual 2 = post-export skill renames (not bulk external/thunk filter) |
| **next** | Append 2 addrs to inventory; re-diff; optionally re-stamp `function_count_ghidra` → 25666 |
