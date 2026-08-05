# Raw capture: FUN_008df6a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008df6a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008df6a0` |
| **Canonical name** | `FUN_008df6a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008df6a0(void)

{
  int iVar1;
  int *piVar2;
  int *unaff_EDI;
  
  piVar2 = unaff_EDI + 0x177;
  iVar1 = 0x33;
  do {
    if (*piVar2 != 0) {
      (**(code **)(*unaff_EDI + 0xbc))(*piVar2);
    }
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = *(int **)unaff_EDI[0x1ac];
  if (piVar2 != (int *)unaff_EDI[0x1ac]) {
    do {
      (**(code **)(*unaff_EDI + 0xbc))(piVar2[2]);
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)unaff_EDI[0x1ac]);
  }
  FUN_004133c0(0);
  return;
}
```
