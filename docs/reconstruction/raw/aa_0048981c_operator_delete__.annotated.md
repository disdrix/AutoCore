# Annotated low-level: operator_delete__

| Field | Value |
|---|---|
| Stable ID | `aa_0048981c` |
| VA | `0x0048981c` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0048981c`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __cdecl operator_delete__(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0048981c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete__(param_1);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
