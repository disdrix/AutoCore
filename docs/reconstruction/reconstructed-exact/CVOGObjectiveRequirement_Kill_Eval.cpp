// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: none.
//  - Return sites: 2.
//  - Asm seal 2026-07-29: COMISS progress>=required; RET 8; param_2 unread.

// =============================================================================
// CVOGObjectiveRequirement_Kill_Eval
// -----------------------------------------------------------------------------
// Purpose:  Requirement **eval** (vtable+0x8) for Kill objectives.
//           Passes when the runtime progress slot float is ≥ the required
//           kill count on the requirement object.
//
// Address:  0x00613910  (autoassault.exe, image base 0x400000)
// Stable:   aa_00613910
// System:   missions-progression
//
// Convention: MSVC __thiscall
//   this / param_1  - CVOGObjectiveRequirement_Kill*
//   param_2         - unused by body (stack arg0)
//   param_3         - active-objective state node*
//
// Returns:  1 if complete, 0 if still in progress
//
// Layout:
//   req+0x08  - slot index (byte)
//   req+0x18  - required kill count (int, CVTSI2SS to float)
//   state+0x4 + slot*4 - progress float
//
// Formula:
//   (float)req.requiredKills  <=  state.slotFloat[req.slotIndex]
//   asm: complete unless progress < required (COMISS + JC)
//
// Progress writers (external):
//   Client_RecvObjectiveState 0x00809460 — S2C 0x2071 absolute state[1..4]
//   Kill_Precheck 0x00613b50 — client += into same slot; early-outs via this eval
//
// Related:  Kill_Precheck (0x00613b50), Client_RecvObjectiveState,
//           UseItem_Eval (0x0060cfe0, threshold at +0x50).
//
// Exactness: Control flow mirrors raw Ghidra decompile + live asm (2026-07-29).
// Dual residual sealed: tmp/a_00613910.md ; reviews A/B aa_00613910.
// =============================================================================

#include <cstdint>

/// @return 1 when progress slot ≥ required kill count; else 0
std::uint32_t __thiscall CVOGObjectiveRequirement_Kill_Eval(
    int thisReq,
    std::uint32_t /*unused*/,
    int pStateNode)
{
    if ((float)*(int*)(thisReq + 0x18) <=
        *(float*)(pStateNode + 4 + (unsigned)*(std::uint8_t*)(thisReq + 8) * 4))
    {
        return 1;
    }
    return 0;
}
