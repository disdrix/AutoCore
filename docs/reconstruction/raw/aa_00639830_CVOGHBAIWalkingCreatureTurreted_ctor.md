# Raw capture: CVOGHBAIWalkingCreatureTurreted_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00639830` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00639830` |
| **Canonical name** | `CVOGHBAIWalkingCreatureTurreted_ctor` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall
CVOGHBAIWalkingCreatureTurreted_ctor(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  CVOGHBAIBase_ctor(param_2,param_3);
  *param_1 = &PTR_LAB_009e3cc0;
  param_1[0x30] = 0;
  param_1[4] = 0;
  FUN_0063a700(0);
  param_1[0x1f] = g_flOne;
  return param_1;
}
```
