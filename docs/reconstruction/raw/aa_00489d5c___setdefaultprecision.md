# Raw capture: __setdefaultprecision

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489d5c` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00489d5c` |
| **Canonical name** | `__setdefaultprecision` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Library Function - Single Match
    __setdefaultprecision
   
   Library: Visual Studio 2003 Release */

void __setdefaultprecision(void)

{
  _controlfp(0x10000,0x30000);
  return;
}
```
