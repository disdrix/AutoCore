# Raw capture: thunk_FUN_006cec70

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c7e80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006c7e80` |
| **Canonical name** | `thunk_FUN_006cec70` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall thunk_FUN_006cec70(int param_1,int param_2)

{
  FUN_006cde50(param_2);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0xc);
  return;
}
```
