# Raw capture: FUN_0067bdf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067bdf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0067bdf0` |
| **Canonical name** | `FUN_0067bdf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_0067bdf0(SOCKET *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = setsockopt(*param_1,param_2,param_3,(char *)&param_4,4);
  return -(uint)(iVar1 != 0);
}
```
