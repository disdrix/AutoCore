# Raw capture: BitStream_writeInt

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b8f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0042b8f0` |
| **Canonical name** | `BitStream_writeInt` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void BitStream_writeInt(undefined4 param_1,undefined1 param_2)

{
  BitStream_writeBits(param_2,&param_1);
  return;
}
```
