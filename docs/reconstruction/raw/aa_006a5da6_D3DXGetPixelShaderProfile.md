# Raw capture: D3DXGetPixelShaderProfile

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a5da6` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a5da6` |
| **Canonical name** | `D3DXGetPixelShaderProfile` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void D3DXGetPixelShaderProfile(void)

{
                    /* WARNING: Could not recover jumptable at 0x006a5da6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  D3DXGetPixelShaderProfile();
  return;
}
```
