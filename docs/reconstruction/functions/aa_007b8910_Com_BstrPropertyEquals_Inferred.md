# Function record: Com_BstrPropertyEquals_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b8910` |
| **Canonical name** | `Com_BstrPropertyEquals_Inferred` |
| **Address** | `0x007b8910` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | COM / ADO field compare (DB load filters) |
| **Completion status** | **Dual A/B complete** (2026-07-29) - accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_007b8910` |
| **Prior alias** | `Named_CalleeOf_Skill_DbLoadSkillsCharacters_007b8910` |

## Purpose

See dual A. Nested/shared plumbing under `Skill_DbLoadSkillsCharacters` (`0x007e34b0`) and peer DbLoad units.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007b8910_FUN_007b8910.md`
- Annotated: `docs/reconstruction/raw/aa_007b8910_FUN_007b8910.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_007b8910.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_007b8910_Com_BstrPropertyEquals_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_007b8910_Com_BstrPropertyEquals_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompile | High |
| Canonical name product-final | Inferred / structural |
| Dual review | Present |
