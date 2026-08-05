# Annotated low-level: FUN_008df6a0

| Field | Value |
|---|---|
| Stable ID | `aa_008df6a0` |
| VA | `0x008df6a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008df6a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008df6a0(void)

{
  int iVar1;
  int *piVar2;
  int *unaff_EDI;
  
  piVar2 = unaff_EDI + 0x177;
  iVar1 = 0x33;
  do {
    if (*piVar2 != 0) {
      (**(code **)(*unaff_EDI + 0xbc))(*piVar2);
    }
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = *(int **)unaff_EDI[0x1ac];
  if (piVar2 != (int *)unaff_EDI[0x1ac]) {
    do {
      (**(code **)(*unaff_EDI + 0xbc))(piVar2[2]);
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)unaff_EDI[0x1ac]);
  }
  FUN_004133c0(0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
