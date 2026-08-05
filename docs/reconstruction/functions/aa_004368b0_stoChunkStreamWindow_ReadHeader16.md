# Function record: stoChunkStreamWindow_ReadHeader16

| Field | Value |
|---|---|
| **Stable ID** | `aa_004368b0` |
| **Canonical name** | `stoChunkStreamWindow_ReadHeader16` |
| **Prior / Ghidra name** | `FUN_004368b0` |
| **Address** | `0x004368b0`–`0x004368f9` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `storage` / arda2 `stoChunk` |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-07-29 (W17-R OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_004368b0`
- OpenChunk dual residual: “binary ReadHeader” / `ReadBinaryHeader16`

## Purpose

Binary-mode **16-byte chunk header** reader for the stoChunk stream window:

1. If `available < cursor + 0x10`, call window ensure/refill `FUN_00435df0(window, base+cursor)`.
2. Fail (`−1`) if ensure returns negative **or** `available < 0x10` after ensure.
3. Copy **4×u32** from `window+0x18+cursor` into caller's out buffer.
4. Advance `cursor` by `0x10`; return `0`.

Sole caller: `stoChunkReader_OpenChunk` binary path (`reader+0x4044 == 0`), with ESI = `reader+0x14`, EDI = stack header.

## Signature (sealed)

```c
// Register ABI: ESI = StoStreamWindow*, EDI = uint32_t out[4]
// Returns 0 success, 0xffffffff fail. Plain RET.
int32_t stoChunkStreamWindow_ReadHeader16(/* ESI window, EDI out */);
```

## Window fields

| Off | Role |
|---:|---|
| `+0x04` | cursor |
| `+0x08` | base (added to cursor for ensure arg) |
| `+0x0c` | available |
| `+0x18` | data buffer base |

## Header out (16 B)

| Word | Field (plate) |
|---:|---|
| 0 | tag FOURCC |
| 1 | size |
| 2 | version |
| 3 | reserved |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004368b0_FUN_004368b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004368b0_FUN_004368b0.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/stoChunkStreamWindow_ReadHeader16.cpp` |
| Clean (FUN_*) | `docs/reconstruction/reconstructed-exact/FUN_004368b0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_004368b0_stoChunkStreamWindow_ReadHeader16.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004368b0_stoChunkStreamWindow_ReadHeader16.md` |

## Callers / callees

| Direction | Symbol | VA |
|---|---|---|
| Caller | `stoChunkReader_OpenChunk` | `0x0076a2c0` (call @ `0x0076a2ee`) |
| Callee | `FUN_00435df0` | `0x00435df0` (ensure/refill; not owned) |

## Confidence

| Claim | Level |
|---|---|
| CF: ensure-if-short → copy 16 → cursor+=16 → 0/−1 | **High** |
| ESI=window, EDI=out register ABI | **High** |
| Window offsets +0x4/+0x8/+0xc/+0x18 | **High** |
| 4-dword header order | **High** (width/order); field English **Probable** (OpenChunk plate) |
| Ensure full semantics | **Out of scope** (other VA) |
| Runtime / bit-exact | **Open** |
