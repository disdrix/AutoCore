# Raw capture: FUN_005fea30

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fea30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fea30` |
| **Canonical name** | `FUN_005fea30` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005fea30(int param_1)

{
  *(undefined2 *)(param_1 + -0x12) = *(undefined2 *)(param_1 + -0x14);
  FUN_00512130();
  return;
}
```
