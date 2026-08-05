# Raw capture: FUN_0064fee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064fee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0064fee0` |
| **Canonical name** | `FUN_0064fee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall hkDefaultWheels_ctor(undefined4 *param_1,undefined4 param_2)

{
  FUN_005fbbb0(param_2);
  *param_1 = &PTR_FUN_009e5010;
  return param_1;
}
```
