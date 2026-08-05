# Function record: stoChunkReader_ReadU8

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437000` |
| **Canonical name** | `stoChunkReader_ReadU8` |
| **Prior / Ghidra name** | `FUN_00437000` |
| **Address** | `0x00437000`–`0x00437048` (**73 B** / `0x49`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `storage` / arda2 `stoChunk` |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (W38-D OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_00437000`
- Scaffold: `Named_CalleeOf_Named_gfxBody_00437000` (**reject** as product alias)
- Binary 1-byte peer of text `FUN_00769660` (bool-token path)
- Width sibling of `stoChunkReader_ReadU32` (`0x00437050`)

## Purpose

Binary-mode **single byte** reader for stoChunk:

1. Remap **EAX** reader → window at `reader+0x14`.
2. If `available < cursor + 1`, call window ensure/refill `FUN_00435df0(window, base+cursor)`.
3. Fail (`−1`) if ensure returns negative **or** `available < 1` after ensure.
4. Store **1×u8** from `window+0x18+cursor` into caller's out pointer (**EDI**).
5. Advance `cursor` by `1`; return `0`.

## Signature (sealed)

```c
// EAX = StoChunkReader*, EDI = uint8_t* out, bare RET
// Returns 0 success, 0xffffffff fail.
int32_t stoChunkReader_ReadU8(/* EAX reader */, /* EDI out */);
```

**Note:** Unlike `ReadU32` (stack out + **RET 4**), this leaf uses **register EDI out** + bare **RET**.

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
| Raw | `docs/reconstruction/raw/aa_00437000_FUN_00437000.md` |
| Annotated | `docs/reconstruction/raw/aa_00437000_FUN_00437000.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/stoChunkReader_ReadU8.cpp` |
| Clean (FUN_*) | `docs/reconstruction/reconstructed-exact/FUN_00437000.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00437000_stoChunkReader_ReadU8.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00437000_stoChunkReader_ReadU8.md` |
| Function alias | `docs/reconstruction/functions/aa_00437000_FUN_00437000.md` |

## Callers / callees

| Direction | Symbol | VA / notes |
|---|---|---|
| Callee | `FUN_00435df0` | `0x00435df0` ensure/refill (not owned) |
| Caller | `FUN_00439a50` | mode dispatcher (binary → this; text → `FUN_00769660`) |
| Caller | binary unserialize paths | 10 xrefs (`FUN_00765740`, `FUN_00963fb0`, …) |

## Confidence

| Claim | Level |
|---|---|
| CF: ensure-if-short → copy 1 → cursor+=1 → 0/−1 | **High** |
| EAX=reader, EDI=out, bare RET | **High** |
| Window @ reader+0x14 field map | **High** |
| Binary-mode role (peer of text token reader) | **High** |
| Fail-path `*out` write is non-product spill | **High** (bytes); port may omit |
| Product English U8 vs bool | **Probable** (width sealed; text peer says bool) |
| Ensure full semantics | **Out of scope** |
| Runtime / bit-exact | **Open** |
