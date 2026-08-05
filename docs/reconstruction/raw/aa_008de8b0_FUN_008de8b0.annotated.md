# Annotated low-level: FUN_008de8b0

| Field | Value |
|---|---|
| Stable ID | `aa_008de8b0` |
| VA | `0x008de8b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008de8b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * FUN_008de8b0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b71c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,0);
  local_4 = 0;
  *param_1 = &PTR_FUN_00a3ccec;
  param_1[0x13f] = 0xf;
  param_1[0x140] = 1;
  FUN_008dddf0();
  NDUIWindow_ReloadInterface("i_d_esc.xml");
  ExceptionList = local_c;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
