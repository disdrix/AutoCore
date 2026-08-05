# Raw capture: _CIpow

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3e2c` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a3e2c` |
| **Canonical name** | `_CIpow` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void _CIpow(void)

{
                    /* WARNING: Could not recover jumptable at 0x006a3e2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _CIpow();
  return;
}
```
