# Dual A/B report — R13-009 OWN-ONLY (`0x0086b9b0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-009**  
**Scope:** VA `0x0086b9b0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R13 residual dual seal — caller of dualed **UI_Widget_MoveToFrontInParentGroup_Inferred** (parent `0x00756c90`); Arena Tournament Schedule create-child-widgets virtual.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` row R13-009.  
**System:** inventory-transfer (UI chrome builder; no inventory wire).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0086b9b0` UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred | **accept-with-gaps** — ECX thiscall / body bounds / vtbl+0x43C / child-build pattern / tab policy / plate family sealed; product host name + residual ctor/tail helpers open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mini-label-only / inventory-wire / non-thiscall / direct-call-only / all-tabs-selected / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0086b9b0` — sealed facts

1. **Body:** `0x0086b9b0`–`0x0086cc81` inclusive (**4818 B** / `0x12D2`); epilogue SEH restore + plain **`RET`** (`C3`).
2. **ABI:** **`__thiscall` ECX** = host window*; **no** stack args; **`RET`**. Entry `MOV EBP,ECX`.
3. **Dispatch:** sole xref **DATA** `0x00a5ed20` — vtbl method slot **`+0x43C`** on class vtbl base `PTR_FUN_00a5e8e4` (installed by ctor `FUN_0086cd10` / plate `UI_arena_tournament_schedule`). **0** direct CALL callers.
4. **Semantics:** Create/attach/XML-load full Arena Tournament Schedule child tree:
   - Host init: `+0x4FC=0xF`, `+0x500=1`, `+0x528=0`, `+0xC5=0`; host vtbl `+0x110`/`+0x130`; `FUN_00792600`.
   - Pattern: `operator_new` → typed ctor → store host slot → attach vtbl `+0xA8` → LoadXml vtbl `+0x28` (+ optional id vtbl `+0x74` / extras).
   - Ctor sizes: `0x488→007b5dd0`, `0x4BC→00864f20` (FxPanel), `0x4CC→0079c860` (Button), `0x9A8→0078b6e0`, `0x954→0078f890`, `0x81C→008230b0` (tab).
   - **Tabs:** console `@+0x630` unselect+moveFront; tournament `@+0x634` select; advanced `@+0x638` unselect+moveFront (helpers `FUN_00822cb0` / `FUN_00756c90`).
   - Mini cluster `@+0x63C/+0x640/+0x644` + optional size normalize vs `DAT_00aaac10`.
   - Tail: host vtbl `+0x448`/`+0x34C`; `FUN_0086b370`; `FUN_0086a900(-1,-1)`; conditional `FUN_0086b3c0` if `DAT_00d1b6d8` and `[+0x4FC]!=0`.
5. **Does not** send inventory C2S packets.
6. **Name:** `UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred` (Ghidra `FUN_0086b9b0`). Supersedes plate alias `UI_arena_tournament_schedule_mini_label`. Product map open → `_Inferred`.
7. **Decompile ≡ raw CF**; XML args + tab ABI sealed via `disassemble_function` (decomp omits many early string pushes).

### Gaps

- Product / RTTI English name of host class.  
- Residual dual of most child ctors + `FUN_0086b370` / `FUN_0086a900` / `FUN_0086b3c0`.  
- Host/child vtbl ordinal product English.  
- Scale-threshold / global layout constants residual.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0086b9b0_UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0086b9b0_UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0086b9b0_FUN_0086b9b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0086b9b0_FUN_0086b9b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0086b9b0.cpp` |
| Function | `docs/reconstruction/functions/aa_0086b9b0_FUN_0086b9b0.md` |
| Function named | `docs/reconstruction/functions/aa_0086b9b0_UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Partition parent residual (R12 duals; not re-dualled):
  FUN_00756c90  UI_Widget_MoveToFrontInParentGroup_Inferred  [dualed R12-003]
  FUN_00822cb0  UI_TabChrome_SetSelected_Inferred            [dualed R12-002]

This unit (R13-009):
  FUN_0086b9b0  UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred  [OWN]
    ├─ operator_new + residual ctors (007b5dd0 / 0079c860 / 00864f20 / 0078b6e0 / 0078f890 / 008230b0)
    ├─ FUN_00822cb0 ×3  (tab select policy)
    ├─ FUN_00756c90 ×2  (console + advanced move-to-front)
    ├─ FUN_00792600 / FUN_0086b370 / FUN_0086a900 / FUN_0086b3c0
    └─ host/child vcalls (+0xA8 attach, +0x28 LoadXml, …)

Sibling ctor (evidence; not dualled):
  FUN_0086cd10  UI_arena_tournament_schedule  — installs PTR_FUN_00a5e8e4 incl. slot +0x43C → this VA
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0086b9b0-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0086b9b0` | Port as **Arena Tournament Schedule dialog create-child-widgets virtual** (`vtbl+0x43C`). **ECX=host**, no stack args, plain `RET`. |
| Do **not** | Treat as inventory C2S; rename to mini-label-only; invent direct CALL graph; claim Runtime Confirmed; dual other VAs here. |
| Pair with | dualed `UI_TabChrome_SetSelected_Inferred` `00822cb0`; dualed `UI_Widget_MoveToFrontInParentGroup_Inferred` `00756c90`; ctor `FUN_0086cd10`; residual tail helpers. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER.md` / progress / WORK_QUEUE as applicable

**Terminal:** false.
