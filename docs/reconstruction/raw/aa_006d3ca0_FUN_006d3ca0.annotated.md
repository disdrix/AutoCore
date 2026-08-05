# Annotated low-level: FUN_006d3ca0

| Field | Value |
|---|---|
| Stable ID | `aa_006d3ca0` |
| VA | `0x006d3ca0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006d3ca0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __fastcall FUN_006d3ca0(int *param_1)

{
  undefined1 local_90 [124];
  undefined1 local_14;
  undefined1 local_13;
  
  local_13 = 0;
  local_14 = 0;
  if (param_1[1] == (param_1[2] & 0x7fffffffU)) {
    FUN_005b3370(param_1,0x80);
  }
  param_1[1] = param_1[1] + 1;
  FUN_006d3e80(local_90);
  return param_1[1] * 0x80 + -0x80 + *param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
