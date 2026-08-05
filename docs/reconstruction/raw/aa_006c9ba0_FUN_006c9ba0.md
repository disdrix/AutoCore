# Raw capture: FUN_006c9ba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c9ba0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006c9ba0` |
| **Canonical name** | `FUN_006c9ba0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
