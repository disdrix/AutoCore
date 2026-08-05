// =============================================================================
// FUN_00567450 — scaffold alias → Map_TreeInsertAndRebalance_Val12 (clone)
// -----------------------------------------------------------------------------
// Stable ID: aa_00567450
// Address:   0x00567450  (autoassault.exe, image base 0x400000)
// W27-R: Prefer clean plate Map_TreeInsertAndRebalance_Val12_00567450.cpp
// =============================================================================

// Scaffold retained for Ghidra-symbol lookup. Authoritative CF + ABI:
//   docs/reconstruction/reconstructed-exact/Map_TreeInsertAndRebalance_Val12_00567450.cpp
//
// void __thiscall FUN_00567450(MapShell*, Node** outIt, char addLeft,
//                              Node* where, const Val12* value);
// RET 0x10; throw if size > 0x15555553 ("map/set<T> too long");
// buys via FUN_005ae220 (StdTree_Buynode_Val12, color 0); RB rebalance.
// Twin: FUN_0051c1c0 / aa_0051c1c0 (do not merge).

void FUN_00567450(void);
