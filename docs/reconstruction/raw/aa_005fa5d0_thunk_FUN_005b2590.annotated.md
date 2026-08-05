# Annotated low-level: thunk_FUN_005b2590

| Field | Value |
|---|---|
| Stable ID | `aa_005fa5d0` |
| VA | `0x005fa5d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fa5d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall thunk_FUN_005b2590(undefined4 *param_1)

{
  int *piVar1;
  void *pvVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &LAB_009a6765;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_LAB_009d953c;
  uStack_4 = 1;
  if ((void *)param_1[0x17] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)param_1[0x17]);
  }
  param_1[0x17] = 0;
  if ((void *)param_1[0x18] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)param_1[0x18]);
  }
  iVar5 = param_1[0x1d];
  param_1[0x18] = 0;
  while( true ) {
    if (iVar5 == 0) {
      FUN_005b2ba0();
      uStack_4 = 0xffffffff;
      FUN_00787020();
      ExceptionList = pvStack_c;
      return;
    }
    uVar4 = (uint)param_1[0x1c] >> 2;
    iVar5 = uVar4 * -4;
    if ((uint)param_1[0x1b] <= uVar4) {
      uVar4 = uVar4 - param_1[0x1b];
    }
    pvVar2 = *(void **)(*(int *)(param_1[0x1a] + uVar4 * 4) + (param_1[0x1c] + iVar5) * 4);
    if (param_1[0x1d] != 0) {
      param_1[0x1c] = param_1[0x1c] + 1;
      if ((uint)(param_1[0x1b] * 4) <= (uint)param_1[0x1c]) {
        param_1[0x1c] = 0;
      }
      iVar5 = param_1[0x1d] + -1;
      param_1[0x1d] = iVar5;
      if (iVar5 == 0) {
        param_1[0x1c] = 0;
      }
    }
    if (pvVar2 != (void *)0x0) break;
    iVar5 = param_1[0x1d];
  }
  piVar3 = *(int **)((int)pvVar2 + 8);
  if (piVar3 != (int *)0x0) {
    piVar1 = piVar3 + 2;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*piVar3 + 8))();
    }
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(pvVar2);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
