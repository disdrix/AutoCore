# Raw capture: ov_pcm_seek

| Field | Value |
|---|---|
| **Stable ID** | `aa_00685a08` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00685a08` |
| **Canonical name** | `ov_pcm_seek` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void ov_pcm_seek(void)

{
                    /* WARNING: Could not recover jumptable at 0x00685a08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ov_pcm_seek();
  return;
}
```
