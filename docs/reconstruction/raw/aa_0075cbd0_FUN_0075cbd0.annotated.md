# Annotated low-level: FUN_0075cbd0

| Field | Value |
|---|---|
| Stable ID | `aa_0075cbd0` |
| VA | `0x0075cbd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0075cbd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_0075cbd0(int param_1,undefined4 *param_2,byte param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  void *unaff_EBX;
  undefined4 unaff_EBP;
  uint uVar7;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar5 = DAT_00d1f614;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b255c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(char *)(DAT_00d1f614 + 200) == '\0') {
    ExceptionList = &pvStack_c;
    iVar6 = FUN_0076c3c0();
    piVar1 = (int *)(iVar5 + 0x34 + *(int *)(iVar5 + 0xc4) * 4);
    *piVar1 = *piVar1 + (iVar6 - *(int *)(iVar5 + 0x30));
    *(int *)(iVar5 + 0x30) = iVar6;
    *(undefined4 *)(iVar5 + 0xc4) = 0;
  }
  local_4 = 0;
  *(undefined4 *)(param_1 + 0xe4) = *param_2;
  *(undefined4 *)(param_1 + 0xe8) = param_2[1];
  if ((param_3 & 4) == 0) {
    if (*(int *)(param_1 + 0x44) == 0) {
      FUN_0075e7e0(0);
    }
    else if (*(int *)(param_1 + 0x44) != 0) {
      FUN_0043f3b0(0);
    }
  }
  FUN_0075c680();
  if ((*(char *)(param_1 + 0x14c) == '\0') || (iVar6 = *(int *)(param_1 + 0x44), iVar6 == 0)) {
    FUN_0075b720(0,0x3f800000);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0xdc);
    uVar3 = *(undefined4 *)(param_1 + 0xe0);
    uVar4 = *(undefined4 *)(iVar6 + 0x1c);
    *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(iVar6 + 0x20);
    *(undefined4 *)(param_1 + 0xdc) = uVar4;
    FUN_0075b720(0,0x3f800000);
    *(undefined4 *)(param_1 + 0xdc) = uVar2;
    *(undefined4 *)(param_1 + 0xe0) = uVar3;
  }
  piVar1 = (int *)*DAT_00d1f044;
  if (*(int *)(param_1 + 0x44) == 0) {
    if (DAT_00d1f044[0x1e1] != 0) {
      (**(code **)(*DAT_00d1f610 + 0x1c))(DAT_00d1f610,0xa1,*(undefined1 *)(DAT_00d1f048 + 0x2c));
    }
  }
  else {
    uVar7 = 0;
    if (((param_3 & 1) != 0) && ((*(byte *)(*(int *)(param_1 + 0x44) + 0x2c) & 0x20) != 0)) {
      uVar7 = 5;
    }
    if (((param_3 & 2) != 0) ||
       ((*(char *)(param_1 + 0x129) != '\0' && (*(int *)(param_1 + 0x13c) == 0)))) {
      uVar7 = uVar7 | 2;
    }
    if (uVar7 != 0) {
      FUN_0075ebd0(DAT_00d1f044,uVar7,param_1 + 0x148,0x3f800000,0);
    }
  }
  if ((*(char *)(param_1 + 0x14c) != '\0') && (*(int *)(param_1 + 0x44) != 0)) {
    FUN_0075b720(0,0x3f800000);
    *(undefined1 *)(param_1 + 0x14c) = 0;
  }
  if ((*(char *)(param_1 + 0x129) != '\0') &&
     ((*(int *)(param_1 + 0x13c) != 0 || (*(int *)(param_1 + 0x44) == 0)))) {
    FUN_0075bcd0();
  }
  if (*(char *)(DAT_00d1f048 + 0xd) != '\0') {
    (**(code **)(*DAT_00d1f610 + 0x1c))(DAT_00d1f610,8,2);
  }
  if (*(char *)((int)DAT_00d1f044 + 0x777) != '\0') {
    (**(code **)(*piVar1 + 0x13c))(piVar1,*(undefined4 *)(DAT_00d1f048 + 0x28));
  }
  iVar6 = FUN_0073f610();
  if (iVar6 < 0) {
    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp",0x275,3,
                   "Failed to Render Object Display List");
    FUN_0043f1d0();
    ExceptionList = pvStack_c;
    return 0xffffffff;
  }
  if (*(char *)((int)DAT_00d1f044 + 0x777) != '\0') {
    (**(code **)(*piVar1 + 0x13c))(piVar1,0);
  }
  if (*(char *)(DAT_00d1f048 + 0xd) != '\0') {
    (**(code **)(*DAT_00d1f610 + 0x1c))(DAT_00d1f610,8,3);
  }
  (**(code **)(*DAT_00d1f610 + 0x1c))(DAT_00d1f610,0xa1,0);
  if (*(char *)(iVar5 + 200) == '\0') {
    iVar6 = FUN_0076c3c0();
    piVar1 = (int *)(iVar5 + 0x34 + *(int *)(iVar5 + 0xc4) * 4);
    *piVar1 = *piVar1 + (iVar6 - *(int *)(iVar5 + 0x30));
    *(int *)(iVar5 + 0x30) = iVar6;
    *(undefined4 *)(iVar5 + 0xc4) = unaff_EBP;
  }
  ExceptionList = unaff_EBX;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
