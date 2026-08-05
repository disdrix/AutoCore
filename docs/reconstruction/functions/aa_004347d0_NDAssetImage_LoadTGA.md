# Function record: NDAssetImage_LoadTGA

| Field | Value |
|---|---|
| **Stable ID** | `aa_004347d0` |
| **Canonical name** | `NDAssetImage_LoadTGA` |
| **Address** | `0x004347d0` |
| **Body** | `0x004347d0` – `0x00434b11` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `gfx-asset` / `NDAssetImage` |
| **Completion status** | **Dual-reviewed** — three-rep decompile sealed CF; residual row-decoder / stream type names |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Load TGA into `NDAssetImage` from an abstract stream. Bottom-origin keeps file row order; top-origin (image-descriptor bit5) **and** 32bpp calls `NDAssetImage_FlipVertical` so `GetPixel` y=0 is always image bottom. Used (via `FUN_00432cb0`) by terrain map image path for `map.tga` area ids.

## Signature (decompiler-derived + prologue)

```c
// Free function: image*, stream*  — formals [ebp+8], [ebp+0xc]
// return 1 success; return 0 if stream==null; otherwise throws on hard errors
undefined4 NDAssetImage_LoadTGA(int image, int *stream);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004347d0_NDAssetImage_LoadTGA.md`
- Annotated: `docs/reconstruction/raw/aa_004347d0_NDAssetImage_LoadTGA.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDAssetImage_LoadTGA.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004347d0_NDAssetImage_LoadTGA.md`
- Review B: `docs/reconstruction/reviews/B_aa_004347d0_NDAssetImage_LoadTGA.md`

## Callers / callees

**Callers (direct):**

| Caller | Sites |
|---|---|
| `FUN_00432cb0` | `0x00432d14`, `0x00432ff6` |

**Callees:**

| VA | Symbol |
|---|---|
| `0x004323e0` | `FUN_004323e0` (create) |
| `0x00433180` | `FUN_00433180` (32bpp setup) |
| `0x00433440` | `FUN_00433440` (palette entry) |
| `0x00433a00` | `FUN_00433a00` (greyscale prep) |
| `0x00433d30` | `FUN_00433d30` (pre-row setup) |
| `0x00433d70` | `FUN_00433d70` (per-row state) |
| `0x00434dd0` | `FUN_00434dd0` (uncompressed row) |
| `0x00434b30` | `FUN_00434b30` (RLE row) |
| `0x004332e0` | `NDAssetImage_FlipVertical` |
| `0x0098acc0` | `FUN_0098acc0` (probable H-flip) |
| `0x006a3d60` | `_CxxThrowException` |

## Key fields / constants

| Item | Value |
|---|---|
| Header size | `0x12` (18) |
| Image types raw | 1, 2, 3 |
| Image types RLE | 9, 10, 11 |
| Allowed bpp | 8, 15, 16, 24, 32 |
| Colormap max length | `0x100` |
| Image create result | `image+0x4` (null → throw) |
| Cancel flag | `image+0x148` |
| Descriptor bit4 | right-origin → `FUN_0098acc0` |
| Descriptor bit5 | top-origin; + bpp32 → `FlipVertical` |

## Three-rep (2026-07-29)

| Rep | Tool | Result |
|---|---|---|
| A | `decompile_function` | Baseline |
| B | `force_decompile` | Identical |
| C | `batch_decompile` + `read_memory` prologue + xrefs | Identical body; ABI formals sealed; sole caller `FUN_00432cb0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler (three-rep) | **High** |
| Header / type / bpp / origin gates | **High** |
| Parameter semantic names (image / stream) | **High** role; stream type English **Tentative** |
| Row decoder internals | **Tentative** (out of own-VA scope) |
| Dual A/B | **accept-with-gaps** |
