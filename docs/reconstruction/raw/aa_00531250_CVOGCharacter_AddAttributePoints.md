# Raw capture: CVOGCharacter_AddAttributePoints

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531250` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00531250` |
| **Canonical name** | `CVOGCharacter_AddAttributePoints` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGCharacter_AddAttributePoints — add short attribute points to character pool (mission
   advance/complete).
   
   Parameters: attrib delta
   Called from CVOGReaction_CompleteObjective on both advance and final branches. */

void __thiscall CVOGCharacter_AddAttributePoints(int param_1,short param_2)

{
  int iVar1;
  undefined1 local_138 [28];
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  
  if (*(short *)(param_1 + 0x6cc) < param_2) {
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
    local_118 = *(undefined4 *)(iVar1 + 0x164 + param_1);
    local_114 = *(undefined4 *)(iVar1 + param_1 + 0x168);
    local_11c = 0x23;
    Client_SendLogicUiPacket(local_138);
  }
  *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 0x40;
  *(short *)(param_1 + 0x6cc) = param_2;
  return;
}
```
