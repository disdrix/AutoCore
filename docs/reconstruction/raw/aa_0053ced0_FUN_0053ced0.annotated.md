# Annotated low-level: FUN_0053ced0

| Field | Value |
|---|---|
| Stable ID | `aa_0053ced0` |
| VA | `0x0053ced0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0053ced0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0053ced0(int param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a3f5b;
  pvStack_c = ExceptionList;
  uVar3 = 0;
  ExceptionList = &pvStack_c;
  iVar2 = param_1;
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + -0x4c + param_1) + 700))(0);
  pvVar1 = operator_new(0x78);
  puStack_8 = (undefined1 *)0x0;
  if (pvVar1 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005b2520(uVar3,pvVar1,iVar2);
  }
  *(undefined4 *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + -0x38 + param_1) = uVar3;
  puStack_8 = (undefined1 *)0xffffffff;
  iVar2 = 0;
  if (param_1 != 0x50) {
    iVar2 = *(int *)(*(int *)(param_1 + -0x4c) + 4) + -0x4c + param_1;
  }
  (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + -0x38 + param_1) + 0x2c))(iVar2)
  ;
  ExceptionList = pvVar1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
