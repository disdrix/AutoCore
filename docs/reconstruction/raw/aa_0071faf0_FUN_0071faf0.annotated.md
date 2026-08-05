# Annotated low-level: FUN_0071faf0

| Field | Value |
|---|---|
| Stable ID | `aa_0071faf0` |
| VA | `0x0071faf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071faf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall FUN_0071faf0(uint param_1)

{
  int *piVar1;
  uint uVar2;
  int unaff_EDI;
  uint local_4;
  
  if (*(int *)(unaff_EDI + 0x10) == 0) {
    return 0;
  }
  uVar2 = 0;
  local_4 = param_1;
  if (*(int *)(unaff_EDI + 0x1c) != 0) {
    do {
      if (*(int *)(*(int *)(unaff_EDI + 0x10) + uVar2 * 4) != 0) {
        local_4 = 0;
        piVar1 = *(int **)(*(int *)(unaff_EDI + 0x10) + uVar2 * 4);
        (**(code **)(*piVar1 + 0x24))(piVar1,&local_4);
        if ((local_4 & 1) == 0) break;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(unaff_EDI + 0x1c));
  }
  if (uVar2 != *(uint *)(unaff_EDI + 0x1c)) {
    return *(undefined4 *)(*(int *)(unaff_EDI + 0x10) + uVar2 * 4);
  }
  CVOGReaction_RandomUnitScalar();
  uVar2 = FUN_00424830();
  return *(undefined4 *)(*(int *)(unaff_EDI + 0x10) + (uVar2 % *(uint *)(unaff_EDI + 0x1c)) * 4);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
