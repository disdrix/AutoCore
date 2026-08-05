# Raw capture: FUN_004b6ed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b6ed0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004b6ed0` |
| **Canonical name** | `FUN_004b6ed0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004b6ed0(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)**(int **)(param_1 + 0x204);
  if (piVar1 != *(int **)(param_1 + 0x204)) {
    do {
      FUN_0058e980(param_2);
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0x204));
  }
  return;
}
```
