// =============================================================================
// FUN_00441960  (Ghidra-symbol twin of StdTree_EraseRange_Isnil11_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00441960
// Address:   0x00441960 – 0x00441a11 inclusive (178 B / 0xB2)
// Named clean: StdTree_EraseRange_Isnil11_Inferred.cpp  ← prefer for port work
// Wave:      2026-08-05 MEGA-136 OWN dual seal
// Scaffold:  Named_CalleeOf_Named_gfxUIWindow_00441960  RETIRED
// =============================================================================

#include <cstdint>

struct MapNode_Isnil11 {
  MapNode_Isnil11 *left;
  MapNode_Isnil11 *parent;
  MapNode_Isnil11 *right;
};

struct MapShell_Isnil11 {
  void *proxy;
  MapNode_Isnil11 *head;
  uint32_t size;
};

extern "C" void __fastcall StdTree_FreeSubtree_Isnil11_Inferred(
    void *tree_base, MapNode_Isnil11 *node);
extern "C" void FUN_004477a0(
    MapShell_Isnil11 *map, MapNode_Isnil11 **outIt, MapNode_Isnil11 *node);

static uint8_t isnil11(const MapNode_Isnil11 *n)
{
  return *reinterpret_cast<const uint8_t *>(reinterpret_cast<const char *>(n) + 0x11);
}

static MapNode_Isnil11 *successor_isnil11(MapNode_Isnil11 *node)
{
  if (isnil11(node) != 0)
    return node;
  MapNode_Isnil11 *right = node->right;
  if (isnil11(right) == 0) {
    MapNode_Isnil11 *succ = right;
    MapNode_Isnil11 *left = right->left;
    while (isnil11(left) == 0) {
      succ = left;
      left = left->left;
    }
    return succ;
  }
  MapNode_Isnil11 *parent = node->parent;
  MapNode_Isnil11 *cur = node;
  while (isnil11(parent) == 0 && cur == parent->right) {
    cur = parent;
    parent = parent->parent;
  }
  return parent;
}

// Ghidra name. EDI = map; stack outIt/first/last; RET 0xC; EAX = outIt*.
extern "C" MapNode_Isnil11 **FUN_00441960(
    MapShell_Isnil11 *map,       // EDI
    MapNode_Isnil11 **outIt,
    MapNode_Isnil11 *first,
    MapNode_Isnil11 *last)
{
  MapNode_Isnil11 *head = map->head;

  if (first == head->left && last == head) {
    StdTree_FreeSubtree_Isnil11_Inferred(map, head->parent);
    head->parent = head;
    map->size = 0;
    head->left = head;
    head->right = head;
    *outIt = head->left;
    return outIt;
  }

  while (first != last) {
    MapNode_Isnil11 *node = first;
    MapNode_Isnil11 *succ = successor_isnil11(first);
    FUN_004477a0(map, &first, node);
    first = succ;
  }
  *outIt = first;
  return outIt;
}
