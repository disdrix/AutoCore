# Raw capture: FUN_0067bce0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067bce0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0067bce0` |
| **Canonical name** | `FUN_0067bce0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
uint __fastcall FUN_0067bce0(SOCKET *param_1)

{
  int iVar1;
  SOCKET *local_4;
  
  local_4 = param_1;
  iVar1 = ioctlsocket(*param_1,0x4004667f,(u_long *)&local_4);
  if (iVar1 == -1) {
    if (*param_1 != 0xffffffff) {
      closesocket(*param_1);
      *param_1 = 0xffffffff;
    }
    *param_1 = 0xffffffff;
  }
  return ~-(uint)(iVar1 != 0) & (uint)local_4;
}
```
