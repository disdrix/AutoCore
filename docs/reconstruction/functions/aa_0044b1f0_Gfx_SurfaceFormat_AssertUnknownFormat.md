# Function record: Gfx_SurfaceFormat_AssertUnknownFormat

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044b1f0` |
| **Canonical name** | `Gfx_SurfaceFormat_AssertUnknownFormat` |
| **Role alias** | `Gfx_SurfaceFormat_CalcByteSize` (primary path is size) |
| **Address** | `0x0044b1f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | graphics |
| **Completion status** | **Dual A/B accept** (2026-07-29) — size CF + unknown log sealed; full D3D enum names Open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_0044b1f0`
- Prior auto-slug names (if any): leave on disk; canonical is `Gfx_SurfaceFormat_AssertUnknownFormat`

## Purpose

Compute texture surface **byte size** from format enum/FourCC + width + height; unknown formats log via `vog_LogMessage` (`effSurfaceFormat.h` line `0x1f2`) and return 0. Canonical name only highlights the unknown branch.

## String evidence

`"..\\palantir/graphics/Effects/effSurfaceFormat.h"`  
`"Unknown Texture format : format:%u width:%u height:%u"`

## Signature (sealed)

```c
// format=ECX, width=EAX, height=ESI  (register formals; plain ret)
int Gfx_SurfaceFormat_AssertUnknownFormat(int format /*, int width in EAX, int height in ESI */);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0044b1f0_FUN_0044b1f0.md`
- Annotated: `docs/reconstruction/raw/aa_0044b1f0_FUN_0044b1f0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Gfx_SurfaceFormat_AssertUnknownFormat.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_0044b1f0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0044b1f0_Gfx_SurfaceFormat_AssertUnknownFormat.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0044b1f0_Gfx_SurfaceFormat_AssertUnknownFormat.md`

## Callers / callees

| Callers | Callees |
|---|---|
| `FUN_0096c730`, `FUN_0096c810` | `FUN_0076cec0`, `vog_LogMessage` |

## Confidence

| Claim | Level |
|---|---|
| Control flow / multipliers / DXT block math | **High** (dual sealed) |
| Register formals ECX/EAX/ESI | **High** |
| Naming from string literals | **High** (path); role name **Probable** partial |
| Full enum English map | Open |
