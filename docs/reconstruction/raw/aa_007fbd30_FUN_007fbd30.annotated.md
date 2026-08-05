# Annotated low-level: FUN_007fbd30

| Field | Value |
|---|---|
| Stable ID | `aa_007fbd30` |
| VA | `0x007fbd30` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fbd30`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
