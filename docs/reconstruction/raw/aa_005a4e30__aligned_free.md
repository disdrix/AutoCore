# Raw capture: _aligned_free

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a4e30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005a4e30` |
| **Canonical name** | `_aligned_free` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __cdecl _aligned_free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x005a4e30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _aligned_free(_Memory);
  return;
}
```
