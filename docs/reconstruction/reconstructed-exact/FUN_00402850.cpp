// =============================================================================
// FUN_00402850 — twin of StdTree_EraseAndRebalance_Isnil29_RetC_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00402850
// Address:   0x00402850  (autoassault.exe, image base 0x400000)
// Body:      0x00402850 – 0x00402ae0 exclusive (656 B / 0x290)
// System:    MSVC std::_Tree erase + RB rebalance (isnil@+0x29, RET 0xC)
// Generated: 2026-08-05 MEGA-034 dual seal
// Exactness: Thin twin — see StdTree_EraseAndRebalance_Isnil29_RetC_Inferred.cpp
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

#include <cstdint>

// Forward to named reconstruction (full body + layout + callees there).
extern "C" void StdTree_EraseAndRebalance_Isnil29_RetC_Inferred(
    void *map, void **outIt, void *node);

extern "C" void FUN_00402850(void *map, void **outIt, void *node)
{
  // ABI: three stack args; RET 0x0C. map*, outIt**, node*.
  // isnil@+0x29 / color@+0x28; bare operator_delete; size--; *outIt=succ.
  StdTree_EraseAndRebalance_Isnil29_RetC_Inferred(map, outIt, node);
}
