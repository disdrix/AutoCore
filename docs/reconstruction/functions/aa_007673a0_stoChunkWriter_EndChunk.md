# Function record: stoChunkWriter_EndChunk

| Field | Value |
|---|---|
| **Stable ID** | `aa_007673a0` |
| **Canonical name** | `stoChunkWriter_EndChunk` |
| **Address** | `0x007673a0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `storage` / `arda2.stoChunk` |
| **Completion status** | **Dual review complete** — three-rep present; A/B accept-with-gaps (`2026-07-29`) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Closes current chunk on `stoChunkWriter`: binary mode patches 16-byte header size (`tell − headerPos − 0x10`), text mode writes `}` + `\r\n`, then pops depth. See dual reviews for sealed layout and contracts.

## Signature (decompiler-derived)

```c
/* stoChunkWriter::EndChunk()  [arda2\storage\stoChunk.cpp] */
uint32_t __fastcall stoChunkWriter_EndChunk(stoChunkWriter *this);  /* ECX = this; returns status @ +0x04 */
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007673a0_stoChunkWriter_EndChunk.md`
- Annotated: `docs/reconstruction/raw/aa_007673a0_stoChunkWriter_EndChunk.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/stoChunkWriter_EndChunk.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_007673a0_stoChunkWriter_EndChunk.md`
- Dual B: `docs/reconstruction/reviews/B_aa_007673a0_stoChunkWriter_EndChunk.md`

## Callers / callees

- Callers: 69 xrefs (inventory) — serialize sites paired with `BeginChunk` (not expanded; own-VA dual).
- Callees: stream vt `+0x30` tell, `+0x04` seek, `+0x18` write; `FUN_00767160` (text).

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + asm | High |
| Size excludes 16-byte header | High (asm `sub 0x10`) |
| Text `}` / `\r\n` DAT seals | High |
| Parameter semantic names | High for offsets; stream product type still Tentative |
| Types | Writer/frame offsets High; stream iface Low |
