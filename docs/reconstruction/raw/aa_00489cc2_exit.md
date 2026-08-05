# Raw capture: exit

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489cc2` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00489cc2` |
| **Canonical name** | `exit` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __cdecl exit(int _Code)

{
                    /* WARNING: Could not recover jumptable at 0x00489cc2. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  exit(_Code);
  return;
}
```
