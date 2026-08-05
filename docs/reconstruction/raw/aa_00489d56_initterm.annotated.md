# Annotated low-level: initterm

| Field | Value |
|---|---|
| Stable ID | `aa_00489d56` |
| VA | `0x00489d56` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00489d56`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __cdecl initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00489d56. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  initterm();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
