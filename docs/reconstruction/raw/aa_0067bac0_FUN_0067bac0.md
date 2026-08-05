# Raw capture: FUN_0067bac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067bac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0067bac0` |
| **Canonical name** | `FUN_0067bac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_0067bac0(SOCKET *param_1,byte param_2)

{
  int iVar1;
  
  _param_2 = (uint)param_2;
  iVar1 = ioctlsocket(*param_1,-0x7ffb9982,(u_long *)&param_2);
  return -(uint)(iVar1 != 0);
}
```
