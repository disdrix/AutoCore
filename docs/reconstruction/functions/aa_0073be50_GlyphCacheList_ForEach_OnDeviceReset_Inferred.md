# Function record: GlyphCacheList_ForEach_OnDeviceReset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073be50` |
| **Canonical name** | `GlyphCacheList_ForEach_OnDeviceReset_Inferred` |
| **Ghidra name** | `FUN_0073be50` |
| **Address** | `0x0073be50` |
| **Body** | **36 B** (`0x0073be50`–`0x0073be74` exclusive) |
| **Module** | `autoassault.exe` |
| **System** | graphics / GlyphCache device-reset broadcast |
| **Name confidence** | **Inferred** (Reset call site + GlyphCache node+0x2c family) |
| **Dual** | **accept-with-gaps** (W38-U A+B) |

## Role

Broadcast device-reset hook across all GlyphCache instances registered in the circular list owned at `gfxDevice+0x758`. Worker leaf under `GfxDevice_Reset` success path.

## ABI

| Slot | Value |
|---|---|
| EBX | container / list manager |
| ESI (to callee) | `*(node+0x2c)` GlyphCache* |
| return | always 0 |
| cleanup | plain `RET` |

## Rejected aliases

- `Named_CalleeOf_Named_gfxDevice_0073be50`
- Treating as GlyphCache factory (that is `FUN_0073bc50`)

## Artifacts

See `aa_0073be50_FUN_0073be50.md`.
