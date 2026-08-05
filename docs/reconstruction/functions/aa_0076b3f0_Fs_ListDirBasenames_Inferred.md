# Function record: Fs_ListDirBasenames_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076b3f0` |
| **Canonical name** | `Fs_ListDirBasenames_Inferred` |
| **Ghidra name** | `FUN_0076b3f0` |
| **Address** | `0x0076b3f0`–`0x0076b54e` (**351 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | filesystem / directory enumeration |
| **Wave** | W33-C OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_0076b3f0_Fs_ListDirBasenames_Inferred.md`, `reviews/B_aa_0076b3f0_Fs_ListDirBasenames_Inferred.md` |

## Purpose

Enumerate directory entries (or a single path/pattern) and push basenames into a caller `std::string` vector. Used by recursive leaf collectors and path-manager helpers near AssResolver / effect probe code.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `Fs_PathIsDirectory_Stat_Inferred` | `0x0076adc0` | peer W33-C; is_dir gate for `/*` |
| `Fs_DirRecurseCollectLeafPaths_Inferred` | `0x009839b0` | W32-D caller (fills listing then joins) |
| `FUN_004301f0` | `0x004301f0` | W33-D string-vector push (thiscall) |

## Signature

```c
void Fs_ListDirBasenames_Inferred(const char* path, void* out_string_vec /*cdecl*/);
```

## Artifacts

See `aa_0076b3f0_FUN_0076b3f0.md` for full paths and confidence table.
