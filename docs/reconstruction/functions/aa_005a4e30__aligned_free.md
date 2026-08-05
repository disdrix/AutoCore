# Function record: _aligned_free

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a4e30` |
| **Canonical name** | `_aligned_free` |
| **Address** | `0x005a4e30` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
void __cdecl _aligned_free(void *_Memory)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005a4e30__aligned_free.md`
- Annotated: `docs/reconstruction/raw/aa_005a4e30__aligned_free.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/_aligned_free.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
