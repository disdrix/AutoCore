# Function record: _CxxThrowException

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3d60` |
| **Canonical name** | `_CxxThrowException` |
| **Address** | `0x006a3d60` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
void _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006a3d60__CxxThrowException.md`
- Annotated: `docs/reconstruction/raw/aa_006a3d60__CxxThrowException.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/_CxxThrowException.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
