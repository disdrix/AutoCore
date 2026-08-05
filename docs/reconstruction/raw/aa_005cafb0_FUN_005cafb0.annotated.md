# Annotated low-level: FUN_005cafb0

| Field | Value |
|---|---|
| Stable ID | `aa_005cafb0` |
| VA | `0x005cafb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005cafb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005cafb0(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0x14 + param_1) + 0x3c);
  if ((iVar2 != 0) &&
     (((sVar1 = *(short *)(iVar2 + 0x3f4), sVar1 == 10 || (sVar1 == 0xb)) &&
      (iVar2 = FUN_004ce940(), iVar2 != 0)))) {
    iVar2 = FUN_005c9a00();
    if ((*(int *)(iVar2 + 4) != 0) && (*(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2 != 0)) {
      iVar2 = FUN_005c9a00();
      iVar2 = *(int *)(iVar2 + 8);
      iVar3 = FUN_005c9a00();
      if ((iVar2 != *(int *)(iVar3 + 4)) &&
         (iVar2 = FUN_005092b0(*(undefined2 *)(iVar2 + -4)), 0 < (short)iVar2)) {
        iVar3 = FUN_0040f540();
        FUN_00413f00(iVar3 - iVar2);
      }
    }
  }
  iVar2 = FUN_005c9a00();
  if ((*(int *)(iVar2 + 4) != 0) && (*(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2 != 0)) {
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + -4;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
