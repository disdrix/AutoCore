# Annotated low-level: FUN_005e0cd0

| Field | Value |
|---|---|
| Stable ID | `aa_005e0cd0` |
| VA | `0x005e0cd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005e0cd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Removing unreachable block (ram,0x005e0f38) */
/* WARNING: Removing unreachable block (ram,0x005e0f03) */
/* WARNING: Removing unreachable block (ram,0x005e0e3c) */
/* WARNING: Removing unreachable block (ram,0x005e0e8e) */
/* WARNING: Removing unreachable block (ram,0x005e0ef2) */
/* WARNING: Removing unreachable block (ram,0x005e0f27) */

undefined4 __thiscall
FUN_005e0cd0(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_30;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a7420;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_005e0480(param_2);
  switch(param_5) {
  case 0:
    param_2 = 0;
    break;
  case 1:
    param_2 = 1;
    break;
  case 2:
    param_2 = 2;
    break;
  case 3:
    param_2 = 3;
    break;
  default:
    param_2 = 4;
  }
  if (param_4 == 0) {
    local_30 = 0;
  }
  else if (param_4 == 1) {
    local_30 = 1;
  }
  else if (param_4 == 2) {
    local_30 = 2;
  }
  else {
    local_30 = 3;
  }
  sVar1 = FUN_005e0590();
  iVar2 = (int)sVar1 + iVar2 * 0x32;
  iVar4 = iVar2 * 4;
  local_4 = 1;
  iVar2 = iVar2 * 0x140 + 0x10e13c + param_1;
  if (((-1 < param_4) && (param_4 < 3)) || ((-1 < param_5 && (param_5 < 4)))) {
    if (param_4 == 0) {
      iVar3 = 0;
    }
    else if (param_4 == 1) {
      iVar3 = 1;
    }
    else if (param_4 == 2) {
      iVar3 = 2;
    }
    else {
      iVar3 = 3;
    }
    FUN_0040f5b0((iVar3 + iVar4) * 0x50 + 0x10e04c + param_1);
    param_1 = param_2 * 0x10 + (iVar4 + local_30) * 0x50 + 0x10e00c + param_1;
    if (*(int *)(param_1 + 4) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
    }
    FUN_00410420(iVar4,0);
    FUN_005e1860(&param_3,0,0,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),0);
  }
  iVar4 = param_6;
  if (*(int *)(iVar2 + 4) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2;
  }
  FUN_00410420(iVar3,0);
  FUN_005e1860(&param_3,0,0,*(undefined4 *)(iVar2 + 4),*(undefined4 *)(iVar2 + 8),
               *(undefined4 *)(iVar4 + 4));
  if ((*(int *)(iVar4 + 4) != 0) && (*(int *)(iVar4 + 8) - *(int *)(iVar4 + 4) >> 2 != 0)) {
    ExceptionList = local_c;
    return 1;
  }
  ExceptionList = local_c;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
