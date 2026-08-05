# Annotated low-level: FUN_005fde50

| Field | Value |
|---|---|
| Stable ID | `aa_005fde50` |
| VA | `0x005fde50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fde50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005fde50(int param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  puStack_8 = &LAB_009a7d6d;
  pvStack_c = ExceptionList;
  iStack_4 = 6;
  ExceptionList = &pvStack_c;
  if (-1 < *(int *)(param_1 + 0x60)) {
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x58),*(int *)(param_1 + 0x60) * 4,0x12);
  }
  iStack_4._0_1_ = 5;
  if (-1 < *(int *)(param_1 + 0x54)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x4c),*(int *)(param_1 + 0x54) * 4,0x12);
  }
  iStack_4._0_1_ = 4;
  if (-1 < *(int *)(param_1 + 0x48)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x40),*(int *)(param_1 + 0x48) * 4,0x12);
  }
  iStack_4._0_1_ = 3;
  if (-1 < *(int *)(param_1 + 0x3c)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x34),*(int *)(param_1 + 0x3c) * 4,0x12);
  }
  iStack_4._0_1_ = 2;
  if (-1 < *(int *)(param_1 + 0x30)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x28),*(int *)(param_1 + 0x30) * 4,0x12);
  }
  iStack_4._0_1_ = 1;
  if (-1 < *(int *)(param_1 + 0x24)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x1c),*(int *)(param_1 + 0x24) * 4,0x12);
  }
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  if (-1 < *(int *)(param_1 + 0x18)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x10),*(int *)(param_1 + 0x18) * 4,0x12);
  }
  iStack_4 = 0xffffffff;
  if (-1 < *(int *)(param_1 + 0xc)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 4),*(int *)(param_1 + 0xc) * 4,0x12);
  }
  ExceptionList = pvStack_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
