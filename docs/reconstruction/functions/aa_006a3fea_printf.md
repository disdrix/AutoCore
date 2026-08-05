# Function record: printf

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3fea` |
| **Canonical name** | `printf` |
| **Address** | `0x006a3fea` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
int __cdecl printf(char *_Format,...)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006a3fea_printf.md`
- Annotated: `docs/reconstruction/raw/aa_006a3fea_printf.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/printf.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
