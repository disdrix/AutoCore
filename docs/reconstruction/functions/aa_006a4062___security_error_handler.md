# Function record: __security_error_handler

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a4062` |
| **Canonical name** | `__security_error_handler` |
| **Address** | `0x006a4062` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
void __security_error_handler(void)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006a4062___security_error_handler.md`
- Annotated: `docs/reconstruction/raw/aa_006a4062___security_error_handler.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/__security_error_handler.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
