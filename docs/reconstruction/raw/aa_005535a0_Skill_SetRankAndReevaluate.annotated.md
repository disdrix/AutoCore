# Annotated low-level: Skill_SetRankAndReevaluate

| Field | Value |
|---|---|
| Stable ID | `aa_005535a0` |
| VA | `0x005535a0` |
| System | skills-abilities |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005535a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Skill_SetRankAndReevaluate(pSkill, sRank)
   
   Parameters:
     pSkill - skill runtime
     sRank  - new rank stored at +0x5f6
   
   Algorithm: set rank; Skill_ReevaluateForCurrentRank.
   Returns: void */

void __thiscall Skill_SetRankAndReevaluate(void *this,void *pSkill,short sRank)

{
  *(undefined2 *)((int)this + 0x5f6) = pSkill._0_2_;
  Skill_ReevaluateForCurrentRank(this);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
