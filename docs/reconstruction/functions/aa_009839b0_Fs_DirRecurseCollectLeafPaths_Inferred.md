# Function record: Fs_DirRecurseCollectLeafPaths_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009839b0` |
| **Canonical name** | `Fs_DirRecurseCollectLeafPaths_Inferred` |
| **Ghidra name** | `FUN_009839b0` |
| **Address** | `0x009839b0`–`0x00983b53` (**420 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | filesystem / path enumeration |
| **Wave** | W32-D OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_009839b0_Fs_DirRecurseCollectLeafPaths_Inferred.md`, `reviews/B_aa_009839b0_Fs_DirRecurseCollectLeafPaths_Inferred.md` |

## Purpose

Recursive directory leaf-path collector into a caller `std::string` vector. Used by path-expansion helpers near AssResolverCore / effect probe code.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `AssResolverCore_Ctor_Inferred` | `0x00983940` | adjacent prior function (W31-G) |
| `FUN_00984340` | `0x00984340` | caller with recurse flag |
| `FUN_00984c70` | `0x00984c70` | caller collect-then-process |
| `FUN_0076adc0` | `0x0076adc0` | is_directory helper (unowned) |
| `FUN_004301f0` | `0x004301f0` | string-vector push (unowned) |

## Signature

```c
int Fs_DirRecurseCollectLeafPaths_Inferred(const char* path, void* out_string_vec /*cdecl*/);
```

## Artifacts

See `aa_009839b0_FUN_009839b0.md` for full paths and confidence table.
