# Corrective Action Plan — AUDIT-2026-08-05-01

**Trigger rating:** PARTIAL FAILURE  
**Rule:** Do not resume large-scale decompilation / residual dual volume waves until P0 items are contained.  
**Preserve evidence:** Do not delete scaffolds, duals, or prior reviews; reclassify and re-verify.

---

## P0 — Contain immediately (this session / next session)

### CAP-001 — Progress vocabulary honesty

| Field | Value |
|-------|-------|
| Addresses | F-001, SR-01 |
| Actions | 1) Add explicit banner to PROJECT_STATE / COVERAGE_LEDGER / progress.json: `full` = three-rep scaffold accounting, **not** dual-verified reconstruction. 2) Rename display language: `terminal_accounting` vs `dual_depth` vs `runtime_confirmed`. 3) Never say “program reconstructed.” |
| Done when | No status file implies dual/runtime complete from inventory stamp alone |
| Owner | Parent / process |

### CAP-002 — Inventory status reconciliation for duals

| Field | Value |
|-------|-------|
| Addresses | F-002 |
| Actions | Script: for each dual A∩B VA, if inventory status is `full`, set `reviewed` **or** add field `dual=true` without claiming semantic complete. Backfill system tags for dualed HP set. |
| Done when | `reviewed` or `dual` flag count ≈ dual A∩B unique; test asserts invariant |
| Owner | Process tooling |

### CAP-003 — Dual count single source of truth

| Field | Value |
|-------|-------|
| Addresses | F-003, F-010, F-020, SR-03 |
| Actions | 1) Recompute dual A∩B from filesystem. 2) Update progress.json only in parent merge. 3) Keep test_progress_dual_matches_filesystem green. 4) ACTIVE_WORK must show in-flight duals as provisional. |
| Done when | unittest dual match passes; RESUME matches disk ±0 |
| Owner | Parent merge only |

### CAP-004 — Freeze residual STL dual waves; restore priority model

| Field | Value |
|-------|-------|
| Addresses | F-004, SR-02 |
| Actions | 1) **Halt** R13-style residual dual expansion on undualed `FUN_*` STL leaves unless a WQ manager explicitly depends. 2) Next dual capacity → unfinished user-facing gaps on WQ-001..009 (runtime prep, DriveControlTick residual, inventory wire, mission dialog live). 3) STL duals remain valid artifacts but do not count as “HP system progress.” |
| Done when | Next wave partition ≥70% user-facing VAs by name/system map |
| Owner | Wave planner |

### CAP-005 — Runtime verification policy (no fabrication)

| Field | Value |
|-------|-------|
| Addresses | F-005, SR-05 |
| Actions | 1) Keep Runtime=N until Launcher approved. 2) When approved, run RT-STEER-001/002 and one mission dialog C2S capture first. 3) Log in RUNTIME_EXPERIMENTS.md. 4) Forbid Confirmed without traces. |
| Done when | Policy written + first live experiment when user approves |
| Owner | Parent + user approval |

### CAP-008 — Language: sealed / Confirmed discipline

| Field | Value |
|-------|-------|
| Addresses | F-008, F-019, SR-05 |
| Actions | Replace “sealed” with `static-dual-accepted` / `static-byte-sealed` / `runtime-confirmed`. Downgrade any Confirmed lacking bytes or runtime. |
| Done when | Grep policy doc + sample matrix rows compliant |
| Owner | Docs |

---

## P1 — Repair quality systems

### CAP-006 — Ghidra type commit for dual-accepted HP units

| Field | Value |
|-------|-------|
| Addresses | F-006, SR-06 |
| Actions | For WQ priority ≥88 dual-accepted units: apply thiscall, param types, return types, key field structs in Ghidra; re-decompile smoke. Start with SetSteer/Longitudinal/Handbrake, HasCompletedMission, InventoryGrab. |
| Done when | analyze_function_complete signature matches docs for pilot set |
| Owner | RE parent |

### CAP-007 — Fix verification matrix structural damage

| Field | Value |
|-------|-------|
| Addresses | F-007 |
| Actions | Repair truncated rows `aa_006070e0`, `aa_005711c0`, and other short rows; move confidence-by-dimension blocks out of main table; add validator script. |
| Done when | All `\| aa_` rows have full column count |
| Owner | Docs |

### CAP-009 — Scaffold vs human-refined labeling in function records

| Field | Value |
|-------|-------|
| Addresses | F-009, F-018, SR-07 |
| Actions | Keep scaffolds; ensure inventory/query distinguishes `scaffold-full` vs `human-refined`. Optional: status code `scaffold` in inventory.jsonl. |
| Done when | Machine-readable distinction exists |
| Owner | Tooling |

### CAP-010 — Wave lifecycle protocol

| Field | Value |
|-------|-------|
| Addresses | F-010, F-020 |
| Actions | Partition → OWN land duals → parent recount dual → update progress → seal CHANGE_LOG. No seal before recount. |
| Done when | Written into RESUME / agent instructions |
| Owner | Process |

### CAP-011 — Refresh experiment preflight expectations

| Field | Value |
|-------|-------|
| Addresses | F-011, F-017 |
| Actions | Delete or rewrite stale unittest_discover_output.txt; fix undefined4 clean policy for `aa_00922270`; keep dual match test. |
| Done when | `unittest discover` green |
| Owner | Experiments |

### CAP-016 — True dual independence for pri≥90

| Field | Value |
|-------|-------|
| Addresses | F-016, SR-04 |
| Actions | A and B must be different agent IDs; optional third ADV only on conflicts. |
| Done when | Wave maps show distinct A/B owners for HP |
| Owner | Wave planner |

---

## P2 — Hygiene

### CAP-012 — Encoding normalize durable markdown

| Field | Value |
|-------|-------|
| Addresses | F-012 |
| Actions | UTF-8 rewrite of WORK_QUEUE, COVERAGE_LEDGER, system maps mojibake |
| Owner | Docs |

### CAP-013 — Naming registry backfill for dual-accepted non-Inferred names

| Field | Value |
|-------|-------|
| Addresses | F-013, F-024 |
| Owner | Docs |

### CAP-014 — Expand TYPE_REGISTRY only from multi-xref layouts

| Field | Value |
|-------|-------|
| Addresses | F-014 |
| Actions | No new types from single function; require ≥2 call-sites or RTTI |
| Owner | RE |

### CAP-015 — Backfill inventory `system` field for dualed + WQ units

| Field | Value |
|-------|-------|
| Addresses | F-015 |
| Owner | Tooling |

### CAP-017 — Fix `Input_TryFirePrimaryWeapons_Inferred` clean policy failure

| Field | Value |
|-------|-------|
| Addresses | F-017 |
| Owner | Experiments / clean owner |

### CAP-018 — InventoryGrab comment fix (vtbl refresh)

| Field | Value |
|-------|-------|
| Addresses | F-021 |
| Actions | Header step list: GetObject +0x3ac; refresh host vtbl+4 |
| Owner | Docs (safe isolated fix) |
| Status | **Done** this audit session |

### CAP-019 — Fix mode-gate `this` = attach object (HasCompletedMission + siblings)

| Field | Value |
|-------|-------|
| Addresses | F-027 |
| Actions | 1) Rewrite clean/docs so `WeaponAllowsKillXpBonus(attach)` with attach from `+0xa8` chain. 2) Audit GiveMission / AddExperience plates for same elision. 3) Confirm aa_004ce340 fields on attach object. 4) Mark dual residuals re-verify if they sealed character-mode story. |
| Owner | RE parent |
| Status | **Queued / in progress** |

---

## Execution order (mandatory)

```
CAP-001 (vocabulary) 
  → CAP-003 (recount duals / progress honesty)
  → CAP-002 (inventory dual flags)
  → CAP-004 (freeze bad waves)
  → CAP-008 (language)
  → CAP-007 / CAP-011 (matrix + tests)
  → CAP-018 (tiny safe fix)
  → CAP-006 (Ghidra types for pilot HP)
  → CAP-005 when user approves Launcher
```

**Suspended until P0 done:** new residual dual waves, industrial full re-batches, mass renames.

**Allowed during containment:** audit docs, metric repair, matrix repair, isolated comment/type fixes, re-verification of REVERIFY items, runtime only with approval.

---

## Success criteria to exit PARTIAL FAILURE

| Criterion | Bar |
|-----------|-----|
| Metrics | progress dual == filesystem; tests green |
| Vocabulary | full ≠ verified in all top-level status docs |
| Priority | Active work is user-facing vertical or metric repair, not STL dual volume |
| HP pilot | ≥5 pri≥88 units byte-sealed + Ghidra types applied |
| Runtime | Policy clear; 0 fabricated Confirmed |
| Dual independence | New HP duals use separate A/B owners |

Exit rating target after remediation: **PASS WITH CORRECTIVE ACTIONS** (not automatic PASS).

---

## This session execution

| CAP | Status |
|-----|--------|
| CAP-001 | **In progress** — audit docs + state file banners |
| CAP-003 | **In progress** — recount + progress note |
| CAP-004 | **Applied** — queue freeze residual dual volume |
| CAP-018 | **Queued** — isolated comment fix eligible |
| CAP-002+ | Queued on WORK_QUEUE |

Large-scale decompilation: **not resumed**.
