# Raw capture: WSACleanup

| Field | Value |
|---|---|
| **Stable ID** | `aa_009c53c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x009c53c0` |
| **Canonical name** | `WSACleanup` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int WSACleanup(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x009c53c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = WSACleanup();
  return iVar1;
}
```
