# Raw capture: FUN_005bbc20

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bbc20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005bbc20` |
| **Canonical name** | `FUN_005bbc20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005bbc20(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)**(int **)(param_1 + 0xa24);
  if (piVar1 != *(int **)(param_1 + 0xa24)) {
    do {
      FUN_004b0f00(param_2);
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0xa24));
  }
  return;
}
```
