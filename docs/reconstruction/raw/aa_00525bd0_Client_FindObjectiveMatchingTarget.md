# Raw capture: Client_FindObjectiveMatchingTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_00525bd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00525bd0` |
| **Canonical name** | `Client_FindObjectiveMatchingTarget` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Traverse character mission hash (param+0x548) looking for an objective that matches target object
   (param_2 = target clonebase field). Returns mission/objective node with field at +0x10 used as
   IDObjective in Client_SendUseObject (+0x18 of 0x2072 packet). Returns 0 if none. */

int __thiscall Client_FindObjectiveMatchingTarget(int param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = 0;
  if (*(int *)(*(int *)(param_1 + 0x55c) + 0xc) < 1) {
    return 0;
  }
  iVar4 = *(int *)(param_1 + 0x548);
  if (*(char *)(iVar4 + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  *(undefined1 *)(iVar4 + 0x1d) = 1;
  while( true ) {
    iVar4 = *(int *)(param_1 + 0x548);
    if (*(char *)(iVar4 + 0x1d) == '\0') {
      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    if (iVar3 == 0) {
      iVar3 = *(int *)(iVar4 + 0x14);
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x14);
    }
    if (iVar3 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar3 + 8);
    }
    if (iVar4 == 0) break;
    for (uVar5 = 0;
        (iVar1 = *(int *)(iVar4 + 0x158), iVar1 != 0 &&
        (uVar5 < (uint)(*(int *)(iVar4 + 0x15c) - iVar1 >> 2))); uVar5 = uVar5 + 1) {
      cVar2 = (**(code **)(**(int **)(iVar1 + uVar5 * 4) + 0x38))(param_2,param_1);
      if (cVar2 != '\0') {
        *(undefined1 *)(*(int *)(param_1 + 0x548) + 0x1d) = 0;
        return iVar4;
      }
    }
  }
  *(undefined1 *)(*(int *)(param_1 + 0x548) + 0x1d) = 0;
  return 0;
}
```
