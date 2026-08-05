# Function record: listen

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717e6a` |
| **Canonical name** | `listen` |
| **Address** | `0x00717e6a` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
int listen(SOCKET s,int backlog)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00717e6a_listen.md`
- Annotated: `docs/reconstruction/raw/aa_00717e6a_listen.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/listen.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
