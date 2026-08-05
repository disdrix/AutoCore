# Raw capture: FUN_007fbd30

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbd30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fbd30` |
| **Canonical name** | `FUN_007fbd30` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fbd30(void)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int *unaff_ESI;
  float unaff_EDI;
  undefined4 uVar4;
  
  if ((in_EAX == (int *)0x0) || (unaff_ESI == (int *)0x0)) {
    return;
  }
  iVar1 = (**(code **)(*in_EAX + 0x490))();
  iVar2 = (**(code **)(*in_EAX + 0x494))();
  iVar3 = (**(code **)(*in_EAX + 0x49c))();
  if (iVar2 < iVar1) {
    (**(code **)(*unaff_ESI + 0x460))(g_flOne / (float)(iVar1 - iVar2));
    (**(code **)(*unaff_ESI + 0x454))((float)iVar3 / unaff_EDI,0);
    uVar4 = 1;
  }
  else {
    if (0 < iVar3) {
      (**(code **)(*unaff_ESI + 0x460))(g_flOne / (float)iVar3);
      (**(code **)(*unaff_ESI + 0x454))(g_flOne - unaff_EDI,0);
      (**(code **)(*unaff_ESI + 0xd4))(1);
      goto LAB_007fbe36;
    }
    (**(code **)(*unaff_ESI + 0x460))(0x3f800000);
    (**(code **)(*unaff_ESI + 0x454))(0,1);
    uVar4 = 0;
  }
  (**(code **)(*unaff_ESI + 0xd4))(uVar4);
LAB_007fbe36:
                    /* WARNING: Could not recover jumptable at 0x007fbe40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*unaff_ESI + 0x34c))();
  return;
}
```
