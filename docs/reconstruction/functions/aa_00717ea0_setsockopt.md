# Function record: setsockopt

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717ea0` |
| **Canonical name** | `setsockopt` |
| **Address** | `0x00717ea0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
int setsockopt(SOCKET s,int level,int optname,char *optval,int optlen)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00717ea0_setsockopt.md`
- Annotated: `docs/reconstruction/raw/aa_00717ea0_setsockopt.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/setsockopt.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
