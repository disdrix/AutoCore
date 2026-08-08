// =============================================================================
// RETIRED scaffold alias — do not use as product name
// -----------------------------------------------------------------------------
// Stable ID: aa_00403250
// Former auto name: Named_CalleeOf_Named_CalleeOf_Client_NotifyActiveMissionChanged_00403250
// Canonical:        StdTree_InsertAndRebalance_Isnil31_Inferred
// Dual:             MEGA-047 2026-08-05 — accept-with-gaps
// =============================================================================
// Chain-of-caller plate only. Structural role is MSVC std::_Tree always-insert
// + RB rebalance for isnil@+0x31 (node 0x38). Prefer named clean source.

#include <cstdint>

struct NodeIsnil31;
struct MapShellIsnil31;

extern "C" NodeIsnil31** StdTree_InsertAndRebalance_Isnil31_Inferred(
    MapShellIsnil31* map /*EDI*/,
    NodeIsnil31* where /*ECX*/,
    NodeIsnil31** out,
    char addLeft,
    const void* value);

// Retired alias — forwards to canonical
extern "C" NodeIsnil31** Named_CalleeOf_Named_CalleeOf_Client_NotifyActiveMissionChanged_00403250(
    MapShellIsnil31* map /*EDI*/,
    NodeIsnil31* where /*ECX*/,
    NodeIsnil31** out,
    char addLeft,
    const void* value)
{
  return StdTree_InsertAndRebalance_Isnil31_Inferred(map, where, out, addLeft, value);
}
