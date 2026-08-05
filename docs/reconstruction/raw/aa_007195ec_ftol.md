# Raw capture: ftol

| Field | Value |
|---|---|
| **Stable ID** | `aa_007195ec` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007195ec` |
| **Canonical name** | `ftol` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __cdecl ftol(void)

{
                    /* WARNING: Could not recover jumptable at 0x007195ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ftol();
  return;
}
```
