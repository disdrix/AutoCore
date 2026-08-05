# Annotated low-level: FUN_008fa5f0

| Field | Value |
|---|---|
| Stable ID | `aa_008fa5f0` |
| VA | `0x008fa5f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008fa5f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008fa5f0(int *param_1)

{
  if (param_1[0x536] != 0) {
    FUN_00855810(0);
    (**(code **)(*(int *)param_1[0x536] + 0xcc))(0);
    (**(code **)(*param_1 + 0xb0))(param_1[0x536]);
  }
  (**(code **)(*param_1 + 0x3ac))();
  FUN_00792490();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
