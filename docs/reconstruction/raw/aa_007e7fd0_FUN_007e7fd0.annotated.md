# Annotated low-level: FUN_007e7fd0

| Field | Value |
|---|---|
| Stable ID | `aa_007e7fd0` |
| VA | `0x007e7fd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007e7fd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall
FUN_007e7fd0(char *param_1,undefined4 param_2,undefined4 param_3,undefined2 *param_4,
            undefined4 *param_5)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined2 uVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  wchar_t local_114 [66];
  wchar_t local_90 [66];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &DAT_009b0c10;
  local_c = ExceptionList;
  if (*param_1 == '\0') {
    iVar1 = -0x7fffbffc;
  }
  else if (DAT_00d1793c == '\0') {
    ExceptionList = &local_c;
    iVar1 = FUN_007e1fb0(param_2,param_3,param_5);
    if (-1 < iVar1) {
      local_130 = *param_5;
      wcscpy(local_114,param_4 + 8);
      pwVar2 = wcscpy(local_90,param_4 + 0x49);
      local_124 = CONCAT22(extraout_var,*param_4);
      local_120 = CONCAT22(extraout_var_00,param_4[1]);
      uVar3 = (undefined2)((uint)pwVar2 >> 0x10);
      local_12c = CONCAT22(uVar3,param_4[2]);
      local_148 = 0;
      local_118 = CONCAT22(extraout_var,param_4[3]);
      local_11c = CONCAT22(extraout_var_00,param_4[4]);
      local_128 = CONCAT22(uVar3,param_4[5]);
      local_144 = 0;
      local_140 = 0;
      local_13c = 0;
      local_138 = 0;
      local_134 = 0;
      local_4 = 0;
      FUN_004230d0(&local_148,&local_130);
      iVar1 = FUN_00422fb0(1,1,4);
      if (((((iVar1 < 0) || (iVar1 = FUN_00422fb0(1,2,0x82), iVar1 < 0)) ||
           (iVar1 = FUN_00422fb0(1,3,0x82), iVar1 < 0)) ||
          (((iVar1 = FUN_00422fb0(1,4,1), iVar1 < 0 || (iVar1 = FUN_00422fb0(1,5,1), iVar1 < 0)) ||
           ((iVar1 = FUN_00422fb0(1,6,1), iVar1 < 0 ||
            ((iVar1 = FUN_00422fb0(1,7,2), iVar1 < 0 || (iVar1 = FUN_00422fb0(1,8,2), iVar1 < 0)))))
           ))) || ((iVar1 = FUN_00422fb0(1,9,2), iVar1 < 0 ||
                   ((((iVar1 = FUN_00422fb0(1,10,2), iVar1 < 0 ||
                      (iVar1 = FUN_00422fb0(1,0xb,2), iVar1 < 0)) ||
                     (iVar1 = FUN_00422fb0(1,0xc,2), iVar1 < 0)) ||
                    (iVar1 = FUN_0041b670(&local_148,param_1 + 0x28,0,0,&DAT_00a140c8,0,0),
                    iVar1 < 0)))))) {
        FUN_00423170();
        FUN_007a4480(1,"DBReader: %u against %s",iVar1,"dcWheelSet_Insert::Open");
      }
      else {
        FUN_00423170();
      }
      local_4 = 0xffffffff;
      FUN_0041a4b0(&local_148);
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 0;
  }
  ExceptionList = local_c;
  return iVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
