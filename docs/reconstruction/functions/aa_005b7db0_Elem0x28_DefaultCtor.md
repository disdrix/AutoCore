# Function record (named): Elem0x28_DefaultCtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b7db0` |
| **Semantic name** | `Elem0x28_DefaultCtor` |
| **Ghidra name** | `FUN_005b7db0` |
| **Address** | `0x005b7db0`–`0x005b7dee` exclusive (**62 B** / `0x3E`) |
| **Naming basis** | Element default ctor for **0x28-byte** cookie-vector elements; registered to `_eh_vector_constructor_iterator_` opposite `Elem0x28_CompleteDtor`. Product demangle open — stride-based structural name. |
| **Status** | Dual sealed W31-L (**accept-with-gaps**) |

**Decision:** promote **`Elem0x28_DefaultCtor`**. Reject scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_005b7db0`. Pair with `Elem0x28_CompleteDtor` (`0x005b8000`, W29-F) and host rebuild `Host_RebuildElem0x28ArrayFromMap_Inferred` (`0x004941b0`, W30-Q).

See `aa_005b7db0_FUN_005b7db0.md` for full signature, layout, xrefs, confidence.
