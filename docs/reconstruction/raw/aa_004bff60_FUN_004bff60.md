# Raw capture: FUN_004bff60

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bff60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bff60` |
| **Canonical name** | `FUN_004bff60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __fastcall FUN_004bff60(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_009cb624;
  _eh_vector_constructor_iterator_(param_1 + 1,0xc,9,FUN_00569290,FUN_004c0520);
  return param_1;
}
```
