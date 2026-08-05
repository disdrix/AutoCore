# Function record: getsockname

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717eac` |
| **Canonical name** | `getsockname` |
| **Address** | `0x00717eac` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
int getsockname(SOCKET s,sockaddr *name,int *namelen)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00717eac_getsockname.md`
- Annotated: `docs/reconstruction/raw/aa_00717eac_getsockname.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/getsockname.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
