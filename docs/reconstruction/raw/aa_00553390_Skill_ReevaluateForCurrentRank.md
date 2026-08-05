# Raw capture: Skill_ReevaluateForCurrentRank

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553390` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00553390` |
| **Canonical name** | `Skill_ReevaluateForCurrentRank` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
