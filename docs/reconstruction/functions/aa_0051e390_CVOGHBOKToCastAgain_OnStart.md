# Function record: CVOGHBOKToCastAgain_OnStart

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e390` |
| **Canonical name** | `CVOGHBOKToCastAgain_OnStart` |
| **Address** | `0x0051e390` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__thiscall` / `__fastcall` — **ECX = HB**; **no stack args**; tail to StampLastFireTime |
| **System** | skills-abilities |
| **Completion status** | **Human-refined + dual residual seal (2026-07-29)** — CF/ABI/slots sealed; runtime open |
| **Bit-for-bit / runtime / diff** | Open |

---

## 1. Summary

Vtable **OnStart** for type-**8** cast-again heartbeat. On activate:

1. If **`HB+0x18` (owner entity)** non-null → **`Skill_SetIsCastingFlag(skill@HB+0x24, 1)`**
2. Always **`CVOGHBBase_StampLastFireTime(HB)`** → **`HB+0x14 = g_dwClientTickMs`**

Duration / category map already established in **ctor** (`0x0051e240`). **OnEnd** (`0x0051e3b0`) clears casting.

---

## 2. Signature (asm-sealed 2026-07-29)

```c
void __fastcall CVOGHBOKToCastAgain_OnStart(void* pHeartbeat /* ECX */);
```

Internal call shape:

```c
// if (*(int*)(pHeartbeat + 0x18) != 0)
void __thiscall Skill_SetIsCastingFlag(void* thisSkill /* ECX */, char bIsCasting /* stack */);
// RET 4; thisSkill+0x628 = bIsCasting (byte)
// if true: +0x170 = 0.0f (movss); +0x178 = g_dwClientTickMs
```

---

## 3. Related artifacts

| Kind | Path |
|---|---|
| Raw / annotated | `raw/aa_0051e390_CVOGHBOKToCastAgain_OnStart.*` |
| Clean | `reconstructed-exact/CVOGHBOKToCastAgain_OnStart.cpp` |
| Dual A/B | `reviews/A_aa_0051e390_*`, `reviews/B_aa_0051e390_*` |
| Residual scratch | `reviews/a_0051e390.md` |
| Ctor | `aa_0051e240` CVOGHBOKToCastAgain_ctor |
| OnEnd | `aa_0051e3b0` CVOGHBOKToCastAgain_OnEnd |
| Flag setter | `aa_005502d0` Skill_SetIsCastingFlag |
| Stamp | `aa_00508270` CVOGHBBase_StampLastFireTime |
| Start / alloc | `aa_00519200` Skill_StartCastAgainHeartbeat (`new 0x28`) |

---

## 4. Layout / constants

| Item | Value | Conf |
|---|---|---|
| Vtbl | `g_pVtbl_CVOGHBOKToCastAgain` = `0x009ce1c4` | High |
| OnStart slot | `*(0x009ce1c8) = 0x0051e390` | High |
| Owner gate | `HB+0x18` | High |
| Skill ptr | `HB+0x24` | High |
| Last fire tick | `HB+0x14` (via stamp) | High |
| Cast flag | skill `+0x628` (byte) | High |
| Cast stamp | skill `+0x178` (on true) | High |
| Clear float | skill `+0x170` (on true) | High |
| Tick global | `g_dwClientTickMs` / `DAT_00b041cc` | High |
| HB alloc (caller) | `0x28` | High |

---

## 5. Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Xrefs to | `0x009ce1c8` (DATA) | vtbl only; no direct CALL |
| Callee | `Skill_SetIsCastingFlag` `0x005502d0` | conditional |
| Callee | `CVOGHBBase_StampLastFireTime` `0x00508270` | tail jmp |

---

## 6. Confidence

| Dimension | Level |
|---|---|
| Control flow | **High** |
| Asm call ABI for flag setter | **High** |
| Owner vs skill field split | **High** |
| Stamp offset `+0x14` | **High** |
| `unaff_SI` phantom | **Falsified** |
| Product English on skill flag fields | Open |
| Runtime / bit-exact | Open |
| Overall | **Human-refined; dual residual accept-with-gaps** |
