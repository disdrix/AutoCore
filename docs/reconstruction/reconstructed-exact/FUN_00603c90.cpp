// =============================================================================
// FUN_00603c90  (scaffold alias)
// -----------------------------------------------------------------------------
// Stable ID: aa_00603c90
// Address:   0x00603c90  (autoassault.exe, image base 0x400000)
// System:    MSVC std::_Tree always-insert + RB rebalance (Val28 / isnil@+0x29)
// Generated: 2026-08-04 WQ9E-F dual — prefer named clean unit
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Named dual: StdTree_InsertAndRebalance_Val28_Isnil29_Inferred
// Clean: docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val28_Isnil29_Inferred.cpp
// Dual:  reviews/A|B_aa_00603c90_StdTree_InsertAndRebalance_Val28_Isnil29_Inferred.md
//
// PURPOSE: always-insert Val28/isnil29 node under where; rebalance; *outIt=n.
// ABI: __thiscall; RET 0x10; body 0x00603c90–0x00603e7a exclusive (490 B).
// Strings: "map/set<T> too long"
// =============================================================================

#include <cstdint>

extern "C" void __thiscall StdTree_InsertAndRebalance_Val28_Isnil29_Inferred(
    std::int32_t map,
    std::int32_t** outIt,
    char addLeft,
    std::int32_t* where,
    void* value);

extern "C" void __thiscall FUN_00603c90(
    std::int32_t map,
    std::int32_t** outIt,
    char addLeft,
    std::int32_t* where,
    void* value)
{
  StdTree_InsertAndRebalance_Val28_Isnil29_Inferred(map, outIt, addLeft, where, value);
}
