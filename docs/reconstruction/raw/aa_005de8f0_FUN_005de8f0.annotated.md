# Annotated low-level: FUN_005de8f0

| Field | Value |
|---|---|
| Stable ID | `aa_005de8f0` |
| VA | `0x005de8f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005de8f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_005de8f0(undefined1 *param_1)

{
  *param_1 = DAT_00bc56a4;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
