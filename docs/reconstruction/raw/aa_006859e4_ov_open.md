# Raw capture: ov_open

| Field | Value |
|---|---|
| **Stable ID** | `aa_006859e4` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006859e4` |
| **Canonical name** | `ov_open` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void ov_open(void)

{
                    /* WARNING: Could not recover jumptable at 0x006859e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ov_open();
  return;
}
```
