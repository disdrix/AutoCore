# Function record: Fs_DeleteDirTreeRecursive_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076ba10` |
| **Canonical name** | `Fs_DeleteDirTreeRecursive_Inferred` |
| **Ghidra name** | `FUN_0076ba10` |
| **Address** | `0x0076ba10`–`0x0076bbff` (**495 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | filesystem / recursive directory delete |
| **Wave** | W34-A OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |

## Signature

```c
bool __cdecl Fs_DeleteDirTreeRecursive_Inferred(const char* path, char recursive_force);
```

## Artifacts

See `aa_0076ba10_FUN_0076ba10.md`.
