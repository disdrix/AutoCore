# Raw capture: CVOGCharacter_AddSkillPoints

| Field | Value |
|---|---|
| **Stable ID** | `aa_005312c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005312c0` |
| **Canonical name** | `CVOGCharacter_AddSkillPoints` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGCharacter_AddSkillPoints — add short skill points to character pool (mission
   advance/complete).
   
   Parameters: skill delta (short)
   Called from CVOGReaction_CompleteObjective on both advance and final branches. */

void __thiscall CVOGCharacter_AddSkillPoints(int param_1,short param_2)

{
  int iVar1;
  undefined1 local_138 [28];
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  
  if (*(short *)(param_1 + 0x6ce) < param_2) {
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
    local_118 = *(undefined4 *)(iVar1 + 0x164 + param_1);
    local_114 = *(undefined4 *)(iVar1 + param_1 + 0x168);
    local_11c = 0x21;
    Client_SendLogicUiPacket(local_138);
  }
  *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 0x40;
  *(short *)(param_1 + 0x6ce) = param_2;
  return;
}
```
