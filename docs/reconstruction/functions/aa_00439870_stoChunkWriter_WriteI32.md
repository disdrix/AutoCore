# Function record: stoChunkWriter_WriteI32

| Field | Value |
|---|---|
| **Stable ID** | `aa_00439870` |
| **Canonical name** | `stoChunkWriter_WriteI32` |
| **Prior scaffold** | `FUN_00439870` / `Named_CalleeOf_Named_effEffect_00439870` |
| **Address** | `0x00439870` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | storage / arda2.stoChunk |
| **Completion status** | **Human-refined** — dual A/B sealed 2026-07-29 W19-Q |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Write one **signed 32-bit** field through `stoChunkWriter`: raw 4 bytes in binary mode, or `"%i"` + CRLF in text mode. Returns cumulative writer status.

## Signature (register ABI)

```c
// ESI = stoChunkWriter* writer
// EAX = const int32_t* pValue
uint32_t stoChunkWriter_WriteI32(void);  // returns writer->status
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00439870_stoChunkWriter_WriteI32.md`
- Annotated: `docs/reconstruction/raw/aa_00439870_stoChunkWriter_WriteI32.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/stoChunkWriter_WriteI32.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00439870_stoChunkWriter_WriteI32.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00439870_stoChunkWriter_WriteI32.md`
- Legacy scaffold: `functions/aa_00439870_FUN_00439870.md`, `raw/aa_00439870_FUN_00439870*.md`, `reconstructed-exact/FUN_00439870.cpp`, `Named_CalleeOf_Named_effEffect_00439870.cpp`

## Callers / callees

| Direction | Target | Evidence |
|---|---|---|
| Callee | `stoChunkWriter_WriteFormatted` (`0x00767160`) | text path |
| Callee | stream `vtbl+0x18` write | binary + CRLF |
| Callers | many serializers (`gfxIndexBufferImpl_Serialize`, `gfxVertexBufferImpl_Serialize`, `gfxGeometryPiece_Serialize`, CPDF/MWGT helpers, …) | `get_function_xrefs` |

## Confidence

| Claim | Level |
|---|---|
| CF ≡ live Ghidra 2026-07-29 | **High** |
| Binary vs text on `+0x1c` | **High** |
| Format string `"%i"` | **High** (`read_memory`) |
| CRLF after text value | **High** |
| ESI writer / EAX value* ABI | **High** (call-site `lea`/`mov` + body) |
| Name WriteI32 (vs generic WriteDword) | **High** (`%i` signed; sibling `%u`) |
