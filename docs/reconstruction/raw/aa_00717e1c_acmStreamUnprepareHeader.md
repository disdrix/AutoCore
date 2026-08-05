# Raw capture: acmStreamUnprepareHeader

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717e1c` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717e1c` |
| **Canonical name** | `acmStreamUnprepareHeader` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void acmStreamUnprepareHeader(void)

{
                    /* WARNING: Could not recover jumptable at 0x00717e1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  acmStreamUnprepareHeader();
  return;
}
```
