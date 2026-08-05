# Function record: List_RemoveAll

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc580` |
| **Canonical name** | `List_RemoveAll` |
| **Ghidra name** | `FUN_004bc580` |
| **Address** | `0x004bc580`–`0x004bc67b` (**252 B**) |
| **Wave** | W37-U OWN-ONLY dual |
| **Verdict** | **accept** |

See `aa_004bc580_FUN_004bc580.md` for full table, callers, confidence.

## Family

| Unit | VA | Role |
|---|---|---|
| `List_TraversalLock` | `0x004294f0` | Enter CS; set `+0x28=1` |
| `List_IterateNext` | `0x004022a0` | Walk under lock |
| `List_RemoveAll` | `0x004bc580` | Drain/destroy; refuse if locked |
