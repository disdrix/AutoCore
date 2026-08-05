# Raw capture: _vsnprintf

| Field | Value |
|---|---|
| **Stable ID** | `aa_00637f20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00637f20` |
| **Canonical name** | `_vsnprintf` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __cdecl _vsnprintf(char *_Dest,size_t _Count,char *_Format,va_list _Args)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00637f20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _vsnprintf(_Dest,_Count,_Format,_Args);
  return iVar1;
}
```
