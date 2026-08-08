// =============================================================================
// FUN_005738d0  (scaffold twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_005738d0
// Address:   0x005738d0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-23 scaffold; refined R11-004 2026-08-05
// Exactness: Behavior-preserving rewrite. Prefer named clean:
//   StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred.cpp
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct StdTreeNode_Val12;
struct StdTreeShell_Val12 {
  void* unused0;
  StdTreeNode_Val12* head;
  std::uint32_t size;
};

extern "C" void __thiscall StdTree_EraseRange_Val12_InventoryGrid_Inferred(
    StdTreeShell_Val12* map,
    StdTreeNode_Val12** outIt,
    StdTreeNode_Val12* first,
    StdTreeNode_Val12* last);
extern "C" void __cdecl operator_delete(void* p);

// Retail: FUN_005738d0 — bare Val12 tidy free-head (InventoryGrid erase leaf).
// Decompiler false-noreturn after operator_delete; bytes null head+size then RET.
extern "C" void __fastcall FUN_005738d0(StdTreeShell_Val12* map /*ECX*/)
{
  void* out;
  StdTreeNode_Val12* head = map->head;
  StdTree_EraseRange_Val12_InventoryGrid_Inferred(
      map,
      reinterpret_cast<StdTreeNode_Val12**>(&out),
      head->left,
      head);
  operator_delete(head);
  map->head = nullptr;
  map->size = 0;
}
