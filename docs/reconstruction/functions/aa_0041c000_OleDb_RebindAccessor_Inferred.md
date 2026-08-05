# Function record: OleDb_RebindAccessor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041c000` |
| **Canonical name** | `OleDb_RebindAccessor_Inferred` |
| **Address** | `0x0041c000` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | COM / OLE DB accessor bind |
| **Completion status** | **Dual A/B complete** (2026-07-29) - accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_0041c000` |
| **Prior alias** | `Named_CalleeOf_Mission_bActiveObjectiveOverride_0041c000` |

## Purpose

See dual A. Nested/shared plumbing under `Skill_DbLoadSkillsCharacters` (`0x007e34b0`) and peer DbLoad units.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0041c000_FUN_0041c000.md`
- Annotated: `docs/reconstruction/raw/aa_0041c000_FUN_0041c000.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0041c000.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0041c000_OleDb_RebindAccessor_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0041c000_OleDb_RebindAccessor_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompile | High |
| Canonical name product-final | Inferred / structural |
| Dual review | Present |
