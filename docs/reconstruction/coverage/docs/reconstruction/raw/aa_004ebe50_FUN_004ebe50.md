# Raw capture: FUN_004ebe50

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ebe50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ebe50` |
| **Canonical name** | `FUN_004ebe50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004ebe50(undefined4 *param_1)

{
  float fVar1;
  
  fVar1 = g_flOne;
  param_1[6] = 0x80000000;
  param_1[4] = 0;
  param_1[5] = 0;
  *param_1 = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[0x18] = 0;
  param_1[0xb] = 0;
  param_1[10] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  param_1[0xf] = 0;
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[0x13] = 0;
  param_1[0x12] = 0;
  param_1[0x11] = 0;
  param_1[0x10] = 0;
  param_1[8] = fVar1;
  param_1[0xd] = fVar1;
  param_1[0x12] = fVar1;
  param_1[0x17] = 0;
  param_1[0x16] = 0;
  param_1[0x15] = 0;
  param_1[0x14] = 0;
  return;
}
```
