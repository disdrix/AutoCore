# Raw capture: WSAAsyncSelect

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717ef4` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717ef4` |
| **Canonical name** | `WSAAsyncSelect` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int WSAAsyncSelect(SOCKET s,HWND hWnd,u_int wMsg,long lEvent)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717ef4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = WSAAsyncSelect(s,hWnd,wMsg,lEvent);
  return iVar1;
}
```
