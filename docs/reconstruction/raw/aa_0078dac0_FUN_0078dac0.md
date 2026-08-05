# Raw capture: FUN_0078dac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078dac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0078dac0` |
| **Canonical name** | `FUN_0078dac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __fastcall FUN_0078dac0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  iVar3 = *(int *)(param_1 + 0x4c0);
  local_8 = -1;
  if ((iVar3 != 0) && (*(int *)(param_1 + 0x928) != -1)) {
    local_8 = 0;
    if (*(char *)(iVar3 + 0x1d) != '\0') {
      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    *(undefined1 *)(iVar3 + 0x1d) = 1;
    piVar1 = (int *)FUN_00411e40();
    if (piVar1 != (int *)0x0) {
      iVar3 = 0;
      do {
        iVar2 = (**(code **)(*piVar1 + 0x78))();
        if (0x67 < iVar2) {
          iVar2 = (**(code **)(*piVar1 + 0x78))();
          if (iVar2 == *(int *)(param_1 + 0x928)) break;
          local_8 = local_8 + 1;
        }
        iVar2 = *(int *)(param_1 + 0x4c0);
        if (*(char *)(iVar2 + 0x1d) == '\0') {
          FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
          FUN_007a4480(0,"VOG_DEBUG_STOP");
        }
        if (iVar3 == 0) {
          iVar3 = *(int *)(iVar2 + 0x14);
        }
        else {
          iVar3 = *(int *)(iVar3 + 0x14);
        }
        if (iVar3 == 0) {
          piVar1 = (int *)0x0;
        }
        else {
          piVar1 = *(int **)(iVar3 + 8);
        }
      } while (piVar1 != (int *)0x0);
    }
    *(undefined1 *)(*(int *)(param_1 + 0x4c0) + 0x1d) = 0;
    if (*(int *)(*(int *)(param_1 + 0x4c0) + 0xc) <= local_8) {
      local_8 = -1;
    }
  }
  return local_8;
}
```
