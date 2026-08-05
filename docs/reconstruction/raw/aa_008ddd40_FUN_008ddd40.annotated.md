# Annotated low-level: FUN_008ddd40

| Field | Value |
|---|---|
| Stable ID | `aa_008ddd40` |
| VA | `0x008ddd40` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008ddd40`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * FUN_008ddd40(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b70c7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,0);
  local_4 = 0;
  *param_1 = &PTR_FUN_00a3d3fc;
  param_1[0x13f] = 0;
  param_1[0x140] = 2;
  param_1[0x12e] = 0;
  param_1[0x12f] = 0;
  param_1[0x12d] = 0;
  param_1[0x141] = 0;
  param_1[0x142] = 0;
  param_1[0x143] = 0;
  param_1[0x145] = 0;
  param_1[0x144] = 0;
  NDUIWindow_ReloadInterface("i_d_et.xml");
  ExceptionList = local_c;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
