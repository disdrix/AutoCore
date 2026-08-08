# Dual A/B report — MEGA-009 OWN-ONLY (`0x0058d8e0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-009**  
**Scope:** VA `0x0058d8e0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + `get_function_by_address` + `get_function_signature`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Mega residual dual partition — skills-abilities nested under dualed parent pulse `0x0061b6f0`.  
**Hint:** `Skill_HB_ApplyMultiArgEffect`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0058d8e0` Skill_HB_ApplyMultiArgEffect_Inferred | **accept-with-gaps** — CF/ABI/cdecl6/list-build/+0x160/terminator/sole-callee/4 xrefs sealed; product English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): multi-hit-merge / heat-HP-shield-merge / thiscall-ret4 / gather / multi-entry-builder / void-no-return / unconditional-tick claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0058d8e0` — sealed facts

1. **Body:** `0x0058d8e0`–`0x0058d95d` inclusive (**126 B** / `0x7E`); pad `CC CC` at `0x0058d95e`; next `0x0058d960`.
2. **ABI:** **__cdecl** six stack formals; bare **`ret`** both exits; callers **`ADD ESP,0x18`**. **EAX** = damage sum (multi-hit pass-through) or 0 on null early-out.
3. **Semantics:** thin multi-arg effect wrapper:
   - Null-check `param_2`; early bare ret if zero.
   - Build 32 B TFID list on stack: copy **16 B** from `param_2+0x160..+0x16f` + terminator from **`DAT_009d4d28..34`** (`ffffffff ffffffff 00000000 00000000`).
   - Call **`Skill_ApplyMultiTargetHits_Inferred`** (`FUN_0058c850`) with `(param_1, &list, param_3, param_4, param_5, param_6)`.
4. **Callees:** **1** — `FUN_0058c850` only (dualed W20-Q).
5. **Callers / xrefs (4 UNCONDITIONAL_CALL):**
   - `FUN_0061b6f0` `CVOGHBSkill_SharedOnHeartBeat_Inferred` @ `0x0061b8f9` (gate `TEST [ESI+0x648],1`)
   - `FUN_00618270` @ `0x0061866e` (same 6-arg pack)
   - orphan @ `0x0061e922`, `0x0061ea7b` (no Ghidra function; use EAX damage)
6. **Parent pack @ `0x0061b8f9`:**  
   `p1=FUN_00578270(skill)`, `p2=skill[+0x18]`, `p3=&skill[+0x24]`, `p4=skill[+0x688]`, `p5=skill[+0x6a0]`, `p6=skill[+0x6c8]`.
7. **Name:** `Skill_HB_ApplyMultiArgEffect_Inferred` (Ghidra `FUN_0058d8e0`). Product map open → `_Inferred`. No `Named_CalleeOf_*` scaffold to retire.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context. Decompiler `void` corrected to **int** return.

### Gaps

- Product/PDB symbol.  
- Exact product English for combat-source vs hittee object roles.  
- Sibling pulse `FUN_00618270` / orphan region dual residual (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0058d8e0_Skill_HB_ApplyMultiArgEffect_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0058d8e0_Skill_HB_ApplyMultiArgEffect_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0058d8e0_FUN_0058d8e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0058d8e0_FUN_0058d8e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_HB_ApplyMultiArgEffect_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0058d8e0.cpp` |
| Function | `docs/reconstruction/functions/aa_0058d8e0_FUN_0058d8e0.md` |
| Function named | `docs/reconstruction/functions/aa_0058d8e0_Skill_HB_ApplyMultiArgEffect_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0061b6f0  CVOGHBSkill_SharedOnHeartBeat_Inferred  [parent dualed WQ9D-C]
  ├─ FUN_005787a0  Skill_HB_RescheduleStatus          [MEGA-004]
  ├─ FUN_0061b960  Skill_HB_CopyTfid16At668_Inferred  [MEGA-016]
  ├─ FUN_00589bc0  Skill_HB_ApplyHeatDelta            [MEGA-005]
  ├─ FUN_00589c70  Skill_HB_ApplyHpDelta              [MEGA-006]
  ├─ FUN_00589d90  Skill_HB_ApplyShieldPool           [MEGA-007]
  ├─ FUN_0058cc40  Skill_HB_ApplyShortAndFloater      [MEGA-008]
  └─ FUN_0058d8e0  Skill_HB_ApplyMultiArgEffect_Inferred  [OWN MEGA-009]
        └─ FUN_0058c850  Skill_ApplyMultiTargetHits_Inferred  [dualed W20-Q]
              ├─ Skill_AccuracyHitCheck_Inferred (skip first target)
              ├─ Client_Combat_ApplySingleHitMaybeDefer_Inferred
              └─ Client_EnqueueCombatFloater_INFERRED (miss)

FUN_00618270  sibling pulse  [residual]
  └─ FUN_0058d8e0 @ 0x0061866e

Orphan region ~0x0061e9xx  [residual; no Ghidra function]
  └─ FUN_0058d8e0 @ 0x0061e922 / 0x0061ea7b
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0058d8e0-mega-009-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0058d8e0` | Port as **cdecl** single-target TFID-list wrapper over multi-hit apply. **Not** thiscall. Build list = object TFID @ **`+0x160`** + null terminator globals. Return **damage sum**. Keep distinct from heat/HP/shield/short-floater Apply* leaves and from multi-hit core `0058c850`. |
| Pair with | parent pulse `0061b6f0`; dualed multi-hit `0058c850`; sibling Apply* leaves under same parent (other MEGA owners). |
| Gate | Parent bit0 of skill-HB **`+0x648`** — do not call unconditionally every tick. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0058d8e0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful name; machine twin retained; ABI corrections (cdecl bare ret; int damage return).  
- Odd behavior preserved: decompiler `void` vs EAX damage; parent decompiler collapses 6-arg pack into fake 1-arg form (assembly wins).  
- `_Inferred` where product English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
