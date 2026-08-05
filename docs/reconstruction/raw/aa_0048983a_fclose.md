# Raw capture: fclose

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048983a` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0048983a` |
| **Canonical name** | `fclose` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __cdecl fclose(FILE *_File)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0048983a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = fclose(_File);
  return iVar1;
}
```
