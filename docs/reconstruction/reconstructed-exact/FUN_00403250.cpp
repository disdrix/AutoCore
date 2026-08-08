// =============================================================================
// FUN_00403250  — twin of StdTree_InsertAndRebalance_Isnil31_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00403250
// Address:   0x00403250–0x004033d1 inclusive (386 B / 0x182)
// System:    MSVC std::_Tree always-insert + RB rebalance (isnil@+0x31)
// Generated: 2026-08-05 MEGA-047 dual seal (replaces 2026-07-23 scaffold)
// Exactness: Ghidra-symbol twin; prefer named clean for port.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// Canonical: StdTree_InsertAndRebalance_Isnil31_Inferred.cpp
// Retire:    Named_CalleeOf_Named_CalleeOf_Client_NotifyActiveMissionChanged_00403250.cpp
// Dual:      reviews/A|B_aa_00403250_StdTree_InsertAndRebalance_Isnil31_Inferred.md
// =============================================================================

#include <cstdint>

// See StdTree_InsertAndRebalance_Isnil31_Inferred.cpp for full plate + body.
// Ghidra symbol kept as twin entry for VA lookup.

struct NodeIsnil31;
struct MapShellIsnil31;

extern "C" NodeIsnil31** StdTree_InsertAndRebalance_Isnil31_Inferred(
    MapShellIsnil31* map /*EDI*/,
    NodeIsnil31* where /*ECX*/,
    NodeIsnil31** out,
    char addLeft,
    const void* value);

// Ghidra name alias — same body / ABI (EDI=map, ECX=where, RET 0xC)
extern "C" NodeIsnil31** FUN_00403250(
    MapShellIsnil31* map /*EDI*/,
    NodeIsnil31* where /*ECX*/,
    NodeIsnil31** out,
    char addLeft,
    const void* value)
{
  return StdTree_InsertAndRebalance_Isnil31_Inferred(map, where, out, addLeft, value);
}
