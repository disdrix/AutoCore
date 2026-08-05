# Raw capture: FUN_005fff00

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fff00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fff00` |
| **Canonical name** | `FUN_005fff00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __fastcall FUN_005fff00(int param_1)

{
  FUN_005ffed0();
  *(undefined1 *)(param_1 + 0x18) = 1;
  *(undefined2 *)(param_1 + 0x1a) = 0xffff;
  return param_1;
}
```
