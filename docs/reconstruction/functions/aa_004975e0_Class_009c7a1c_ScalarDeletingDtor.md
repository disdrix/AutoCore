# Function record (named): Class_009c7a1c_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004975e0` |
| **Semantic name** | `Class_009c7a1c_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004975e0` |
| **Address** | `0x004975e0`–`0x004975fe` exclusive (**30 B** / `0x1E`) |
| **Naming basis** | MSVC scalar-deleting dtor = **vtbl[0]** of `PTR_FUN_009c7a1c` (`0x009c7a1c` → `0x004975e0`); always calls complete body `Class_009c7a1c_CompleteDtor` (`FUN_004970b0`); product demangle open — vtbl suffix disambiguates |
| **Status** | Dual sealed W29-F (**accept**) |

**Decision:** promote **`Class_009c7a1c_ScalarDeletingDtor`**. Do **not** treat as complete-object body or as element dtor.

See `aa_004975e0_FUN_004975e0.md` for full signature, callers, confidence.
