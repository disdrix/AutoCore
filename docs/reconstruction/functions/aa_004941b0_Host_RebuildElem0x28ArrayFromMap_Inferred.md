# Function record (named): Host_RebuildElem0x28ArrayFromMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004941b0` |
| **Semantic name** | `Host_RebuildElem0x28ArrayFromMap_Inferred` |
| **Ghidra name** | `FUN_004941b0` |
| **Address** | `0x004941b0`–`0x00494304` exclusive (**341 B** / `0x155`) |
| **Naming basis** | Free+rebuild host cookie-vector (**0x28** stride) from map extents @ `*(mapCtx+0xe4f8)` with 64/32 scale select. Product demangle open — structural **Inferred** name. |
| **Status** | Dual sealed W30-Q (**accept-with-gaps**) |

**Decision:** promote **`Host_RebuildElem0x28ArrayFromMap_Inferred`**. **Reject** scaffold `Named_VOG_DEBUG_STOP_004941b0`. Pair with free helper `Host_ClearElem0x28Array_Inferred` (`0x00494170`). Element ctors/dtors: `FUN_005b7db0` / `Elem0x28_CompleteDtor`.

See `aa_004941b0_FUN_004941b0.md` for full signature, formula, callers, confidence.
