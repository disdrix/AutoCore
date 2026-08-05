// =============================================================================
// FUN_004e4130 — scaffold alias → StdTree_EraseAndRebalance_Val12
// -----------------------------------------------------------------------------
// Stable ID: aa_004e4130
// Address:   0x004e4130  (autoassault.exe, image base 0x400000)
// W27-Q: Prefer clean plate StdTree_EraseAndRebalance_Val12.cpp
// =============================================================================

// Scaffold retained for Ghidra-symbol lookup. Authoritative CF + ABI:
//   docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Val12.cpp
//
// void __thiscall FUN_004e4130(MapShell*, Node** outIt, Node* node);
// RET 8; throw if node->isnil ("invalid map/set<T> iterator" @ 0x00a152f0);
// unlink + RB rebalance (Val12 L/R rotate); operator_delete; size--; *outIt.

void FUN_004e4130(void);
