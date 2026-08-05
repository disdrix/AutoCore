# Annotated low-level: ov_open_callbacks

| Field | Value |
|---|---|
| Stable ID | `aa_006859ea` |
| VA | `0x006859ea` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006859ea`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void ov_open_callbacks(void)

{
                    /* WARNING: Could not recover jumptable at 0x006859ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ov_open_callbacks();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
