// =============================================================================
// FUN_005ae2f0  (scaffold twin of StdTree_InsertAndRebalance_Val20_Isnil21_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005ae2f0
// Address:   0x005ae2f0–0x005ae4da inclusive (491 B / 0x1EB)
// System:    skills-abilities / STL map-set helpers
// Dual A/B:  2026-08-05 R12-034 OWN-ONLY
// Prefer:    StdTree_InsertAndRebalance_Val20_Isnil21_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================

// PURPOSE: Always-insert + RB rebalance for Val20 / isnil@+0x21 (node 0x24).
// Embedded strings: "map/set<T> too long"
// Callees: FUN_005ae1c0, FUN_0050e9f0, FUN_005a27f0×2, _CxxThrowException
// Caller:  FUN_005aec50 only
// ABI:     __thiscall; RET 0x10; size gate 0xCCCCCCB

#include <cstdint>

// Forward to named clean implementation.
extern "C" void __thiscall StdTree_InsertAndRebalance_Val20_Isnil21_Inferred(
    void* map,
    void** out,
    char addLeft,
    void* where,
    const void* value);

extern "C" void __thiscall FUN_005ae2f0(
    void* map,
    void** out,
    char addLeft,
    void* where,
    const void* value)
{
  StdTree_InsertAndRebalance_Val20_Isnil21_Inferred(map, out, addLeft, where, value);
}
