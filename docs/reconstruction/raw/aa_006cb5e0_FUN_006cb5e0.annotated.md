# Annotated low-level: FUN_006cb5e0

| Field | Value |
|---|---|
| Stable ID | `aa_006cb5e0` |
| VA | `0x006cb5e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006cb5e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall FUN_006cb5e0(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  param_1[2] = param_2;
  *(undefined2 *)((int)param_1 + 6) = 1;
  *param_1 = &PTR_FUN_00a0d914;
  iVar3 = 0;
  param_1[0x1364] = 0;
  param_1[0x1365] = 0;
  param_1[0x1366] = 0x80000000;
  param_1[0x1369] = 0x80000000;
  param_1[0x1367] = 0;
  param_1[0x1368] = 0;
  *(undefined1 *)(param_1 + 0x1363) = 0;
  *(undefined1 *)((int)param_1 + 0x4d8d) = 1;
  piVar1 = param_1 + 3;
  iVar4 = 8;
  do {
    iVar5 = 8;
    do {
      *piVar1 = param_3;
      if (param_3 != 0) {
        *(short *)(param_3 + 6) = *(short *)(param_3 + 6) + 1;
      }
      piVar1 = piVar1 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  piVar1 = param_1 + 0x43;
  do {
    bVar2 = (byte)iVar3;
    iVar3 = iVar3 + 1;
    *piVar1 = 1 << (bVar2 & 0x1f);
    piVar1 = piVar1 + 1;
  } while (iVar3 < 0x20);
  FUN_006cafd0();
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
