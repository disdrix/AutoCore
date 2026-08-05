# Function record: select

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717ec4` |
| **Canonical name** | `select` |
| **Address** | `0x00717ec4` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
int select(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,timeval *timeout)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00717ec4_select.md`
- Annotated: `docs/reconstruction/raw/aa_00717ec4_select.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/select.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
