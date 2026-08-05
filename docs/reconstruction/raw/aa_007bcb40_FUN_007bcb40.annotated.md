# Annotated low-level: FUN_007bcb40

| Field | Value |
|---|---|
| Stable ID | `aa_007bcb40` |
| VA | `0x007bcb40` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007bcb40`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_007bcb40(char *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 local_18a;
  undefined1 local_189;
  undefined4 uStack_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 *local_17c;
  undefined4 local_178;
  int local_174;
  undefined4 local_170;
  undefined4 *local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  char *local_150;
  wchar_t local_14c [32];
  wchar_t local_10c [128];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009adf65;
  local_c = ExceptionList;
  if (DAT_00d1793c != '\0') {
    return 0;
  }
  local_154 = param_2[1];
  local_18a = *(undefined1 *)(param_2 + 2);
  ExceptionList = &local_c;
  local_150 = param_1;
  wcscpy(local_14c,(wchar_t *)((int)param_2 + 10));
  local_189 = *(undefined1 *)(param_2 + 0x13);
  wcscpy(local_10c,(wchar_t *)((int)param_2 + 0x4e));
  local_158 = param_2[0x54];
  if (*param_1 == '\0') {
    ExceptionList = local_c;
    return 0x80004004;
  }
  local_16c = &local_184;
  local_184 = 0;
  local_180 = 0;
  local_17c = (undefined4 *)0x0;
  local_178 = 0;
  local_174 = 0;
  local_170 = 0;
  local_164 = 0;
  local_168 = 0;
  local_160 = 0;
  local_15c = 0;
  local_4 = 0;
  FUN_004230d0(local_16c,&local_18a);
  iVar1 = FUN_00422fb0(1,1,1);
  if (((((-1 < iVar1) && (iVar1 = FUN_00422fb0(1,2,4), -1 < iVar1)) &&
       (iVar1 = FUN_00422fb0(1,3,0x40), -1 < iVar1)) &&
      ((iVar1 = FUN_00422fb0(1,4,1), -1 < iVar1 && (iVar1 = FUN_00422fb0(1,5,0x100), -1 < iVar1))))
     && (iVar1 = FUN_00422fb0(1,6,4), -1 < iVar1)) {
    iVar1 = FUN_0041a810(&local_184,local_150 + 0x28,0,0,&DAT_00a140c8,0,0);
  }
  local_17c = &uStack_188;
  if ((-1 < iVar1) && (iVar1 = FUN_004231d0(&local_184,1,4), -1 < iVar1)) {
    if (local_174 != 0) {
      iVar1 = FUN_0041a9b0();
      if (iVar1 == 0) {
        *param_3 = uStack_188;
        *param_2 = uStack_188;
        FUN_0041a990();
        FUN_00423170();
      }
      else {
        FUN_0041a990();
        FUN_00423170();
        FUN_007a4480(1,"DBReader: %u against %s",iVar1,"InsertMapModule::MoveFirst");
      }
      goto LAB_007bcdb6;
    }
    iVar1 = -0x7fffbffb;
  }
  FUN_00423170();
  FUN_007a4480(1,"DBReader: %u against %s",iVar1,"InsertMapModule");
LAB_007bcdb6:
  local_4 = 0xffffffff;
  FUN_0041a3e0(&local_184);
  ExceptionList = local_c;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
