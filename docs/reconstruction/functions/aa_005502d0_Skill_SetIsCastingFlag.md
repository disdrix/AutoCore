# Function record: Skill_SetIsCastingFlag

| Field | Value |
|---|---|
| **Stable ID** | `aa_005502d0` |
| **Canonical name** | `Skill_SetIsCastingFlag` |
| **Address** | `0x005502d0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Dual residual sealed** (2026-07-29) — A/B **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Set client skill **is-casting** flag at **`+0x628`**. True path also zeros **`+0x170`** (float) and stamps **`+0x178`** with `g_dwClientTickMs`. False path clears flag only.

## Signature (asm-sealed)

```c
void __thiscall Skill_SetIsCastingFlag(void* thisSkill /* ECX */, char bIsCasting /* stack */);
// RET 4
// *(uint8_t*)(thisSkill+0x628) = bIsCasting;
// if (bIsCasting) {
//   *(float*)(thisSkill+0x170) = 0.0f;
//   *(uint32_t*)(thisSkill+0x178) = g_dwClientTickMs; // DAT_00b041cc
// }
```

## Sealed fields

| Offset | Width | Role |
|---|---|---|
| `+0x628` | u8 | Is-casting flag (**sealed**) |
| `+0x170` | float | Zeroed on cast-start stamp |
| `+0x178` | u32 | Cast-start tick ms |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005502d0_Skill_SetIsCastingFlag.md`
- Annotated: `docs/reconstruction/raw/aa_005502d0_Skill_SetIsCastingFlag.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_SetIsCastingFlag.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005502d0_Skill_SetIsCastingFlag.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005502d0_Skill_SetIsCastingFlag.md`
- Residual scratch: `docs/reconstruction/reviews/a_005502d0.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `CVOGHBOKToCastAgain_OnStart` `0x0051e390` @ `0x0051e39e` | `push 1` |
| Caller | `CVOGHBOKToCastAgain_OnEnd` `0x0051e3b0` @ `0x0051e3be` | `push 0` |
| Caller | `FUN_0052c780` @ `0x0052c82c` | bulk `push 0` per skill |
| Callee | (none) | pure stores; global load `g_dwClientTickMs` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from machine body | **High** |
| `skill+0x628` is-casting byte | **High** (sealed) |
| ABI / parameter shape | **High** |
| Product English names | Open |
