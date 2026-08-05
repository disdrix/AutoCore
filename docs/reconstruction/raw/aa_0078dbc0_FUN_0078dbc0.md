# Raw capture: FUN_0078dbc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078dbc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0078dbc0` |
| **Canonical name** | `FUN_0078dbc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0078dbc0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int unaff_ESI;
  int *piVar2;
  int iVar3;
  int aiStack_10 [3];
  int iStack_4;
  
  iVar1 = *(int *)(param_1 + 0x4c0);
  if (iVar1 != 0) {
    iVar3 = 0;
    if (*(char *)(iVar1 + 0x1d) != '\0') {
      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    *(undefined1 *)(iVar1 + 0x1d) = 1;
    while( true ) {
      iVar1 = *(int *)(param_1 + 0x4c0);
      if (*(char *)(iVar1 + 0x1d) == '\0') {
        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
        FUN_007a4480(0,"VOG_DEBUG_STOP");
      }
      if (iVar3 == 0) {
        iVar3 = *(int *)(iVar1 + 0x14);
      }
      else {
        iVar3 = *(int *)(iVar3 + 0x14);
      }
      if (iVar3 == 0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = *(int **)(iVar3 + 8);
      }
      if (piVar2 == (int *)0x0) break;
      iVar1 = (**(code **)(*piVar2 + 0x78))();
      if (0x67 < iVar1) {
        (**(code **)(*piVar2 + 0x120))(aiStack_10,1,0);
        aiStack_10[0] = iStack_4 + unaff_ESI;
        (**(code **)(*piVar2 + 0x110))(&stack0xffffffec);
      }
    }
    *(undefined1 *)(*(int *)(param_1 + 0x4c0) + 0x1d) = 0;
    *(int *)(param_1 + 0x910) = *(int *)(param_1 + 0x910) + param_2;
    *(int *)(param_1 + 0x914) = *(int *)(param_1 + 0x914) + param_3;
  }
  return;
}
```
