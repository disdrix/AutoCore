# Annotated low-level: _CIacos

| Field | Value |
|---|---|
| Stable ID | `aa_006a3e26` |
| VA | `0x006a3e26` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006a3e26`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void _CIacos(void)

{
                    /* WARNING: Could not recover jumptable at 0x006a3e26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _CIacos();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
