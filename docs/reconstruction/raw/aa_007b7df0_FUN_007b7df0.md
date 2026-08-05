# Raw capture: FUN_007b7df0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b7df0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007b7df0` |
| **Canonical name** | `FUN_007b7df0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_007b7df0(undefined1 *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0x20);
  *piVar1 = *piVar1 + -1;
  if ((*piVar1 == 0) && (DAT_00d1793c == '\0')) {
    piVar1 = *(int **)(param_1 + 0x28);
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x28) = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar1 = *(int **)(param_1 + 0x24);
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x24) = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *param_1 = 0;
  }
  return 0;
}
```
