# Annotated low-level: FUN_004cf3b0

| Field | Value |
|---|---|
| Stable ID | `aa_004cf3b0` |
| VA | `0x004cf3b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004cf3b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_004cf3b0(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  float unaff_ESI;
  TFID_16 TStack_14;
  float fStack_4;
  
  iVar1 = (**(code **)(*param_1 + 0x210))(0);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*param_1 + 0x1d8))();
    if (iVar1 != 0) {
      TStack_14._12_4_ = *(undefined4 *)(iVar1 + 0x234);
      if (((*(uint *)(iVar1 + 0x228) & *(uint *)(iVar1 + 0x22c)) != 0xffffffff) ||
         ((char)*(undefined4 *)(iVar1 + 0x230) != '\0')) {
        TStack_14.dwCoidLo = *(uint *)(iVar1 + 0x228);
        TStack_14.dwCoidHi = *(uint *)(iVar1 + 0x22c);
        TStack_14._8_4_ = *(undefined4 *)(iVar1 + 0x230);
        TStack_14._12_4_ = *(undefined4 *)(iVar1 + 0x234);
        piVar2 = Object_ResolveFromTFID(&TStack_14);
        if ((piVar2 != (int *)0x0) && (iVar1 = (**(code **)(*piVar2 + 0x1dc))(), iVar1 != 0)) {
          return;
        }
      }
    }
    (**(code **)(*param_1 + 0x23c))();
    (**(code **)(*param_1 + 0x244))();
    iVar1 = (**(code **)(*param_1 + 0x244))();
    (**(code **)(*param_1 + 0x248))
              ((int)ROUND((*(float *)(&DAT_009cc390 + param_2 * 4) + g_flOne) *
                          ((float)iVar1 / (*(float *)(&DAT_009cc390 + (int)param_1 * 4) + g_flOne)))
              );
    iVar1 = (**(code **)(*param_1 + 0x244))();
    fStack_4 = (float)iVar1 * unaff_ESI;
    (**(code **)(*param_1 + 0x240))((int)ROUND(fStack_4));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
