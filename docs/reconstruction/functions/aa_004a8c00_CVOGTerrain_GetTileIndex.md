# Function record: CVOGTerrain_GetTileIndex

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a8c00` |
| **Canonical name** | `CVOGTerrain_GetTileIndex` |
| **Address** | `0x004a8c00` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
/* CVOGTerrain::GetTileIndex(x, y). Per-cell terrain tile layer = map TGA G channel & 7 (buffer at
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004a8c00_CVOGTerrain_GetTileIndex.md`
- Annotated: `docs/reconstruction/raw/aa_004a8c00_CVOGTerrain_GetTileIndex.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGTerrain_GetTileIndex.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
