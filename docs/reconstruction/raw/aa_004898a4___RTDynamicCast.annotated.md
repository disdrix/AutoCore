# Annotated low-level: __RTDynamicCast

| Field | Value |
|---|---|
| Stable ID | `aa_004898a4` |
| VA | `0x004898a4` |
| System | skills-abilities |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004898a4`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __RTDynamicCast(void)

{
                    /* WARNING: Could not recover jumptable at 0x004898a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __RTDynamicCast();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
