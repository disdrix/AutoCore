# Raw capture: FUN_004dea70

| Field | Value |
|---|---|
| **Stable ID** | `aa_004dea70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004dea70` |
| **Canonical name** | `FUN_004dea70` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004dea70(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (((*(int *)(param_1 + 0xe8a0) != 0) &&
      (puVar3 = *(undefined4 **)(param_1 + 0xe864), puVar3 != (undefined4 *)0x0)) &&
     (*(int *)(param_1 + 0xe868) - (int)puVar3 >> 3 != 0)) {
    if (puVar3 != *(undefined4 **)(param_1 + 0xe868)) {
      do {
        iVar1 = FUN_004bb040(0,*puVar3,puVar3[1]);
        if (iVar1 != 0) {
          uVar2 = (**(code **)(**(int **)(param_1 + 0xe8a0) + 0x1dc))(iVar1);
          FUN_004de760(uVar2,iVar1);
        }
        puVar3 = puVar3 + 2;
      } while (puVar3 != *(undefined4 **)(param_1 + 0xe868));
    }
    if (*(void **)(param_1 + 0xe864) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(*(void **)(param_1 + 0xe864));
    }
    *(undefined4 *)(param_1 + 0xe864) = 0;
    *(undefined4 *)(param_1 + 0xe868) = 0;
    *(undefined4 *)(param_1 + 0xe86c) = 0;
  }
  return;
}
```
