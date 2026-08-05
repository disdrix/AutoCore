# Annotated low-level: ov_raw_seek

| Field | Value |
|---|---|
| Stable ID | `aa_00685a02` |
| VA | `0x00685a02` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00685a02`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void ov_raw_seek(void)

{
                    /* WARNING: Could not recover jumptable at 0x00685a02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ov_raw_seek();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
