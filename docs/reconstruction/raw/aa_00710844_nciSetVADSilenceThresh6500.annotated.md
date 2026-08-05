# Annotated low-level: nciSetVADSilenceThresh6500

| Field | Value |
|---|---|
| Stable ID | `aa_00710844` |
| VA | `0x00710844` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00710844`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void nciSetVADSilenceThresh6500(void)

{
                    /* WARNING: Could not recover jumptable at 0x00710844. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  nciSetVADSilenceThresh6500();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
