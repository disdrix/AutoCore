# Raw capture: ov_pcm_total

| Field | Value |
|---|---|
| **Stable ID** | `aa_006859f6` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006859f6` |
| **Canonical name** | `ov_pcm_total` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void ov_pcm_total(void)

{
                    /* WARNING: Could not recover jumptable at 0x006859f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ov_pcm_total();
  return;
}
```
