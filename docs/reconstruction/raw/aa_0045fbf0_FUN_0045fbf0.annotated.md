# Annotated low-level: FUN_0045fbf0

| Field | Value |
|---|---|
| Stable ID | `aa_0045fbf0` |
| VA | `0x0045fbf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0045fbf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0045fbf0(void)

{
  void *in_EAX;
  
                    /* WARNING: Subroutine does not return */
  operator_delete(in_EAX);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
