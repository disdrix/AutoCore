# Function record: Skill_StartCastAgainHeartbeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519200` |
| **Canonical name** | `Skill_StartCastAgainHeartbeat` |
| **Address** | `0x00519200` |
| **Body range** | `0x00519200`–`0x00519279` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__thiscall` — **`RET 0x8`** (2 stack dwords) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined + dual A/B residual strengthen (2026-07-29)** — ABI/type-8/list/6-callers/null-path sealed; runtime open |
| **Bit-for-bit / runtime / diff** | Open |

---

## 1. Summary

`operator_new(0x28)` → `CVOGHBOKToCastAgain_ctor(owner, skill, chargeMs)` → enqueue on `*(owner+0xa4)+0xe4ec` → `CVOGHBBase_Start`. Optimistic cast-again / cooldown HB. Duration math is **ctor-only**. This unit does **not** dedup type-8 instances. Null alloc still Enqueue/Start with null.

---

## 2. Signature (bytes-sealed 2026-07-29)

```c
void __thiscall Skill_StartCastAgainHeartbeat(
    void* pOwnerEntity,    // ECX: character/owner; +0xa4 → world
    void* pSkillRuntime,   // stack0
    int   nChargeDelayMs); // stack1 (caller-dependent source)
// RET 0x8
```

Ghidra plate `(this, pOwnerCtx, pSkill, nChargeDelayMs)` with 3 stack formals is **falsified**.

Ctor (callee, `RET 0xC`):

```c
void* __thiscall CVOGHBOKToCastAgain_ctor(
    void* thisHb, void* pOwnerEntity, void* pSkillRuntime, int nChargeDelayMs);
// HB+0x1c = 8; duration at HB+0x8 from skill+0x10 × equip + charge
```

---

## 3. Callees / callers

| Role | Symbol | VA |
|---|---|---|
| Alloc | `operator_new` | `0x00489892` |
| Ctor | `CVOGHBOKToCastAgain_ctor` | `0x0051e240` |
| Enqueue | `CVOGHBList_Enqueue` | `0x005078f0` |
| Start | `CVOGHBBase_Start` | `0x005081c0` |

| Caller | Call site | Charge |
|---|---|---|
| `Client_RequestCastSkill` | `0x00941731` | skill+0x14 |
| `Client_QuickBarActivateSkillSlot` | `0x00921cfd` | skill+0x14 |
| `Client_StanceOrGadgetActivatePath` | `0x0093a525` | skill+0x14 |
| `Skill_ClearCastBindingAndMaybeRestartCd` | `0x0051a77c` | 0 |
| `Skill_ApplyStatusEffectLocal` | `0x0051ac53` | packet+0x10 |
| `Skill_LocalRangeTargetCheck` | `0x005531ac` | skill+0x10 |

---

## 4. Related artifacts

| Kind | Path |
|---|---|
| Raw / annotated | `raw/aa_00519200_Skill_StartCastAgainHeartbeat.*` |
| Clean | `reconstructed-exact/Skill_StartCastAgainHeartbeat.cpp` |
| Dual A/B | `reviews/A_aa_00519200_*`, `reviews/B_aa_00519200_*` |
| Scratch | `reviews/a_00519200.md` |
| Callee | `aa_0051e240` CVOGHBOKToCastAgain_ctor |

---

## 5. Confidence

| Dimension | Level |
|---|---|
| Control flow | **High** |
| Asm ABI / `RET 0x8` | **High** |
| Type-8 via ctor | **High** |
| World list +0xe4ec | **High** |
| Null-alloc path | **High** |
| 6-caller set + charge taxonomy | **High** |
| In-unit stacking guard | **None** (always alloc) — High |
| Duration formula | Ctor, not here |
| Plate formal names | **Falsified** |
| Overall | **Human-refined; dual residual accept-with-gaps** |
