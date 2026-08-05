# Raw capture: ioctlsocket

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717ee8` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717ee8` |
| **Canonical name** | `ioctlsocket` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int ioctlsocket(SOCKET s,long cmd,u_long *argp)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717ee8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = ioctlsocket(s,cmd,argp);
  return iVar1;
}
```
