# Function record: Fs_CreateDirectoryForce_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076bc00` |
| **Canonical name** | `Fs_CreateDirectoryForce_Inferred` |
| **Ghidra name** | `FUN_0076bc00` |
| **Address** | `0x0076bc00` |
| **Body** | **121 B** (`0x0076bc00`–`0x0076bc79` exclusive) |
| **Module** | `autoassault.exe` |
| **System** | filesystem |
| **Name confidence** | **Inferred** (structural; no product/PDB plate) |
| **Dual** | **accept** (W37-Z A+B) |

## Role

Force-capable directory create used by pack/compact paths (`AssPackManager_CompactPackFile` with `"_pk_"` force=1) and sibling mkpath helpers.

## ABI

| Slot | Value |
|---|---|
| stack+4 | `const char* path` |
| stack+8 | `char force_clear` |
| return | bool AL (`CreateDirectoryA != 0`) |
| cleanup | `ADD ESP,0x24; RET` (cdecl) |

## Rejected aliases

- `Named_CalleeOf_Named_NDRenderEngine_0076bc00`

## Artifacts

See `aa_0076bc00_FUN_0076bc00.md`.
