# Raw capture: FUN_007fdb20

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fdb20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fdb20` |
| **Canonical name** | `FUN_007fdb20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fdb20(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int unaff_EDI;
  
  piVar1 = *(int **)(unaff_EDI + 0x3124);
  piVar2 = (int *)*piVar1;
  if (piVar2 != piVar1) {
    while ((*(int *)piVar2[2] != param_1 || (((int *)piVar2[2])[1] != param_2))) {
      piVar2 = (int *)*piVar2;
      if (piVar2 == piVar1) {
        return;
      }
    }
    if ((void *)piVar2[2] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)piVar2[2]);
    }
    piVar2[2] = 0;
    if (piVar2 != *(int **)(unaff_EDI + 0x3124)) {
      *(int *)piVar2[1] = *piVar2;
      *(int *)(*piVar2 + 4) = piVar2[1];
                    /* WARNING: Subroutine does not return */
      operator_delete(piVar2);
    }
  }
  return;
}
```
