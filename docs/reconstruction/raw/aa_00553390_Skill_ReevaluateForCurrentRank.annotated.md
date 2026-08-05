# Annotated low-level: Skill_ReevaluateForCurrentRank

| Field | Value |
|---|---|
| Stable ID | `aa_00553390` |
| VA | `0x00553390` |
| System | skills-abilities |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00553390`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Skill_ReevaluateForCurrentRank(pSkill)
   
   Parameters:
     pSkill - skill runtime
   
   Algorithm: Skill_EvaluateRankedElements(id, rank+offset, pSkill, offset);
   updates targeting flags +0x624.
   
   VERIFIED calls Evaluate with skill+0x5fc id and +0x5f6 rank. */

void __fastcall Skill_ReevaluateForCurrentRank(void *pSkill)

{
  uint uVar1;
  
  Skill_EvaluateRankedElements
            (*(undefined4 *)((int)pSkill + 0x5fc),
             *(short *)((int)pSkill + 0x5f6) + *(short *)((int)pSkill + 0x174),pSkill,
             *(short *)((int)pSkill + 0x174));
  uVar1 = FUN_00627be0();
  if (*(uint *)((int)pSkill + 0x620) == 0) {
    *(uint *)((int)pSkill + 0x624) = uVar1;
  }
  else {
    *(uint *)((int)pSkill + 0x624) = uVar1 | 4;
    if (*(char *)((int)pSkill + 0x148) == '\0') {
      *(uint *)((int)pSkill + 0x620) = *(uint *)((int)pSkill + 0x620) | 0x100000;
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
