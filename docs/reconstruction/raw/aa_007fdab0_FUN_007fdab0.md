# Raw capture: FUN_007fdab0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fdab0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fdab0` |
| **Canonical name** | `FUN_007fdab0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fdab0(int param_1)

{
  void *pvVar1;
  int *piVar2;
  int *piVar3;
  int unaff_EDI;
  
  piVar2 = (int *)**(int **)(unaff_EDI + 0x3124);
  if (piVar2 != *(int **)(unaff_EDI + 0x3124)) {
    do {
      pvVar1 = (void *)piVar2[2];
      if (*(int *)((int)pvVar1 + 0x20) == param_1) {
        if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
          operator_delete(pvVar1);
        }
        piVar2[2] = 0;
        piVar3 = (int *)*piVar2;
        if (piVar2 != *(int **)(unaff_EDI + 0x3124)) {
          *(int **)piVar2[1] = piVar3;
          *(int *)(*piVar2 + 4) = piVar2[1];
                    /* WARNING: Subroutine does not return */
          operator_delete(piVar2);
        }
      }
      else {
        piVar3 = (int *)*piVar2;
      }
      piVar2 = piVar3;
    } while (piVar3 != *(int **)(unaff_EDI + 0x3124));
  }
  return;
}
```
