# Function record: AdoRowsetHolder_Teardown_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041bf70` |
| **Canonical name** | `AdoRowsetHolder_Teardown_Inferred` |
| **Address** | `0x0041bf70` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | COM / ADO-OLEDB DB load teardown |
| **Completion status** | **Dual A/B complete** (2026-07-29) - accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_0041bf70` |
| **Prior alias** | `Named_CalleeOf_Skill_IDSkillBattleMode1_0041bf70` |

## Purpose

See dual A. Nested/shared plumbing under `Skill_DbLoadSkillsCharacters` (`0x007e34b0`) and peer DbLoad units.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0041bf70_FUN_0041bf70.md`
- Annotated: `docs/reconstruction/raw/aa_0041bf70_FUN_0041bf70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0041bf70.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0041bf70_AdoRowsetHolder_Teardown_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0041bf70_AdoRowsetHolder_Teardown_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompile | High |
| Canonical name product-final | Inferred / structural |
| Dual review | Present |
