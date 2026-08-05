# Raw capture: D3DXCreateTextureFromFileInMemoryEx

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a5d64` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a5d64` |
| **Canonical name** | `D3DXCreateTextureFromFileInMemoryEx` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void D3DXCreateTextureFromFileInMemoryEx(void)

{
                    /* WARNING: Could not recover jumptable at 0x006a5d64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  D3DXCreateTextureFromFileInMemoryEx();
  return;
}
```
