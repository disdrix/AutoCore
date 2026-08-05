# Annotated low-level: VehicleEntity_SetFlag_109

| Field | Value |
|---|---|
| Stable ID | `aa_004f3630` |
| VA | `0x004f3630` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004f3630`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall VehicleEntity_SetFlag_109(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x109) = param_2;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
