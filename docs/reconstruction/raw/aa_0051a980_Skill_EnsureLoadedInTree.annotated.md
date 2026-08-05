# Annotated low-level: Skill_EnsureLoadedInTree

| Field | Value |
|---|---|
| Stable ID | `aa_0051a980` |
| VA | `0x0051a980` |
| System | skills-abilities |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0051a980`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Skill_EnsureLoadedInTree(skillId, rank)
   
   Looks up skill in character/object skill tree hash. If missing, ResolveSkillTargets
   and insert; if present but lower rank, Skill_SetRankAndReevaluate. */

void __thiscall Skill_EnsureLoadedInTree(void *this,int nSkillId,short sRank)

{
  void *this_00;
  undefined4 *puVar1;
  short unaff_DI;
  undefined2 in_stack_0000000a;
  
  if (0 < nSkillId) {
    this_00 = CNDHash_LookupByKey(*(void **)((int)this + 0x70),nSkillId);
    if (this_00 == (void *)0x0) {
      puVar1 = CVOGReaction_ResolveSkillTargets((void *)nSkillId,_sRank);
      if (puVar1 != (undefined4 *)0x0) {
        FUN_0051e6d0(nSkillId,puVar1,0);
        return;
      }
      FUN_007a4480(0,"AddSkillToTree, unable to find skill #%d, level %d",nSkillId,(int)sRank);
    }
    else if (*(short *)((int)this_00 + 0x5f6) < sRank) {
      Skill_SetRankAndReevaluate(this_00,_sRank,unaff_DI);
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
