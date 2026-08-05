# Function record: GlyphCache_GetOrCreate_ByFontKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073bc50` |
| **Canonical name** | `GlyphCache_GetOrCreate_ByFontKey_Inferred` |
| **Ghidra name** | `FUN_0073bc50` |
| **Address** | `0x0073bc50`–`0x0073be47` exclusive (**503 B** / `0x1F7`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | GlyphCache / gfxFont font-key map |
| **Completion status** | **Dual-sealed W37-AE** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Classification** | worker (get-or-create factory) |

## Alias

- Ghidra: `FUN_0073bc50`
- Reject scaffold: `Named_CalleeOf_Named_gfxFont_0073bc50` (parent-seed only)

## Purpose

Map get-or-create of a **GlyphCache** (`0xB8`) keyed by font name + size/style dwords. Miss path: `new(0xB8)` + `GlyphCache_PlacementCtor` (W35-H) + `FUN_00754a10` (requested face, then **`"Arial"`** fallback). Fail: scalar deleting dtor, return null. Hit: return `*(node+0x2c)`.

## Signature (sealed)

```c
// ECX + 3 stack formals; RET 12; returns GlyphCache* (null on fail)
GlyphCache* GlyphCache_GetOrCreate_ByFontKey_Inferred(
    int size_or_style /*ECX*/,
    void* map /*stack*/,
    const char* face_name /*stack*/,
    int key_dword_b /*stack*/);
```

## Product evidence

- Sole CODE caller `FUN_0099ed40` logs `"Failed to create font: %s"` with path  
  `C:\vog\1_code\palantir\palantir\graphics\gfxFont.cpp`.
- Body immediate `"Arial"` @ `0x00aa267c`.
- Placement ctor peer W35-H seals **GlyphCache** via vtbl-adjacent  
  `"Failed to create texture for glyph cache"`.
- Map global at sole site: `DAT_00d1f628`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0073bc50_FUN_0073bc50.md` (+ W37-AE append)
- Annotated: `docs/reconstruction/raw/aa_0073bc50_FUN_0073bc50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GlyphCache_GetOrCreate_ByFontKey_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0073bc50.cpp`
- A: `docs/reconstruction/reviews/A_aa_0073bc50_GlyphCache_GetOrCreate_ByFontKey_Inferred.md`
- B: `docs/reconstruction/reviews/B_aa_0073bc50_GlyphCache_GetOrCreate_ByFontKey_Inferred.md`

## Callers / callees

| Dir | Target |
|-----|--------|
| Caller (1) | `FUN_0099ed40` @ `0x0099ed4e` |
| Callee | `FUN_00463c40` map lower_bound |
| Callee | `operator_new(0xB8)` |
| Callee | `FUN_00754ee0` GlyphCache_PlacementCtor (W35-H) |
| Callee | `FUN_00754a10` font rasterize (×2 possible) |
| Callee | `FUN_004638c0` map insert |
| Callee | IAT `basic_string` ctor/assign/dtor/copy |

## Confidence

| Claim | Level |
|---|---|
| Body 503 B / RET 12 / SEH | **High** |
| Get-or-create + Arial fallback | **High** |
| GlyphCache product + 0xB8 | **High** (W35-H + caller) |
| Hit value at node+0x2c | **High** |
| Exact formal product English (size vs style) | **Medium** |
| Map / node full layout dual | **Open** (unowned helpers) |
