# Annotated low-level: FUN_007bfa70

| Field | Value |
|---|---|
| Stable ID | `aa_007bfa70` |
| VA | `0x007bfa70` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007bfa70`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_007bfa70(char *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 *local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puVar1 = param_3;
  puStack_8 = &LAB_009ae190;
  local_c = ExceptionList;
  if (*param_1 == '\0') {
    return 0x80004004;
  }
  if (DAT_00d1793c != '\0') {
    return 0;
  }
  param_3 = (undefined4 *)*param_3;
  local_38 = 0;
  local_34 = 0;
  local_30 = (undefined4 *)0x0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = &local_38;
  local_18 = 0;
  local_1c = 0;
  local_14 = 0;
  local_10 = 0;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_004230d0(local_20,&param_3);
  iVar2 = FUN_00422fb0(1,1,4);
  if (((((-1 < iVar2) && (iVar2 = FUN_00422fb0(1,2,2), -1 < iVar2)) &&
       (iVar2 = FUN_00422fb0(1,3,2), -1 < iVar2)) &&
      ((iVar2 = FUN_00422fb0(1,4,2), -1 < iVar2 && (iVar2 = FUN_00422fb0(1,5,2), -1 < iVar2)))) &&
     ((iVar2 = FUN_00422fb0(1,6,2), -1 < iVar2 && (iVar2 = FUN_00422fb0(1,7,2), -1 < iVar2)))) {
    iVar2 = FUN_0041a810(&local_38,param_1 + 0x28,0,0,&DAT_00a140c8,0,0);
  }
  local_30 = &param_2;
  if ((-1 < iVar2) && (iVar2 = FUN_004231d0(&local_38,1,4), -1 < iVar2)) {
    if (local_28 != 0) {
      iVar2 = FUN_0041a9b0();
      if (iVar2 == 0) {
        *puVar1 = param_2;
        FUN_0041a990();
        FUN_00423170();
      }
      else {
        FUN_0041a990();
        FUN_00423170();
        FUN_007a4480(1,"DBReader: %u against %s",iVar2,"dcDamage_Insert::MoveFirst");
      }
      goto LAB_007bfce7;
    }
    iVar2 = -0x7fffbffb;
  }
  FUN_00423170();
  FUN_007a4480(1,"DBReader: %u against %s",iVar2,"dcDamage::Open");
LAB_007bfce7:
  local_4 = 0xffffffff;
  FUN_0041a3e0(&local_38);
  ExceptionList = local_c;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
