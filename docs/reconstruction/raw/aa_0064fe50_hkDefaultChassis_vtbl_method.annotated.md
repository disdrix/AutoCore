# Annotated low-level: hkDefaultChassis_vtbl_method

| Field | Value |
|---|---|
| Stable ID | `aa_0064fe50` |
| VA | `0x0064fe50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0064fe50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void hkDefaultChassis_vtbl_method(undefined4 param_1,undefined4 param_2)

{
  thunk_FUN_0065ea90(param_2);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
