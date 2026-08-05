// =============================================================================
// FUN_0099bba0 — scaffold twin of CNDAssetStringTable_Unserialize
// Stable ID: aa_0099bba0
// Address:   0x0099bba0–0x0099BED5 exclusive (821 B)
// W34-J: prefer named clean CNDAssetStringTable_Unserialize.cpp
// Product plate: "CNDAssetStringTable::Unserialize"
// =============================================================================

#include <cstdint>

extern "C" uint8_t CNDAssetStringTable_Unserialize(void* host_table,
                                                   void* scratch,
                                                   void* reader);

// Retail: 3 stack args; ret 12; AL=1
extern "C" uint8_t FUN_0099bba0(void* host_table, void* scratch, void* reader)
{
  return CNDAssetStringTable_Unserialize(host_table, scratch, reader);
}
