# Annotated low-level: ov_clear

| Field | Value |
|---|---|
| Stable ID | `aa_006859de` |
| VA | `0x006859de` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006859de`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void ov_clear(void)

{
                    /* WARNING: Could not recover jumptable at 0x006859de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ov_clear();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
