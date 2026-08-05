# Function record (named): Elem0x28_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b8000` |
| **Semantic name** | `Elem0x28_CompleteDtor` |
| **Ghidra name** | `FUN_005b8000` |
| **Address** | `0x005b8000`–`0x005b810b` exclusive (**267 B** / `0x10B`) |
| **Naming basis** | Element complete dtor for **0x28-byte** cookie-vector elements; registered to `_eh_vector_destructor_iterator_` from Class_009c7a1c and peer hosts. Product demangle open — stride-based structural name. |
| **Status** | Dual sealed W29-F (**accept-with-gaps**) |

**Decision:** promote **`Elem0x28_CompleteDtor`**. Reject scaffold alias tying this to VOG_DEBUG_STOP. Do **not** treat as host complete dtor or scalar-deleting wrapper.

See `aa_005b8000_FUN_005b8000.md` for full signature, layout, callers, confidence.
