# Raw capture: FUN_007fbe50

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbe50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fbe50` |
| **Canonical name** | `FUN_007fbe50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fbe50(void)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  int *unaff_ESI;
  
  if ((in_EAX != (int *)0x0) && (unaff_ESI != (int *)0x0)) {
    iVar1 = (**(code **)(*in_EAX + 0x490))();
    iVar2 = (**(code **)(*in_EAX + 0x494))();
    (**(code **)(*unaff_ESI + 0x454))(0,1);
    if (iVar1 <= iVar2) {
      (**(code **)(*unaff_ESI + 0x460))(0x3f800000);
    }
    else {
      (**(code **)(*unaff_ESI + 0x460))(g_flOne / (float)(iVar1 - iVar2));
    }
    (**(code **)(*unaff_ESI + 0xd4))(iVar1 > iVar2);
                    /* WARNING: Could not recover jumptable at 0x007fbecb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*unaff_ESI + 0x34c))();
    return;
  }
  return;
}
```
