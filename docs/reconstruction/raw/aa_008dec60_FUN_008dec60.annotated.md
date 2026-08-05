# Annotated low-level: FUN_008dec60

| Field | Value |
|---|---|
| Stable ID | `aa_008dec60` |
| VA | `0x008dec60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008dec60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * FUN_008dec60(undefined4 *param_1,undefined4 param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b71ef;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_00a3c6bc;
  param_1[0x13f] = 5;
  param_1[0x140] = 1;
  FUN_008de9f0();
  NDUIWindow_ReloadInterface("i_d_e.xml");
  ExceptionList = local_c;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
