# Function record: OleDb_ReleaseAccessorHandle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423170` |
| **Canonical name** | `OleDb_ReleaseAccessorHandle_Inferred` |
| **Address** | `0x00423170` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | COM / OLE DB IAccessor |
| **Completion status** | **Dual A/B complete** (2026-07-29) - accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_00423170` |
| **Prior alias** | `Named_CalleeOf_Mission_bActiveObjectiveOverride_00423170` |

## Purpose

See dual A. Nested/shared plumbing under `Skill_DbLoadSkillsCharacters` (`0x007e34b0`) and peer DbLoad units.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00423170_FUN_00423170.md`
- Annotated: `docs/reconstruction/raw/aa_00423170_FUN_00423170.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_00423170.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00423170_OleDb_ReleaseAccessorHandle_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00423170_OleDb_ReleaseAccessorHandle_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompile | High |
| Canonical name product-final | Inferred / structural |
| Dual review | Present |
