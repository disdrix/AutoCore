# Function record: VehicleNet_SoftPoseIntegrate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053eb90` |
| **Canonical name** | `VehicleNet_SoftPoseIntegrate_Inferred` |
| **Address** | `0x0053eb90` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control |
| **Completion status** | Dual A/B **present** (accept-with-gaps) — 2026-07-29 OWN-ONLY batch |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Dead-reckon soft buffer: ½ω quat step + pos Euler; age 6399ms

## Signature (decompiler-derived)

See dual reviews and raw capture.

## Artifacts

- Reviews: `docs/reconstruction/reviews/A_aa_0053eb90_VehicleNet_SoftPoseIntegrate_Inferred.md`, `B_aa_0053eb90_VehicleNet_SoftPoseIntegrate_Inferred.md`
- Raw: `docs/reconstruction/raw/aa_0053eb90_FUN_0053eb90.md`
- Annotated: `docs/reconstruction/raw/aa_0053eb90_FUN_0053eb90.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0053eb90.cpp`
- Prior FUN scaffold: `docs/reconstruction/functions/aa_0053eb90_FUN_0053eb90.md` (if present)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Dual review | accept-with-gaps |
