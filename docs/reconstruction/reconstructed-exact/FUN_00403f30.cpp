// =============================================================================
// FUN_00403f30  — scaffold twin of StdTree_Buynode_Val32_Isnil31_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00403f30
// Address:   0x00403f30–0x00403fb2 exclusive (130 B / 0x82)
// System:    MSVC std::_Tree buynode isnil@+0x31 / Val32 / size 0x38
// Generated: 2026-08-05 MEGA-048 dual seal (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving; see named clean for full plate.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Prefer: StdTree_Buynode_Val32_Isnil31_Inferred.cpp
// Reject retired Named_CalleeOf_*NotifyActiveMission* scaffold name.

#include <cstdint>

struct NodeIsnil31_Size0x38;

extern "C" NodeIsnil31_Size0x38* __stdcall StdTree_Buynode_Val32_Isnil31_Inferred(
    NodeIsnil31_Size0x38* left,
    NodeIsnil31_Size0x38* parent,
    NodeIsnil31_Size0x38* right,
    const std::uint32_t* value8,
    std::uint8_t color);

extern "C" NodeIsnil31_Size0x38* __stdcall FUN_00403f30(
    NodeIsnil31_Size0x38* left,
    NodeIsnil31_Size0x38* parent,
    NodeIsnil31_Size0x38* right,
    const std::uint32_t* value8,
    std::uint8_t color)
{
  return StdTree_Buynode_Val32_Isnil31_Inferred(left, parent, right, value8, color);
}
