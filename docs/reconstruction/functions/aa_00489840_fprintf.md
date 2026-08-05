# Function record: fprintf

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489840` |
| **Canonical name** | `fprintf` |
| **Address** | `0x00489840` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
int __cdecl fprintf(FILE *_File,char *_Format,...)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00489840_fprintf.md`
- Annotated: `docs/reconstruction/raw/aa_00489840_fprintf.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/fprintf.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
