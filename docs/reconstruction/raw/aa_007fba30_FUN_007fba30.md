# Raw capture: FUN_007fba30

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fba30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fba30` |
| **Canonical name** | `FUN_007fba30` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_007fba30(void)

{
  char cVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x30b0) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x30b0) + 0x3d8))();
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x30b0) + 0xd0))();
      if (cVar1 != '\0') {
        return 1;
      }
    }
  }
  return 0;
}
```
