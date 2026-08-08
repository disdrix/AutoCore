// =============================================================================
// FUN_00404180  (scaffold twin → StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00404180
// Address:   0x00404180–0x00404202 exclusive (130 B / 0x82)
// System:    MSVC std::_Tree buynode Val24/isnil29 (EAX-ctor path)
// Generated: 2026-08-04 WQ9K-C dual seal (scaffold 2026-07-23 refined)
// Exactness: Behavior-preserving; prefer named clean sibling for ports.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct NodeIsnil29;

extern "C" NodeIsnil29* __stdcall StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred(
    NodeIsnil29* left,
    NodeIsnil29* parent,
    NodeIsnil29* right,
    const std::uint32_t* value6,
    std::uint8_t color);

extern "C" NodeIsnil29* __stdcall FUN_00404180(
    NodeIsnil29* left,
    NodeIsnil29* parent,
    NodeIsnil29* right,
    const std::uint32_t* value6,
    std::uint8_t color)
{
  return StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred(
      left, parent, right, value6, color);
}
