# Function record: Gfx_DepthStencilFormat_ToBpp_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043b800` |
| **Canonical name** | `Gfx_DepthStencilFormat_ToBpp_Inferred` |
| **Ghidra name** | `FUN_0043b800` |
| **Address** | `0x0043b800` |
| **Body** | **49 B** (`0x0043b800`–`0x0043b831` exclusive) |
| **Module** | `autoassault.exe` |
| **System** | graphics / D3D depth-stencil format utility |
| **Name confidence** | **Inferred** (structural + exact D3DFMT depth enum match) |
| **Dual** | **accept** (W38-U A+B) |

## Role

Leaf mapper: depth/stencil `D3DFORMAT` → bits-per-pixel. Primary consumers convert via `(bpp * W * H) >> 3` into graphics memory counters (`DAT_00d1f614+0x3b0`) and surface byte-size helpers.

## ABI

| Slot | Value |
|---|---|
| EAX in | format |
| EAX out | bpp (0 = unknown) |
| cleanup | plain `RET` |

## Rejected aliases

- `Named_CalleeOf_Named_gfxDevice_0043b800`
- Conflation with `FUN_0040ead0` (color/texture bpp twin)

## Artifacts

See `aa_0043b800_FUN_0043b800.md`.
