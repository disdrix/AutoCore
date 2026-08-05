# Raw capture: FUN_005fa6e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fa6e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fa6e0` |
| **Canonical name** | `FUN_005fa6e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __fastcall FUN_005fa6e0(undefined4 *param_1)

{
  float fVar1;
  float local_20 [7];
  
  local_20[0] = g_flOne;
  local_20[1] = 0.0;
  local_20[2] = 0.0;
  local_20[3] = 0.0;
  FUN_00567ce0(local_20,0);
  *(undefined1 *)(param_1 + 0x20) = 0;
  fVar1 = g_flOne;
  param_1[0x21] = g_flOne;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  *(undefined1 *)(param_1 + 0x2a) = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[0xb] = 0;
  param_1[10] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = fVar1;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = fVar1;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = fVar1;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = fVar1;
  param_1[0x1b] = 0;
  return param_1;
}
```
