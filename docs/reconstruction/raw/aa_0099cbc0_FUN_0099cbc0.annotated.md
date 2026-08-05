# Annotated low-level: FUN_0099cbc0

| Field | Value |
|---|---|
| Stable ID | `aa_0099cbc0` |
| VA | `0x0099cbc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0099cbc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4
FUN_0099cbc0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009b1211;
  local_c = ExceptionList;
  uStack_1c = param_2;
  local_4 = 1;
  uStack_20 = 0x99cbfa;
  ExceptionList = &local_c;
  iVar1 = FUN_0099ed40();
  if (iVar1 < 0) {
    local_4 = 0xffffffff;
    uStack_1c = 0x99cc0d;
    FUN_0040add0();
    ExceptionList = local_c;
    return 0xffffffff;
  }
  uStack_1c = param_5;
  uStack_20 = param_4;
  uStack_24 = param_5;
  FUN_0040aef0(&uStack_24);
  FUN_0099cae0();
  local_4 = 0xffffffff;
  uStack_1c = 0x99cc56;
  FUN_0040add0();
  ExceptionList = local_c;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
