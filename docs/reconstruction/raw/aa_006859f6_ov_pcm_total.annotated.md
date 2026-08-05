# Annotated low-level: ov_pcm_total

| Field | Value |
|---|---|
| Stable ID | `aa_006859f6` |
| VA | `0x006859f6` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006859f6`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void ov_pcm_total(void)

{
                    /* WARNING: Could not recover jumptable at 0x006859f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ov_pcm_total();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
