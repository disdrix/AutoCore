// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CVOGObjectiveRequirement_UseItem_Eval.
//  - Return sites: 2.

// =============================================================================
// CVOGObjectiveRequirement_UseItem_Eval
// -----------------------------------------------------------------------------
// Purpose:  Requirement **eval** (vtable+0x8) for UseItem objectives.
//           Passes when the runtime progress slot float is ≥ the required
//           use count stored on the requirement object.
//
// Address:  0x0060cfe0  (autoassault.exe, image base 0x400000)
// Stable:   aa_0060cfe0
// System:   missions-progression
//
// Convention: MSVC __thiscall
//   this / param_1  - CVOGObjectiveRequirement_UseItem*
//   param_2         - unused by body (character or context; decompiler keeps it)
//   param_3         - active-objective state node* (from AddActiveObjective)
//
// Returns:  1 if complete, 0 if still in progress
//
// Layout:
//   req+0x08  - slot index (byte) into state floats (FirstStateSlot / XML slot)
//   req+0x50  - required use count (int, cast to float for compare) = RepeatCount
//   state+0x4 + slot*4 - progress float written by RecvObjectiveState (0x2071)
//                        absolute use count (0,1,2…), NOT a per-event delta
//
// Formula:
//   (float)req.requiredCount  <=  state.slotFloat[req.slotIndex]
//
// Related:  UseItem_InitActive, UseItem_SlotAction (same slot formula, display),
//           Client_RecvObjectiveState (absolute assigns state[1..4]).
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 batch).
// Residual 2026-07-29: absolute 0x2071 + shared slot sealed (tmp/a_0060cfe0.md;
//   reviews/A|B_aa_0060cfe0_*_residual.md). Runtime/diff still open.
// =============================================================================

#include <cstdint>

/// @return 1 when progress slot ≥ required use count; else 0
std::uint32_t __thiscall CVOGObjectiveRequirement_UseItem_Eval(
    int thisReq,
    std::uint32_t /*unused*/,
    int pStateNode)
{
    // requiredCount (int@+0x50) vs progress float at state[+4 + slot*4]
    if ((float)*(int*)(thisReq + 0x50) <=
        *(float*)(pStateNode + 4 + (unsigned)*(std::uint8_t*)(thisReq + 8) * 4))
    {
        return 1;
    }
    return 0;
}
