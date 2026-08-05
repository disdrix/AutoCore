# Function record: VehicleAction_tickSubsystems

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636a60` |
| **Canonical name** | `VehicleAction_tickSubsystems` |
| **Address** | `0x00636a60` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
/* WI-MOV-003: this = hkVehicleFramework (VA+0x40), NOT VehicleAction. Call site applyAction
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00636a60_VehicleAction_tickSubsystems.md`
- Annotated: `docs/reconstruction/raw/aa_00636a60_VehicleAction_tickSubsystems.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/VehicleAction_tickSubsystems.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
