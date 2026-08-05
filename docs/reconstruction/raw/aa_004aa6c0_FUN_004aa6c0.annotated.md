# Annotated low-level: FUN_004aa6c0

| Field | Value |
|---|---|
| Stable ID | `aa_004aa6c0` |
| VA | `0x004aa6c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004aa6c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004aa6c0(int param_1)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  char *local_320;
  undefined1 local_31c [4];
  char local_318 [260];
  char local_214 [260];
  char local_110 [260];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a12b2;
  local_c = ExceptionList;
  pvVar2 = *(void **)(param_1 + 0x3f0);
  if (pvVar2 != (void *)0x0) {
    ExceptionList = &local_c;
    FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar2);
  }
  pvVar2 = *(void **)(param_1 + 0x3f4);
  if (pvVar2 != (void *)0x0) {
    ExceptionList = &local_c;
    FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar2);
  }
  pvVar2 = *(void **)(param_1 + 0x3f8);
  if (pvVar2 != (void *)0x0) {
    ExceptionList = &local_c;
    FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar2);
  }
  ExceptionList = &local_c;
  local_320 = operator_new(4);
  local_4 = 0;
  if (local_320 == (char *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0096ef70();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x3f0) = uVar3;
  local_320 = operator_new(4);
  local_4 = 1;
  if (local_320 == (char *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0096ef70();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x3f4) = uVar3;
  local_320 = operator_new(4);
  local_4 = 2;
  if (local_320 == (char *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0096ef70();
  }
  *(undefined4 *)(param_1 + 0x3f8) = uVar3;
  local_4 = 0xffffffff;
  FUN_004a9800(0,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x340) + 0x78) + 0x154),local_110);
  FUN_004a9800(2,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x340) + 0x78) + 0x154),local_214);
  FUN_004a9800(1,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x340) + 0x78) + 0x154),local_318);
  local_320 = local_110;
  do {
    cVar1 = *local_320;
    local_320 = local_320 + 1;
  } while (cVar1 != '\0');
  local_320 = local_320 + -(int)(local_110 + 1);
  if (local_320 != (char *)0x0) {
    FUN_00989e00(local_31c,local_214);
    FUN_0096f3e0(local_31c,0);
  }
  local_320 = local_318;
  do {
    cVar1 = *local_320;
    local_320 = local_320 + 1;
  } while (cVar1 != '\0');
  local_320 = local_320 + -(int)(local_318 + 1);
  if (local_320 != (char *)0x0) {
    FUN_00989e00(local_31c,local_318);
    FUN_0096f3e0(local_31c,0);
  }
  local_320 = local_214;
  do {
    cVar1 = *local_320;
    local_320 = local_320 + 1;
  } while (cVar1 != '\0');
  local_320 = local_320 + -(int)(local_214 + 1);
  if (local_320 != (char *)0x0) {
    FUN_00989e00(&local_320,local_110);
    FUN_0096f3e0(&local_320,0);
  }
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
