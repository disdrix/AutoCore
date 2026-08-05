# Function record: stoChunkReader_PeekChunkTag

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076a900` |
| **Canonical name** | `stoChunkReader_PeekChunkTag` |
| **Ghidra name** | `FUN_0076a900` |
| **Prior scaffold alias** | `Named_CalleeOf_Named_gfxBodyMassageMachine_0076a900` |
| **Address** | `0x0076a900`–`0x0076aac9` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | storage / arda2 `stoChunk` |
| **Classification** | non-destructive chunk-tag peek |
| **Completion status** | **Sealed** — dual A/B 2026-07-29 W19-R; ABI + CF + restore sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |

## Purpose

Return the **next chunk FOURCC tag** on a `stoChunkReader` **without permanently consuming** the stream: save cursor + pending string, temporarily open/parse, undo nest/bookkeeping, restore cursor + pending, return tag (or 0).

Used by effect / physics / mesh unserialize loops to branch on upcoming chunk ids (e.g. `'PARM'`).

## Signature (sealed)

```c
// this in ESI (not ECX); 0 stack args; plain RET; EAX = FOURCC or 0
std::uint32_t stoChunkReader_PeekChunkTag(void *self /* ESI */);
```

| Param | Location | Meaning |
|---|---|---|
| `self` | **ESI** | `stoChunkReader*` |
| return | EAX | next tag FOURCC, or `0` |

## Key offsets (reader)

| Off | Role |
|---:|---|
| `+0x18` | stream cursor (window-relative) |
| `+0x1c` | stream base / partner |
| `+0x20` | remaining / window size partner |
| `+0x28` | upper bound for restore clamp |
| `+0x403c` / `+0x4040` | nest / active ring bookkeeping |
| `+0x4044` | mode: `0` binary, `1` text |
| `+0x404c` | pending token `std::string` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0076a900_FUN_0076a900.md`
- Annotated: `docs/reconstruction/raw/aa_0076a900_FUN_0076a900.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/stoChunkReader_PeekChunkTag.cpp`
- Scaffold alias: `docs/reconstruction/reconstructed-exact/FUN_0076a900.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0076a900_stoChunkReader_PeekChunkTag.md`
- Review B: `docs/reconstruction/reviews/B_aa_0076a900_stoChunkReader_PeekChunkTag.md`
- Report: `docs/agents/task-dual-ab-00745d70-0076a900-w19r-report.md`

## Callers / callees

**Callees:** `stoChunkReader_OpenChunk` `0x0076a2c0`; `FUN_00436220`; `FUN_00767840`; `FUN_00769b70`; `std::basic_string` / `operator!=`.

**Callers (11):**

- `effEffect_Unserialize` `0x00970260` (e.g. `cmp eax,'PARM'`)
- `phyBoneSharedData_unserialize` `0x00997540`
- `FUN_00437b00`, `FUN_00437c90`, `FUN_0044fe10`
- `FUN_0073eb40`, `FUN_0095dae0`, `FUN_0095dc70`, `FUN_0095f560`
- `FUN_00960f80`, `FUN_009615c0`

**Xrefs:** 18.

**Sibling:** `stoChunkReader_OpenChunk` (consume header; this in **ECX**).

## Confidence

| Claim | Level |
|---|---|
| Peek semantics (save/restore cursor + pending) | **High** |
| ESI this ABI + 0 stack args | **High** |
| Mode `+0x4044` 0/1 paths | **High** |
| Return FOURCC / 0 | **High** |
| Product English name | **Probable** (role High; no plate) |
| Ring slot type behind `FUN_00436220` | **Probable** |
| Text FOURCC endian vs all binary tags | **Probable** |
