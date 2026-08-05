# Function record: CxImage_Create

| Field | Value |
|---|---|
| **Stable ID** | `aa_004323e0` |
| **Canonical name** | `CxImage_Create` |
| **Name confidence** | **High** — plate strings `CxImage::Create …` |
| **Ghidra** | `FUN_004323e0` |
| **Address** | `0x004323e0`–`0x0043255f` (Ghidra range to `0x00432575`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | graphics / CxImage |
| **Completion status** | **Dual A/B sealed** (W22-Q 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Verdict** | **accept-with-gaps** |

## Alias

- Ghidra: `FUN_004323e0`
- Registry: `CxImage_Create` / `CxImage::Create`

## Purpose

Allocate and install a CxImage pixel buffer for given width, height, bpp, and type: quantize bpp→bit depth, enforce `CXIMAGE_MAX_MEMORY`, `malloc` BITMAPINFOHEADER+palette+bits, zero palette, copy header into block, set bits pointer.

## Signature (retail)

```c
// EBX = this, EAX = height, stack (width, bpp, type), RET 12
int32_t* CxImage_Create(CxImage* self /*EBX*/,
                        int32_t height /*EAX*/,
                        int32_t width,
                        uint32_t bpp,
                        uint32_t type);
// returns malloc block / BITMAPINFO* or NULL
```

## Key offsets

| Off | Field |
|---|---|
| `+0x04` | block |
| `+0x08` | biSize (0x28) |
| `+0x0c` / `+0x10` | width / height |
| `+0x14` / `+0x16` | planes / bitCount |
| `+0x1c` | imageBytes |
| `+0x28` | paletteCount |
| `+0x30` | stride |
| `+0x34` | bits |
| `+0x40` | type |
| `+0x44` | lastError |
| `+0x1b0` | optional secondary gate |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004323e0_FUN_004323e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004323e0_FUN_004323e0.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/CxImage_Create.cpp` |
| Clean (Ghidra alias) | `docs/reconstruction/reconstructed-exact/FUN_004323e0.cpp` |
| Function (Ghidra) | `docs/reconstruction/functions/aa_004323e0_FUN_004323e0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_004323e0_CxImage_Create.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004323e0_CxImage_Create.md` |

## Callers / callees

| Kind | Target |
|---|---|
| Callees | `FUN_004321b0`, `malloc`, `FUN_00433490`, `FUN_004331d0` |
| Callers | `NDAssetImage_LoadTGA` `0x004347d0`; BMP `FUN_00433dc0`; PNG `FUN_00435410`; WBMP `FUN_0098b5b0`; `FUN_00432260` |

## Confidence

| Claim | Level |
|---|---|
| Control flow / strings / MAX_MEMORY / stride | **High** |
| ABI EBX/EAX/stack/ret12 | **High** |
| Nested callees' full semantics | **Tentative** |
| Runtime | **Open** |
