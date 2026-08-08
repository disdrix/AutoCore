// =============================================================================
// FUN_0083ac90 — twin of ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred
// Stable ID: aa_0083ac90  VA: 0x0083ac90  WQ9K-H 2026-08-05
// Prefer the named clean source for port notes.
// =============================================================================

// See: ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred.cpp

extern "C" void ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred(void *host,
                                                                       int select_index);

extern "C" void FUN_0083ac90(void *host)
{
  // Product: select_index arrives in EAX; this twin documents the Ghidra name only.
  ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred(host, 0);
}
