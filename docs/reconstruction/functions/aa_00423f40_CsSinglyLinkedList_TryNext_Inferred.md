# Function record: CsSinglyLinkedList_TryNext_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423f40` |
| **Canonical name** | `CsSinglyLinkedList_TryNext_Inferred` |
| **Address** | `0x00423f40` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / thread-safe list (DB load cursor) |
| **Completion status** | **Dual A/B complete** (2026-07-29) - accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_00423f40` |
| **Prior alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_00423f40` |

## Purpose

See dual A. Nested/shared plumbing under `Skill_DbLoadSkillsCharacters` (`0x007e34b0`) and peer DbLoad units.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00423f40_FUN_00423f40.md`
- Annotated: `docs/reconstruction/raw/aa_00423f40_FUN_00423f40.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_00423f40.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00423f40_CsSinglyLinkedList_TryNext_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00423f40_CsSinglyLinkedList_TryNext_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompile | High |
| Canonical name product-final | Inferred / structural |
| Dual review | Present |
