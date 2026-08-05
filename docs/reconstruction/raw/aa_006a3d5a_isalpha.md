# Raw capture: isalpha

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3d5a` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a3d5a` |
| **Canonical name** | `isalpha` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __cdecl isalpha(int _C)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006a3d5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = isalpha(_C);
  return iVar1;
}
```
