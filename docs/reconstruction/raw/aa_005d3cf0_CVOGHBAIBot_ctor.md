# Raw capture: CVOGHBAIBot_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d3cf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d3cf0` |
| **Canonical name** | `CVOGHBAIBot_ctor` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall CVOGHBAIBot_ctor(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  CVOGHBAICreatureBase_ctor(param_2,param_3);
  *param_1 = &PTR_LAB_009dabd0;
  return param_1;
}
```
