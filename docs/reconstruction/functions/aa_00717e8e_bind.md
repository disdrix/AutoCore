# Function record: bind

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717e8e` |
| **Canonical name** | `bind` |
| **Address** | `0x00717e8e` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
int bind(SOCKET s,sockaddr *addr,int namelen)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00717e8e_bind.md`
- Annotated: `docs/reconstruction/raw/aa_00717e8e_bind.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/bind.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
