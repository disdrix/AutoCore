# Function record: FUN_0040ead0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ead0` |
| **Canonical name** | `FUN_0040ead0` |
| **Preferred name** | `D3dFormat_GetBitsPerPixel_Inferred` |
| **Address** | `0x0040ead0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Graphics / D3D format utility |
| **Body** | jump-table leaf through index end `0x0040eb90` (**193 B** / `0xC1`) |
| **ABI** | `__cdecl`; stack `(format)`; returns bpp; plain `ret` |
| **Classification** | leaf |
| **Completion status** | **Dual-sealed W38-T** — accept |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |

## Alias

- **Prefer:** `D3dFormat_GetBitsPerPixel_Inferred`
- **Reject:** `Named_CalleeOf_Named_gfxDevice_0040ead0` (scaffold noise)

## Purpose

Map D3DFORMAT (and engine-extended values) to **bits per pixel**. Unknown → 0. Used by GfxDevice reset memory accounting, texture size math, paint-pallet path, etc. Callers convert with `bpp >> 3`.

## Signature

```c
uint32_t D3dFormat_GetBitsPerPixel_Inferred(uint32_t d3d_format);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040ead0_FUN_0040ead0.md`
- Annotated: `docs/reconstruction/raw/aa_0040ead0_FUN_0040ead0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/D3dFormat_GetBitsPerPixel_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0040ead0.cpp`
- Function named: `docs/reconstruction/functions/aa_0040ead0_D3dFormat_GetBitsPerPixel_Inferred.md`
- Review A: `docs/reconstruction/reviews/A_aa_0040ead0_D3dFormat_GetBitsPerPixel_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040ead0_D3dFormat_GetBitsPerPixel_Inferred.md`

## Callers / callees

- **Callees:** none (leaf)
- **Callers (17):** `FUN_0075eff0` (GfxDevice_Reset), `FUN_0075fc40`, `FUN_00735410`, `FUN_007358c0`, `FUN_00735c90`, `FUN_0073c350`/`4d0`/`610`, `FUN_00583170`, `FUN_005843b0`, `FUN_00850140`, `FUN_00850490`, `FUN_00858080`, `FUN_008edf80`, `FUN_007b09a0`, `FUN_0096c300`, `FUN_0096c450`, …

## Confidence

| Claim | Level |
|---|---|
| Switch CF / jump tables | Confirmed |
| Return = bits-per-pixel | Confirmed (caller `shr 3`) |
| `__cdecl` / `add esp,4` | Confirmed |
| Core D3DFMT identities | High |
| Extended `0x6f`–`0x74` product names | Open |
| Runtime / diff | Open |
