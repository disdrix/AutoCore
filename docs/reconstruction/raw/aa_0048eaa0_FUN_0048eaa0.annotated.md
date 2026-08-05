# Annotated low-level: FUN_0048eaa0

| Field | Value |
|---|---|
| Stable ID | `aa_0048eaa0` |
| VA | `0x0048eaa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0048eaa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0048eaa0(undefined1 param_1)

{
  DAT_00b04810 = param_1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
