# Annotated low-level: FUN_005fdaf0

| Field | Value |
|---|---|
| Stable ID | `aa_005fdaf0` |
| VA | `0x005fdaf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fdaf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005fdaf0(int param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a7ceb;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  if (-1 < *(int *)(param_1 + 0x2c)) {
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x24),*(int *)(param_1 + 0x2c) * 4,0x12);
  }
  local_4 = 0xffffffff;
  if (-1 < *(int *)(param_1 + 0x20)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x18),*(int *)(param_1 + 0x20) * 4,0x12);
  }
  ExceptionList = pvStack_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
