# Raw capture: FUN_0044bfb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044bfb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0044bfb0` |
| **Canonical name** | `FUN_0044bfb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0044bfb0(void)

{
  int *piVar1;
  int *piVar2;
  int in_EAX;
  int *piVar3;
  int unaff_EDI;
  
  if (in_EAX == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(in_EAX + 4);
  }
  piVar3 = (int *)*piVar3;
  if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {
    (**(code **)(*piVar3 + 4))();
  }
  piVar2 = *(int **)(unaff_EDI + 4);
  if (piVar2 != (int *)0x0) {
    piVar1 = piVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*piVar2 + 8))();
    }
  }
  *(int **)(unaff_EDI + 4) = piVar3;
  return;
}
```
