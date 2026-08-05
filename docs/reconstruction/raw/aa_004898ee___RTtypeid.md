# Raw capture: __RTtypeid

| Field | Value |
|---|---|
| **Stable ID** | `aa_004898ee` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004898ee` |
| **Canonical name** | `__RTtypeid` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __RTtypeid(void)

{
                    /* WARNING: Could not recover jumptable at 0x004898ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __RTtypeid();
  return;
}
```
