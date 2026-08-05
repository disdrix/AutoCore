# Raw capture: FUN_007fbfb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbfb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fbfb0` |
| **Canonical name** | `FUN_007fbfb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fbfb0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int unaff_ESI;
  
  piVar1 = (int *)**(int **)(unaff_ESI + 0x3c08);
  if (piVar1 != *(int **)(unaff_ESI + 0x3c08)) {
    do {
      if (piVar1[2] == param_1) {
        piVar2 = (int *)*piVar1;
        if (piVar1 != *(int **)(unaff_ESI + 0x3c08)) {
          *(int **)piVar1[1] = piVar2;
          *(int *)(*piVar1 + 4) = piVar1[1];
                    /* WARNING: Subroutine does not return */
          operator_delete(piVar1);
        }
      }
      else {
        piVar2 = (int *)*piVar1;
      }
      piVar1 = piVar2;
    } while (piVar2 != *(int **)(unaff_ESI + 0x3c08));
  }
  return;
}
```
