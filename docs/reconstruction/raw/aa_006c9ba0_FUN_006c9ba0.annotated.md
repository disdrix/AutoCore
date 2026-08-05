# Annotated low-level: FUN_006c9ba0

| Field | Value |
|---|---|
| Stable ID | `aa_006c9ba0` |
| VA | `0x006c9ba0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006c9ba0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006c9ba0(int param_1,float *param_2,undefined4 *param_3)

{
  if ((*(float *)(param_1 + 0x20) - *(float *)(param_1 + 0x10)) * *param_2 +
      (*(float *)(param_1 + 0x24) - *(float *)(param_1 + 0x14)) * param_2[1] +
      (*(float *)(param_1 + 0x28) - *(float *)(param_1 + 0x18)) * param_2[2] < g_flZero) {
    *param_3 = *(undefined4 *)(param_1 + 0x10);
    param_3[1] = *(undefined4 *)(param_1 + 0x14);
    param_3[2] = *(undefined4 *)(param_1 + 0x18);
    param_3[3] = *(undefined4 *)(param_1 + 0x1c);
    param_3[3] = 0x3f000000;
    return;
  }
  *param_3 = *(undefined4 *)(param_1 + 0x20);
  param_3[1] = *(undefined4 *)(param_1 + 0x24);
  param_3[2] = *(undefined4 *)(param_1 + 0x28);
  param_3[3] = *(undefined4 *)(param_1 + 0x2c);
  param_3[3] = 0x3f000010;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
