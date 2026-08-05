# Raw capture: SkillSet_GetEntryCount

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402d80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00402d80` |
| **Canonical name** | `SkillSet_GetEntryCount` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* SkillSet_GetEntryCount(pSkillSet)
   
   Returns (end-begin)/0x18 for NPCSkillSetEntry vector at +0x4/+0x8. */

int __fastcall SkillSet_GetEntryCount(void *pSkillSet)

{
  if (*(int *)((int)pSkillSet + 4) == 0) {
    return 0;
  }
  return (*(int *)((int)pSkillSet + 8) - *(int *)((int)pSkillSet + 4)) / 0x18;
}
```
