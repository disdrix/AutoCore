# Annotated low-level: nciEncodeSase6500

| Field | Value |
|---|---|
| Stable ID | `aa_00710868` |
| VA | `0x00710868` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00710868`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void nciEncodeSase6500(void)

{
                    /* WARNING: Could not recover jumptable at 0x00710868. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  nciEncodeSase6500();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
