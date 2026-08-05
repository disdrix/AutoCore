# Function record: _snprintf

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048989e` |
| **Canonical name** | `_snprintf` |
| **Address** | `0x0048989e` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
int __cdecl _snprintf(char *_Dest,size_t _Count,char *_Format,...)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0048989e__snprintf.md`
- Annotated: `docs/reconstruction/raw/aa_0048989e__snprintf.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/_snprintf.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
