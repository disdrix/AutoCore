# Raw capture: FUN_0044fdd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044fdd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0044fdd0` |
| **Canonical name** | `FUN_0044fdd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0044fdd0(void)

{
  int *piVar1;
  int unaff_EDI;
  
  piVar1 = *(int **)(unaff_EDI + 0x10);
  if (piVar1 != *(int **)(unaff_EDI + 0x14)) {
    do {
      if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar1)(1);
      }
      piVar1 = piVar1 + 1;
    } while (piVar1 != *(int **)(unaff_EDI + 0x14));
  }
  FUN_0044fe70(0);
  return;
}
```
