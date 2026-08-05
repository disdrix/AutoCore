# Annotated low-level: nciInjectSilence6500

| Field | Value |
|---|---|
| Stable ID | `aa_0071087a` |
| VA | `0x0071087a` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071087a`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void nciInjectSilence6500(void)

{
                    /* WARNING: Could not recover jumptable at 0x0071087a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  nciInjectSilence6500();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
