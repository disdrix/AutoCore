# Raw capture: setsockopt

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717ea0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717ea0` |
| **Canonical name** | `setsockopt` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int setsockopt(SOCKET s,int level,int optname,char *optval,int optlen)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717ea0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = setsockopt(s,level,optname,optval,optlen);
  return iVar1;
}
```
