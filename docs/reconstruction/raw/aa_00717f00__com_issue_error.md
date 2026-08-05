# Raw capture: _com_issue_error

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717f00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717f00` |
| **Canonical name** | `_com_issue_error` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Library Function - Single Match
    void __stdcall _com_issue_error(long)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug */

void _com_issue_error(long param_1)

{
  (*(code *)PTR_FUN_00af8b20)(param_1,0);
  return;
}
```
