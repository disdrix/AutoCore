# Raw capture: FUN_007fc0b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fc0b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fc0b0` |
| **Canonical name** | `FUN_007fc0b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined1 * FUN_007fc0b0(void)

{
  char cVar1;
  int unaff_ESI;
  undefined1 *apuStack_c [3];
  
  if (*(int *)(unaff_ESI + 0xc78) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0xc78) + 8))();
    if (cVar1 != '\0') {
      (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x54))();
      if ((apuStack_c < apuStack_c[0]) && ((undefined1 *)0x1770 < apuStack_c[0])) {
        return apuStack_c[0];
      }
      return (undefined1 *)apuStack_c;
    }
  }
  return (undefined1 *)0x0;
}
```
