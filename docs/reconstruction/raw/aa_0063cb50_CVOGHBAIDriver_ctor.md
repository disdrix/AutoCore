# Raw capture: CVOGHBAIDriver_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063cb50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0063cb50` |
| **Canonical name** | `CVOGHBAIDriver_ctor` |
| **System** | input-drive-control |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall
CVOGHBAIDriver_ctor(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  CVOGHBAICharacterOrMine_ctor(param_2,param_3);
  *param_1 = &PTR_LAB_009e3dc0;
  return param_1;
}
```
