# Raw capture: __WSAFDIsSet

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717e82` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717e82` |
| **Canonical name** | `__WSAFDIsSet` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __WSAFDIsSet(SOCKET param_1,fd_set *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717e82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = __WSAFDIsSet(param_1,param_2);
  return iVar1;
}
```
