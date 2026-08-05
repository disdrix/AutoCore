# Function record: OleDb_CreateAccessorFromBindings_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004231d0` |
| **Canonical name** | `OleDb_CreateAccessorFromBindings_Inferred` |
| **Address** | `0x004231d0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | COM / OLE DB IAccessor |
| **Completion status** | **Dual A/B complete** (2026-07-29) - accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_004231d0` |
| **Prior alias** | `Named_CalleeOf_Mission_bActiveObjectiveOverride_004231d0` |

## Purpose

See dual A. Nested/shared plumbing under `Skill_DbLoadSkillsCharacters` (`0x007e34b0`) and peer DbLoad units.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004231d0_FUN_004231d0.md`
- Annotated: `docs/reconstruction/raw/aa_004231d0_FUN_004231d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004231d0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004231d0_OleDb_CreateAccessorFromBindings_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004231d0_OleDb_CreateAccessorFromBindings_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompile | High |
| Canonical name product-final | Inferred / structural |
| Dual review | Present |
