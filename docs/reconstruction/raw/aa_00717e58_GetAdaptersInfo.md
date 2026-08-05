# Raw capture: GetAdaptersInfo

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717e58` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717e58` |
| **Canonical name** | `GetAdaptersInfo` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void GetAdaptersInfo(void)

{
                    /* WARNING: Could not recover jumptable at 0x00717e58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetAdaptersInfo();
  return;
}
```
