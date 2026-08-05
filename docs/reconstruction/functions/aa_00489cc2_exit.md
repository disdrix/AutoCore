# Function record: exit

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489cc2` |
| **Canonical name** | `exit` |
| **Address** | `0x00489cc2` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
void __cdecl exit(int _Code)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00489cc2_exit.md`
- Annotated: `docs/reconstruction/raw/aa_00489cc2_exit.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/exit.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
