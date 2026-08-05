# Raw capture: FUN_005fc3d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fc3d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fc3d0` |
| **Canonical name** | `FUN_005fc3d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
