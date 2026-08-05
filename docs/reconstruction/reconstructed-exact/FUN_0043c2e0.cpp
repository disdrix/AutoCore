// Scaffold twin — see Map_TreeInsertAndRebalance_Val12_EsiBuy.cpp (aa_0043c2e0, W29-D)
// Ghidra name retained for path stability.

#include <cstdint>

struct MapNode_Val12;
struct MapShell_Val12;

extern "C" void Map_TreeInsertAndRebalance_Val12_EsiBuy(
    MapShell_Val12* map,
    MapNode_Val12** outIt,
    char addLeft,
    MapNode_Val12* where,
    const uint32_t value[3]);

extern "C" void FUN_0043c2e0(
    MapNode_Val12** outIt,
    char addLeft,
    MapNode_Val12* where,
    const uint32_t* value)
{
  // Retail: map in EDI; ret 0x10.
  Map_TreeInsertAndRebalance_Val12_EsiBuy(
      /*EDI*/ nullptr, outIt, addLeft, where, value);
}
