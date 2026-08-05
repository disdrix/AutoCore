# Function record: Fs_PathIsDirectory_Stat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076adc0` |
| **Canonical name** | `Fs_PathIsDirectory_Stat_Inferred` |
| **Ghidra name** | `FUN_0076adc0` |
| **Address** | `0x0076adc0`–`0x0076ae35` (**118 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | filesystem / path probe |
| **Wave** | W33-C OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_0076adc0_Fs_PathIsDirectory_Stat_Inferred.md`, `reviews/B_aa_0076adc0_Fs_PathIsDirectory_Stat_Inferred.md` |

## Purpose

Return whether a path names an existing directory via CRT `stat` and the `S_IFDIR` bit. Shared helper for directory listing (`0076b3f0`), recursive leaf collect (`009839b0`), and ass/path managers.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `Fs_ListDirBasenames_Inferred` | `0x0076b3f0` | peer W33-C; calls this for `/*` gate |
| `Fs_DirRecurseCollectLeafPaths_Inferred` | `0x009839b0` | W32-D caller (is_dir gate) |
| `FUN_004301f0` | `0x004301f0` | W33-D string-vector push (sibling FS stack) |

## Signature

```c
uint32_t Fs_PathIsDirectory_Stat_Inferred(const char* path /*cdecl*/);
```

## Artifacts

See `aa_0076adc0_FUN_0076adc0.md` for full paths and confidence table.
