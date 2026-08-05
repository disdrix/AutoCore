# Raw capture: _aligned_malloc

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a4e20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005a4e20` |
| **Canonical name** | `_aligned_malloc` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void * __cdecl _aligned_malloc(size_t _Size,size_t _Alignment)



{

  void *pvVar1;

  

                    /* WARNING: Could not recover jumptable at 0x005a4e20. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  pvVar1 = _aligned_malloc(_Size,_Alignment);

  return pvVar1;

}
```
