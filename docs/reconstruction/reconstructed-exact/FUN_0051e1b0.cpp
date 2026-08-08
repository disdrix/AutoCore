// =============================================================================
// FUN_0051e1b0  (scaffold alias — see Map_Tidy_FreeHead_Isnil15_B.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051e1b0
// Address:   0x0051e1b0  (autoassault.exe, image base 0x400000)
// System:    STL map tidy free-head (isnil@+0x15_B family)
// Generated: 2026-08-04 WQ9G-D — scaffold kept as FUN_* twin of named clean
// Exactness: Behavior-preserving. Prefer Map_Tidy_FreeHead_Isnil15_B.cpp.
// Dual: reviews/A|B_aa_0051e1b0_Map_Tidy_FreeHead_Isnil15_B.md
// =============================================================================

#include <cstdint>

struct MapNode {
  MapNode* left;
  MapNode* parent;
  MapNode* right;
};

struct MapFacade {
  void* _unused0;
  MapNode* head;
  std::uint32_t size;
};

extern "C" void __thiscall Map_EraseRange_Isnil15_B(MapFacade* map,
                                                    void* out_iter,
                                                    MapNode* first,
                                                    MapNode* last);
extern "C" void __cdecl operator_delete(void* p);

void __fastcall FUN_0051e1b0(MapFacade* map)
{
  void* out;
  MapNode* head = map->head;
  Map_EraseRange_Isnil15_B(map, &out, head->left, head);
  operator_delete(head);
  map->head = nullptr;
  map->size = 0;
}
