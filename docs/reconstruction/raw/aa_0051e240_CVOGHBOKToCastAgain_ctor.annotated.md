# Annotated low-level: CVOGHBOKToCastAgain_ctor (`aa_0051e240`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e240` |
| **VA** | `0x0051e240` |
| **System** | skills-abilities |
| **Source raw** | `aa_0051e240_CVOGHBOKToCastAgain_ctor.md` |
| **Dual residual** | `2026-07-29` — see `reviews/a_0051e240.md` |

## Signature (asm-sealed)

```c
void* __thiscall CVOGHBOKToCastAgain_ctor(
    void* thisHb,          // ECX
    void* pOwnerEntity,    // stack0
    void* pSkillRuntime,   // stack1
    int   nChargeDelayMs); // stack2
// RET 0xC  (epilogue C2 0C 00 @ 0x0051e38b)
```

Prior 2-stack plate **falsified**. Regs after prolog: ESI=this, EDI=owner, EBX=skill.

## Duration formula

```
HB+0x8 = ROUND(ceil( (float)skill+0x10 * equipModifier )) + nChargeDelayMs
```

- `equipModifier`: if **owner**.vtbl+0x210() == 0 → **`g_flOne`** (`0x00a0f2a0` = 1.0f); else ST0 from `Vehicle_GetSkillCooldownModifier` after second owner.+0x210 resolve.
- Decompiler `unaff_EBX` / "polluted float" path **falsified**.
- If **owner**.vtbl+0x1dc() non-null and `*(pool+0x6b4) >= 1`: clamp `HB+0x8` to **500** max (`cmp 0x1F4`).
- Vfuncs are on **owner**, not skill (decomp skill.vtbl claims **falsified**).

## Category map

If `skill+0x5e8 != -1`:

```
entry = { key=skill+0x5e8, start=DAT_00b041cc, duration=HB+0x8 }
map   = Skill_GetCategoryCooldownMap(**owner**)   // lazy @ owner+0x6c
Skill_CategoryCooldownMap_Insert(map, &outPair, &entry)
```

Same pack as `Skill_InsertCategoryCooldown` (`0x00518df0`). CONCAT residual **closed**.

## Identity fields

| Offset | Value |
|-------:|-------|
| vtbl | `g_pVtbl_CVOGHBOKToCastAgain` = `0x009ce1c4` |
| `+0x1c` | type **8** |
| `+0x24` | skill runtime pointer |
| owner | `CVOGHBBase_AttachOwnerObject(this, **owner**)` — not skill |

## Port note

AutoCore must send power-plant cooldown modifier **1.0**, not 0.0 (topic: zero collapses duration to charge-only).

## Open

- Product English for owner.vtbl+0x210 / +0x1dc / pool+0x6b4.
- Second +0x210 push pack / skill+0x5ec role.
- Full `Vehicle_GetSkillCooldownModifier` body (sibling).
- Runtime / bit-exact.

OnStart/OnEnd (`0x0051e390` / `0x0051e3b0`) set/clear casting flag (sibling units).
