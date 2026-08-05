# Raw capture: CVOGHBAIBase_Default_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063c940` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0063c940` |
| **Canonical name** | `CVOGHBAIBase_Default_ctor` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall
CVOGHBAIBase_Default_ctor(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  CVOGHBAIWalkingCreatureTurreted_ctor(param_2,param_3);
  *param_1 = &PTR_FUN_009e3d40;
  param_1[4] = 0;
  FUN_0063a700(0);
  param_1[0x1f] = g_flOne;
  return param_1;
}
```
