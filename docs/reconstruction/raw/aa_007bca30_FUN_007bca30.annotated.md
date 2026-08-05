# Annotated low-level: FUN_007bca30

| Field | Value |
|---|---|
| Stable ID | `aa_007bca30` |
| VA | `0x007bca30` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007bca30`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall FUN_007bca30(char *param_1)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009adf4e;
  local_c = ExceptionList;
  if (*param_1 == '\0') {
    return 0x80004004;
  }
  if (DAT_00d1793c == '\0') {
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_4 = 0;
    ExceptionList = &local_c;
    FUN_004230d0(&local_24,&stack0x00000004);
    iVar1 = FUN_00422fb0(1,1,4);
    if ((iVar1 < 0) ||
       (iVar1 = FUN_0041b670(&local_24,param_1 + 0x28,0,0,&DAT_00a140c8,0,0), iVar1 < 0)) {
      FUN_00423170();
      FUN_007a4480(1,"DBReader: %u against %s",iVar1,"DeleteMapModule");
    }
    else {
      FUN_00423170();
    }
    local_4 = 0xffffffff;
    FUN_0041a4b0(&local_24);
    ExceptionList = local_c;
    return 0;
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
