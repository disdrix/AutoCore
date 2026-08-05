# Function record: strncmp

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048982e` |
| **Canonical name** | `strncmp` |
| **Address** | `0x0048982e` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
int __cdecl strncmp(char *_Str1,char *_Str2,size_t _MaxCount)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0048982e_strncmp.md`
- Annotated: `docs/reconstruction/raw/aa_0048982e_strncmp.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/strncmp.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
