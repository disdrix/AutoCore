# Raw capture: FUN_0092cef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092cef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0092cef0` |
| **Canonical name** | `FUN_0092cef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0092cef0(void)

{
  char cVar1;
  int *piVar2;
  int unaff_ESI;
  
  piVar2 = *(int **)(unaff_ESI + 0xf40);
  if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
    (**(code **)(*(int *)*piVar2 + 0x94))();
    if (*(int *)(unaff_ESI + 0x1138) != 0) {
      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x1138) + 0x3d8))();
      if (cVar1 != '\0') {
        (**(code **)(**(int **)(unaff_ESI + 0x1138) + 0x94))();
      }
    }
    piVar2 = (int *)FUN_0090d390();
    if (piVar2 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0092cf3f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*piVar2 + 0x94))();
      return;
    }
  }
  return;
}
```
