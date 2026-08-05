# Annotated low-level: __RTtypeid

| Field | Value |
|---|---|
| Stable ID | `aa_004898ee` |
| VA | `0x004898ee` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004898ee`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __RTtypeid(void)

{
                    /* WARNING: Could not recover jumptable at 0x004898ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __RTtypeid();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
