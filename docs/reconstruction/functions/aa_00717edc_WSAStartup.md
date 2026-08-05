# Function record: WSAStartup

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717edc` |
| **Canonical name** | `WSAStartup` |
| **Address** | `0x00717edc` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
int WSAStartup(WORD wVersionRequired,LPWSADATA lpWSAData)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00717edc_WSAStartup.md`
- Annotated: `docs/reconstruction/raw/aa_00717edc_WSAStartup.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/WSAStartup.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
