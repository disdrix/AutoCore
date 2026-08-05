# Raw capture: FUN_005fea00

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fea00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fea00` |
| **Canonical name** | `FUN_005fea00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005fea00(int param_1,short param_2)

{
  *(short *)(param_1 + 0xb4) = *(short *)(param_1 + 0xb4) + param_2;
  if (*(short *)(param_1 + 0xb4) < 1) {
    *(undefined2 *)(param_1 + 0xb4) = 1;
  }
  return;
}
```
