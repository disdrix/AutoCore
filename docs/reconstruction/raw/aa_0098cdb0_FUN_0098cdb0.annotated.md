# Annotated low-level: FUN_0098cdb0

| Field | Value |
|---|---|
| Stable ID | `aa_0098cdb0` |
| VA | `0x0098cdb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0098cdb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * FUN_0098cdb0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b6867;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_008a7640(param_1);
  *param_1 = &PTR_FUN_00a45a44;
  ExceptionList = local_c;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
