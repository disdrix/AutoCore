# Raw capture: shutdown

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717ea6` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717ea6` |
| **Canonical name** | `shutdown` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int shutdown(SOCKET s,int how)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717ea6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = shutdown(s,how);
  return iVar1;
}
```
