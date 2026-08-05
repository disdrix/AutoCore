# Raw capture: FUN_0075eee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075eee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0075eee0` |
| **Canonical name** | `FUN_0075eee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0075eee0(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *unaff_EDI;
  
  pvVar1 = (void *)unaff_EDI[0x1e8];
  if (pvVar1 != (void *)0x0) {
    FUN_009658e0(pvVar1);
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  unaff_EDI[0x1e8] = 0;
  puVar2 = *(undefined4 **)(unaff_EDI[0x1db] + 8);
  for (puVar4 = *(undefined4 **)(unaff_EDI[0x1db] + 4); puVar4 != puVar2; puVar4 = puVar4 + 1) {
    (**(code **)(*(int *)*puVar4 + 0x14))();
  }
  FUN_0073c270();
  FUN_00986130();
  FUN_0073bf60();
  FUN_00967400(unaff_EDI[0x1d7]);
  FUN_0073dc40(unaff_EDI[0x1d9]);
  FUN_00986760(unaff_EDI[0x1d3]);
  FUN_00985800(unaff_EDI[0x1d4]);
  FUN_0073bad0();
  FUN_0096e710();
  pvVar1 = (void *)unaff_EDI[0x1e7];
  if (pvVar1 == (void *)0x0) {
    unaff_EDI[0x1e7] = 0;
    piVar3 = (int *)unaff_EDI[3];
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    unaff_EDI[3] = 0;
    piVar3 = (int *)unaff_EDI[2];
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    unaff_EDI[2] = 0;
    piVar3 = (int *)*unaff_EDI;
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    *unaff_EDI = 0;
    piVar3 = (int *)unaff_EDI[1];
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    unaff_EDI[1] = 0;
    return 0;
  }
  FUN_009667b0(pvVar1);
                    /* WARNING: Subroutine does not return */
  operator_delete(pvVar1);
}
```
