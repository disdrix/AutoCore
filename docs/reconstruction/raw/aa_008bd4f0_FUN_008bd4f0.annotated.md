# Annotated low-level: FUN_008bd4f0

| Field | Value |
|---|---|
| Stable ID | `aa_008bd4f0` |
| VA | `0x008bd4f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008bd4f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008bd4f0(int *param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  piVar2 = DAT_00d1d8dc;
  for (uVar3 = 0;
      (iVar1 = param_1[0x154], iVar1 != 0 && (uVar3 < (uint)(param_1[0x155] - iVar1 >> 2)));
      uVar3 = uVar3 + 1) {
    iVar1 = *(int *)(iVar1 + uVar3 * 4);
    if (((iVar1 == 0) || (piVar2 == (int *)0x0)) || (iVar1 == piVar2[0x146])) {
      DAT_00d1d8f4 = 1;
      DAT_00d1d8f5 = 0;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(0);
        piVar2 = DAT_00d1d8dc;
      }
    }
  }
  param_1[0x144] = -1;
  param_1[0x145] = -1;
  (**(code **)(*param_1 + 0x3ac))();
  FUN_00792490();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
