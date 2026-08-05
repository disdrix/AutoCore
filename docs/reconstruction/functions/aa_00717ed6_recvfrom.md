# Function record: recvfrom

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717ed6` |
| **Canonical name** | `recvfrom` |
| **Address** | `0x00717ed6` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
int recvfrom(SOCKET s,char *buf,int len,int flags,sockaddr *from,int *fromlen)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00717ed6_recvfrom.md`
- Annotated: `docs/reconstruction/raw/aa_00717ed6_recvfrom.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/recvfrom.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
