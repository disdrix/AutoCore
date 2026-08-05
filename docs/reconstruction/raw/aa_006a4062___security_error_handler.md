# Raw capture: __security_error_handler

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a4062` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a4062` |
| **Canonical name** | `__security_error_handler` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __security_error_handler(void)

{
                    /* WARNING: Could not recover jumptable at 0x006a4062. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __security_error_handler();
  return;
}
```
