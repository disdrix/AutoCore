# Function record (named): Client_TryInventoryAutoMergePartialStacks_Notify

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c2f50` |
| **Semantic name** | `Client_TryInventoryAutoMergePartialStacks_Notify` |
| **Ghidra name** | `FUN_008c2f50` |
| **Address** | `0x008c2f50`–`0x008c2fdf` exclusive (**143 B** / `0x8F`) |
| **Naming basis** | Client gate + call `InventoryGrid_AutoMergePartialStacks_Inferred` + sector notify `0x204a` on dirty; sole UI-handler caller; product plate open |
| **Status** | Dual sealed W30-N (**accept-with-gaps**) |

**Decision:** promote **`Client_TryInventoryAutoMergePartialStacks_Notify`**. Do **not** reimplement merge math here (owned by `0x00572ab0`). Do **not** treat as generic inventory UI dispatcher (`FUN_008c3ca0`).

See `aa_008c2f50_FUN_008c2f50.md` for full signature, callers, confidence.
