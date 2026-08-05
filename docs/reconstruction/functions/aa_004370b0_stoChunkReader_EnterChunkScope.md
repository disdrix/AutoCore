# Function record: stoChunkReader_EnterChunkScope

| Field | Value |
|---|---|
| **Stable ID** | `aa_004370b0` |
| **Canonical name** | `stoChunkReader_EnterChunkScope` |
| **Address** | `0x004370b0`–`0x0043711a` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `storage` / arda2 `stoChunk` |
| **Completion status** | **Partial** — three-rep present; dual A/B **accept-with-gaps** (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Enter a chunk scope for Unserialize: store `reader` on the caller's `ChunkScope`, call `stoChunkReader_OpenChunk`, set `okFlag` from signed success, fill absolute stream position + ring top **tag**/**version**, return scope*.

## Signature (sealed)

```c
/* stoChunkReader::EnterChunkScope(scope*, reader*) */
ChunkScope* __thiscall stoChunkReader_EnterChunkScope(
    ChunkScope* scope,       /* ECX */
    stoChunkReader* reader); /* stack, RET 4 */
```

### ChunkScope (size 0x14)

| Off | Field |
|---:|---|
| `+0x00` | `reader*` |
| `+0x04` | `absPos` (`reader+0x1c` + `reader+0x18`) |
| `+0x08` | `okFlag` (u8; OpenChunk ≥ 0) |
| `+0x0c` | `tag` FOURCC |
| `+0x10` | `version` |

## Key reader offsets touched

| Offset | Role | Confidence |
|---:|---|---|
| `+0x18` | stream cursor | High |
| `+0x1c` | stream base partner | High |
| `+0x4030` | ring object base | High |
| `+0x4034` | ring entry pointer array | High |
| `+0x4038` | ring capacity | High |
| `+0x403c` | ring base index | High |
| `+0x4040` | ring write/depth index | High |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004370b0_FUN_004370b0.md`
- Annotated: `docs/reconstruction/raw/aa_004370b0_FUN_004370b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/stoChunkReader_EnterChunkScope.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004370b0_stoChunkReader_EnterChunkScope.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004370b0_stoChunkReader_EnterChunkScope.md`
- Prior scaffold record: `docs/reconstruction/functions/aa_004370b0_FUN_004370b0.md`

## Callers / callees

**Callee (1):** `stoChunkReader_OpenChunk` (`0x0076a2c0`).

**Callers:** many Unserialize/asset paths (`get_function_callers` / xrefs) — geometry, index/vertex buffers, physics bones, effects, KEYR/CPDG readers, etc.

## Confidence

| Claim | Level |
|---|---|
| ABI thiscall(scope, reader) + RET 4 | High |
| Scope layout + size 0x14 | High |
| okFlag / ring wrap / tag@0 / version@8 | High |
| absPos formula | High |
| absPos English name | Probable |
| Ring entry full layout | Probable (sibling) |
| Runtime / differential | Open |
