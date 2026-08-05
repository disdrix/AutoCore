# Raw capture: closesocket

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717e7c` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717e7c` |
| **Canonical name** | `closesocket` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int closesocket(SOCKET s)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717e7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = closesocket(s);
  return iVar1;
}
```
