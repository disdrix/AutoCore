// =============================================================================
// FUN_004e52a0  (scaffold twin of StdTree_EraseRange_Isnil21_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e52a0
// Address:   0x004e52a0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-05 R13-025 dual (was 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical: StdTree_EraseRange_Isnil21_Inferred
// =============================================================================

// See: StdTree_EraseRange_Isnil21_Inferred.cpp for named clean body.
// This twin keeps the Ghidra symbol for inventory / emit tooling.

#include <cstdint>

struct MapNode_Isnil21 {
  MapNode_Isnil21* left;
  MapNode_Isnil21* parent;
  MapNode_Isnil21* right;
  std::uint8_t pad_0c[0x14];
  std::uint8_t color;
  std::uint8_t isnil;
};

struct MapShell_Isnil21 {
  void* unused0;
  MapNode_Isnil21* head;
  std::uint32_t size;
};

extern "C" void __thiscall FUN_004e2e40(MapShell_Isnil21* map,
                                        MapNode_Isnil21* node);
extern "C" void __thiscall FUN_004e3e70(MapShell_Isnil21* map,
                                        MapNode_Isnil21** outIt,
                                        MapNode_Isnil21* node);

extern "C" void __thiscall FUN_004e52a0(
    MapShell_Isnil21* map,
    MapNode_Isnil21** outIt,
    MapNode_Isnil21* first,
    MapNode_Isnil21* last)
{
  MapNode_Isnil21* head = map->head;

  if (first == head->left && last == head) {
    FUN_004e2e40(map, head->parent);
    head->parent = head;
    map->size = 0;
    head->left = head;
    head->right = head;
    *outIt = head->left;
    return;
  }

  while (first != last) {
    MapNode_Isnil21* next = first;
    if (first->isnil == 0) {
      MapNode_Isnil21* r = first->right;
      if (r->isnil == 0) {
        next = r;
        MapNode_Isnil21* l = next->left;
        while (l->isnil == 0) {
          next = l;
          l = l->left;
        }
      } else {
        MapNode_Isnil21* p = first->parent;
        MapNode_Isnil21* cur = first;
        while (p->isnil == 0 && cur == p->right) {
          cur = p;
          p = p->parent;
        }
        next = p;
      }
    }
    MapNode_Isnil21* slot = first;
    FUN_004e3e70(map, &slot, first);
    first = next;
  }

  *outIt = first;
}
