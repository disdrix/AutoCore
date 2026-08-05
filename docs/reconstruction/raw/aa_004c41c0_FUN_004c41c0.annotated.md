# Annotated low-level: Creature_GetPerception

| Field | Value |
|---|---|
| Stable ID | `aa_004c41c0` |
| VA | `0x004c41c0`–`0x004c428e` |
| System | `skills-abilities` / character stats |
| Date | 2026-07-29 (W18-H) |

## Machine-level notes

- **`__fastcall` / `__thiscall`-style:** creature/`this` in **ECX** (`mov esi,ecx`); return int in **EAX**; plain **`RET`** (no stack args).
- Reads **signed shorts** at `this+0x142` (base) and `this+0x14a` (bonus/modifier).
- Caps base at **200**, sum at **250** — same arithmetic shape as Combat (`004c4070`).
- Applies **vehicle/MI floor** via multiple-inheritance this-adjust then **vtbl+0x1DC**:
  - probe ≠ 0 → thr = **1**
  - probe == 0 → thr = **-100**
  - return **max(score, thr)** (`if thr < score return score; else return thr`)
- Second identical vtbl call on thr-return path (asm not CSE; decompiler preserves both).
- Product name **"Perception"** from UI requirements formatter `FUN_00845360` (`FUN_007a6de0("Perception")`).
- Sibling pattern: Combat `004c4070` (+0x13e/+0x146 + thr); Theory `004c4140` (+0x140/+0x148, floor 1, **no** thr).
- Ghidra marks classification **leaf** (no static FUN_* callees); **indirect** call present.

## Pseudocode (annotated)

```c
// Canonical: int __fastcall Creature_GetPerception(void *creature);
// score = min(min(base,200)+bonus, 250)
// thr   = (MI_vtbl(+0x1DC) != 0) ? 1 : -100
// return max(score, thr)

int __fastcall FUN_004c41c0(int param_1 /* creature* in ECX */)
{
  short base = *(short *)(param_1 + 0x142);
  short bonus = *(short *)(param_1 + 0x14a);
  int score = (int)((base > 199) ? 200 : base) + (int)bonus;
  if (score >= 0xfa) score = 0xfa;

  int probe = (*(code**)(/* MI this-adjust */ + 0x1dc))();
  int thr = (-(uint)(probe != 0) & 0x65) - 100;  // 1 or -100

  if (thr < score) {
    // recompute score (asm not CSE)
    return min(min(base,200)+bonus, 250);
  }
  probe = (*(code**)(/* same MI */ + 0x1dc))();
  return (-(uint)(probe != 0) & 0x65) - 100;
}
```

## Control flow

```
base  = int16(this+0x142)
bonus = int16(this+0x14a)
score = min(min(base, 200) + bonus, 250)
probe = MI_vtbl[+0x1DC]()
thr   = (probe != 0) ? 1 : -100
if thr < score:
  return score          // recomputed on return path
else:
  probe2 = MI_vtbl[+0x1DC]()
  return (probe2 != 0) ? 1 : -100
```

## Threshold encode (same as Combat)

```
neg eax        ; 0 → 0; nonzero → two's complement
sbb eax, eax   ; 0 → 0; nonzero → -1
and eax, 0x65  ; 0 or 101
add eax, -100  ; 0 → -100; 101 → 1
```

## Open questions

1. English DB/wire names for shorts at `+0x142` / `+0x14a`.
2. Product name of `vtbl+0x1DC` (vehicle-present / MI probe — Probable).
3. Why Theory lacks this thr while Combat/Perception share it.
4. Runtime dump: Perception UI value == this formula under vehicle vs on-foot.
5. Whether negative thr path (-100) is reachable with retail data (unmodified shorts).

