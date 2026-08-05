# Raw capture: __onexit

| Field | Value |
|---|---|
| **Stable ID** | `aa_004898b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004898b0` |
| **Canonical name** | `__onexit` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 2003 Release */

void __onexit(_onexit_t param_1)

{
  if (DAT_00d21a08 == -1) {
                    /* WARNING: Could not recover jumptable at 0x004898b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    _onexit(param_1);
    return;
  }
  __dllonexit(param_1,&DAT_00d21a08,&DAT_00d21a04);
  return;
}
```
