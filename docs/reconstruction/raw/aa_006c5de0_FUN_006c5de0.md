# Raw capture: FUN_006c5de0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c5de0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006c5de0` |
| **Canonical name** | `FUN_006c5de0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall
FUN_006c5de0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_006d0e50(param_2,*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10),param_3,
               param_4);
  return param_2;
}
```
