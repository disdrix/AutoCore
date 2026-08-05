# Raw capture: FUN_006a3ff6

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3ff6` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a3ff6` |
| **Canonical name** | `FUN_006a3ff6` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void * __cdecl calloc(size_t _Count,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006a3ff6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = calloc(_Count,_Size);
  return pvVar1;
}
```
