# Function record: Vehicle_BuildSteeringDescriptor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fc710` |
| **Canonical name** | `Vehicle_BuildSteeringDescriptor` |
| **Address** | `0x005fc710` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
void Vehicle_BuildSteeringDescriptor(int param_1,uint32_t /* width from decompiler */ param_2,uint8_t *param_3)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005fc710_Vehicle_BuildSteeringDescriptor.md`
- Annotated: `docs/reconstruction/raw/aa_005fc710_Vehicle_BuildSteeringDescriptor.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Vehicle_BuildSteeringDescriptor.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
