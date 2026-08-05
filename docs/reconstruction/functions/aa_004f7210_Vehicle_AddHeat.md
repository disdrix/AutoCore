# Function record: Vehicle_AddHeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f7210` |
| **Canonical name** | `Vehicle_AddHeat` |
| **Address** | `0x004f7210` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
/* Vehicle_AddHeat — apply signed heat delta; clamp [0, 2*MaxHeat]; dirty HeatMask 0x20000000.
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004f7210_Vehicle_AddHeat.md`
- Annotated: `docs/reconstruction/raw/aa_004f7210_Vehicle_AddHeat.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Vehicle_AddHeat.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
