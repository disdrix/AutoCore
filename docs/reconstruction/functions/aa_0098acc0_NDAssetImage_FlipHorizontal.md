# Function record: NDAssetImage_FlipHorizontal

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098acc0` |
| **Canonical name** | `NDAssetImage_FlipHorizontal` |
| **Prior scaffold** | `FUN_0098acc0` |
| **Address** | `0x0098acc0`–`0x0098ae77` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client assets / `NDAssetImage` |
| **Completion status** | **Dual reviewed** — three-rep present; A/B sealed CF **accept-with-gaps** (2026-07-29 W20-L) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Horizontal flip of an `NDAssetImage` for **TGA image-descriptor bit4** (right→left origin). Allocates a temp image (`0x1b8`), reverse-copies the `+0x34` pixel store bpp-aware (8 / 24 / other), post-processes via `FUN_00433390` + `FUN_00432580` (move into original), destroys temp. Sibling of `NDAssetImage_FlipVertical` (`0x004332e0`). Sole caller: `NDAssetImage_LoadTGA` (`0x004347d0`).

## Signature (decompiler + bytes)

```c
// this in EDI; return AL = 0 fail / 1 success; frame SUB ESP,0x10; plain RET
uint8_t /* bool in AL */ NDAssetImage_FlipHorizontal(/* NDAssetImage* this in EDI */);
```

| Offset | Field |
|---|---|
| `+0x04` | Valid/create gate |
| `+0x0c` | Width (pixels) |
| `+0x10` | Height (rows) |
| `+0x16` | bpp (`short`) |
| `+0x30` | Row pitch (bytes) for `+0x34` |
| `+0x34` | Pixel buffer (raw reverse-copy target/source) |
| `+0x1b0` | Working buffer (post via `FUN_00433390` / transfer) |

## Artifacts

- Raw scaffold + re-verify: `docs/reconstruction/raw/aa_0098acc0_FUN_0098acc0.md`
- Raw named: `docs/reconstruction/raw/aa_0098acc0_NDAssetImage_FlipHorizontal.md`
- Annotated named: `docs/reconstruction/raw/aa_0098acc0_NDAssetImage_FlipHorizontal.annotated.md`
- Annotated scaffold: `docs/reconstruction/raw/aa_0098acc0_FUN_0098acc0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDAssetImage_FlipHorizontal.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0098acc0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0098acc0_NDAssetImage_FlipHorizontal.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0098acc0_NDAssetImage_FlipHorizontal.md`

## Callers / callees

| Direction | Symbol | VA |
|---|---|---|
| Caller | `NDAssetImage_LoadTGA` | `0x004347d0` |
| Callee | `operator_new` | `0x00489892` |
| Callee | `FUN_004320d0` | `0x004320d0` (temp init) |
| Callee | `FUN_00432260` | `0x00432260` (clone setup) |
| Callee | `FUN_00433530` / `FUN_004337d0` | other-bpp pixel path |
| Callee | `FUN_00433390` | `0x00433390` (`+0x1b0` horizontal reverse) |
| Callee | `FUN_00432580` | `0x00432580` (move temp → original) |
| Sibling | `NDAssetImage_FlipVertical` | `0x004332e0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + entry/tail bytes | **High** |
| Horizontal (not vertical) reverse of rows | **High** |
| this in EDI; AL return | **High** |
| TGA bit4 sole caller gate | **High** |
| bpp 8 / 24 dedicated loops | **High** |
| Field map `+4/+c/+10/+16/+30/+34` | **High** |
| Product English name of helpers | **Tentative** (not OWN) |
| Dual-buffer `+0x34` vs `+0x1b0` product model | **Probable** residual |
