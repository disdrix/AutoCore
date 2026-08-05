# Annotated low-level: FUN_005abfa0

| Field | Value |
|---|---|
| Stable ID | `aa_005abfa0` |
| VA | `0x005abfa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005abfa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall FUN_005abfa0(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a655b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_009d8da8;
  *(undefined1 *)(param_1 + 0x237) = 0;
  *(undefined1 *)(param_1 + 0x277) = 0;
  *(undefined1 *)(param_1 + 0x46b) = 0;
  *(undefined1 *)(param_1 + 0x4ab) = 0;
  *(undefined1 *)(param_1 + 0x69f) = 0;
  *(undefined1 *)(param_1 + 0x6df) = 0;
  *(undefined1 *)(param_1 + 0x8d3) = 0;
  *(undefined1 *)(param_1 + 0x913) = 0;
  *(undefined1 *)(param_1 + 0xb07) = 0;
  *(undefined1 *)(param_1 + 0xb47) = 0;
  *(undefined1 *)(param_1 + 0xd3b) = 0;
  *(undefined1 *)(param_1 + 0xd7b) = 0;
  *(undefined1 *)(param_1 + 0xf6f) = 0;
  *(undefined1 *)(param_1 + 0xfaf) = 0;
  *(undefined1 *)(param_1 + 0x11a3) = 0;
  *(undefined1 *)(param_1 + 0x11e3) = 0;
  param_1[0x143f] = 0;
  param_1[0x1440] = 0;
  param_1[0x1441] = 0;
  local_4 = 0;
  iVar1 = FUN_0044e100();
  param_1[0x1443] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(param_1[0x1443] + 4) = param_1[0x1443];
  *(undefined4 *)param_1[0x1443] = param_1[0x1443];
  *(undefined4 *)(param_1[0x1443] + 8) = param_1[0x1443];
  param_1[0x1444] = 0;
  param_1[2] = param_2;
  FUN_005a9e70();
  FUN_005ab110();
  ExceptionList = local_c;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
