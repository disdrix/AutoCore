# Dual A/B report — R12-004 OWN-ONLY (`0x0061c940`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-004**  
**Scope:** VA `0x0061c940` only. Dual A/B + raw append + annotated + clean named + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs; parent ledger ownership of `0x0061c590` / `0x00650f50` / `0x005787a0`.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + callers/xrefs + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → R12-004  
**System:** skills-abilities  
**Parent (context only):** `0x0061c590` `CVOGHBSkill_XP_ApplyToTargetList_Inferred`  
**Dual start:** 2646  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0061c940` CVOGHBSkill_XP_OnHeartBeat_Inferred | **accept** — RTTI class Confirmed; thin OnHB personal/multi CF/ABI/vtbl/XPAdder/Enqueue/RescheduleStatus sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): ApplyToTargetList-merge / XP-self-ctor / 0x6c0-size / SharedOnHB-cascade / multi-CALL / free-fn-XPAdder / Runtime-Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).  
**Terminal:** false.

---

## VA `0x0061c940` — sealed facts

1. **Body:** `0x0061c940`–`0x0061caf0` inclusive (**433 B** / `0x1B1`); SEH `LAB_009a87bb`.
2. **ABI:** MSVC **`__thiscall`** — **ECX = `CVOGHBSkill_XP` this**; one stack dword (`pOutStatus`); **`ret 0x04`**; **EAX = param_2**.
3. **Class:** **`CVOGHBSkill_XP`** — RTTI **Confirmed** `.?AVCVOGHBSkill_XP@@` via COL `0x00aade00` → type_info `0x00af29ec` on vtbl **`PTR_FUN_009d119c`**.
4. **Vtbl placement:** this VA at **vtbl+0x0C** (`0x009d11a8`) — sole inbound xref (**DATA**). No UNCONDITIONAL_CALL callers.
5. **Source cast:** `__RTDynamicCast(*(this+0x18), CVOGClonedObjectBase → CVOGCharacter)`.
6. **Branch:** `*(character+0xcb0)` — **null** ⇒ personal arm; **non-null** ⇒ 4-slot multi arm (pointer is `FUN_00574760` this).
7. **Personal:** if `float(this+0x104) != g_flZero` (`DAT_00a0f518` = 0.0f) → `operator_new(0x6d0)` + **`CVOGHBSkill_XPAdder_ctor`** with target = source.
8. **Multi:** `for i in 0..3`: `FUN_00574760(slotTable, i)`; non-null → MI adjustor → XPAdder ctor with adjusted target.
9. **Accept path:** if `pOwner != null` → **`CVOGHBList_Enqueue(*(world+0xe4ec))`** + **`CVOGHBBase_Start`**; else **vtbl[0](1)** scalar delete.
10. **Tail:** **`Skill_HB_RescheduleStatus_Inferred`** (`0x005787a0`) then return `pOutStatus`.
11. **Name:** `CVOGHBSkill_XP_OnHeartBeat_Inferred` — class Confirmed, method role **Inferred**. Ghidra: `FUN_0061c940`.

### Gaps

- Product/PDB method name for vtbl+0x0C.  
- Product English for `character+0xcb0` and float `this+0x104`.  
- Full type of slot-table host / `FUN_00574760` beyond 4-pointer getter.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0061c940_CVOGHBSkill_XP_OnHeartBeat_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0061c940_CVOGHBSkill_XP_OnHeartBeat_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ R12-004 append) | `docs/reconstruction/raw/aa_0061c940_FUN_0061c940.md` |
| Annotated | `docs/reconstruction/raw/aa_0061c940_FUN_0061c940.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_XP_OnHeartBeat_Inferred.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_0061c940.cpp` |
| Function named | `docs/reconstruction/functions/aa_0061c940_CVOGHBSkill_XP_OnHeartBeat_Inferred.md` |
| Function scaffold | `docs/reconstruction/functions/aa_0061c940_FUN_0061c940.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0061c940_CVOGHBSkill_XP_OnHeartBeat_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0061c940_CVOGHBSkill_XP_OnHeartBeat_Inferred.md` |
| This report | `docs/agents/task-dual-ab-0061c940-r12-report.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGHBSkill_XP vtbl  PTR_FUN_009d119c
  +0x0C  FUN_0061c940 / CVOGHBSkill_XP_OnHeartBeat_Inferred  [OWN R12-004]
        ├─ __RTDynamicCast → CVOGCharacter
        ├─ personal: float +0x104 gate → new(0x6d0) XPAdder (target=self)
        ├─ multi: FUN_00574760 × slots 0..3 + MI adjust → XPAdder
        ├─ CVOGHBList_Enqueue(world+0xe4ec) + CVOGHBBase_Start  |  vtbl[0](1)
        └─ Skill_HB_RescheduleStatus_Inferred  0x005787a0  [dualed MEGA-004]

  +0x2C  FUN_0061c590 / CVOGHBSkill_XP_ApplyToTargetList_Inferred  [parent dual R11-015]
        └─ new(0x6c0) XP HB + base ctor + always-ready −1000  [not OWN]

Child (not OWN):
  FUN_00650f50  CVOGHBSkill_XPAdder_ctor  [dualed R11-025]
    ├─ CVOGHBSkillBase_ctor
    ├─ vtbl PTR_FUN_009e5304
    └─ float this+0x6c0 = 0

Sibling debug slots (not OWN):
  +0x38  FUN_0061c7c0   conversion_percent
  +0x3C  FUN_0061c830   op_scalar_1
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0061c940` | Port as **XP skill specialized OnHeartBeat**: personal residual float gate **or** 4-slot multi-target fan-out; spawn **0x6d0** `CVOGHBSkill_XPAdder` HBs; Enqueue on **world+0xe4ec**; tail RescheduleStatus. |
| Preserve | thiscall + `ret 4`; vtbl DATA dispatch; accept polarity via **pOwner**; slot bound **4**; XPAdder size **0x6d0** (not XP 0x6c0). |
| Do not | Merge with ApplyToTargetList `0061c590`; invent CALL parents; claim SharedOnHB effect cascade; claim runtime Confirmed. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent may later lockstep:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` + rename-history
- `systems/skills-abilities.md` residual tables
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0061c940`); no Launcher; no parent ledger edits; no `disassemble_bytes`; raw append-only.
- Dual start **2646**; partition R12-004; system skills-abilities.
