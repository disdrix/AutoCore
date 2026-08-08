// =============================================================================
// FUN_004cb740 — scaffold alias → StdTree_EraseAndRebalance_Isnil29_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004cb740
// Address:   0x004cb740  (autoassault.exe, image base 0x400000)
// WQ9E-E: Prefer clean plate StdTree_EraseAndRebalance_Isnil29_Inferred.cpp
// =============================================================================

// Scaffold retained for Ghidra-symbol lookup. Authoritative CF + ABI:
//   docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil29_Inferred.cpp
//
// void __thiscall FUN_004cb740(MapShell*, Node** outIt, Node* node);
// RET 8; throw if node->isnil ("invalid map/set<T> iterator");
// unlink + RB rebalance (isnil29 L/R rotate); operator_delete; size--; *outIt.

void FUN_004cb740(void);
