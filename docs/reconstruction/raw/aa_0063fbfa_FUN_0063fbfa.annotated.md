# Annotated low-level: FUN_0063fbfa

| Field | Value |
|---|---|
| Stable ID | `aa_0063fbfa` |
| VA | `0x0063fbfa` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0063fbfa`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __fastcall FUN_0063fbfa(undefined4 *param_1)

{
  undefined4 in_EAX;
  bool in_ZF;
  
  param_1[5] = in_EAX;
  param_1[2] = in_EAX;
  *param_1 = in_EAX;
  if (!in_ZF) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1,*(undefined2 *)(param_1 + 1),0x10);
  }
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
