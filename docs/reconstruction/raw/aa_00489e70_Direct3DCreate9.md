# Raw capture: Direct3DCreate9

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489e70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00489e70` |
| **Canonical name** | `Direct3DCreate9` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void Direct3DCreate9(void)

{
                    /* WARNING: Could not recover jumptable at 0x00489e70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Direct3DCreate9();
  return;
}
```
