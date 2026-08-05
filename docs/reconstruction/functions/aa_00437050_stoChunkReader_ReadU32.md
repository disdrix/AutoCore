# Function record: stoChunkReader_ReadU32

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437050` |
| **Canonical name** | `stoChunkReader_ReadU32` |
| **Prior / Ghidra name** | `FUN_00437050` |
| **Address** | `0x00437050`–`0x00437095` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `storage` / arda2 `stoChunk` |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-07-29 (W18-N OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_00437050`
- Scaffold: `Named_CalleeOf_Named_gfxBody_00437050`
- Binary 4-byte peer of text `FUN_007689e0`

## Purpose

Binary-mode **single dword** reader for stoChunk:

1. If `available < cursor + 4`, call window ensure/refill `FUN_00435df0(window, base+cursor)`.
2. Fail (`−1`) if ensure returns negative **or** `available < 4` after ensure.
3. Store **1×u32** from `window+0x18+cursor` into caller's out pointer.
4. Advance `cursor` by `4`; return `0`.

Entry takes the **full reader** in **EAX** and remaps to the stream window at `reader+0x14` (same window layout as `stoChunkStreamWindow_ReadHeader16`).

## Signature (sealed)

```c
// EAX = StoChunkReader*, stack = uint32_t* out, epilogue RET 4
// Returns 0 success, 0xffffffff fail.
int32_t stoChunkReader_ReadU32(/* EAX reader */, uint32_t* out);
```

## Window fields (via reader+0x14)

| Reader off | Window off | Role |
|---:|---:|---|
| `+0x18` | `+0x04` | cursor |
| `+0x1c` | `+0x08` | base |
| `+0x20` | `+0x0c` | available |
| `+0x2c` | `+0x18` | data buffer base |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00437050_FUN_00437050.md` |
| Annotated | `docs/reconstruction/raw/aa_00437050_FUN_00437050.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/stoChunkReader_ReadU32.cpp` |
| Clean (FUN_*) | `docs/reconstruction/reconstructed-exact/FUN_00437050.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00437050_stoChunkReader_ReadU32.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00437050_stoChunkReader_ReadU32.md` |
| Function alias | `docs/reconstruction/functions/aa_00437050_FUN_00437050.md` |

## Callers / callees

| Direction | Symbol | VA / notes |
|---|---|---|
| Callee | `FUN_00435df0` | `0x00435df0` ensure/refill (not owned) |
| Caller | `FUN_00436900` | mode dispatcher (binary → this; text → `FUN_007689e0`) |
| Caller | `stoChunkReader_OpenChunk` | binary path call @ `0x0076a650` |
| Caller | many binary unserialize paths | 40+ xrefs (phyBone, gfx, inventory, …) |

## Confidence

| Claim | Level |
|---|---|
| CF: ensure-if-short → copy 4 → cursor+=4 → 0/−1 | **High** |
| EAX=reader, stack out, RET 4 | **High** |
| Window @ reader+0x14 field map | **High** |
| Binary-mode role (peer of text reader) | **High** |
| Product English signedness (U32 vs I32) | **Probable** (width sealed) |
| Ensure full semantics | **Out of scope** |
| Runtime / bit-exact | **Open** |
