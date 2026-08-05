// =============================================================================
// FUN_00539210 — scaffold alias → StdTree_InsertAndRebalance_Val12
// -----------------------------------------------------------------------------
// Stable ID: aa_00539210
// Address:   0x00539210  (autoassault.exe, image base 0x400000)
// W27-Q: Prefer clean plate StdTree_InsertAndRebalance_Val12.cpp
// =============================================================================

// Scaffold retained for Ghidra-symbol lookup. Authoritative CF + ABI:
//   docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val12.cpp
//
// void __thiscall FUN_00539210(MapShell*, Node** outIt, char addLeft,
//                              Node* where, const Val12* value);
// RET 0x10; throw if size > 0x15555553 ("map/set<T> too long");
// buys via FUN_005ae220 (StdTree_Buynode_Val12, color 0); RB rebalance.

void FUN_00539210(void);
