# Raw capture: FUN_0043edb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043edb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0043edb0` |
| **Canonical name** | `FUN_0043edb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0043edb0(void)

{
  int unaff_ESI;
  
  stoChunkReader_readF32Array(unaff_ESI);
  stoChunkReader_readF32Array(unaff_ESI);
  stoChunkReader_readF32Array(unaff_ESI);
  stoChunkReader_readF32Array(unaff_ESI);
  return *(undefined4 *)(unaff_ESI + 0x402c);
}
```
