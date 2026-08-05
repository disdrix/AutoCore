# Function record: Fs_ExpandPathSpecToStringVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00984340` |
| **Canonical name** | `Fs_ExpandPathSpecToStringVec_Inferred` |
| **Ghidra name** | `FUN_00984340` |
| **Address** | `0x00984340`–`0x009847bb` (**1148 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | filesystem / path-spec expansion |
| **Wave** | W33-E OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_00984340_Fs_ExpandPathSpecToStringVec_Inferred.md`, `reviews/B_aa_00984340_Fs_ExpandPathSpecToStringVec_Inferred.md` |

## Purpose

Path-spec expander for offline asset/pack tooling: `@list`, single file, glob, one-level dir, or deep leaf recurse (`FUN_009839b0`). Results land in a caller string vector.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `Fs_DirRecurseCollectLeafPaths_Inferred` | `0x009839b0` | callee when recurse flag set (W32-D) |
| `AssPackManager_AddDirectoryTree_Inferred` | `0x00984c70` | sibling pack-tree ingest (W33-E pair) |
| `FUN_009841d0` | `0x009841d0` | `@` path-list reader (unowned) |
| `FUN_0076b210` | `0x0076b210` | glob match (unowned) |

## Signature

```c
void* Fs_ExpandPathSpecToStringVec_Inferred(void* out_string_vec,
                                            const char* path_spec,
                                            char recurse_dirs /*cdecl*/);
```

## Artifacts

See `aa_00984340_FUN_00984340.md` for full paths and confidence table.
