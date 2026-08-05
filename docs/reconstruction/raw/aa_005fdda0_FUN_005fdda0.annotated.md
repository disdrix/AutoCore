# Annotated low-level: FUN_005fdda0

| Field | Value |
|---|---|
| Stable ID | `aa_005fdda0` |
| VA | `0x005fdda0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fdda0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005fdda0(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009a7d93;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  if (-1 < (int)param_1[8]) {
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[6],param_1[8] * 4,0x12);
  }
  local_4 = local_4 & 0xffffff00;
  if (-1 < (int)param_1[5]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[3],param_1[5] << 4,0x12);
  }
  local_4 = 0xffffffff;
  if (-1 < (int)param_1[2]) {
    (**(code **)(*DAT_00b05060 + 0x14))(*param_1,param_1[2] << 4,0x12);
  }
  ExceptionList = pvStack_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
