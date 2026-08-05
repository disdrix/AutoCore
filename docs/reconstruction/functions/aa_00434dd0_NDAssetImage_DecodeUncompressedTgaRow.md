# Function record: NDAssetImage_DecodeUncompressedTgaRow

| Field | Value |
|---|---|
| **Stable ID** | `aa_00434dd0` |
| **Canonical name** | `NDAssetImage_DecodeUncompressedTgaRow` |
| **Ghidra name** | `FUN_00434dd0` |
| **Address** | `0x00434dd0`–`0x00434f08` (**312 bytes**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `gfx-asset` / `NDAssetImage` / TGA |
| **Completion status** | **Dual sealed (W22-O)** — raw/annotated/clean + A/B reviews |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Name confidence** | **INFERRED** (LoadTGA plate + row role; no local plate string) |

## Purpose

Decode an **uncompressed TGA** pixel span into an **RGB8** destination buffer, branching on bpp at `header+0x10`:

| bpp | Action |
|---|---|
| 8 | Bulk stream read `count` bytes |
| 15/16 | Per pixel: read 2 B; RGB555 → 3 B expand |
| 24 | Bulk stream read `count*3` bytes |
| 32 | Per pixel: read 4 B; write 3 B RGB; store A via `FUN_00433280` |

Used by `NDAssetImage_LoadTGA` for non-RLE image types, and by RLE helper for raw packets.

## Signature (sealed)

```c
// ECX=stream*, EDX=destRgb*, ret 0x14 (5 stack dwords)
void NDAssetImage_DecodeUncompressedTgaRow(
    Stream *stream,       // ECX; Read @ vtbl+8
    uint8_t *destRgb,     // EDX
    NDAssetImage *image,  // stack+0  (32bpp alpha only)
    void *header,         // stack+4  bpp @ +0x10
    int count,            // stack+8
    int y,                // stack+12
    int x0);              // stack+16
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00434dd0_FUN_00434dd0.md` |
| Annotated | `docs/reconstruction/raw/aa_00434dd0_FUN_00434dd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDAssetImage_DecodeUncompressedTgaRow.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00434dd0.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_00434dd0_FUN_00434dd0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00434dd0_NDAssetImage_DecodeUncompressedTgaRow.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00434dd0_NDAssetImage_DecodeUncompressedTgaRow.md` |

## Callers / callees

**Callers:** `NDAssetImage_LoadTGA` @ `0x00434a55`; `FUN_00434b30` @ `0x00434d45`.

**Callees:** stream `vtbl+8` (indirect); `FUN_00433280` (32bpp only).

## Confidence

| Claim | Level |
|---|---|
| bpp switch + bulk/loop CF | **Confirmed** |
| `ret 0x14` / ECX stream / EDX dest | **Confirmed** |
| RGB555 expand math (incl. `&0x1f` on R) | **Confirmed** (bytes; decomp residual noted) |
| Product English name | **Inferred** |
| Alpha plane layout in `FUN_00433280` | Residual (callee) |
| Runtime | Open |

## Related

- `aa_004347d0` NDAssetImage_LoadTGA (parent)
- `aa_004332e0` NDAssetImage_FlipVertical (post-process sibling)
- RLE sibling `FUN_00434b30` (out of owned scope)
