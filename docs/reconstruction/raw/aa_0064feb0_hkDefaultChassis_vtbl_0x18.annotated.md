# Annotated low-level: hkDefaultChassis_vtbl_0x18

| Field | Value |
|---|---|
| Stable ID | `aa_0064feb0` |
| VA | `0x0064feb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0064feb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void hkDefaultChassis_vtbl_0x18(int param_1)

{
  if (param_1 != 0) {
    FUN_0065eb10();
    return;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
