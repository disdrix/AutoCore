# Function record: hkpVehicleSteering_setSteeringAngle

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636410` |
| **Canonical name** | `hkpVehicleSteering_setSteeringAngle` |
| **Address** | `0x00636410` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
/* Trivial __thiscall setter: *(this+0x50) = param_2 (float). Called from
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00636410_hkpVehicleSteering_setSteeringAngle.md`
- Annotated: `docs/reconstruction/raw/aa_00636410_hkpVehicleSteering_setSteeringAngle.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/hkpVehicleSteering_setSteeringAngle.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
