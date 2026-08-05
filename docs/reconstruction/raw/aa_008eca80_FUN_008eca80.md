# Raw capture: FUN_008eca80

| Field | Value |
|---|---|
| **Stable ID** | `aa_008eca80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008eca80` |
| **Canonical name** | `FUN_008eca80` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_008eca80(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 auStack_18 [4];
  void *local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009af077;
  local_c = ExceptionList;
  if ((param_1 != 0) && (param_2 != -1)) {
    iVar2 = 0;
    ExceptionList = &local_c;
    local_14 = (void *)FUN_0040fb90();
    local_10 = 0;
    local_4 = 0;
    if (*(char *)(param_1 + 0x1d) != '\0') {
      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    *(undefined1 *)(param_1 + 0x1d) = 1;
    while( true ) {
      if (*(char *)(param_1 + 0x1d) == '\0') {
        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
        FUN_007a4480(0,"VOG_DEBUG_STOP");
      }
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_1 + 0x14);
      }
      else {
        iVar2 = *(int *)(iVar2 + 0x14);
      }
      if (iVar2 == 0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = *(int **)(iVar2 + 8);
      }
      if (piVar3 == (int *)0x0) break;
      if ((((piVar3[0x3f] == param_2) && ((short)piVar3[0x3e] == 0)) && (piVar3[0x22] != -1)) &&
         (((*piVar3 < 0xdfd || (0xe02 < *piVar3)) ||
          ((DAT_00d1b6d8 == 0 ||
           (iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +
                                         DAT_00d1b6d8) + 0x27c))(), 4 < iVar1)))))) {
        FUN_00402dd0(0);
        FUN_008ec750(piVar3,auStack_18);
      }
    }
    *(undefined1 *)(param_1 + 0x1d) = 0;
    local_4 = 0xffffffff;
    FUN_00415e90();
                    /* WARNING: Subroutine does not return */
    operator_delete(local_14);
  }
  return 0;
}
```
