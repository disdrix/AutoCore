# Dual A/B report — MEGA-004 OWN-ONLY (`0x005787a0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-004**  
**Scope:** VA `0x005787a0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `get_assembly_context` + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Mega residual dual partition — skills-abilities residual of dualed **CVOGHBSkill_SharedOnHeartBeat_Inferred** (`0x0061b6f0`).  
**Hint name:** Skill_HB_RescheduleStatus.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005787a0` Skill_HB_RescheduleStatus_Inferred | **accept-with-gaps** — CF/ABI/RET4/RTTI/offsets/callers sealed; product field English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): pure-wrapper / fastcall-EDX / Character-cast / always-AfterFire / heat-merge claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005787a0` — sealed facts

1. **Body:** `0x005787a0`–`0x0057882d` inclusive (**142 B** / `0x8E`).
2. **ABI:** MSVC **`__thiscall`**. **ECX** = skill HB this; stack `uint32_t *pOutStatus`; **EAX** = `pOutStatus`; **`RET 4`** ×2 exits. Decompiler `__fastcall` + phantom EDX **rejected**.
3. **Semantics (structural):**
   - If `short@this+0x2e == 0` → `CVOGHBBase_RescheduleAfterFire` only.
   - Else resolve TFID `@+0x658/+0x65c/+0x660` via `[*(this+0x688)+0xe4e8]` → `CVOGReaction_ResolveObjectTarget` → `__RTDynamicCast` to **CVOGCreature**.
   - If null or `creature.short@+0x12c < required`: `this.vtbl+0x40()`; `*pOut = DAT_00af31e8` (**0x10**); return (**no** AfterFire).
   - Else `creature.vtbl+0xb0(required)` then AfterFire.
4. **Constants:** `DAT_00af31e8` = **0x10**; parent compares against `DAT_00af4bd0` = **0x10** to skip effect cascade.
5. **RTTI:** `.?AVCVOGCreature@@` @ `0x00af8d0c`; `.?AVCVOGClonedObjectBase@@` @ `0x00af8e10`.
6. **Callees:** ResolveObjectTarget `0x004bae70`; RTDynamicCast `0x004898a4`; creature `vtbl+0xb0`; this `vtbl+0x40`; RescheduleAfterFire `0x00508350`.
7. **Callers (named, 5):** SharedOnHB `0061b6f0` @ `0061b6fd`; thin OnHB `0061c940`, `0061d400`, `00621980`, `00622a70`. Extra CALL xrefs: `0061f90a`, `00624d2c`, `00626b6d/88/a7`. Many DATA vtbl installs.
8. **Name:** `Skill_HB_RescheduleStatus_Inferred` (Ghidra `FUN_005787a0`). Product map open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory`.

### Gaps

- Product English for `this+0x2e`, creature `+0x12c`, `vtbl+0xb0`, `vtbl+0x40`.  
- Full RTTI census of DATA vtbl hosts.  
- Alias intent among 0x10 globals (`af31e8` / `af4bd0` / default period).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005787a0_Skill_HB_RescheduleStatus_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005787a0_Skill_HB_RescheduleStatus_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005787a0_FUN_005787a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005787a0_FUN_005787a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_HB_RescheduleStatus_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005787a0.cpp` |
| Function | `docs/reconstruction/functions/aa_005787a0_FUN_005787a0.md` |
| Function named | `docs/reconstruction/functions/aa_005787a0_Skill_HB_RescheduleStatus_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0061b6f0  CVOGHBSkill_SharedOnHeartBeat_Inferred  [dualed WQ9D-C]
  ├─ FUN_005787a0  Skill_HB_RescheduleStatus_Inferred  [OWN MEGA-004]
  │     ├─ CVOGReaction_ResolveObjectTarget
  │     ├─ __RTDynamicCast → CVOGCreature
  │     ├─ creature.vtbl+0xb0(required)     [or this.vtbl+0x40 fail]
  │     └─ CVOGHBBase_RescheduleAfterFire   [success / zero-required only]
  ├─ pulse counter this[+0x6c8]++
  ├─ gate status != 0x10 → effect cascade:
  │     FUN_00589bc0 heat   [MEGA-005 residual]
  │     FUN_00589c70 HP     [MEGA-006 residual]
  │     FUN_00589d90 shield [MEGA-007 residual]
  │     FUN_0058cc40 …      [MEGA-008 residual]
  │     FUN_0058d8e0 …      [MEGA-009 residual]
  │     FUN_0058c3b0 impulse
  └─ *pOutStatus = status

Thin OnHB callers (0061c940 / 0061d400 / 00621980 / 00622a70 / …)
  └─ FUN_005787a0 as body or tail  [OWN MEGA-004]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005787a0-mega-004-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005787a0` | Port as **skill HB reschedule + optional creature status gate**. **thiscall RET 4**. Fail: stop via `vtbl+0x40`, write **0x10**, **no** AfterFire. Success/zero-required: AfterFire. Keep distinct from heat/HP/shield leaves and fire-tail FX. |
| Pair with | dualed SharedOnHB `0061b6f0`; dualed RescheduleAfterFire `00508350`; residual apply leaves MEGA-005..009. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x005787a0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + call-site context + RTTI strings. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended**.  
- Clean sources use meaningful name; machine ABI corrections (thiscall RET 4; absolute offsets).  
- Odd behavior preserved: fail skips AfterFire; zero required short skips creature path; decompiler fastcall/EDX phantom corrected.  
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
