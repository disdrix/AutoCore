# Raw capture: ov_clear

| Field | Value |
|---|---|
| **Stable ID** | `aa_006859de` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006859de` |
| **Canonical name** | `ov_clear` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void ov_clear(void)

{
                    /* WARNING: Could not recover jumptable at 0x006859de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ov_clear();
  return;
}
```
