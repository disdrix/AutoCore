# Function record: MissionTree_InorderCollectMediaPreloads_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a04f0` |
| **Canonical name** | `MissionTree_InorderCollectMediaPreloads_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_004a04f0` |
| **Address** | `0x004a04f0`–`0x004a057a` exclusive (**138 B** / `0x8A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | mission tree inorder → `MissionHost_CollectMediaPreloads` |
| **Completion status** | **Dual sealed** W37-C — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Bridge used by CollectAll*Preloads parents: when the object’s mission tree pointer is live, walk every host node in **inorder** and run the sealed media/audio/path collect helper with a **flag triple** selected by the parent (graphics / sound / physics / all-ones).

## Signature

```c
// thiscall; RET 0x10
void MissionTree_InorderCollectMediaPreloads_Inferred(
    TreeHolder* holder,           /* ECX */
    uint32_t unused,              /* stack0 — forwarded */
    uint32_t flag_media_strings,  /* stack1 */
    uint32_t flag_mission_audio,  /* stack2 */
    uint32_t flag_obj_paths);     /* stack3 */
```

## Related

| VA | Role |
|---|---|
| `0x004b88e0` | per-node collect (W32-H) |
| `0x004f1ff0` | Object_CollectAllGraphicsPreloads — flags `(1,0,0)` |
| `0x004ebf50` | CollectAllSoundPreloads — `(0,1,0)`; ECX from `obj+0x88` |
| `0x004ec7b0` | CollectAllPhysicsPreloads — `(0,0,1)` |
| `0x00542e20` / `0x00542790` | mission apply — all flags |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004a04f0_FUN_004a04f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004a04f0_FUN_004a04f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionTree_InorderCollectMediaPreloads_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004a04f0.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_004a04f0_MissionTree_InorderCollectMediaPreloads_Inferred.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-00469c80-004a04f0-w37c-report.md` |

## Gaps

- Product English for tree / holder / node types.
- Holder first-indirection field names (`*ecx` then `+4` head).
- Runtime / bit-exact.
