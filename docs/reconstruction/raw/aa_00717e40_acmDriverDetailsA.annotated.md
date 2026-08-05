# Annotated low-level: acmDriverDetailsA

| Field | Value |
|---|---|
| Stable ID | `aa_00717e40` |
| VA | `0x00717e40` |
| System | input-drive-control |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00717e40`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void acmDriverDetailsA(void)

{
                    /* WARNING: Could not recover jumptable at 0x00717e40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  acmDriverDetailsA();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
