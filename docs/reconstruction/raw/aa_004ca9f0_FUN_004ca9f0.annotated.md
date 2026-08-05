# Annotated low-level: FUN_004ca9f0

| Field | Value |
|---|---|
| Stable ID | `aa_004ca9f0` |
| VA | `0x004ca9f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004ca9f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004ca9f0(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uStack_64;
  int iStack_5c;
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [4];
  void *pvStack_2c;
  int iStack_24;
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  puStack_18 = &LAB_009a1dc5;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  (**(code **)(*(int *)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) + 0x144))();
  FUN_0058e0b0();
  piVar1 = *(int **)(*(int *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1) + 0xe8a0);
  uStack_14 = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1d8))();
  }
  (**(code **)(*param_1 + 0x4c))(auStack_40,auStack_30);
  iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0x90,0x2c);
  *(undefined2 *)(iVar2 + 4) = 0x90;
  iStack_24._0_1_ = 1;
  iVar2 = FUN_00581220(&stack0xffffff90);
  param_1[0x95] = iVar2;
  iStack_24 = (uint)iStack_24._1_3_ << 8;
  FUN_0055ff20(iVar2);
  iStack_24 = 0xffffffff;
  if (-1 < iStack_5c) {
    (**(code **)(*DAT_00b05060 + 0x14))(uStack_64,iStack_5c * 8,0x12);
  }
  ExceptionList = pvStack_2c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
