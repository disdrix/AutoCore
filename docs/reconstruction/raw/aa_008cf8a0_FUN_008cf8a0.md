# Raw capture: FUN_008cf8a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008cf8a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008cf8a0` |
| **Canonical name** | `FUN_008cf8a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008cf8a0(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int unaff_EBX;
  int *unaff_ESI;
  int *unaff_EDI;
  int iVar6;
  int iStack_18;
  float fStack_14;
  float fStack_10;
  
  if (unaff_ESI != (int *)0x0) {
    (**(code **)(*unaff_ESI + 0x34c))();
    if ((unaff_EDI == (int *)0x0) || (iVar2 = (**(code **)(*unaff_EDI + 0x1b8))(), iVar2 == 0)) {
      (**(code **)(*unaff_ESI + 0xd4))(0);
      (**(code **)(*unaff_ESI + 4))(0);
      return;
    }
    puVar3 = (undefined4 *)(**(code **)(*unaff_EDI + 0x140))(&iStack_18,1);
    fStack_10 = (float)*puVar3;
    iVar2 = puVar3[1];
    (**(code **)(*unaff_EDI + 0x204))(&iStack_18);
    if (iVar2 < iStack_18) {
      (**(code **)(*unaff_ESI + 0xd4))(1);
      (**(code **)(*unaff_ESI + 4))(1);
      piVar4 = (int *)(**(code **)(*unaff_EDI + 0x1b8))();
      iVar2 = ((*(int *)(*piVar4 + 0x7c) - iVar2) + -1 + unaff_EBX) / *(int *)(*piVar4 + 0x7c);
      if (iVar2 < 1) {
        iVar2 = 1;
      }
      cVar1 = (**(code **)(*unaff_ESI + 0xd0))();
      if (cVar1 == '\0') {
        (**(code **)(*unaff_ESI + 0xfc))(1,0x3f000000);
      }
      fStack_10 = (float)iVar2;
      (**(code **)(*unaff_ESI + 0x460))(g_flOne / fStack_10);
      iVar6 = *unaff_ESI;
      iVar5 = (**(code **)(*unaff_EDI + 0x218))(0);
      (**(code **)(iVar6 + 0x454))((float)iVar5 / fStack_14);
      if (param_1 != (int *)0x0) {
        *param_1 = iVar2;
        return;
      }
    }
    else {
      (**(code **)(*unaff_ESI + 0xd4))(0);
      (**(code **)(*unaff_ESI + 4))(0);
    }
  }
  return;
}
```
