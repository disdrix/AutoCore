# Raw capture: BitStream_readInt

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b8b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0042b8b0` |
| **Canonical name** | `BitStream_readInt` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
uint BitStream_readInt(byte param_1)

{
  uint local_4;
  
  local_4 = 0;
  BitStream_readBits(param_1,&local_4);
  if (param_1 != 0x20) {
    local_4 = local_4 & (1 << (param_1 & 0x1f)) - 1U;
  }
  return local_4;
}
```
