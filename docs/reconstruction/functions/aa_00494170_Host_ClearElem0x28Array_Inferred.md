# Function record (named): Host_ClearElem0x28Array_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00494170` |
| **Semantic name** | `Host_ClearElem0x28Array_Inferred` |
| **Ghidra name** | `FUN_00494170` |
| **Address** | `0x00494170`–`0x004941af` exclusive (**64 B** / `0x40`) |
| **Naming basis** | Host-level free of **0x28-stride** MSVC cookie-vector @ `+0x28` + zero dim fields @ `+4/+8`. Product demangle open — structural **Inferred** name. |
| **Status** | Dual sealed W30-Q (**accept-with-gaps**) |

**Decision:** promote **`Host_ClearElem0x28Array_Inferred`**. Pair with rebuild `Host_RebuildElem0x28ArrayFromMap_Inferred` (`0x004941b0`). Do **not** merge with `Class_009c7a1c_CompleteDtor` (inlines same free but continues into buffer/list teardown).

See `aa_00494170_FUN_00494170.md` for full signature, layout, callers, confidence.
