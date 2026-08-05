# Function record (named): MapChild_RebuildHostElemsAndIntGrid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ac100` |
| **Semantic name** | `MapChild_RebuildHostElemsAndIntGrid_Inferred` |
| **Ghidra name** | `FUN_004ac100` |
| **Address** | `0x004ac100`–`0x004ac215` exclusive (**277 B** / `0x115`) |
| **Naming basis** | Structural: rebuilds host 0x28-elem cookie-vector (via W30-Q helper) **and** this object's int tile grid. Product demangle open — `_Inferred` suffix. |
| **Status** | Dual sealed W31-L (**accept-with-gaps**) |

**Decision:** promote **`MapChild_RebuildHostElemsAndIntGrid_Inferred`**. **Reject** scaffold `Named_VOG_DEBUG_STOP_004ac100`. Do **not** merge with `Host_RebuildElem0x28ArrayFromMap_Inferred` (`0x004941b0`) — this is the outer orchestrator.

See `aa_004ac100_FUN_004ac100.md` for full signature, offsets, callers, confidence.
