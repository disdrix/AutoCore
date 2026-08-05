// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: CVOGObjectiveRequirement_Patrol_GetTarget.
//  - Return sites: 3.

// =============================================================================
// CVOGObjectiveRequirement_Patrol_GetTarget
// -----------------------------------------------------------------------------
// Purpose:  Fill an out-target structure with the **next patrol waypoint**
//           for the current progress slot. Used by patrol tick / HUD / range
//           checks (see Client_FindObjectiveMatchingTarget MatchTarget chain
//           and MissionPatrolProgress server-side).
//
// Address:  0x0060e370  (autoassault.exe, image base 0x400000)
// Stable:   aa_0060e370
// System:   missions-progression
//
// Convention: MSVC __thiscall
//   this / param_1  — CVOGObjectiveRequirement_Patrol*
//   param_2         — out target blob* (TFID + flags written below)
//   param_3         — active-objective state node* (0 → fail)
//
// Returns:  1 if a next waypoint was written; 0 if done / no state
//
// Layout:
//   req+0x08        — slot index (byte)
//   req+0x10        — flag byte copied to out+0xea
//   req+0x14        — dword copied to out[0x3b]
//   req+0x24        — visit weight / multiplier
//   req+0x28        — out[0] primary field (range / type)
//   req+0x30+i*8    — waypoint TFID lo/hi pairs
//   req+0xd0        — required visit count (modulo period)
//   state+4+slot*4  — progress float → int currentProgress
//
// Logic:
//   progress = (int)state.slotFloat
//   if requiredVisits * visitWeight <= progress → return 0 (complete)
//   index = progress % requiredVisits
//   write waypoint TFID[index] + flags into out
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 batch).
// =============================================================================

#include <cstdint>

std::uint32_t __thiscall CVOGObjectiveRequirement_Patrol_GetTarget(
    int thisReq,
    std::uint32_t* pOutTarget,
    int pStateNode)
{
    int iProgress;
    int iRequired;

    if (pStateNode == 0) {
        return 0;
    }

    // Current visit progress from RecvObjectiveState slot float
    iProgress = (int)*(float*)(pStateNode + 4 +
                               (unsigned)*(std::uint8_t*)(thisReq + 8) * 4);
    iRequired = *(int*)(thisReq + 0xd0);

    // Already satisfied full requiredVisits * weight → no next target
    if (*(int*)(thisReq + 0x24) * iRequired <= iProgress) {
        return 0;
    }

    // Waypoint index cycles through [0, requiredVisits)
    iProgress = iProgress % iRequired;
    pOutTarget[2] = *(std::uint32_t*)(thisReq + 0x30 + iProgress * 8);
    pOutTarget[3] = *(std::uint32_t*)(thisReq + 0x34 + iProgress * 8);
    *(std::uint8_t*)((int)pOutTarget + 0xea) = *(std::uint8_t*)(thisReq + 0x10);
    pOutTarget[0x3b] = *(std::uint32_t*)(thisReq + 0x14);
    *pOutTarget = *(std::uint32_t*)(thisReq + 0x28);
    return 1;
}
