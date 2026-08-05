# Raw capture: fseek

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3d4e` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a3d4e` |
| **Canonical name** | `fseek` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __cdecl fseek(FILE *_File,long _Offset,int _Origin)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006a3d4e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = fseek(_File,_Offset,_Origin);
  return iVar1;
}
```
