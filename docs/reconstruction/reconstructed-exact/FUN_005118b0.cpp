// =============================================================================
// FUN_005118b0  — scaffold twin of StdTree_Buynode_Node24_Isnil21_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005118b0
// Address:   0x005118b0–0x00511935 inclusive (134 B / 0x86)
// System:    skills-abilities / STL Node24 isnil@+0x21 buynode
// Generated: 2026-08-05 R13-030 (forwards to named clean)
// Exactness: Behavior-preserving; named plate is authoritative.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct Node24Isnil21;
struct ValueIntKeyVec;

extern "C" Node24Isnil21* __stdcall StdTree_Buynode_Node24_Isnil21_Inferred(
    Node24Isnil21* left,
    Node24Isnil21* parent,
    Node24Isnil21* right,
    const ValueIntKeyVec* value,
    std::uint8_t color);

extern "C" Node24Isnil21* __stdcall FUN_005118b0(
    Node24Isnil21* left,
    Node24Isnil21* parent,
    Node24Isnil21* right,
    const ValueIntKeyVec* value,
    std::uint8_t color)
{
  return StdTree_Buynode_Node24_Isnil21_Inferred(left, parent, right, value, color);
}
