# Annotated low-level: FUN_004d9cd0

| Field | Value |
|---|---|
| Stable ID | `aa_004d9cd0` |
| VA | `0x004d9cd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004d9cd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined1 __fastcall FUN_004d9cd0(int *param_1)

{
  float fVar1;
  char cVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a226c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar3 = operator_new(0x3fc);
  local_4 = 0;
  if (pvVar3 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_004ad730();
  }
  param_1[0x393e] = iVar4;
  *(int **)(iVar4 + 0x340) = param_1;
  local_4 = 0xffffffff;
  cVar2 = FUN_004aaa20(param_1 + 0x3866);
  if (cVar2 == '\0') {
    ExceptionList = local_c;
    return 0;
  }
  FUN_004ac0e0();
  (**(code **)(*param_1 + 8))();
  fVar1 = DAT_00a0f6a4;
  iVar4 = param_1[0x393e];
  iVar8 = (int)(*(int *)(iVar4 + 0x10) + (*(int *)(iVar4 + 0x10) >> 0x1f & 7U)) >> 3;
  param_1[0x39ee] = iVar8;
  iVar5 = (int)(*(int *)(iVar4 + 0x14) + (*(int *)(iVar4 + 0x14) >> 0x1f & 7U)) >> 3;
  param_1[0x39ef] = iVar5;
  iVar5 = iVar5 * iVar8;
  param_1[0x39f0] = (int)(*(float *)(iVar4 + 0x18) * fVar1);
  param_1[0x39f1] = (int)(*(float *)(iVar4 + 0x18) * fVar1);
  piVar6 = operator_new__(iVar5 * 0x20 + 4);
  local_4 = 1;
  if (piVar6 == (int *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = piVar6 + 1;
    *piVar6 = iVar5;
    _eh_vector_constructor_iterator_(piVar7,0x20,iVar5,FUN_004e45a0,FUN_004e45e0);
  }
  local_4 = 0xffffffff;
  param_1[0x39ed] = (int)piVar7;
  local_10 = 0;
  if (0 < param_1[0x39ef] * param_1[0x39ee]) {
    iVar4 = 0;
    do {
      pvVar3 = *(void **)(param_1[0x39ed] + 4 + iVar4);
      iVar5 = param_1[0x39ed] + iVar4;
      if (pvVar3 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar3);
      }
      *(undefined4 *)(iVar5 + 4) = 0;
      *(undefined4 *)(iVar5 + 8) = 0;
      *(undefined4 *)(iVar5 + 0xc) = 0;
      pvVar3 = *(void **)(param_1[0x39ed] + 0x14 + iVar4);
      iVar5 = param_1[0x39ed] + 0x10 + iVar4;
      if (pvVar3 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar3);
      }
      *(undefined4 *)(iVar5 + 4) = 0;
      *(undefined4 *)(iVar5 + 8) = 0;
      *(undefined4 *)(iVar5 + 0xc) = 0;
      local_10 = local_10 + 1;
      iVar4 = iVar4 + 0x20;
    } while (local_10 < param_1[0x39ef] * param_1[0x39ee]);
  }
  FUN_004ce370();
  if (*(char *)((int)param_1 + 0x7d) == '\0') {
    FUN_004d8270();
  }
  FUN_004ac100(0);
  ExceptionList = local_c;
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
