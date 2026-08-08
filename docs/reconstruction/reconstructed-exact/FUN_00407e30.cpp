// =============================================================================
// FUN_00407e30 — scaffold twin of StdTree_Buynode_Val24_Isnil29_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00407e30
// Address:   0x00407e30–0x00407eb4 exclusive (132 B)
// Canonical: StdTree_Buynode_Val24_Isnil29_Inferred
// Generated: 2026-08-04 WQ9F-B (replaces 2026-07-23 scaffold body)
// =============================================================================

#include <cstdint>

// Full plate: reconstructed-exact/StdTree_Buynode_Val24_Isnil29_Inferred.cpp

struct NodeIsnil29;

extern "C" NodeIsnil29* __stdcall StdTree_Buynode_Val24_Isnil29_Inferred(
    NodeIsnil29* left,
    NodeIsnil29* parent,
    NodeIsnil29* right,
    const std::uint32_t* value6,
    std::uint8_t color);

extern "C" NodeIsnil29* __stdcall FUN_00407e30(
    NodeIsnil29* left,
    NodeIsnil29* parent,
    NodeIsnil29* right,
    const std::uint32_t* value6,
    std::uint8_t color)
{
  return StdTree_Buynode_Val24_Isnil29_Inferred(left, parent, right, value6, color);
}
