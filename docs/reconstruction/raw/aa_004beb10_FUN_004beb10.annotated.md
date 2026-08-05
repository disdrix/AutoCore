# Annotated low-level: FUN_004beb10

| Field | Value |
|---|---|
| Stable ID | `aa_004beb10` |
| VA | `0x004beb10` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004beb10`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004beb10(int param_1,int param_2)

{
  char cVar1;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a1852;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0076cf00("BuildGlom");
  local_4 = 0;
  if (*(char *)(param_1 + 0x570) != '\0') {
    FUN_004bde20();
  }
  if (((*(char *)(param_1 + 0x571) != '\0') ||
      ((*(float *)(param_1 + 0x5c8) <= DAT_00aef954 + _DAT_00aefa4c &&
       ((*(char *)(param_1 + 0x572) != '\0' || (*(char *)(param_1 + 0x573) != '\0')))))) &&
     (0 < param_2)) {
    if ((DAT_00b03778 & 1) == 0) {
      DAT_00b03778 = DAT_00b03778 | 1;
      local_4._0_1_ = 1;
      FUN_0076c500(1000);
      local_4 = (uint)local_4._1_3_ << 8;
    }
    FUN_0076c4d0();
    if ((DAT_00b03740 == '\0') || (*(char *)(param_1 + 0x571) == '\0')) {
      FUN_004bdb10();
      *(undefined1 *)(param_1 + 0x571) = 0;
    }
    else {
      cVar1 = FUN_004bdb70(&DAT_00b03748,&param_2);
      if (cVar1 != '\0') goto LAB_004bec8c;
    }
    if (*(float *)(param_1 + 0x5c8) <= DAT_00aef954 + _DAT_00aefa4c) {
      if (*(char *)(param_1 + 0x572) != '\0') {
        cVar1 = FUN_004be440(&DAT_00b03748,&param_2);
        if (cVar1 != '\0') goto LAB_004bec8c;
        FUN_004bdf80(*(undefined4 *)(param_1 + 0x5c8));
      }
      if (*(char *)(param_1 + 0x573) != '\0') {
        cVar1 = FUN_004be7d0(&DAT_00b03748,&param_2);
        if (cVar1 != '\0') goto LAB_004bec8c;
        FUN_004bdf80(*(undefined4 *)(param_1 + 0x5c8));
      }
    }
    *(undefined1 *)(param_1 + 0x5b0) = 1;
  }
LAB_004bec8c:
  local_4 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
