// READABILITY (auto CF):
//  - Body size: ~5 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGObjectiveRequirement_UseItem_MatchTarget, FUN_0060d460.
//  - Return sites: 1.

// =============================================================================
// CVOGObjectiveRequirement_UseItem_MatchTarget
// -----------------------------------------------------------------------------
// Purpose:  Requirement **MatchTarget** (vtable+0x38) for UseItem objectives.
//           Thin trampoline into FUN_0060d460 (shared match helper that
//           compares the target key against the requirement's item / object
//           criteria). Invoked from Client_FindObjectiveMatchingTarget when
//           building C2S 0x2072 IDObjective.
//
// Address:  0x0060d7f0  (autoassault.exe, image base 0x400000)
// Stable:   aa_0060d7f0
// System:   missions-progression
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 batch).
//            FUN_0060d460 body not yet unit-reconstructed.
// =============================================================================

void FUN_0060d460(); // shared UseItem target-match implementation

void CVOGObjectiveRequirement_UseItem_MatchTarget(void)
{
    FUN_0060d460();
    return;
}
