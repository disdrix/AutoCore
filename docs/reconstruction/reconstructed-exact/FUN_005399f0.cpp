// =============================================================================
// FUN_005399f0 — scaffold alias → Map_EraseNode_Val12
// -----------------------------------------------------------------------------
// Stable ID: aa_005399f0
// Address:   0x005399f0  (autoassault.exe, image base 0x400000)
// W27-R: Prefer clean plate Map_EraseNode_Val12.cpp
// =============================================================================

// Scaffold retained for Ghidra-symbol lookup. Authoritative CF + ABI:
//   docs/reconstruction/reconstructed-exact/Map_EraseNode_Val12.cpp
//
// void __thiscall FUN_005399f0(MapShell*, Node** outIt, Node* node);
// RET 8; throw if isnil@+0x19 ("invalid map/set<T> iterator");
// Val12 color@+0x18; size-- after operator_delete; *outIt = successor.

void FUN_005399f0(void);
