# Annotated low-level: FUN_005fc3d0

| Field | Value |
|---|---|
| Stable ID | `aa_005fc3d0` |
| VA | `0x005fc3d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fc3d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_005fc3d0(int param_1,undefined4 param_2,float *param_3)

{
  *param_3 = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +
                                0x3c) + 0x6a8) * *(float *)(param_1 + 0x1fc);
  param_3[1] = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +
                                  0x3c) + 0x6ac) * *(float *)(param_1 + 0x1fc);
  param_3[2] = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +
                                  0x3c) + 0x6b4) * *(float *)(param_1 + 0x1fc);
  param_3[9] = *param_3;
  param_3[3] = (float)((int)*(short *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac
                                                        + param_1) + 0x3c) + 0x69a) +
                      *(int *)(param_1 + 0x218));
  param_3[4] = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +
                                  0x3c) + 0x6a0);
  param_3[5] = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +
                                  0x3c) + 0x6a4);
  param_3[6] = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +
                                  0x3c) + 0x6b8);
  param_3[7] = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +
                                  0x3c) + 0x6bc);
  param_3[8] = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +
                                  0x3c) + 0x6c0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
