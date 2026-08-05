# Function record: memset

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3d1e` |
| **Canonical name** | `memset` |
| **Address** | `0x006a3d1e` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
void * __cdecl memset(void *_Dst,int _Val,size_t _Size)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006a3d1e_memset.md`
- Annotated: `docs/reconstruction/raw/aa_006a3d1e_memset.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/memset.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
