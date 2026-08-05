# Raw capture: connect

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717ee2` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717ee2` |
| **Canonical name** | `connect` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int connect(SOCKET s,sockaddr *name,int namelen)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717ee2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = connect(s,name,namelen);
  return iVar1;
}
```
