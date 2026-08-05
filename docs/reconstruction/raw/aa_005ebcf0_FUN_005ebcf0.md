# Raw capture: FUN_005ebcf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ebcf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ebcf0` |
| **Canonical name** | `FUN_005ebcf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005ebcf0(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (*param_2 != 0) {
    iVar5 = *(int *)(param_1 + 0xc4) + -1;
    if (-1 < iVar5) {
      puVar4 = (undefined4 *)(*(int *)(param_1 + 0xc0) + 4 + iVar5 * 8);
      do {
        if ((int *)*puVar4 == param_2) {
          FUN_00580b60(param_2,1);
          piVar1 = *(int **)(*(int *)(param_1 + 0xc0) + iVar5 * 8);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 0x14))();
          }
          *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + -1;
          iVar2 = *(int *)(param_1 + 0xc4);
          iVar3 = *(int *)(param_1 + 0xc0);
          *(undefined4 *)(iVar3 + iVar5 * 8) = *(undefined4 *)(iVar3 + iVar2 * 8);
          *(undefined4 *)(iVar3 + 4 + iVar5 * 8) = *(undefined4 *)(iVar3 + 4 + iVar2 * 8);
          return;
        }
        iVar5 = iVar5 + -1;
        puVar4 = puVar4 + -2;
      } while (-1 < iVar5);
    }
    FUN_00580b60(param_2,(uint)param_2 & 0xffffff00);
  }
  return;
}
```
