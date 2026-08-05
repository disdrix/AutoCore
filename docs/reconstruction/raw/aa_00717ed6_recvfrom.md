# Raw capture: recvfrom

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717ed6` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717ed6` |
| **Canonical name** | `recvfrom` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int recvfrom(SOCKET s,char *buf,int len,int flags,sockaddr *from,int *fromlen)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717ed6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = recvfrom(s,buf,len,flags,from,fromlen);
  return iVar1;
}
```
