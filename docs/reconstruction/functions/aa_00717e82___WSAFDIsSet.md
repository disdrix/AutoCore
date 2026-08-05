# Function record: __WSAFDIsSet

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717e82` |
| **Canonical name** | `__WSAFDIsSet` |
| **Address** | `0x00717e82` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
int __WSAFDIsSet(SOCKET param_1,fd_set *param_2)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00717e82___WSAFDIsSet.md`
- Annotated: `docs/reconstruction/raw/aa_00717e82___WSAFDIsSet.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/__WSAFDIsSet.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
