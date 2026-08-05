# Annotated low-level: FUN_007ab0f0

| Field | Value |
|---|---|
| Stable ID | `aa_007ab0f0` |
| VA | `0x007ab0f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007ab0f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007ab0f0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *unaff_ESI;
  undefined1 **unaff_EDI;
  undefined1 *local_90;
  undefined1 local_8c [124];
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009aba77;
  local_c = ExceptionList;
  iVar1 = *param_1;
  if (iVar1 == 0) {
    if ((void *)unaff_ESI[0xa2] != (void *)0x0) {
      ExceptionList = &local_c;
      operator_delete__((void *)unaff_ESI[0xa2]);
    }
    unaff_ESI[0xa2] = 0;
    ExceptionList = local_c;
    return;
  }
  local_90 = local_8c;
  ExceptionList = &local_c;
  uVar2 = (*(code *)PTR_FUN_00af8c9c)();
  FUN_00403450(iVar1,uVar2);
  uStack_4 = 0;
  (**(code **)(*unaff_ESI + 0x308))(local_90);
  if (unaff_EDI != &local_90) {
    free(unaff_EDI);
  }
  ExceptionList = pvStack_10;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
