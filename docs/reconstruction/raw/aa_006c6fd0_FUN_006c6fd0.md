# Raw capture: FUN_006c6fd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c6fd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006c6fd0` |
| **Canonical name** | `FUN_006c6fd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_006c6fd0(undefined4 *param_1)

{
  *(undefined2 *)((int)param_1 + 6) = 1;
  param_1[2] = &PTR_LAB_009d27b0;
  param_1[3] = &PTR_LAB_009d2784;
  param_1[4] = &PTR_LAB_009d278c;
  param_1[5] = &PTR_LAB_009d27b0;
  *param_1 = &PTR_FUN_00a0d41c;
  param_1[2] = &PTR_LAB_00a0d418;
  param_1[3] = &PTR_FUN_00a0d410;
  param_1[4] = &PTR_LAB_00a0d408;
  param_1[5] = &PTR_LAB_00a0d404;
  param_1[7] = 0xffffffff;
  param_1[8] = 0xffffffff;
  param_1[9] = 0xffffffff;
  param_1[10] = 0xffffffff;
  param_1[0xb] = 0xffffffff;
  param_1[0xc] = 0xffffffff;
  param_1[0xd] = 0xffffffff;
  param_1[0xe] = 0xffffffff;
  param_1[0xf] = 0xffffffff;
  param_1[0x10] = 0xffffffff;
  param_1[0x11] = 0xffffffff;
  param_1[0x12] = 0xffffffff;
  param_1[0x13] = 0xffffffff;
  param_1[0x14] = 0xffffffff;
  param_1[0x15] = 0xffffffff;
  param_1[0x16] = 0xffffffff;
  param_1[0x17] = 0xffffffff;
  param_1[0x18] = 0xffffffff;
  param_1[0x19] = 0xffffffff;
  param_1[0x1a] = 0xffffffff;
  param_1[0x1b] = 0xffffffff;
  param_1[0x1c] = 0xffffffff;
  param_1[0x1d] = 0xffffffff;
  param_1[0x1e] = 0xffffffff;
  param_1[0x1f] = 0xffffffff;
  param_1[0x20] = 0xffffffff;
  param_1[0x21] = 0xffffffff;
  param_1[0x22] = 0xffffffff;
  param_1[0x23] = 0xffffffff;
  param_1[0x24] = 0xffffffff;
  param_1[0x25] = 0xffffffff;
  param_1[0x26] = 0xffffffff;
  param_1[6] = 0;
  return;
}
```
