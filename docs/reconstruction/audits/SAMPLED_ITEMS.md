# Sampled Items — AUDIT-2026-08-05-01

Per-item records. Live Ghidra used where marked. Status claims are those on disk *before* audit downgrades.

Legend — Verification status after audit:

- `HOLD` — claims hold under evidence inspected
- `HOLD-GAPS` — core claims hold; documented gaps remain appropriate
- `REVERIFY` — defects or process issues require re-verification
- `SCAFFOLD-ONLY` — industrial scaffold; not behaviorally complete

---

## A. High-priority dual-reviewed units

### S-001 `aa_004f5620` VehicleEntity_SetSteerInput @ `0x004f5620`

| Field | Value |
|-------|-------|
| Claimed name / status | `VehicleEntity_SetSteerInput`; human-refined + dual residual sealed; matrix **partial** |
| Evidence | Live decompile; `analyze_function_complete`; `read_memory` 48 B; clean cpp; function record; dual A/B; callers list |
| Bytes | `8b 41 04 8b 50 04 8b 84 0a b0 00 00 00 85 c0 74 09 f6 80 b4 00 00 00 c7 75 0e f3 0f 10 44 24 04 f3 0f 11 81 18 06 00 00 c2 04 00` |
| Confirmed | Boundary ~0x2b; thiscall `ret 4`; gate chain `*(*(*(this+4)+4)+this+0xb0)`; mask imm **0xC7**; store **+0x618**; null allows write; no other stores; callees none; callers include DriveControlTick + MoveToTarget family |
| Incorrect | Ghidra stored signature still `undefined …(void)` / weak types — **docs ahead of DB** |
| Uncertain | Product identity of wobj; per-bit meanings of 0xC7; “lock” semantics (docs correctly avoid sealing) |
| Severity | None on CF; **Moderate** process (Ghidra lag F-006) |
| Revised confidence | **High** static CF/store; **Probable** gate object identity; Runtime **open** |
| Verification status | **HOLD-GAPS** |

### S-002 `aa_004f5650` VehicleEntity_SetLongitudinalInput @ `0x004f5650`

| Field | Value |
|-------|-------|
| Claimed | Sibling of SetSteerInput → `+0x614` |
| Evidence | Live decompile (batch) |
| Confirmed | Identical gate; store offset **0x614**; thiscall |
| Incorrect | — |
| Uncertain | Same as S-001 gate object |
| Severity | — |
| Revised confidence | **High** static |
| Status | **HOLD-GAPS** |

### S-003 `aa_004f3620` VehicleEntity_SetHandbrake @ `0x004f3620`

| Field | Value |
|-------|-------|
| Claimed | Ungated store `+0x61c` |
| Evidence | Live decompile |
| Confirmed | Single byte store; **no** 0xC7 gate; matches docs |
| Incorrect | — |
| Uncertain | Whether adjacent bits share byte |
| Severity | — |
| Status | **HOLD-GAPS** |

### S-004 `aa_009223b0` Client_Input_DriveControlTick @ `0x009223b0`

| Field | Value |
|-------|-------|
| Claimed | Partial; soft-steer High; dual present; large body |
| Evidence | Live decompile (partial body via batch — large); clean 33KB; dual A/B + soft/camera dual slices; system map |
| Confirmed | Calls SetLongitudinal/SetSteer/SetHandbrake; action-map DAT flags present; early returns; vehicle+0x101 gate; camera vs steer locals are separate concerns (docs claim) |
| Incorrect | Cannot claim full assembly CF verified end-to-end in this audit (size) |
| Uncertain | UF-006 labels; analog device branch; skill/airborne side paths; unaff vars in decomp |
| Severity | **Moderate** residual size risk |
| Revised confidence | **High** for digital axis path; **Probable** full body |
| Status | **HOLD-GAPS** (do not mark complete) |

### S-005 `aa_0052aa20` CVOGCharacter_HasCompletedMission @ `0x0052aa20`

| Field | Value |
|-------|-------|
| Claimed | Human-refined clean; dual A/B; dual-hash policy |
| Evidence | Live decompile; clean cpp; function record; dual reviews; **adversarial asm of mode CALL sites** |
| Confirmed | Null attach → only `+0x538`; attached Path A compound with `+0xfc` / mode / def; Path B `+0x53c` under mode; nesting preserved (no OR-simplification) |
| Incorrect | **Mode gate ECX = continent attach object** (`…+0xa8`), not character. Clean/docs that call `WeaponAllowsKillXpBonus()` without attach `this` are **ABI-wrong for ports** (F-027). Dual-hash CF still holds. |
| Uncertain | Product English for attach `+0xa8` / `+0xfc`; mode field writers on attach |
| Severity | **Major** (ABI / porting) |
| Revised confidence | **High** dual-hash CF; **Probable** overall until mode-this fixed in clean/docs |
| Status | **REVERIFY** (mode this + sibling sites) |

### S-006 `aa_00533f90` CVOGReaction_CompleteObjective @ `0x00533f90`

| Field | Value |
|-------|-------|
| Claimed | Human-refined + dual; priority 96; partial |
| Evidence | Live decompile (large); clean 31KB; dual A/B; function record |
| Confirmed | Active-obj hash walk; missing path can GiveMission; “Finishing mission %d”; advance vs final via sequence index; XP/credits final path; dirty `\|0x10`; SearchAutoMissions local-only branch; preserves VOG_DEBUG_STOP / hash error strings |
| Incorrect | Not fully assembly-walked this audit |
| Uncertain | Many FUN_* callees product names; reward packing; force flag semantics at all call sites |
| Severity | **Moderate** complexity residual |
| Status | **HOLD-GAPS** |

### S-007 `aa_00860e20` Client_SendInventoryGrab_FromGrid @ `0x00860e20`

| Field | Value |
|-------|-------|
| Claimed | Human-refined; dual residual; opcode 0x2034 size 0x20 |
| Evidence | Live decompile; `read_memory` prologue; clean cpp; duals |
| Confirmed | Opcode imm **0x2034** in bytes (`c7 44 24 04 34 20 00 00`); busy `DAT_00d1a8f6`; GetObject vtbl **0x3ac** (`ff 90 ac 03 00 00`); refresh call **`ff 52 04`** (vtbl+4); TFID fields +0x160/+0x164/+0x168; type from window+0x56c→+4; qty stack; send vtbl+0x18; return 1; **+0x04 unwritten** correctly documented |
| Incorrect | Clean **header comment** oversimplifies refresh as vtbl+0x3ac (body is correct) — F-021 |
| Uncertain | Product name of selection host class; busy clear site |
| Severity | **Minor** comment |
| Status | **HOLD-GAPS** |

### S-008 `aa_00813f40` Client_RecvInventoryEquip @ `0x00813f40`

| Field | Value |
|-------|-------|
| Claimed | Dual A/B strengthened; partial |
| Evidence | Matrix/system map/function record presence; not full live assembly pass this audit |
| Confirmed | Artifacts + duals exist; treated as high-value inventory path |
| Incorrect | — not disproven |
| Uncertain | Full demux class map without this-audit decompile |
| Severity | **Moderate** undersample |
| Status | **REVERIFY** (expand next audit pass) |

### S-009 `aa_00532b60` CVOGCharacter_SearchAutoMissions @ `0x00532b60`

| Field | Value |
|-------|-------|
| Claimed | Dual A/B; partial; matrix shows many **P** dimensions |
| Evidence | Live decompile requested in batch set; matrix honesty already low |
| Confirmed | Present as mission manager entry |
| Incorrect | Any implication of complete |
| Uncertain | unaff_ESI; auto-flag vs toast (matrix open issues) |
| Status | **HOLD-GAPS** / matrix already cautious |

### S-010 `aa_008ae7c0` / `aa_008ab8f0` mission dialog C2S path

| Field | Value |
|-------|-------|
| Claimed | 0x206E send sealed static; dual accept-with-gaps |
| Evidence | System map + matrix + experiment tests for flush artifacts |
| Confirmed | Artifact chain exists; tests soft-check duals |
| Uncertain | Runtime live send; Accepted polarity |
| Status | **HOLD-GAPS** (static only) |

---

## B. Industrial / random `full` units

### S-011 `aa_0048dde0` FUN_0048dde0 @ `0x0048dde0` (random full)

| Field | Value |
|-------|-------|
| Claimed status | inventory **full**; record **Partial scaffold** |
| Evidence | Live decompile; clean cpp; raw; annotated |
| Confirmed | Clean preserves ExceptionList/SEH frame, error paths, operator_delete noreturn paths, many branches; string “Error parsing Element” |
| Incorrect | Treating as reconstructed product behavior / named XML API |
| Uncertain | Full semantic role (XML element parse — plausible from strings); types; callers not in record |
| Severity | **Major** if counted as complete reconstruction (F-001) |
| Revised confidence | **High** that scaffold tracks decomp; **Low** product semantics |
| Status | **SCAFFOLD-ONLY** |

### S-012–S-023 Random full batch (seed 42 / 99)

Addresses include: `0x004166b0`, `0x00648c00`, `0x005ef780`, `0x005afa60`, `0x004db8b0`, `0x0047ad80`, `0x0045f9d0`, `0x00810a80`, `0x0041c500`, `0x007a7380`, `0x007669d0`, `0x005704b0`, …

| Aggregate | Result |
|-----------|--------|
| Artifact triad present | **Yes** (sampled) |
| Dual present | **Minority** (~16% of random full 25) |
| Record quality | Partial scaffold boilerplate |
| Clean quality | Pseudocode-style / FUN_* dominant |
| Status | **SCAFFOLD-ONLY** class |

### S-024 `aa_004db8b0` CVOGReaction_RemoveObject (random full + dual)

| Field | Value |
|-------|-------|
| Evidence | Dual A/B files exist (sizes ~3k/2k) |
| Status | Dual present; not deep CF audited this pass → **REVERIFY** if used as manager |

### S-025 `aa_00810a80` Client_RecvBroadcast (random full + dual)

| Field | Value |
|-------|-------|
| Evidence | Dual A/B ~1.8k each (short) |
| Note | Short duals may be thinner reviews |
| Status | **REVERIFY** |

---

## C. Recent residual dual samples

### S-026 `aa_004e3e70` StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|-------|-------|
| Claimed | accept-with-gaps; R12 residual; skills-abilities system tag on STL helper |
| Evidence | Dual A/B read; A documents bytes/epilogue ret 8; B adversarially falsifies decomp-only conclusions |
| Confirmed | Dual format works; B found real decomp hazards (noreturn delete, size--, outIt) |
| Incorrect | System tag “skills-abilities” for generic STL — organizational inflation |
| Uncertain | Product map type parameters |
| Severity | **Moderate** priority/system tagging (F-004) |
| Status | **HOLD-GAPS** as STL helper dual; **not** user-facing progress |

### S-027 R13 partition VAs (40)

| Field | Value |
|-------|-------|
| Evidence | Partition map + dual presence check mid-audit **23/40** complete A∩B |
| Confirmed | Wave truly in progress; almost all `FUN_*` |
| Incorrect | Counting unfinished R13 as sealed dual depth in progress.json |
| Status | **REVERIFY** / process **F-010** |

---

## D. Types / layouts

### S-028 VehicleEntity drive input region (`OBJECT_LAYOUTS.md`)

| Field | Value |
|-------|-------|
| Confirmed | +0x614/+0x618/+0x61c match live stores; gate chain matches setters; unresolved bits explicit |
| Incorrect | Full VehicleEntity size not claimed (good) |
| Status | **HOLD-GAPS** |

### S-029 InventoryGrid partial layout

| Field | Value |
|-------|-------|
| Confirmed | Offsets documented with evidence pointers; empty cell 0xFFFFFFFF pattern claimed |
| Uncertain | Full English field names; invType enum completeness |
| Status | **HOLD-GAPS** (not cross-checked every offset this audit) |

### S-030 TYPE_REGISTRY.md

| Field | Value |
|-------|-------|
| Confirmed | Narrow, honest partial |
| Incorrect | Insufficient as program-wide type foundation |
| Status | **HOLD** as scoped note; **gap** vs project-scale need |

---

## E. Trivial batch

### S-031 Trivial-batch sample (20)

| Field | Value |
|-------|-------|
| Names | Unwind@*, Catch@* |
| Confirmed | Appropriate compiler SEH accounting |
| Status | **HOLD** as trivial-batch legitimacy |

---

## F. Claimed verification / experiments

### S-032 Runtime experiments log

| Field | Value |
|-------|-------|
| Claimed | none run |
| Confirmed | File matches; no fabricated runtime |
| Status | **HOLD** (honesty good); coverage **0%** |

### S-033 Experiment unit tests

| Field | Value |
|-------|-------|
| Result | 111 tests, **2 failures** (dual count; undefined4 policy on one inferred unit) |
| Gate model tests for SetSteerInput | **PASS** (model agrees with static reconstruction) |
| Note | Passing model tests ≠ runtime Confirmed |
| Status | **REVERIFY** harness honesty |

---

## Sampling expansion rule (applied)

Defects clustered by:

1. **Industrial scaffold method** → expanded random full quality probe (500 head scan → 81.4% scaffold).
2. **Residual dual wave method** → expanded recent dual name taxonomy (80).
3. **Metric seal method** → dual count race + test failure.

No expansion needed for trivial-batch (legitimate). HP dualed core held under adversarial byte checks — defects there are process/type lag, not CF falsification.

---

## Summary table

| ID | VA | Name | Claimed | Audit status | Severity |
|----|-----|------|---------|--------------|----------|
| S-001 | 004f5620 | SetSteerInput | dual partial | HOLD-GAPS | — / Ghidra lag |
| S-002 | 004f5650 | SetLongitudinalInput | dual partial | HOLD-GAPS | — |
| S-003 | 004f3620 | SetHandbrake | dual partial | HOLD-GAPS | — |
| S-004 | 009223b0 | DriveControlTick | dual partial | HOLD-GAPS | Moderate residual |
| S-005 | 0052aa20 | HasCompletedMission | dual partial | HOLD-GAPS | — |
| S-006 | 00533f90 | CompleteObjective | dual partial | HOLD-GAPS | Moderate residual |
| S-007 | 00860e20 | InventoryGrab FromGrid | dual partial | HOLD-GAPS | Minor comment |
| S-008 | 00813f40 | RecvInventoryEquip | dual partial | REVERIFY | Moderate |
| S-011 | 0048dde0 | FUN_0048dde0 | full | SCAFFOLD-ONLY | Major (metrics) |
| S-026 | 004e3e70 | StdTree erase | dual accept-gaps | HOLD-GAPS (STL) | Moderate priority |
| S-031 | many | Unwind/Catch | trivial-batch | HOLD | — |
