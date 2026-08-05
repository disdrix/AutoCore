# Raw capture: FID_conflict__dynamic_initializer_for__vtMissing__

| Field | Value |
|---|---|
| **Stable ID** | `aa_009c2ec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x009c2ec0` |
| **Canonical name** | `FID_conflict__dynamic_initializer_for__vtMissing__` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Library Function - Multiple Matches With Different Base Names
    void __cdecl `dynamic initializer for 'vtMissing''(void)
    _$E1
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug */

void FID_conflict__dynamic_initializer_for__vtMissing__(void)

{
  _variant_t::_variant_t((_variant_t *)&DAT_00d09850,-0x7ffdfffc,10);
  _atexit(FUN_009c5cf0);
  return;
}
```
