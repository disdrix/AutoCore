# Raw capture: D3DXGetVertexShaderProfile

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a5da0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a5da0` |
| **Canonical name** | `D3DXGetVertexShaderProfile` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void D3DXGetVertexShaderProfile(void)

{
                    /* WARNING: Could not recover jumptable at 0x006a5da0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  D3DXGetVertexShaderProfile();
  return;
}
```
