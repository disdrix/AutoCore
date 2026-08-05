# Annotated low-level: FUN_0043aff0

| Field | Value |
|---|---|
| Stable ID | `aa_0043aff0` |
| VA | `0x0043aff0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0043aff0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0043aff0(uint param_1,undefined4 param_2,void *param_3)

{
  uint uVar1;
  int iVar2;
  int unaff_ESI;
  void *in_stack_00000018;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009bedc8;
  local_c = ExceptionList;
  local_4 = 0;
  iVar2 = *(int *)(unaff_ESI + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(unaff_ESI + 8) - iVar2) / 0x28;
  }
  local_10 = param_1;
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(unaff_ESI + 8) - iVar2) / 0x28;
    }
    ExceptionList = &local_c;
    FUN_0043b190(unaff_ESI,*(undefined4 *)(unaff_ESI + 8),param_1 - iVar2);
  }
  else {
    ExceptionList = &local_c;
    if ((iVar2 != 0) &&
       (ExceptionList = &local_c, param_1 < (uint)((*(int *)(unaff_ESI + 8) - iVar2) / 0x28))) {
      ExceptionList = &local_c;
      FUN_0043b110(unaff_ESI,&local_10,iVar2 + param_1 * 0x28,*(int *)(unaff_ESI + 8));
    }
  }
  if (in_stack_00000018 == (void *)0x0) {
    if (param_3 == (void *)0x0) {
      ExceptionList = local_c;
      return;
    }
                    /* WARNING: Subroutine does not return */
    operator_delete(param_3);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(in_stack_00000018);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
