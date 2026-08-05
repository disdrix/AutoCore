# Raw capture: D3DXSaveTextureToFileA

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a5d58` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a5d58` |
| **Canonical name** | `D3DXSaveTextureToFileA` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void D3DXSaveTextureToFileA(void)

{
                    /* WARNING: Could not recover jumptable at 0x006a5d58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  D3DXSaveTextureToFileA();
  return;
}
```
