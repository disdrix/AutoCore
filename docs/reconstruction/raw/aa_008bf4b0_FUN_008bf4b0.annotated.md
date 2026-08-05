# Annotated low-level: FUN_008bf4b0

| Field | Value |
|---|---|
| Stable ID | `aa_008bf4b0` |
| VA | `0x008bf4b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008bf4b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int * FUN_008bf4b0(int *param_1,undefined4 param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b68f7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,param_2);
  *param_1 = (int)&PTR_FUN_00a44f04;
  param_1[0x14b] = 0;
  param_1[0x14c] = 0;
  param_1[0x14d] = 0;
  local_4 = 1;
  param_1[0x13f] = 0;
  param_1[0x140] = 2;
  FUN_008bebc0();
  NDUIWindow_ReloadInterface("i_d_inv_loot_queue.xml");
  (**(code **)(*param_1 + 0x448))();
  (**(code **)(*param_1 + 0x34c))();
  *(undefined1 *)((int)param_1 + 0xc5) = 1;
  *(undefined1 *)(param_1 + 0x31) = 0;
  param_1[0x149] = 0;
  ExceptionList = local_c;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
