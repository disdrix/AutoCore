# Raw capture: FUN_005db1b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005db1b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005db1b0` |
| **Canonical name** | `FUN_005db1b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005db1b0(int param_1)

{
  undefined4 *puVar1;
  
  if (*(int *)(param_1 + 0xd0) != 0) {
    if (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xe4a4) != 0) {
      FUN_00560020(*(int *)(param_1 + 0xd0));
    }
    puVar1 = *(undefined4 **)(param_1 + 0xd0);
    *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;
    if (*(short *)((int)puVar1 + 6) == 0) {
      (**(code **)*puVar1)(1);
    }
    *(undefined4 *)(param_1 + 0xd0) = 0;
    if (*(void **)(param_1 + 0xd4) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(*(void **)(param_1 + 0xd4));
    }
    *(undefined4 *)(param_1 + 0xd4) = 0;
  }
  return;
}
```
