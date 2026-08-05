# Function record: NDAssetImage_FlipVertical

| Field | Value |
|---|---|
| **Stable ID** | `aa_004332e0` |
| **Canonical name** | `NDAssetImage_FlipVertical` |
| **Address** | `0x004332e0`–`0x0043382` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client assets / `NDAssetImage` |
| **Completion status** | **Dual reviewed** — three-rep present; A/B sealed CF **accept-with-gaps** (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Vertical flip of the `NDAssetImage` pixel buffer at `this+0x1b0`: malloc full `pitch×height`, copy rows bottom→top, free old, install new. Used so GetPixel y=0 is image bottom after top-origin TGA (see `NDAssetImage_LoadTGA`).

## Signature (decompiler + bytes)

```c
// this in EBX; return AL = 0 fail / 1 success
undefined4 /* bool in AL */ NDAssetImage_FlipVertical(void /* NDAssetImage* this in EBX */);
```

| Offset | Field |
|---|---|
| `+0x0c` | Row pitch (bytes) |
| `+0x10` | Height (rows) |
| `+0x1b0` | Pixel buffer pointer |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004332e0_NDAssetImage_FlipVertical.md`
- Annotated: `docs/reconstruction/raw/aa_004332e0_NDAssetImage_FlipVertical.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDAssetImage_FlipVertical.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004332e0_NDAssetImage_FlipVertical.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004332e0_NDAssetImage_FlipVertical.md`

## Callers / callees

| Direction | Symbol | VA |
|---|---|---|
| Caller | `NDAssetImage_LoadTGA` | `0x004347d0` (xref `0x00434a93`) |
| Caller | `FUN_0098ae80` | `0x0098ae80` (xref `0x0098af31`) |
| Callee | `malloc` | IAT `0x009c6528` |
| Callee | `free` | IAT `0x009c6524` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| Vertical row reverse (not horizontal) | **High** |
| `+0x0c` pitch / `+0x10` height / `+0x1b0` buffer | **High** |
| this in EBX; AL return | **High** |
| `+0x0c` product name vs width×bpp | **Probable** |
| Full class layout beyond these fields | **Tentative** |
