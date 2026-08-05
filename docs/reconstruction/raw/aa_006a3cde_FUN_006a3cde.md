# Raw capture: FUN_006a3cde

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3cde` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a3cde` |
| **Canonical name** | `FUN_006a3cde` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */

void FUN_006a3cde(void)

{
  __security_error_handler(1,0);
                    /* WARNING: Subroutine does not return */
  ExitProcess(3);
}
```
