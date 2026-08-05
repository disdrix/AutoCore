# Coverage Ledger

| Field | Value |
|-------|-------|
| Program | `autoassault.exe` |
| Image base | `0x400000` |
| Ghidra function count (**live** `list_functions_enhanced`) | **25666** |
| Ghidra function count (legacy stamp) | 26256 — **stale**; do not size worklists from this alone |
| Inventory listed | **25666** (52 pages + 2 live gap closes) |
| Inventory accounted (`none=0`) | **true** |
| Dual A/B pairs | **2209 unique** (deep reviewed ≪ universe ≈ 8.6%) |
| Function records `aa_*.md` | **~18200** |
| Terminal full coverage | **false** — every live VA must be full/reviewed/trivial-batch/deferred-low |
| Bit-for-bit vs retail EXE | **Deferred** |
| Last refresh | 2026-08-04 WQ-007 residual dual seal |

## Honesty (mandatory)

1. `progress.json` **`full_coverage: true`** means **inventory stamp accounted** on listed rows only (`none=0`). It is **not** dual depth and **not** terminal OBJECTIVE complete.
2. Dual A/B **2209 ≪ 25666**. Function-record / clean industrial counts are also not dual-reviewed depth.
3. Legacy dual~586 / Ghidra 26256 are **stale** — do not size worklists from those alone.
3. Terminal bar (plan AC2): continue multi-agent waves until **every** live Ghidra VA is `full` / `reviewed` / `trivial-batch` / `deferred-low` (with reason).
4. Live inventory gap report: `reviews/WAVE_2026-07-29_inventory_gap_report.md` (legacy 592 mostly stale count; residual was 2 addrs, closed).

## Artifact counts (refresh each major pass)

| Artifact class | Count | Notes |
|----------------|------:|-------|
| `functions/aa_*.md` | **~18200** | Function records |
| `raw/aa_*.md` | large industrial | Immutable captures |
| `reconstructed-exact/*.cpp` | **~27370** | Clean sources |
| Dual A/B | **2209** | Deep dual-reviewed unique VA |
| Trivial-batch (Unwind@/Catch@) | **8508** | `coverage/trivial_batch_unwind.jsonl` |
| Import trivial ledger | **201** (FF25 pool exhausted) | `coverage/trivial_batch_imports.jsonl` |
| Thunk trivial ledger | **67** (E9 pool exhausted) | `coverage/trivial_batch_thunks.jsonl` |

## Status codes

| Code | Meaning |
|------|---------|
| `none` | Not started |
| `raw` | Raw capture only |
| `partial` | Raw + some of annotated/clean/record |
| `full` | Three representations + function record |
| `reviewed` | Full + dual reviews (important units) |
| `trivial-batch` | Accounted as accessor/thunk/compiler via batch template |
| `deferred-low` | Low-priority infrastructure parked after HL work |

## Machine-readable index

- `coverage/inventory.jsonl` — one line per function: `{addr,name,status,system,priority}`
- `coverage/progress.json` — aggregate counts

## Priority order (always in force)

1. Missions / skills / inventory / interaction / input managers
2. Movement, actions, health, progression, entity interaction, dialog, world transitions
3. User-visible state / persistence / comms as needed
4. Lifecycle last unless required
5. Physics / lighting / networking plumbing / allocators **last** (unless dependency)

## Full-coverage rule

Criterion 1 (terminal) is met only when **every** live Ghidra function address is either `full`/`reviewed`/`trivial-batch` with artifacts (or batch ledger entry) under `docs/reconstruction/`, or `deferred-low` with explicit reason. Partial sessions must not claim complete. Inventory stamp alone is insufficient.
