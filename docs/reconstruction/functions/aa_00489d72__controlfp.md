# Function record: _controlfp

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489d72` |
| **Canonical name** | `_controlfp` |
| **Address** | `0x00489d72` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
uint __cdecl _controlfp(uint _NewValue,uint _Mask)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00489d72__controlfp.md`
- Annotated: `docs/reconstruction/raw/aa_00489d72__controlfp.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/_controlfp.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
