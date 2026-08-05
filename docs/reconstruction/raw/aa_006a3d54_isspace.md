# Raw capture: isspace

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3d54` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a3d54` |
| **Canonical name** | `isspace` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __cdecl isspace(int _C)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006a3d54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = isspace(_C);
  return iVar1;
}
```
