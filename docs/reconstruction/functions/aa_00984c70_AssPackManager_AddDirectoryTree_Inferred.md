# Function record: AssPackManager_AddDirectoryTree_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00984c70` |
| **Canonical name** | `AssPackManager_AddDirectoryTree_Inferred` |
| **Ghidra name** | `FUN_00984c70` |
| **Address** | `0x00984c70`–`0x00984d25` (**182 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | AssPackManager / offline pack ingest |
| **Wave** | W33-E OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_00984c70_AssPackManager_AddDirectoryTree_Inferred.md`, `reviews/B_aa_00984c70_AssPackManager_AddDirectoryTree_Inferred.md` |

## Purpose

Directory-tree ingest for AssPackManager: recurse-collect leaf paths, then add each via nested add-file worker (`FUN_00984910`).

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `Fs_DirRecurseCollectLeafPaths_Inferred` | `0x009839b0` | leaf collector (W32-D) |
| `Fs_ExpandPathSpecToStringVec_Inferred` | `0x00984340` | path-spec expand sibling (W33-E pair) |
| `AssPackManager_OpenPackFile_Inferred` | `0x00984ee0` | open host (W31-H) |
| `AssPackManager_CompactPackFile_Inferred` | `0x00985010` | compact tool (W32-E) |
| `FUN_00984910` | `0x00984910` | add-file (unowned) |

## Signature

```c
int AssPackManager_AddDirectoryTree_Inferred(const char* dir_path /*ECX*/,
                                             void* ass_pack_manager /*stack*/);
// EDI mode formal: open gap
```

## Artifacts

See `aa_00984c70_FUN_00984c70.md` for full paths and confidence table.
