# Function record: OleDb_ReleaseAccessorHandleArray_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00422de0` |
| **Canonical name** | `OleDb_ReleaseAccessorHandleArray_Inferred` |
| **Address** | `0x00422de0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | COM / OLE DB IAccessor |
| **Completion status** | **Dual A/B complete** (2026-07-29) - accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_00422de0` |
| **Prior alias** | `Named_CalleeOf_Skill_IDSkillBattleMode1_00422de0` |

## Purpose

See dual A. Nested/shared plumbing under `Skill_DbLoadSkillsCharacters` (`0x007e34b0`) and peer DbLoad units.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00422de0_FUN_00422de0.md`
- Annotated: `docs/reconstruction/raw/aa_00422de0_FUN_00422de0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_00422de0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00422de0_OleDb_ReleaseAccessorHandleArray_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00422de0_OleDb_ReleaseAccessorHandleArray_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompile | High |
| Canonical name product-final | Inferred / structural |
| Dual review | Present |
