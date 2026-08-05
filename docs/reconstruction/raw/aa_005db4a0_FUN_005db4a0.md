# Raw capture: FUN_005db4a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005db4a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005db4a0` |
| **Canonical name** | `FUN_005db4a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005db4a0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);
  *puVar2 = *param_2;
  puVar2[1] = param_2[1];
  puVar2[2] = param_2[2];
  puVar2[3] = param_2[3];
  if (*(int **)(param_1 + 0x48) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x48) + 0x10))(3);
    *(undefined4 *)(iVar1 + 0xbc) = 0xffffffff;
    *(int *)(iVar1 + 0xb4) = *(int *)(iVar1 + 0xb4) + 1;
    puVar2 = (undefined4 *)
             FUN_004e88e0(&stack0xfffffff0,*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);
    *(undefined4 *)(iVar1 + 0x90) = *puVar2;
    *(undefined4 *)(iVar1 + 0x94) = puVar2[1];
    *(undefined4 *)(iVar1 + 0x98) = puVar2[2];
  }
  return;
}
```
