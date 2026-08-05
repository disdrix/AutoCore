# Annotated low-level: FUN_007d8fe0

| Field | Value |
|---|---|
| Stable ID | `aa_007d8fe0` |
| VA | `0x007d8fe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007d8fe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_007d8fe0(char *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  byte bStack_1b7;
  undefined1 uStack_1b6;
  undefined1 uStack_1b5;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 *local_1ac;
  undefined4 local_1a8;
  int local_1a4;
  undefined4 local_1a0;
  undefined4 *local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined2 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  wchar_t awStack_15c [66];
  wchar_t awStack_d8 [102];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009aeaff;
  local_c = ExceptionList;
  if (*param_1 == '\0') {
    return 0x80004004;
  }
  if (DAT_00d1793c != '\0') {
    return 0;
  }
  local_19c = &local_1b4;
  local_1b4 = 0;
  local_1b0 = 0;
  local_1ac = (undefined4 *)0x0;
  local_1a8 = 0;
  local_1a4 = 0;
  local_1a0 = 0;
  local_194 = 0;
  local_198 = 0;
  local_190 = 0;
  local_18c = 0;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_004230d0(local_19c,&param_2);
  iVar1 = FUN_00422fb0(1,1,4);
  if (-1 < iVar1) {
    iVar1 = FUN_0041a810(&local_1b4,param_1 + 0x28,0,0,&DAT_00a140c8,0,0);
  }
  local_1ac = &uStack_184;
  if (((((((-1 < iVar1) && (iVar1 = FUN_004231d0(&local_1b4,1,4), -1 < iVar1)) &&
         (iVar1 = FUN_004231d0(&local_1b4,2,4), -1 < iVar1)) &&
        ((iVar1 = FUN_004231d0(&local_1b4,3,4), -1 < iVar1 &&
         (iVar1 = FUN_004231d0(&local_1b4,4,4), -1 < iVar1)))) &&
       ((iVar1 = FUN_004231d0(&local_1b4,5,4), -1 < iVar1 &&
        ((iVar1 = FUN_004231d0(&local_1b4,6,2), -1 < iVar1 &&
         (iVar1 = FUN_004231d0(&local_1b4,7,1), -1 < iVar1)))))) &&
      (iVar1 = FUN_004231d0(&local_1b4,8,1), -1 < iVar1)) &&
     ((((iVar1 = FUN_004231d0(&local_1b4,9,4), -1 < iVar1 &&
        (iVar1 = FUN_004231d0(&local_1b4,10,1), -1 < iVar1)) &&
       (iVar1 = FUN_004231d0(&local_1b4,0xb,0xca), -1 < iVar1)) &&
      (((iVar1 = FUN_004231d0(&local_1b4,0xc,0x82), -1 < iVar1 &&
        (iVar1 = FUN_004231d0(&local_1b4,0xd,4), -1 < iVar1)) &&
       ((iVar1 = FUN_004231d0(&local_1b4,0xe,4), -1 < iVar1 &&
        ((iVar1 = FUN_004231d0(&local_1b4,0xf,4), -1 < iVar1 &&
         (iVar1 = FUN_004231d0(&local_1b4,0x10,4), -1 < iVar1)))))))))) {
    if (local_1a4 != 0) {
      iVar2 = FUN_0041c000(0,1);
      iVar1 = param_3;
      if (iVar2 == 0) {
        *(undefined4 *)(param_3 + 4) = uStack_184;
        *(undefined4 *)(param_3 + 8) = uStack_174;
        *(undefined4 *)(param_3 + 0xc) = uStack_168;
        *(undefined4 *)(param_3 + 0x10) = uStack_160;
        *(undefined4 *)(param_3 + 0x1c) = uStack_180;
        *(undefined2 *)(param_3 + 0x28) = uStack_188;
        *(undefined4 *)(param_3 + 0x20) = uStack_164;
        *(undefined1 *)(param_3 + 0x2a) = uStack_1b5;
        *(undefined1 *)(param_3 + 0x2b) = uStack_1b6;
        *(float *)(param_3 + 0x24) = (float)bStack_1b7 * DAT_00a0f718;
        wcscpy((wchar_t *)(param_3 + 0x2c),awStack_d8);
        wcscpy((wchar_t *)(iVar1 + 0xf6),awStack_15c);
        *(undefined4 *)(iVar1 + 0x178) = uStack_16c;
        *(undefined4 *)(iVar1 + 0x17c) = uStack_17c;
        *(undefined4 *)(iVar1 + 0x14) = uStack_178;
        *(undefined4 *)(iVar1 + 0x18) = uStack_170;
      }
      if (local_1a4 != 0) {
        FUN_00422de0();
        FUN_0041bf70();
      }
      FUN_00423170();
      goto LAB_007d940f;
    }
    iVar1 = -0x7fffbffb;
  }
  FUN_00423170();
  FUN_007a4480(1,"DBReader: %u against %s",iVar1,"LoadOneVehicleTemplate::dcFetch::Open");
LAB_007d940f:
  local_4 = 0xffffffff;
  FUN_0041a3e0(&local_1b4);
  ExceptionList = local_c;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
