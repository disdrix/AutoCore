// =============================================================================
// FUN_00603830  (scaffold alias)
// -----------------------------------------------------------------------------
// Stable ID: aa_00603830
// Address:   0x00603830  (autoassault.exe, image base 0x400000)
// System:    MSVC std::_Tree erase + RB rebalance (Val28 / isnil@+0x29)
// Generated: 2026-08-04 WQ9E-F dual — prefer named clean unit
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Named dual: StdTree_EraseAndRebalance_Val28_Isnil29_Inferred
// Clean: docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Val28_Isnil29_Inferred.cpp
// Dual:  reviews/A|B_aa_00603830_StdTree_EraseAndRebalance_Val28_Isnil29_Inferred.md
//
// PURPOSE: erase one Val28/isnil29 map node; rebalance; size--; write outIt.
// ABI: __thiscall; RET 8; body 0x00603830–0x00603b03 exclusive (723 B).
// Strings: "invalid map/set<T> iterator"
// =============================================================================

#include <cstdint>

// Forward to named implementation (same translation unit may compile either).
extern "C" void __thiscall StdTree_EraseAndRebalance_Val28_Isnil29_Inferred(
    std::int32_t map,
    std::int32_t** outIt,
    std::int32_t* node);

extern "C" void __thiscall FUN_00603830(
    std::int32_t map,
    std::int32_t** outIt,
    std::int32_t* node)
{
  StdTree_EraseAndRebalance_Val28_Isnil29_Inferred(map, outIt, node);
}
