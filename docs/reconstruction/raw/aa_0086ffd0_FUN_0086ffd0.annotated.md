# Annotated low-level: FUN_0086ffd0

| Field | Value |
|---|---|
| Stable ID | `aa_0086ffd0` |
| VA | `0x0086ffd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0086ffd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * FUN_0086ffd0(undefined4 *param_1)

{
  undefined4 uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b8c7f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,0);
  local_4 = 0;
  *param_1 = &PTR_FUN_00a5d3ec;
  uVar1 = FUN_0040fb90();
  param_1[0x146] = uVar1;
  param_1[0x147] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  param_1[0x13f] = 0xf;
  param_1[0x140] = 1;
  FUN_0086e840();
  *(undefined1 *)(param_1 + 0x144) = 0;
  param_1[0x143] = 0;
  NDUIWindow_ReloadInterface("i_d_arena/i_d_arena_selection.xml");
  ExceptionList = local_c;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
