# Annotated low-level: Skill_AccuracyScore_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005531d0` |
| VA | `0x005531d0`–`0x00553239` |
| Canonical name | `Skill_AccuracyScore_Inferred` |
| System | `skills-abilities` |
| Date | `2026-07-29` |
| Dual | `reviews/A\|B_aa_005531d0_Skill_AccuracyScore_Inferred.md` |

## Machine-level notes

- **ABI (assembly-sealed):** skill `__thiscall`; three stack args; callee `RET 0xC`.
- **Return:** `float` in **ST0** via tail of `FUN_004ceba0` / `Skill_NonCreatureCastAutoHit`. Decompiler `void` is wrong (`analyze_function_complete` return-type warning).
- **Role:** thin skill wrapper that (1) optional attacker short-stat bonus → f32, (2) loads `skill+0x24` accuracy f32, (3) calls `Skill_NonCreatureCastAutoHit(bonus, 0.0f, skillAcc, attacker, target, debugReasonOut)`.
- Parent `Skill_AccuracyHitCheck_Inferred` compares returned score to `(roll%100)*0.01f`.

## Pseudocode (annotated)

```c
// __thiscall  ECX = skill runtime
// returns ST0 float score (hit fraction / AutoHit 0 or 1 paths inside cebao)
float Skill_AccuracyScore_Inferred(
    void *skill,              // this — f32 accuracy @ +0x24
    void *attacker,           // entity*; may be NULL → bonus 0
    void *target,             // entity*; forwarded
    char *debugReasonOut)     // may be NULL; filled by cebao string paths
{
  float attackerShortBonus = 0.0f;
  void *creature;

  if (attacker != NULL) {
    creature = attacker->vtbl[+0x214]();   // related creature / animate probe
    if (creature != NULL) {
      creature = attacker->vtbl[+0x214](); // re-fetch into ECX for fastcall
      // FUN_004c4140: clamp(min(s16[creature+0x140],200) + s16[creature+0x148], 1, 250)
      attackerShortBonus = (float)(int)(short)FUN_004c4140(creature);
    }
  }

  // cdecl 6 dwords; ADD ESP,0x18 after return
  return Skill_NonCreatureCastAutoHit(
      attackerShortBonus,          // f32 first
      0.0f,                        // literal 0 push
      *(float *)((char *)skill + 0x24),
      attacker,
      target,
      debugReasonOut);
}
```

## Offsets / callees

| Item | Role |
|---|---|
| skill+0x24 | f32 skill accuracy (also sentinel -1 in parent hit-check) |
| attacker vtbl+0x214 | creature/animate getter (null → no short bonus) |
| creature+0x140 | s16 base (capped 200 inside 004c4140) |
| creature+0x148 | s16 addend |
| `0x004c4140` | short-stat clamp helper → [1,250] |
| `0x004ceba0` | `Skill_NonCreatureCastAutoHit` score product |

## Call sites

| Site | Context |
|---|---|
| `0x00553297` | Sole named caller: `Skill_AccuracyHitCheck_Inferred` |
| `0x0082731b` | Unnamed code (no Ghidra function); `ECX=EDI` skill; score then `* 100.0f` (`DAT_00aaa7ac`) for int display path |

## Open questions

- Product C++ name.
- English names for creature +0x140 / +0x148 and vtbl+0x214.
- Whether cebao consumes third float (skill accuracy) or only attacker bonus + entity+0x260 path (cebao residual).
- Enclosing product for `0x0082731b` UI path.
