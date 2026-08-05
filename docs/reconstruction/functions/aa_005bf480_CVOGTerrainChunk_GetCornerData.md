# Function record: CVOGTerrainChunk_GetCornerData

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bf480` |
| **Canonical name** | `CVOGTerrainChunk_GetCornerData` |
| **Address** | `0x005bf480` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
/* CVOGTerrainChunk::GetCornerData(out, x, y). Returns 8-byte corner record {u16 height16; u8
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005bf480_CVOGTerrainChunk_GetCornerData.md`
- Annotated: `docs/reconstruction/raw/aa_005bf480_CVOGTerrainChunk_GetCornerData.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGTerrainChunk_GetCornerData.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
