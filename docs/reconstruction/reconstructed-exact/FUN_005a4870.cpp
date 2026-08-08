// =============================================================================
// FUN_005a4870 — scaffold twin of StdTree_Buynode_Isnil21_Node0x24_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005a4870
// Address:   0x005a4870–0x005a48f5 inclusive (134 B / 0x86)
// System:    MSVC std::_Tree node buy — isnil@+0x21 / node 0x24
// Generated: 2026-08-05 R13-008 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Canonical named plate:
//   docs/reconstruction/reconstructed-exact/StdTree_Buynode_Isnil21_Node0x24_Inferred.cpp
// Dual: reviews/A|B_aa_005a4870_StdTree_Buynode_Isnil21_Node0x24_Inferred.md

#include <cstdint>

// Forward to named reconstruction (same ABI / body).
extern "C" void* __stdcall StdTree_Buynode_Isnil21_Node0x24_Inferred(
    void* left,
    void* parent,
    void* right,
    const void* value,
    std::uint8_t color);

extern "C" void* __stdcall FUN_005a4870(
    void* left,
    void* parent,
    void* right,
    const void* value,
    std::uint8_t color)
{
  return StdTree_Buynode_Isnil21_Node0x24_Inferred(left, parent, right, value, color);
}
