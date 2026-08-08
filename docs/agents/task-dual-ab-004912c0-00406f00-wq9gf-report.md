# Dual A/B report — WQ9G-F OWN-ONLY (`0x004912c0`, `0x00406f00`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9G-F**  
**Scope:** VAs `0x004912c0`, `0x00406f00` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth4_partition_map.md` → **WQ9G-F**.  
**Work item:** WQ-009 depth-4 residual dual seal (sky blend consumer of dualed WorldClock leaves + tree-neighborhood residual leaf near insert `00406c40`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004912c0` Env_DayCycle_ApplySkyBlendAndLight_Inferred | **accept-with-gaps** — ECX/env, ret4, dualed clock getters, mode remap 1/3·2/3, sky material dirty path sealed; product English open |
| `aa_00406f00` SkillSet_Vector_UninitializedFillN_0x18_Inferred | **accept-with-gaps** — EDI/ESI/stack ABI, ret4, stride 0x18 Ufill, sole insert caller sealed; product demangle open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): clock-leaf / skill-combat / tree-insert / chain-of-caller scaffold mix-ups **rejected**.

---

## VA `0x004912c0` — sealed facts

1. **Body:** `0x004912c0`–`0x0049146a` exclusive (**426 B** / `0x1AA`).
2. **ABI:** **`__thiscall`**; ECX = env host; one stack dword (caller dt — **unread**); **`ret 4`** (`C2 04 00`).
3. **Semantics — env day-cycle sky + light:**
   - Clock via `env+0xb8` → `+0x78`. If null **or** `env+0x180==0` → sky blend = **`g_flOne`** (1.0).
   - Else: dualed **`WorldClock_GetSkyBlendAmount_Inferred`** (`0x00553cd0`) → blend; dualed **`WorldClock_GetQuarterPhase01_Inferred`** (`0x00553dd0`) → quarter.
   - **Mode** dword at **`clock+0x154`** (0..3) remaps quarter → day phase with **`DAT_00aaa6c0` ≈ 1/3** and **`DAT_00aaa684` ≈ 2/3**.
   - Light helpers `FUN_0079a110` / `FUN_0074e690` / `FUN_0074e910` (undualed).
   - Optional secondary float sink @ `env+0x188` when `env+0x87` set.
   - Dirty `env+0x90` + bank `env+0x94`: **`FUN_00490af0(blend,1,cloud,sky)`** (`SkyBox*` / `fBlendAmount`); if blend ≥ 1 → **`FUN_00490820`** + clear dirty.
4. **Caller (1):** `FUN_00942e20` @ `0x00942e75`.
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Name:** `Env_DayCycle_ApplySkyBlendAndLight_Inferred` (Ghidra `FUN_004912c0`). Product English open → `_Inferred`.
7. **Decompile ≡ raw CF**; `ret 4` + float constants sealed via `read_memory`.

### Gaps

- Product / PDB env host + clock mode field English.  
- Writers of clock `+0x15c` / `+0x154`.  
- Light helpers + secondary object undualed.  
- Dead stack dt product intent.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004912c0_Env_DayCycle_ApplySkyBlendAndLight_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004912c0_Env_DayCycle_ApplySkyBlendAndLight_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004912c0_FUN_004912c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004912c0_FUN_004912c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Env_DayCycle_ApplySkyBlendAndLight_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004912c0.cpp` |
| Function | `docs/reconstruction/functions/aa_004912c0_FUN_004912c0.md` |
| Function named | `docs/reconstruction/functions/aa_004912c0_Env_DayCycle_ApplySkyBlendAndLight_Inferred.md` |

---

## VA `0x00406f00` — sealed facts

1. **Body:** `0x00406f00`–`0x00406f1c` exclusive (**28 B** / `0x1C`); pad `CC`.
2. **ABI:** **EDI** = dest; **ESI** = count; **ECX** = vector/SkillSet*; stack **`const T* value`**; **`ret 4`**; EAX = **`dest + count*0x18`**.
3. **Semantics:** MSVC-style **vector uninitialized_fill_n** for **element size 0x18**:
   - Calls `FUN_00412aa0` (loop: `FUN_00412b10` copies **6 dwords**, advances **+0x18**).
   - Returns end pointer via `lea` (`esi*3*8`).
4. **Not a tree helper** — VA-neighborhood residual next to dualed insert `0x00406c40` only.
5. **Caller (1 fn, 2 sites):** `FUN_00412730` SkillSet vector insert/reallocate @ `0x0041287e` (grow) and `0x00412978` (in-place). Same family as dualed `SkillSet_GetEntryCount` (`0x00402d80`).
6. **Xrefs:** 2 UNCONDITIONAL_CALL.
7. **Name:** `SkillSet_Vector_UninitializedFillN_0x18_Inferred` (Ghidra `FUN_00406f00`). Reject scaffold `Named_CalleeOf_Skill_Uses_*`.
8. **Decompile ≡ raw CF** with register-arg trap closed via call-site disasm + bytes.

### Gaps

- Product / MSVC demangle (`_Ufill` / exact helper).  
- Full `NPCSkillSetEntry` field English.  
- Parent insert `FUN_00412730` undualed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00406f00_SkillSet_Vector_UninitializedFillN_0x18_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00406f00_SkillSet_Vector_UninitializedFillN_0x18_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00406f00_FUN_00406f00.md` |
| Annotated | `docs/reconstruction/raw/aa_00406f00_FUN_00406f00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillSet_Vector_UninitializedFillN_0x18_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00406f00.cpp` |
| Function | `docs/reconstruction/functions/aa_00406f00_FUN_00406f00.md` |
| Function named | `docs/reconstruction/functions/aa_00406f00_SkillSet_Vector_UninitializedFillN_0x18_Inferred.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004912c0-00406f00-wq9gf-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004912c0` | Port as **env day-cycle tick**: sky blend = clock`+0x15c` (or 1.0 if absent); quarter phase remapped by mode`+0x154` with **1/3** and **2/3**; apply `fBlendAmount` to SkyBox materials when dirty; texture commit when blend ≥ 1. Not combat. Pair dualed getters `00553cd0` / `00553dd0`. Preserve unread stack dt if matching retail call shape. |
| `00406f00` | Port as **SkillSet vector Ufill** stride **0x18**: construct n copies; return end. **EDI/ESI** register ABI + **ret 4**. Not tree insert (`00406c40`). Pair insert parent `00412730` / size `SkillSet_GetEntryCount`. |
| Pair with | dualed clock leaves; SkillSet size; insert parent when dualed |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` and/or environment system notes  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x004912c0`, `0x00406f00`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended/rewritten with integrity note**; clean sources use meaningful names.  
- Odd behavior preserved: unread stack dt on env tick; decompiler unaff_ESI/EDI on Ufill (register args); float bit-pattern `1` as cloud flag.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
