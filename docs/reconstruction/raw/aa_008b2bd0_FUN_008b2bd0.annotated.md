# Annotated low-level: FUN_008b2bd0

| Field | Value |
|---|---|
| Stable ID | `aa_008b2bd0` |
| VA | `0x008b2bd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008b2bd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008b2bd0(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009b659e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_00a4934c;
  local_4 = 0;
  if ((int *)param_1[0x146] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x146] + 0x58))();
    if ((undefined4 *)param_1[0x146] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x146])(1);
    }
    param_1[0x146] = 0;
  }
  if ((undefined4 *)param_1[0x14a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x14a])(1);
  }
  param_1[0x14a] = 0;
  *param_1 = &PTR_FUN_00a58c6c;
  local_4 = 0xffffffff;
  FUN_00792c20();
  ExceptionList = pvStack_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
