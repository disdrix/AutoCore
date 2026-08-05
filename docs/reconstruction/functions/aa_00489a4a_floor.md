# Function record: floor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489a4a` |
| **Canonical name** | `floor` |
| **Address** | `0x00489a4a` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
double __cdecl floor(double _X)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00489a4a_floor.md`
- Annotated: `docs/reconstruction/raw/aa_00489a4a_floor.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/floor.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
