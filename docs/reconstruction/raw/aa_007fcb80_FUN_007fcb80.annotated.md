# Annotated low-level: FUN_007fcb80

| Field | Value |
|---|---|
| Stable ID | `aa_007fcb80` |
| VA | `0x007fcb80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fcb80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int FUN_007fcb80(void)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int unaff_ESI;
  
  if ((DAT_00d1b778 != (int *)0x0) &&
     (cVar3 = (**(code **)(*DAT_00d1b778 + 0x3d8))(), piVar2 = DAT_00d1d898, cVar3 != '\0')) {
    for (; piVar2 != DAT_00d1d89c; piVar2 = piVar2 + 1) {
      if (((*piVar2 != 0) && (iVar1 = *(int *)(*piVar2 + 0x534), iVar1 != 0)) &&
         (iVar1 == unaff_ESI)) {
        return *piVar2;
      }
    }
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
