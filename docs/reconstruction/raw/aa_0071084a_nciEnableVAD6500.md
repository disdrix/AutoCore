# Raw capture: nciEnableVAD6500

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071084a` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0071084a` |
| **Canonical name** | `nciEnableVAD6500` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void nciEnableVAD6500(void)

{
                    /* WARNING: Could not recover jumptable at 0x0071084a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  nciEnableVAD6500();
  return;
}
```
