# Raw capture: printf

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3fea` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a3fea` |
| **Canonical name** | `printf` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __cdecl printf(char *_Format,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006a3fea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = printf(_Format);
  return iVar1;
}
```
