// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CVOGObjectiveRequirement_Patrol_Eval.
//  - Return sites: 2.

// =============================================================================
// CVOGObjectiveRequirement_Patrol_Eval
// -----------------------------------------------------------------------------
// Purpose:  Requirement **eval** (vtable+0x8) for Patrol objectives.
//           Passes when the runtime progress slot float is ≥
//           (targetCount * Laps) from the requirement object.
//
// Address:  0x0060e0f0  (autoassault.exe, image base 0x400000)
// Stable:   aa_0060e0f0
// System:   missions-progression
//
// Convention: MSVC __thiscall  (ret 8 — two stack args)
//   this / param_1  - CVOGObjectiveRequirement_Patrol*
//   param_2         - unused by body
//   param_3         - active-objective state node*
//
// Returns:  1 if complete, 0 if still in progress
//
// Layout:
//   req+0x08  - slot index (byte)
//   req+0x24  - Laps (int; XML <Laps>; GetFlags 0x0060e260 pushes [this+0x24])
//   req+0xd0  - listed waypoint/target count (int; GenericTargetCOID loop bound)
//   state+0x4 + slot*4 - progress float = **absolute pad count** (0,1,2… from
//                        S2C 0x2071 / AutoPatrol; not a 0..1 ratio)
//
// Formula:
//   (float)(req.targetCount * req.Laps)  <=  state.slotFloat[slot]
//
// Zero product: completes for any slotFloat >= 0. Action (0x0060e120) returns
// 1.0 when denom is 0. Server NeededCount may normalize Laps<=0 / targets==0
// differently — port caution only.
//
// Related:  Patrol_GetTarget (0x0060e370), Patrol_InitActive, Patrol_Action,
//           Patrol_GetFlags (0x0060e260), Client_RecvObjectiveState.
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 batch);
//            residual field seal 2026-07-29 (image imul/comiss).
// =============================================================================

#include <cstdint>

/// @return 1 when progress slot ≥ targetCount*Laps; else 0
std::uint32_t __thiscall CVOGObjectiveRequirement_Patrol_Eval(
    int thisReq,
    std::uint32_t /*unused*/,
    int pStateNode)
{
    if ((float)(*(int*)(thisReq + 0xd0) * *(int*)(thisReq + 0x24)) <=
        *(float*)(pStateNode + 4 + (unsigned)*(std::uint8_t*)(thisReq + 8) * 4))
    {
        return 1;
    }
    return 0;
}
