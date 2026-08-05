# Annotated low-level: FUN_004ba6f0

| Field | Value |
|---|---|
| Stable ID | `aa_004ba6f0` |
| VA | `0x004ba6f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004ba6f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_004ba6f0(undefined4 *param_1)

{
  if ((_DAT_00b0372c & 1) == 0) {
    _DAT_00b0372c = _DAT_00b0372c | 1;
  }
  _DAT_00b0371c = *param_1;
  _DAT_00b03720 = param_1[1];
  _DAT_00b03724 = param_1[2];
  _DAT_00b03728 = param_1[3];
  return &DAT_00b0371c;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
