# Function record: inet_addr

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717ed0` |
| **Canonical name** | `inet_addr` |
| **Address** | `0x00717ed0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
ulong inet_addr(char *cp)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00717ed0_inet_addr.md`
- Annotated: `docs/reconstruction/raw/aa_00717ed0_inet_addr.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/inet_addr.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
