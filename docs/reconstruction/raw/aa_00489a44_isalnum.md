# Raw capture: isalnum

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489a44` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00489a44` |
| **Canonical name** | `isalnum` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __cdecl isalnum(int _C)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00489a44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = isalnum(_C);
  return iVar1;
}
```
