# Function record: fclose

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048983a` |
| **Canonical name** | `fclose` |
| **Address** | `0x0048983a` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
int __cdecl fclose(FILE *_File)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0048983a_fclose.md`
- Annotated: `docs/reconstruction/raw/aa_0048983a_fclose.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/fclose.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
