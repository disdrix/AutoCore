# Coverage Ledger

| Field | Value |
|-------|-------|
| Program | `autoassault.exe` |
| Image base | `0x400000` |
| Ghidra function count (**live** `list_functions_enhanced`) | **25671** |
| Ghidra `get_function_count` MCP | **26263** â€” inflated vs list enumeration (same class as legacy 26256 stamp); **do not size terminal from this alone** |
| Inventory listed | **25671** |
| Inventory accounted (`none`/`raw`/`partial` = 0) | **true** |
| Inventory status | full **14437** · trivial-batch **8508** · reviewed **2726** |
| Dual A/B pairs | **2726 unique** (filesystem A∩B; ≪ universe ≈ 10.6%) |
| Inventory `reviewed` | **2726** — **matches dual A∩B** after WQ-AUDIT-002 bulk promote |
| Function records `aa_*.md` | **~18812** (~81% still **Partial scaffold**) |
| Terminal full coverage (list_functions universe) | **true** as **inventory stamp only** — every live listed VA is full / reviewed / trivial-batch |
| Dual depth complete | **false** — dual 2726 ≪ 25671; not the terminal status bar |
| Bit-for-bit vs retail EXE | **Deferred** |
| Last refresh | 2026-08-05 R13 sealed + WQ-AUDIT-002 reconcile (dual/reviewed=2726) |
| Residual dual volume waves | **Frozen** (CAP-004) |

## Honesty (mandatory)

1. **Never optimize for coverage metrics.** Dual count, dual %, inventory `full`/`reviewed`, and artifact totals are **byproducts**, not objectives.
2. A function is **complete** only when it satisfies **project verification requirements** (evidence-sealed CF/constants, dual when required, honest gaps; Runtime Confirmed only with approved Launcher). Scaffolds / placeholders / partial docs **must not** increase any completion metric.
3. **Terminal accounting** uses live `list_functions_enhanced` vs `inventory.jsonl` status ∈ {`full`,`reviewed`,`trivial-batch`,`deferred-low`} for **stamp inventory only**.
4. **`full_coverage: true` / `terminal_full_coverage: true`** means inventory stamp accounted (`none=0`). It is **not** dual depth, **not** runtime confirmed, and **not** reconstruction complete. Most `full` rows are industrial **Partial scaffold**.
5. Dual A/B **2726 ≪ 25671**. Inventory `reviewed` **2726** tracks dual presence after WQ-AUDIT-002 — **review depth**, not product-complete.
6. `get_function_count` **26263** / legacy **26256** are **not** the live enumeration used for sizing.
7. Runtime / bit-exact / differential remain open without Launcher approval.
8. **Audit:** `docs/reconstruction/audits/CURRENT_AUDIT.md` — rating **PARTIAL FAILURE**. Residual dual volume waves **frozen**.

## Artifact counts (refresh each major pass)

| Artifact class | Count | Notes |
|----------------|------:|-------|
| `functions/aa_*.md` | **~18812** | Function records (~81% Partial scaffold) |
| `raw/aa_*.md` | **~34487** | Immutable captures |
| `reconstructed-exact/*.cpp` | **~27663** | Clean sources (many industrial) |
| Dual A/B | **2726** | Deep dual-reviewed unique VA (filesystem) |
| Trivial-batch (Unwind@/Catch@) | **8508** | `coverage/trivial_batch_unwind.jsonl` |
| Import trivial ledger | **201** | `coverage/trivial_batch_imports.jsonl` |
| Thunk trivial ledger | **67** | `coverage/trivial_batch_thunks.jsonl` |

## Status codes

| Code | Meaning |
|------|---------|
| `none` | Not started |
| `raw` | Raw capture only |
| `partial` | Raw + some of annotated/clean/record |
| `full` | Three representations + function record (**often industrial scaffold — not dual-verified**) |
| `reviewed` | Full + dual reviews — bulk-synced to dual A∩B (WQ-AUDIT-002); still ≪ universe |
| `trivial-batch` | Accounted as accessor/thunk/compiler via batch template |
| `deferred-low` | Low-priority infrastructure parked after HL work |

## Machine-readable index

- `coverage/inventory.jsonl` â€” one line per function: `{addr,name,status,system,priority}`
- `coverage/progress.json` â€” aggregate counts

## Priority order (always in force)

1. Missions / skills / inventory / interaction / input managers
2. Movement, actions, health, progression, entity interaction, dialog, world transitions
3. User-visible state / persistence / comms as needed
4. Lifecycle last unless required
5. Physics / lighting / networking plumbing / allocators **last** (unless dependency)

## Full-coverage rule

Criterion 1 (terminal accounting) is met when **every** live `list_functions_enhanced` address is `full`/`reviewed`/`trivial-batch` with artifacts (or batch ledger entry), or `deferred-low` with explicit reason. Dual depth remains a separate continuous goal. Inventory stamp alone without live re-diff is insufficient.

