# Function record (named): Object_009d33c4_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00575c00` |
| **Semantic name** | `Object_009d33c4_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_00575c00` |
| **Address** | `0x00575c00` |
| **Naming basis** | vtbl[0] of `PTR_FUN_009d33c4` + classic MSVC scalar deleting pattern (complete dtor then flags&1 free, RET 4) |
| **Status** | Dual sealed W29-H |

**Decision:** promote **`Object_009d33c4_ScalarDeletingDtor`**. Do not merge with complete dtor `FUN_00575350` or base dtor `FUN_00518ec0`.

See `aa_00575c00_FUN_00575c00.md` for full signature, layout, callers, confidence.
