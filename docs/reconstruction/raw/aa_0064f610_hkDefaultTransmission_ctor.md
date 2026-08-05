# Raw capture: hkDefaultTransmission_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064f610` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0064f610` |
| **Canonical name** | `hkDefaultTransmission_ctor` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall hkDefaultTransmission_ctor(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  FUN_0065e460(param_2);
  uVar1 = DAT_00aaa668;
  *param_1 = &PTR_FUN_009e4dac;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0x80000000;
  param_1[0x15] = 0x80000000;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[4] = 0;
  param_1[0x17] = uVar1;
  *(undefined1 *)(param_1 + 0x16) = 0;
  FUN_0064f100(param_2);
  return param_1;
}
```
