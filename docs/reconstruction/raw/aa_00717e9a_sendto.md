# Raw capture: sendto

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717e9a` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717e9a` |
| **Canonical name** | `sendto` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int sendto(SOCKET s,char *buf,int len,int flags,sockaddr *to,int tolen)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717e9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = sendto(s,buf,len,flags,to,tolen);
  return iVar1;
}
```
