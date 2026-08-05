# Function record: CVOGHBOKToCastAgain_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e240` |
| **Canonical name** | `CVOGHBOKToCastAgain_ctor` |
| **Address** | `0x0051e240` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__thiscall` — **`RET 0xC`** (3 stack dwords) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined + dual residual seal (2026-07-29)** — ABI/owner-skill/duration/insert sealed; runtime open |
| **Bit-for-bit / runtime / diff** | Open |

---

## 1. Summary

Heartbeat type **8** for cast-again / category cooldown overlay.

```
durationMs = ROUND(ceil(skill.cooldownMs(+0x10) * equipMod)) + chargeDelay
// equipMod = g_flOne if owner.vtbl+0x210()==0; else Vehicle_GetSkillCooldownModifier ST0
// optional clamp to 500 when owner.vtbl+0x1dc() object has +0x6b4 >= 1
// optional category map insert on **owner** (+0x6c) unless skill+0x5e8 == -1
// AttachOwner(owner); skill @ HB+0x24; type @ HB+0x1c = 8
```

Sole production caller: `Skill_StartCastAgainHeartbeat` (`0x00519200`) after `operator_new(0x28)`.

---

## 2. Signature (asm-sealed 2026-07-29)

```c
void* __thiscall CVOGHBOKToCastAgain_ctor(
    void* thisHb,          // ECX
    void* pOwnerEntity,    // stack0 — vehicle/pool vfuncs, category map host, AttachOwner
    void* pSkillRuntime,   // stack1 — +0x10 CD, +0x5e8 category key, stored @ HB+0x24
    int   nChargeDelayMs); // stack2
// RET 0xC
```

Prior 2-stack plate `(this, skill, charge)` **falsified**.

---

## 3. Related artifacts

| Kind | Path |
|---|---|
| Raw / annotated | `raw/aa_0051e240_CVOGHBOKToCastAgain_ctor.*` |
| Clean | `reconstructed-exact/CVOGHBOKToCastAgain_ctor.cpp` |
| Dual A/B | `reviews/A_aa_0051e240_*`, `reviews/B_aa_0051e240_*` |
| Scratch | `reviews/a_0051e240.md` |
| Caller | `aa_00519200` Skill_StartCastAgainHeartbeat |
| OnStart / OnEnd | `0x0051e390` / `0x0051e3b0` |
| Modifier | `Vehicle_GetSkillCooldownModifier` `0x0052a9b0` |
| Category | GetMap `0x00518d70`, Insert `0x0051d2f0`, high-level Insert `0x00518df0` |
| Attach | `CVOGHBBase_AttachOwnerObject` `0x005083b0` |

---

## 4. Layout / constants

| Item | Value | Conf |
|---|---|---|
| HB alloc size (caller) | `0x28` | High |
| Vtbl | `g_pVtbl_CVOGHBOKToCastAgain` = `0x009ce1c4` | High |
| Type field | HB+0x1c = **8** | High |
| Skill ptr | HB+0x24 | High |
| Duration ms | HB+0x8 | High |
| Identity float | `g_flOne` @ `0x00a0f2a0` | High |
| Clamp | **500** (`0x1F4`) | High |
| Tick global | `DAT_00b041cc` / `g_dwClientTickMs` | High |
| Category map | lazy at **owner+0x6c** | High |

---

## 5. Confidence

| Dimension | Level |
|---|---|
| Control flow | **High** |
| Asm ABI / `RET 0xC` | **High** |
| Owner vs skill parameter split | **High** |
| Duration formula structure | **High** |
| No-vehicle mod = 1.0 | **High** |
| 500 ms clamp condition (numeric) | **High** |
| Category map insert arg pack | **High** (sealed 2026-07-29) |
| vfunc / +0x6b4 product English | Open |
| Equip modifier plant math | Sibling unit |
| Overall | **Human-refined; dual residual accept-with-gaps** |
