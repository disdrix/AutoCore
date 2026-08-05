# Raw capture: FUN_007fb8a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fb8a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fb8a0` |
| **Canonical name** | `FUN_007fb8a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fb8a0(void)

{
  char cVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x1164) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x1164) + 0x3d8))();
    if (cVar1 != '\0') {
      (**(code **)(**(int **)(unaff_ESI + 0x1164) + 0x440))();
      if (*(int *)(unaff_ESI + 0xf38) != 0) {
        (**(code **)(**(int **)(unaff_ESI + 0xf38) + 0xb0))(*(undefined4 *)(unaff_ESI + 0x1164));
      }
    }
  }
  return;
}
```
