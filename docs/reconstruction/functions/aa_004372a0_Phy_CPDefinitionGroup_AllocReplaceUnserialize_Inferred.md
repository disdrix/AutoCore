# Function record: Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004372a0` |
| **Canonical name** | `Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred` |
| **Ghidra name** | `FUN_004372a0` |
| **Address** | `0x004372a0` |
| **Body** | **158 B** (`0x004372a0`–`0x0043733e` exclusive) |
| **Module** | `autoassault.exe` |
| **System** | physics / phyCPDefinition CPDG alloc-replace-unserialize |
| **Name confidence** | **Inferred** |
| **Dual** | **accept-with-gaps** (W38-E A+B) |

## Role

Factory-style helper: `new` + ctor + refcount slot replace at `*EDI` + CPDG unserialize. Used from gfxBody / asset load paths that accumulate status with `OR`.

## ABI

| Slot | Value |
|---|---|
| EDI | `T**` out slot |
| stack | `stoChunkReader*` |
| cleanup | `RET 4` |
| return | status; `-1` on OOM (slot preserved) |

## Rejected aliases

- `Named_CalleeOf_Named_gfxBody_004372a0`
- Treating as pure thiscall / void

## Artifacts

See `aa_004372a0_FUN_004372a0.md`.
