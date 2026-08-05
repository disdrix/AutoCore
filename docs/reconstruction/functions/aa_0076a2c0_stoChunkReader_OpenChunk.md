# Function record: stoChunkReader_OpenChunk

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076a2c0` |
| **Canonical name** | `stoChunkReader_OpenChunk` |
| **Address** | `0x0076a2c0`–`0x0076a8f9` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `storage` / arda2 `stoChunk` |
| **Completion status** | **Partial** — three-rep present; dual A/B **accept-with-gaps** (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Open the next chunk on a `stoChunkReader`: read a **binary 16-byte header** or a **text** `CHUNK` / FOURCC / version / `{` sequence, OR sticky error at `this+0x402c`, then **push** the header onto the chunk ring (`this+0x4030` base; bookkeeping `+0x4034..0x4040`). Mode select: `this+0x4044` (0 = binary, non-zero = text).

## Signature (decompiler-derived)

```c
/* stoChunkReader::OpenChunk()  [arda2\storage\stoChunk.cpp:~0x1d4] */
undefined4 __fastcall stoChunkReader_OpenChunk(int this /* ECX */);
/* returns 0 success, 0xffffffff failure */
```

## Key offsets (this)

| Offset | Role | Confidence |
|---:|---|---|
| `+0x14` | Stream window base (ESI for binary header read) | High |
| `+0x18` | Read cursor | High |
| `+0x1c` | Stream base partner | High |
| `+0x20` | Remaining / available | High |
| `+0x2c` | Data buffer base | High |
| `+0x402c` | Sticky error (OR + signed test) | High |
| `+0x4030` | Chunk ring object base | High |
| `+0x4034..0x4040` | Ring bookkeeping (plate) | High |
| `+0x4044` | Text-mode flag (0 = binary) | High |
| `+0x404c` | Pending token `std::string` | Probable |
| `+0x4060` | Use-pending-token flag | Probable |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0076a2c0_stoChunkReader_OpenChunk.md`
- Annotated: `docs/reconstruction/raw/aa_0076a2c0_stoChunkReader_OpenChunk.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/stoChunkReader_OpenChunk.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0076a2c0_stoChunkReader_OpenChunk.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0076a2c0_stoChunkReader_OpenChunk.md`

## Callers / callees

**Callers (3):** `stoChunkReader_EnterChunkScope` (`0x004370b0`), `FUN_0076a900`, `FUN_009615c0`.

**Callees (owned as names only):** `FUN_004368b0` (binary 16 B header), `FUN_00436340` (ring push), `FUN_00769b70` (text tag), `FUN_007689e0` / `FUN_00437050` (version), `FUN_00435df0` (refill), `FUN_0076cec0` (format), `vog_LogMessage`, CRT `isspace` / `_stricmp`, `std::string` ops.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + prologue/tail bytes | High |
| Mode / sticky / return codes | High |
| Stream + ring offsets above | High |
| FOURCC text pack endian | Probable |
| Callee product English names | Tentative |
| Runtime / differential | Open |
