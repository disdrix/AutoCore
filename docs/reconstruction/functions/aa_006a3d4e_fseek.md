# Function record: fseek

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3d4e` |
| **Canonical name** | `fseek` |
| **Address** | `0x006a3d4e` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
int __cdecl fseek(FILE *_File,long _Offset,int _Origin)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006a3d4e_fseek.md`
- Annotated: `docs/reconstruction/raw/aa_006a3d4e_fseek.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/fseek.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
