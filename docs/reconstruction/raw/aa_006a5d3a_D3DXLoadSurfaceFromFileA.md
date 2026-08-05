# Raw capture: D3DXLoadSurfaceFromFileA

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a5d3a` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a5d3a` |
| **Canonical name** | `D3DXLoadSurfaceFromFileA` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void D3DXLoadSurfaceFromFileA(void)

{
                    /* WARNING: Could not recover jumptable at 0x006a5d3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  D3DXLoadSurfaceFromFileA();
  return;
}
```
