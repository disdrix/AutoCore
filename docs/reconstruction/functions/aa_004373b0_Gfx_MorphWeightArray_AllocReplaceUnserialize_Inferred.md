# Function record: Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004373b0` |
| **Canonical name** | `Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred` |
| **Ghidra name** | `FUN_004373b0` |
| **Address** | `0x004373b0` |
| **Body** | **105 B** (`0x004373b0`–`0x00437419` exclusive) |
| **Module** | `autoassault.exe` |
| **System** | graphics / gfxMorphWeightArrayImpl MWGT alloc-replace-unserialize |
| **Name confidence** | **Inferred** |
| **Dual** | **accept-with-gaps** (W38-E A+B) |

## Role

Factory-style helper: `new` + inline ctor + refcount slot replace at `host+4` + MWGT unserialize. Loop callers step host by 8 bytes.

## ABI

| Slot | Value |
|---|---|
| EBX | `host*` with slot at `+4` |
| stack | `stoChunkReader*` |
| cleanup | `RET 4` |
| return | status from unserialize (not void) |

## Rejected aliases

- `Named_CalleeOf_Named_gfxBody_004373b0`
- Treating as pure void / no stack reader
- Conflating OOM policy with phy twin `0x004372a0`

## Artifacts

See `aa_004373b0_FUN_004373b0.md`.
