# Annotated low-level: FUN_006a3cde

| Field | Value |
|---|---|
| Stable ID | `aa_006a3cde` |
| VA | `0x006a3cde` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006a3cde`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */

void FUN_006a3cde(void)

{
  __security_error_handler(1,0);
                    /* WARNING: Subroutine does not return */
  ExitProcess(3);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
