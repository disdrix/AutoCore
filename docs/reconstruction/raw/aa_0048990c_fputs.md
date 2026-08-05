# Raw capture: fputs

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048990c` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0048990c` |
| **Canonical name** | `fputs` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __cdecl fputs(char *_Str,FILE *_File)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0048990c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = fputs(_Str,_File);
  return iVar1;
}
```
