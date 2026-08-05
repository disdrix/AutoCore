# Raw capture: ftell

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3d48` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a3d48` |
| **Canonical name** | `ftell` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
long __cdecl ftell(FILE *_File)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006a3d48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = ftell(_File);
  return lVar1;
}
```
