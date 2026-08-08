// =============================================================================
// FUN_005a3500  (scaffold twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_005a3500
// Address:   0x005a3500–0x005a36ea inclusive (491 B / 0x1EB)
// Canonical: StdTree_InsertAndRebalance_Val16_Isnil21_Inferred
// Dual A/B:  2026-08-05 R12-031
// See:       StdTree_InsertAndRebalance_Val16_Isnil21_005a3500_Inferred.cpp
// =============================================================================
// PURPOSE: MSVC std::_Tree always-insert + red-black rebalance for Val16 /
// isnil@+0x21 / node 0x28. Always-insert (no key compare). RET 0x10 thiscall.
// Buynode FUN_004e2b80; Lrotate FUN_0050e9f0; Rrotate FUN_005a27f0; one L inlined.
// Parent sole caller FUN_005a3be0 (2 sites). Twin of 0x004e37e0 (R12-012).
// Never Runtime Confirmed.
// =============================================================================

#include <cstdint>

// Forward to named clean reconstruction.
extern "C" void __thiscall StdTree_InsertAndRebalance_Val16_Isnil21_Inferred(
    void* map,
    void** out,
    char addLeft,
    void* where,
    const void* value);

extern "C" void __thiscall FUN_005a3500(
    void* map,
    void** out,
    char addLeft,
    void* where,
    const void* value)
{
  StdTree_InsertAndRebalance_Val16_Isnil21_Inferred(map, out, addLeft, where, value);
}
