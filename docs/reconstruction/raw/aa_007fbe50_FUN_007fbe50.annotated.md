# Annotated low-level: FUN_007fbe50

| Field | Value |
|---|---|
| Stable ID | `aa_007fbe50` |
| VA | `0x007fbe50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fbe50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
