# Function record: stoChunkWriter_BeginChunk

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767460` |
| **Canonical name** | `stoChunkWriter_BeginChunk` |
| **Address** | `0x00767460` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | storage / arda2 stoChunk |
| **Completion status** | **Dual-reviewed** — trio present; A/B accept-with-gaps (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Open a nested chunk on `stoChunkWriter`:

- **Binary (`this+0x1c == 0`)**: Tell stream, write 16-byte header `{tag, size=0, version, reserved=0}`, push stack frame (headerPos for EndChunk size patch).
- **Text**: write `CHUNK "<FourCC>" <ver>\r\n{\r\n`, clear text column, push stack frame.
- Return sticky status (`this+0x04`).

## Signature (decompiler-derived)

```c
/* stoChunkWriter::BeginChunk(u32 tag4cc, u32 version)  [arda2\storage\stoChunk.cpp] */
uint __thiscall stoChunkWriter_BeginChunk(stoChunkWriter *this, uint tag4cc, uint version);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00767460_stoChunkWriter_BeginChunk.md`
- Annotated: `docs/reconstruction/raw/aa_00767460_stoChunkWriter_BeginChunk.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/stoChunkWriter_BeginChunk.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00767460_stoChunkWriter_BeginChunk.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00767460_stoChunkWriter_BeginChunk.md`

## Callers / callees

| Direction | Symbols |
|---|---|
| Callees | `FUN_00436190` (FourCC→string), `FUN_00767160` (FormattedWrite), stream Write/Tell vtbl, `FUN_00436340` (stack push), `std::string` dtor |
| Pair | `stoChunkWriter_EndChunk` `0x007673a0` |
| Callers | 54 xrefs — gfx serialize, keyframe tracks, anim/asset writers (see dual A) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **Confirmed** (live ≡ force ≡ raw) |
| Binary 16-byte header + payload-only size contract | **High** / Confirmed (size formula on EndChunk) |
| Text multi-write sequence + constants | **Confirmed** (`read_memory`) |
| Parameter semantic names | **High** |
| Stack-helper this-adjust | **Open** |
| Runtime | **Open** |
