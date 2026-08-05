# Raw capture: FUN_007fe2c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fe2c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fe2c0` |
| **Canonical name** | `FUN_007fe2c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fe2c0(void)

{
  int *piVar1;
  int unaff_EDI;
  
  piVar1 = (int *)**(int **)(unaff_EDI + 0x3124);
  if (piVar1 != *(int **)(unaff_EDI + 0x3124)) {
    do {
      if ((void *)piVar1[2] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete((void *)piVar1[2]);
      }
      piVar1[2] = 0;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EDI + 0x3124));
  }
  FUN_004133c0(0);
  return;
}
```
