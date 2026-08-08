# Function record: List_DestroyAll

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc950` |
| **Canonical name** | `List_DestroyAll` |
| **Ghidra name** | `FUN_004bc950` |
| **Address** | `0x004bc950`–`0x004bca4a` (**251 B**) |
| **Wave** | R10-028 OWN-ONLY dual |
| **Verdict** | **accept** |

See `aa_004bc950_FUN_004bc950.md` for full table, callers, confidence.

## Family

| Unit | VA | Role |
|---|---|---|
| `List_TraversalLock` | `0x004294f0` | Enter CS; set `+0x28=1` |
| `List_IterateNext` | `0x004022a0` | Walk under lock |
| `List_RemoveAll` | `0x004bc580` | Mid-life drain; zeros `node[+4]` |
| `List_DestroyAll` | `0x004bc950` | Dtor/teardown drain; no `node[+4]` clear |
| `ObjectCsList_DestroyAll_Inferred` | `0x00424060` | CF twin (separate VA; do not merge) |
