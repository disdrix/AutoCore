# Raw capture: acmStreamSize

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717e28` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717e28` |
| **Canonical name** | `acmStreamSize` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void acmStreamSize(void)

{
                    /* WARNING: Could not recover jumptable at 0x00717e28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  acmStreamSize();
  return;
}
```
