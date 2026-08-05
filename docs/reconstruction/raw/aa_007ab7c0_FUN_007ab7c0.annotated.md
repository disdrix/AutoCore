# Annotated low-level: FUN_007ab7c0

| Field | Value |
|---|---|
| Stable ID | `aa_007ab7c0` |
| VA | `0x007ab7c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007ab7c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_007ab7c0(int *param_1,undefined4 *param_2)

{
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = *param_2;
  local_4 = param_2[1];
  (**(code **)(*param_1 + 0x110))(&local_8);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
