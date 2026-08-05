# Function record: NDAssetImage_WriteAlphaPlaneByte

| Field | Value |
|---|---|
| **Stable ID** | `aa_00433280` |
| **Canonical name** | `NDAssetImage_WriteAlphaPlaneByte` |
| **Prior scaffold** | `FUN_00433280` |
| **Address** | `0x00433280` |
| **Body** | `0x00433280`–`0x004332ac` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `gfx-asset` / `NDAssetImage` / alpha plane |
| **Completion status** | **Dual A/B sealed** (W23-A, 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Write one `uint8` into the image **alpha plane** at `(col, row)` when the plane pointer at `this+0x1b0` is non-null and coordinates are in-range (`0 ≤ col < width@+0xc`, `0 ≤ row < height@+0x10`). Out-of-range / null plane → silent no-op.

## Signature (machine-sealed)

```c
// EAX=this, ESI=row, EDX=col, stack alpha; RET 4
void NDAssetImage_WriteAlphaPlaneByte(void *image, int row, int col, uint8_t alpha);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00433280_FUN_00433280.md`
- Annotated: `docs/reconstruction/raw/aa_00433280_FUN_00433280.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDAssetImage_WriteAlphaPlaneByte.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00433280.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00433280_NDAssetImage_WriteAlphaPlaneByte.md`
- Review B: `docs/reconstruction/reviews/B_aa_00433280_NDAssetImage_WriteAlphaPlaneByte.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callees | **none** (leaf) |
| Callers | `NDAssetImage_DecodeUncompressedTgaRow` (`0x00434dd0` @ `0x00434efb`); PNG path `FUN_00435410` @ `0x00435a10` |
| Sibling | `FUN_004332b0` read counterpart (same plane layout) |

## Confidence

| Claim | Level |
|---|---|
| Control flow / bounds / index math | **High** (bytes) |
| Register ABI (EAX/ESI/EDX + RET 4) | **High** (bytes + call sites) |
| Alpha plane role of `+0x1b0` | **High** (TGA/PNG alpha write sites) |
| Product English name | **Structural** (NDAssetImage family; no RTTI on VA) |
| Full image object size | **Open** |
