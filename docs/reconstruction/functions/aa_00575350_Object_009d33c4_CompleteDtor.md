# Function record (named): Object_009d33c4_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00575350` |
| **Semantic name** | `Object_009d33c4_CompleteDtor` |
| **Ghidra name** | `FUN_00575350` |
| **Address** | `0x00575350` |
| **Naming basis** | Complete dtor for vtbl `PTR_FUN_009d33c4`; extends `Object_SharedBase` (ctor `0x00518940` / dtor tail `0x00518ec0`); product demangle open — vtbl suffix disambiguates |
| **Status** | Dual sealed W28-M (**accept-with-gaps**) |

**Decision:** promote **`Object_009d33c4_CompleteDtor`**. Do not merge with base-only `FUN_00518ec0` or scalar deleting `FUN_00575c00`.

See `aa_00575350_FUN_00575350.md` for full signature, layout, callers, confidence.
