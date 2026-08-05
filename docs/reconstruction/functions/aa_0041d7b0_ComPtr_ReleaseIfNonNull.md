# Function record: ComPtr_ReleaseIfNonNull

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041d7b0` |
| **Canonical name** | `ComPtr_ReleaseIfNonNull` |
| **Address** | `0x0041d7b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | COM / OLE DB plumbing |
| **Completion status** | **Dual A/B complete** (2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_0041d7b0` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_Skill_IDSkillBattleMode1_0041d7b0` |

## Purpose

See dual A. Shared com_ptr Release helper under OLE DB / COM QI paths and SEH unwind tables.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0041d7b0_FUN_0041d7b0.md`
- Annotated: `docs/reconstruction/raw/aa_0041d7b0_FUN_0041d7b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0041d7b0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0041d7b0_ComPtr_ReleaseIfNonNull.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0041d7b0_ComPtr_ReleaseIfNonNull.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompile | High / Confirmed |
| Canonical name product-final | Structural (no product string) |
| Dual review | Present |
