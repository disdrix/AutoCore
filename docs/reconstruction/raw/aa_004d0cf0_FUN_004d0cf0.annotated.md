# Annotated low-level: FUN_004d0cf0

| Field | Value |
|---|---|
| Stable ID | `aa_004d0cf0` |
| VA | `0x004d0cf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004d0cf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int * FUN_004d0cf0(undefined4 param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint auStack_64 [5];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  char *pcStack_44;
  uint local_2c [4];
  undefined4 local_1c;
  undefined1 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a1f8f;
  pvStack_c = ExceptionList;
  pcStack_44 = "GenerateLootItem (type)";
  uStack_48 = 0x4d0d22;
  ExceptionList = &pvStack_c;
  FUN_0076cf00();
  local_4 = 0;
  if (param_2 < 1) {
    param_2 = 1;
  }
  local_2c[3] = param_1;
  local_2c[0] = 0;
  local_1c = 0;
  local_14 = 0;
  local_10 = 0;
  local_18 = 0;
  local_2c[1] = ((int)(param_2 - 5U) < 1) - 1 & param_2 - 5U;
  local_2c[2] = param_2 + 5;
  if (0x4f < param_2 + 5) {
    local_2c[2] = 0x50;
  }
  pcStack_44 = (char *)0x1;
  puVar3 = local_2c;
  puVar4 = auStack_64;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_005e0580();
  uStack_50 = FUN_005e1030();
  pcStack_44 = (char *)0x0;
  uStack_48 = 0x3f000000;
  uStack_4c = param_3;
  auStack_64[3] = 0x4d0daf;
  piVar1 = (int *)FUN_0050b6c0();
  if (piVar1 != (int *)0x0) {
    uStack_48 = 0x4d0dc0;
    (**(code **)(*piVar1 + 0x218))();
  }
  local_4 = 0xffffffff;
  pcStack_44 = (char *)0x4d0dd1;
  FUN_0076cef0();
  ExceptionList = pvStack_c;
  return piVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
