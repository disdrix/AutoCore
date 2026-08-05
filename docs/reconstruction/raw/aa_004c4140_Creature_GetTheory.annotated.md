# Annotated low-level: Creature_GetTheory

| Field | Value |
|---|---|
| Stable ID | `aa_004c4140` |
| VA | `0x004c4140`–`0x004c41bb` |
| System | `skills-abilities` / character stats |
| Date | 2026-07-29 (W17-I) |

## Machine-level notes

- **Leaf** `__fastcall` / `__thiscall`-style: creature/`this` in **ECX**; return int in **EAX**; plain `RET`.
- Reads **signed shorts** at `this+0x140` (base) and `this+0x148` (bonus/modifier).
- Caps base at **200** (`if 199 < base then 200`), adds bonus, clamps result to **[1, 250]**.
- Product name **"Theory"** from UI requirements formatter `FUN_00845360` (`FUN_007a6de0("Theory")`).
- Sibling pattern (not owned): Combat `004c4070` (+0x13e/+0x146), Perception `004c41c0` (+0x142/+0x14a) — those add vehicle floor via vfunc `+0x1dc`; **Theory has no vehicle branch**, only [1,250] clamp.
- Accuracy chain: `Skill_AccuracyScore_Inferred` casts return to float as attacker bonus.

## Pseudocode (annotated)

```c
// Canonical: int __fastcall Creature_GetTheory(void *creature);
// Equivalent: clamp(min((int16)creature[+0x140], 200) + (int16)creature[+0x148], 1, 250)

int __fastcall FUN_004c4140(int param_1 /* creature* in ECX */)
{
  short base = *(short *)(param_1 + 0x140);
  short bonus = *(short *)(param_1 + 0x148);
  int capped = (base > 199) ? 200 : base;   // signed: 199 < base → 200
  int sum = capped + (int)bonus;

  if (sum < 0xfa) {                         // sum < 250
    if (sum < 2)
      return 1;                             // floor
    // recompute min(base,200)+bonus (same as sum)
    return ((base > 199) ? 200 : base) + (int)bonus;
  }
  return 0xfa;                              // ceiling 250
}
```

## Control flow

```
base  = int16(this+0x140)
bonus = int16(this+0x148)
cap   = min(base, 200)          // via (199 < base) ? 200 : base
sum   = cap + bonus
if sum < 250:
  if sum < 2: return 1
  return sum
else:
  return 250
```

## Open questions

1. English names for the two short fields (base Theory vs bonus/equipment).
2. Why Theory lacks the vehicle floor present on Combat/Perception getters.
3. Whether accuracy uses Theory intentionally (design) vs shared short-stat pipeline accident — sealed as live caller path either way.
