# Annotated low-level: FUN_004cfca0

| Field | Value |
|---|---|
| Stable ID | `aa_004cfca0` |
| VA | `0x004cfca0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004cfca0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004cfca0(int param_1)

{
  int *piVar1;
  void *pvVar2;
  CVOGHBBase *pAction;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a1f4b;
  pvStack_c = ExceptionList;
  piVar1 = *(int **)(param_1 + 0x78);
  ExceptionList = &pvStack_c;
  if (piVar1 != (int *)0x0) {
    if (*(int *)(param_1 + 0xe4ec) == 0) {
      ExceptionList = &pvStack_c;
      (**(code **)*piVar1)(1);
    }
    else {
      ExceptionList = &pvStack_c;
      (**(code **)(*piVar1 + 0x18))(1);
    }
    *(undefined4 *)(param_1 + 0x78) = 0;
  }
  if (*(int *)(param_1 + 0xe894) != 0) {
    FUN_0048e9e0();
  }
  pvVar2 = operator_new(0x1d8);
  uStack_4 = 0;
  if (pvVar2 == (void *)0x0) {
    pAction = (CVOGHBBase *)0x0;
  }
  else {
    pAction = (CVOGHBBase *)FUN_00558b20(param_1);
  }
  uStack_4 = 0xffffffff;
  *(CVOGHBBase **)(param_1 + 0x78) = pAction;
  if (*(void **)(param_1 + 0xe4ec) != (void *)0x0) {
    CVOGHBList_Enqueue(*(void **)(param_1 + 0xe4ec),pAction);
    CVOGHBBase_Start(*(CVOGHBBase **)(param_1 + 0x78));
  }
  ExceptionList = pvStack_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
