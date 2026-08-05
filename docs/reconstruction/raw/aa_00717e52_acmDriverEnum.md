# Raw capture: acmDriverEnum

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717e52` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717e52` |
| **Canonical name** | `acmDriverEnum` |
| **System** | input-drive-control |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void acmDriverEnum(void)

{
                    /* WARNING: Could not recover jumptable at 0x00717e52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  acmDriverEnum();
  return;
}
```
