# Raw capture: stat

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3d36` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a3d36` |
| **Canonical name** | `stat` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __cdecl stat(void)

{
                    /* WARNING: Could not recover jumptable at 0x006a3d36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  stat();
  return;
}
```
