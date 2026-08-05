# Function record: GlyphCache_InitGdiFont_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00754a10` |
| **Canonical name** | `GlyphCache_InitGdiFont_Inferred` |
| **Ghidra name** | `FUN_00754a10` |
| **Address** | `0x00754a10` |
| **Body** | **1228 B** (`0x00754a10`–`0x00754edc` exclusive) |
| **Module** | `autoassault.exe` |
| **System** | GlyphCache / gfxFontImpl GDI open |
| **Name confidence** | **Inferred** (path + host layout; no method plate) |
| **Dual** | **accept-with-gaps** (W38-N A+B) |

## Role

GDI face open + metrics + atlas DIB for a pre-constructed GlyphCache. Called from get-or-create with requested face, then `"Arial"` fallback on failure.

## ABI

| Slot | Value |
|---|---|
| ESI | `GlyphCache* this` |
| ECX | style flags |
| stack | `face*`, `height` |
| cleanup | `RET 8` |
| return | EAX `0` / `0xFFFFFFFF` |

## Rejected aliases

- `Named_gfxFontImpl_00754a10` (scaffold path seed only)
- Treating ECX as C++ this (decompiler `__thiscall` mislabel)

## Artifacts

See `aa_00754a10_FUN_00754a10.md`.
