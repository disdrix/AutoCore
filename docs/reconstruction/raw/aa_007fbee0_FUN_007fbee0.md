# Raw capture: FUN_007fbee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fbee0` |
| **Canonical name** | `FUN_007fbee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fbee0(void)

{
  bool bVar1;
  undefined1 uVar2;
  int *piVar3;
  int *unaff_ESI;
  char cStack_5;
  
  if (unaff_ESI != (int *)0x0) {
    piVar3 = (int *)(**(code **)(*unaff_ESI + 0x34))();
    if (piVar3 == (int *)0x0) {
      cStack_5 = '\0';
    }
    else {
      cStack_5 = (**(code **)(*piVar3 + 0x3d8))();
    }
    uVar2 = (**(code **)(*unaff_ESI + 0xd0))();
    bVar1 = false;
    if ((unaff_ESI[0x70] != DAT_00d1e818) || (unaff_ESI[0x71] != DAT_00d1e81c)) {
      bVar1 = true;
    }
    if (cStack_5 != '\0') {
      (**(code **)(*piVar3 + 0x440))();
    }
    if (bVar1) {
      (**(code **)(*unaff_ESI + 0x28))(0);
    }
    if (cStack_5 != '\0') {
      (**(code **)(*piVar3 + 0x43c))();
    }
    if (bVar1) {
      (**(code **)(*unaff_ESI + 0x10c))();
    }
    if ((piVar3 == (int *)0x0) || (cStack_5 != '\0')) {
      (**(code **)(*unaff_ESI + 0xcc))(uVar2);
    }
                    /* WARNING: Could not recover jumptable at 0x007fbf9d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*unaff_ESI + 0x34c))();
    return;
  }
  return;
}
```
