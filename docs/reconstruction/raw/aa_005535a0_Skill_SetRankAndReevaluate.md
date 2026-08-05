# Raw capture: Skill_SetRankAndReevaluate

| Field | Value |
|---|---|
| **Stable ID** | `aa_005535a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005535a0` |
| **Canonical name** | `Skill_SetRankAndReevaluate` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
