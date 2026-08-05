# Raw capture: _snprintf

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048989e` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0048989e` |
| **Canonical name** | `_snprintf` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __cdecl _snprintf(char *_Dest,size_t _Count,char *_Format,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0048989e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _snprintf(_Dest,_Count,_Format);
  return iVar1;
}
```
