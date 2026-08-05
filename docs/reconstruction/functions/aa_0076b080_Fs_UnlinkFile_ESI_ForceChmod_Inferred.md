# Function record: Fs_UnlinkFile_ESI_ForceChmod_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076b080` |
| **Canonical name** | `Fs_UnlinkFile_ESI_ForceChmod_Inferred` |
| **Ghidra name** | `FUN_0076b080` |
| **Address** | `0x0076b080`–`0x0076b0f1` (**114 B**) |
| **Module** | `autoassault.exe` base `0x400000` |
| **System** | filesystem |
| **Wave** | W37-S |
| **Verdict** | **accept** |
| **Classification** | worker |

## Signature

```c
bool __cdecl Fs_UnlinkFile_ESI_ForceChmod_Inferred(char force /* ESI = path */);
// ADD ESP,0x28; RET; full 114 B hex in raw
```

## Evidence anchors

| Fact | Source |
|---|---|
| Full body hex | `read_memory` 114 B |
| ESI path | body + call sites LEA/PUSH force |
| Force chmod gate | `CMP [esp+0x28],0` + mode bits |
| Callers | `0076ba10`, `0076bc00`, `007b75b0` |
| Peer | W34-A `Fs_DeleteDirTreeRecursive` file arm |

## Port note

Port as **single-file force-unlink** with optional make-writable. Path is **register formal ESI**, not a stack string. Pair with recursive dir delete (W34-A). Do not treat force as path.

## Artifacts

See `aa_0076b080_FUN_0076b080.md`.
