# Annotated low-level: nciGetInfoSase6500

| Field | Value |
|---|---|
| Stable ID | `aa_0071085c` |
| VA | `0x0071085c` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071085c`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void nciGetInfoSase6500(void)

{
                    /* WARNING: Could not recover jumptable at 0x0071085c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  nciGetInfoSase6500();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
