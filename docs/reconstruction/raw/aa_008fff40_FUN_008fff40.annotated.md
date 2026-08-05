# Annotated low-level: FUN_008fff40

| Field | Value |
|---|---|
| Stable ID | `aa_008fff40` |
| VA | `0x008fff40` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008fff40`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * FUN_008fff40(undefined4 *param_1)

{
  undefined4 uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b7c23;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,0);
  *param_1 = &PTR_FUN_00a33cec;
  param_1[0x1ef] = 0;
  param_1[0x1f0] = 0;
  param_1[0x1f1] = 0;
  param_1[0x1f5] = 0;
  param_1[0x1f6] = 0;
  param_1[0x1f7] = 0;
  uVar1 = DAT_00aaabe8;
  local_4 = 2;
  param_1[0x140] = 1;
  param_1[0x165] = uVar1;
  param_1[0x13f] = 0x10;
  param_1[0x146] = 7;
  param_1[0x147] = 7;
  param_1[0x166] = 0;
  param_1[0x1ec] = 0xffffffff;
  param_1[0x1f2] = 0xffffffff;
  param_1[0x1f8] = 0xffffffff;
  FUN_008fd530();
  FUN_008ffe20("i_d_body.xml");
  ExceptionList = local_c;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
