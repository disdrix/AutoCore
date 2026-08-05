# Raw capture: setjmp3

| Field | Value |
|---|---|
| **Stable ID** | `aa_009a03d8` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x009a03d8` |
| **Canonical name** | `setjmp3` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __cdecl setjmp3(void)

{
                    /* WARNING: Could not recover jumptable at 0x009a03d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  setjmp3();
  return;
}
```
