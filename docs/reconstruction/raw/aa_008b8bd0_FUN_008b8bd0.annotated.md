# Annotated low-level: FUN_008b8bd0

| Field | Value |
|---|---|
| Stable ID | `aa_008b8bd0` |
| VA | `0x008b8bd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008b8bd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int * FUN_008b8bd0(int *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b66a1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,0);
  local_4 = 0;
  *param_1 = (int)&PTR_FUN_00a47174;
  param_1[0x13f] = 5;
  param_1[0x140] = 1;
  param_1[0x143] = 0;
  param_1[0x144] = 1;
  *(undefined1 *)(param_1 + 0x148) = 1;
  FUN_008b8020();
  *(undefined1 *)(param_1 + 0x124) = 0;
  NDUIWindow_ReloadInterface("i_d_mail.xml");
  (**(code **)(*param_1 + 0x34c))();
  ExceptionList = local_c;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
