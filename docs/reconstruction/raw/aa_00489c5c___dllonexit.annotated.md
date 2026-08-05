# Annotated low-level: __dllonexit

| Field | Value |
|---|---|
| Stable ID | `aa_00489c5c` |
| VA | `0x00489c5c` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00489c5c`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __dllonexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00489c5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __dllonexit();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
