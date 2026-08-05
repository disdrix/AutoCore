# Raw capture: FUN_006ef0d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ef0d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ef0d0` |
| **Canonical name** | `FUN_006ef0d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006ef0d0(int param_1,int param_2)

{
  FUN_006cde50(param_2);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0xc);
  FUN_005eb040(param_1 + 0x10);
  return;
}
```
