# Raw capture: CVOGHBAICharacterOrMine_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063d0b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0063d0b0` |
| **Canonical name** | `CVOGHBAICharacterOrMine_ctor` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall
CVOGHBAICharacterOrMine_ctor(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  
  CVOGHBAIBase_ctor(param_2,param_3);
  fVar1 = g_flOne;
  *param_1 = &PTR_LAB_009e3e40;
  param_1[0x38] = fVar1;
  param_1[0x39] = fVar1;
  param_1[0x3a] = fVar1;
  param_1[0x3b] = fVar1;
  param_1[0x3f] = 0;
  param_1[0x3e] = 0;
  param_1[0x3d] = 0;
  param_1[0x3c] = 0;
  param_1[0x43] = 0;
  param_1[0x42] = 0;
  param_1[0x41] = 0;
  param_1[0x40] = 0;
  param_1[0x33] = 0;
  param_1[0x32] = 0;
  param_1[0x31] = 0;
  param_1[0x30] = 0;
  param_1[0x37] = 0;
  param_1[0x36] = 0;
  param_1[0x35] = 0;
  param_1[0x34] = 0;
  param_1[4] = DAT_00aaa668;
  return param_1;
}
```
