# Annotated low-level: FUN_0065ebe0

| Field | Value |
|---|---|
| Stable ID | `aa_0065ebe0` |
| VA | `0x0065ebe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0065ebe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0065ebe0(int param_1,undefined4 *param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x60) = *param_2;
  *(undefined4 *)(param_1 + 100) = param_2[1];
  *(undefined4 *)(param_1 + 0x68) = param_2[2];
  *(undefined4 *)(param_1 + 0x6c) = param_2[3];
  FUN_005eb040(param_3);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
