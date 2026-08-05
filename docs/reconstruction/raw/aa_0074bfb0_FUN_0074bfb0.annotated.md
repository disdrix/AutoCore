# Annotated low-level: FUN_0074bfb0

| Field | Value |
|---|---|
| Stable ID | `aa_0074bfb0` |
| VA | `0x0074bfb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0074bfb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0074bfb0(void)

{
  float *pfVar1;
  int unaff_EBX;
  float *unaff_ESI;
  
  pfVar1 = (float *)FUN_00972fa0(unaff_EBX);
  if ((pfVar1[2] - unaff_ESI[2]) * (pfVar1[2] - unaff_ESI[2]) +
      (*pfVar1 - *unaff_ESI) * (*pfVar1 - *unaff_ESI) +
      (pfVar1[1] - unaff_ESI[1]) * (pfVar1[1] - unaff_ESI[1]) <=
      *(float *)(unaff_EBX + 0xc) * *(float *)(unaff_EBX + 0xc)) {
    return 1;
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
