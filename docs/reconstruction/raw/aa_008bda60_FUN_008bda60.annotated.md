# Annotated low-level: FUN_008bda60

| Field | Value |
|---|---|
| Stable ID | `aa_008bda60` |
| VA | `0x008bda60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008bda60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008bda60(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int unaff_EDI;
  
  piVar4 = (int *)(unaff_EDI + 0x56c);
  iVar3 = 0;
  do {
    if (*(int *)(unaff_EDI + 0x550) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(int *)(unaff_EDI + 0x554) - *(int *)(unaff_EDI + 0x550) >> 2;
    }
    uVar2 = *(int *)(unaff_EDI + 0x548) + iVar3;
    if (uVar2 < uVar1) {
      FUN_008bd580(iVar3,*(undefined4 *)(*(int *)(unaff_EDI + 0x550) + uVar2 * 4));
    }
    else {
      if (piVar4[-4] != 0) {
        (**(code **)(*(int *)piVar4[-4] + 4))(0);
      }
      if (*piVar4 != 0) {
        (**(code **)(*(int *)*piVar4 + 4))(0);
      }
      if (piVar4[4] != 0) {
        (**(code **)(*(int *)piVar4[4] + 4))(0);
      }
      if (piVar4[8] != 0) {
        (**(code **)(*(int *)piVar4[8] + 4))(0);
      }
      if (piVar4[0xc] != 0) {
        (**(code **)(*(int *)piVar4[0xc] + 4))(0);
      }
    }
    iVar3 = iVar3 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar3 < 4);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
