# Function record: NDAssetImage_Flip

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098ae80` |
| **Canonical name** | `NDAssetImage_Flip` |
| **Address** | `0x0098ae80`–`0x0098af4c` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client assets / `NDAssetImage` (CxImage Flip) |
| **Completion status** | **Dual-sealed accept-with-gaps** (W20-K 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Status |
|---|---|
| `FUN_0098ae80` | Ghidra scaffold |
| `NDAssetImage_Flip` | **Structural sealed** (CxImage::Flip behavior; PDB open) |
| `NDAssetImage_FlipVertical` (`0x004332e0`) | **Sibling** — only `+0x1b0` buffer, not this unit |

## Purpose

In-place vertical flip via temp clone:

1. Fail if `image+4` (DIB) null or `new(0x1b8)` fails.
2. Construct/copy temp (`FUN_004320d0`, `FUN_00432260(...,1)`).
3. Reverse-copy DIB rows (`pitch+0x30`, `pBits+0x34`, `height+0x10`).
4. `NDAssetImage_FlipVertical` on temp; transfer fields back (`FUN_00432580`); dtor temp.

Caller: BMP loader `FUN_00433dc0` when top-down (`biHeight < 0`).

## Signature (machine)

```c
// stack NDAssetImage* image; ret 4; AL 0/1
uint8_t NDAssetImage_Flip(NDAssetImage* image);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0098ae80_FUN_0098ae80.md`
- Annotated: `docs/reconstruction/raw/aa_0098ae80_FUN_0098ae80.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDAssetImage_Flip.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0098ae80.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0098ae80_NDAssetImage_Flip.md`
- Review B: `docs/reconstruction/reviews/B_aa_0098ae80_NDAssetImage_Flip.md`

## Callers / callees

| Dir | Symbol | VA / note |
|---|---|---|
| caller | `FUN_00433dc0` (BMP decode) | xref `0x004345f0` |
| callee | `operator_new` | size `0x1b8` |
| callee | `FUN_004320d0` / `FUN_00432260` | ctor / copy |
| callee | `NDAssetImage_FlipVertical` | `0x004332e0` |
| callee | `FUN_00432580` | transfer ownership |
| callee | vtbl dtor | `(*vtbl)(1)` |

## Confidence

| Claim | Level |
|---|---|
| In-place vertical flip via temp | **High** |
| ret 4, size 0x1b8, pitch/pBits/height | **High** |
| Top-down BMP caller role | **High** |
| Product CxImage::Flip symbol | **Open** / Probable |
| Runtime / bit-exact | **Open** |
