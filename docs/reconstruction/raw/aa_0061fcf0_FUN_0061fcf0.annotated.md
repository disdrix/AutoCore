# Annotated low-level: FUN_0061fcf0

| Field | Value |
|---|---|
| Stable ID | `aa_0061fcf0` |
| VA | `0x0061fcf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0061fcf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0061fcf0(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(float *)(param_1 + 0x160) != g_flZero) {
    FUN_005781b0(param_3,param_2,"virus decays)\n",0);
  }
  if (*(float *)(param_1 + 0x164) != g_flZero) {
    FUN_005781b0(param_3,param_2,"op_scalar_2] (max virus jumps)\n",1);
  }
  FUN_0061a370(param_1,param_2,param_3);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
