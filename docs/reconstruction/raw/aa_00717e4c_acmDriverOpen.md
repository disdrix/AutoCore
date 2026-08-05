# Raw capture: acmDriverOpen

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717e4c` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717e4c` |
| **Canonical name** | `acmDriverOpen` |
| **System** | input-drive-control |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void acmDriverOpen(void)

{
                    /* WARNING: Could not recover jumptable at 0x00717e4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  acmDriverOpen();
  return;
}
```
