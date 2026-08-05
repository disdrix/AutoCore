# Function record: ComPtr_ClearSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437cd0` |
| **Canonical name** | `ComPtr_ClearSlot` |
| **Address** | `0x00437cd0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | COM / OLE DB plumbing |
| **Completion status** | **Dual A/B complete** (2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_00437cd0` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_Skill_IDSkillBattleMode1_00437cd0` |

## Purpose

See dual A. Shared com_ptr slot clear under OLE DB / COM QI paths (nested of `Skill_DbLoadSkillsCharacters` plumbing and peers).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00437cd0_FUN_00437cd0.md`
- Annotated: `docs/reconstruction/raw/aa_00437cd0_FUN_00437cd0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_00437cd0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00437cd0_ComPtr_ClearSlot.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00437cd0_ComPtr_ClearSlot.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompile | High / Confirmed |
| Canonical name product-final | Structural (no product string) |
| Dual review | Present |
