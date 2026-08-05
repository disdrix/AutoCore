# Annotated low-level: ftol

| Field | Value |
|---|---|
| Stable ID | `aa_007195ec` |
| VA | `0x007195ec` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007195ec`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __cdecl ftol(void)

{
                    /* WARNING: Could not recover jumptable at 0x007195ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ftol();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
