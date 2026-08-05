# Annotated low-level: FUN_004cf2a0

| Field | Value |
|---|---|
| Stable ID | `aa_004cf2a0` |
| VA | `0x004cf2a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004cf2a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_004cf2a0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a1f21;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (DAT_00b037ec == 0) {
    ExceptionList = &pvStack_c;
    pvVar1 = operator_new(0x2c);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      DAT_00b037ec = 0;
    }
    else {
      DAT_00b037ec = FUN_00568920(DAT_00b041fc,1,pvVar1);
    }
  }
  local_4 = 0xffffffff;
  FUN_00568670(param_1,param_2,param_3);
  ExceptionList = pvStack_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
