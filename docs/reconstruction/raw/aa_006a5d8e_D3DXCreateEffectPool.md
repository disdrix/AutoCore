# Raw capture: D3DXCreateEffectPool

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a5d8e` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a5d8e` |
| **Canonical name** | `D3DXCreateEffectPool` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void D3DXCreateEffectPool(void)

{
                    /* WARNING: Could not recover jumptable at 0x006a5d8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  D3DXCreateEffectPool();
  return;
}
```
