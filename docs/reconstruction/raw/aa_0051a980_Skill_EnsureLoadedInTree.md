# Raw capture: Skill_EnsureLoadedInTree

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a980` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0051a980` |
| **Canonical name** | `Skill_EnsureLoadedInTree` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
