# Annotated low-level: FUN_0076bff0

| Field | Value |
|---|---|
| Stable ID | `aa_0076bff0` |
| VA | `0x0076bff0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0076bff0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0076bff0(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_00a9d184;
  if (*(char *)(unaff_ESI + 5) != '\0') {
    free((void *)unaff_ESI[1]);
  }
  *unaff_ESI = &PTR_LAB_00a9d774;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
