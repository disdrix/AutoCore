# Annotated low-level: nciFreeDecodeSase6500

| Field | Value |
|---|---|
| Stable ID | `aa_00710838` |
| VA | `0x00710838` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00710838`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void nciFreeDecodeSase6500(void)

{
                    /* WARNING: Could not recover jumptable at 0x00710838. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  nciFreeDecodeSase6500();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
