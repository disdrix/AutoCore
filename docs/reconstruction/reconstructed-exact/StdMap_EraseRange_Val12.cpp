// =============================================================================
// StdMap_EraseRange_Val12  (FUN_004e5120)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e5120
// Address:   0x004e5120  (autoassault.exe, image base 0x400000)
// Body:      0x004e5120 – 0x004e51d4 exclusive (180 B / 0xB4)
// System:    std map/set red-black tree range erase (Val12 / isnil@+0x19)
// Generated: 2026-07-29 W28-P dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of live decompile CF + byte-sealed RET 0x0C.
// ABI:       __thiscall; ECX=map*; stack (outIt, first, last); RET 0x0C
// =============================================================================

#include <cstdint>

struct MapNode_Val12 {
  MapNode_Val12* left;    // +0x00
  MapNode_Val12* parent;  // +0x04
  MapNode_Val12* right;   // +0x08
  std::uint32_t value[3];// +0x0C  (key at value[0] for int-key maps)
  std::uint8_t color;    // +0x18
  std::uint8_t isnil;    // +0x19
};

struct MapShell_Val12 {
  void* unused0;         // +0x00
  MapNode_Val12* head;   // +0x04 sentinel (left=leftmost, parent=root, right=rightmost)
  std::uint32_t size;    // +0x08
};

// Callees (sealed elsewhere / leave FUN_* where product open):
//   FUN_004e2940(root)  — recursive free non-nil Val12 subtree
//   FUN_004e4130        — StdTree_EraseAndRebalance_Val12 (W27-Q)

extern "C" void __thiscall FUN_004e2940(MapNode_Val12* node);
extern "C" void __thiscall StdTree_EraseAndRebalance_Val12(
    MapShell_Val12* map, MapNode_Val12** outIt, MapNode_Val12* node);

static MapNode_Val12* TreeSuccessor_Val12(MapNode_Val12* node)
{
  if (node->isnil == 0) {
    MapNode_Val12* r = node->right;
    if (r->isnil == 0) {
      MapNode_Val12* cur = r;
      MapNode_Val12* left = cur->left;
      while (left->isnil == 0) {
        cur = left;
        left = left->left;
      }
      return cur;
    }
    MapNode_Val12* parent = node->parent;
    MapNode_Val12* cur = node;
    while (parent->isnil == 0 && cur == parent->right) {
      cur = parent;
      parent = parent->parent;
    }
    return parent;
  }
  return node;
}

// Retail: FUN_004e5120
void __thiscall StdMap_EraseRange_Val12(
    MapShell_Val12* map,
    MapNode_Val12** outIt,
    MapNode_Val12* first,
    MapNode_Val12* last)
{
  MapNode_Val12* head = map->head;

  // Full-range: [begin, end) == [head->left, head)
  if (first == head->left && last == head) {
    FUN_004e2940(head->parent);
    head->parent = head;
    map->size = 0;
    head->left = head;
    head->right = head;
    *outIt = head->left;
    return; // ret 0x0c
  }

  while (first != last) {
    MapNode_Val12* succ = TreeSuccessor_Val12(first);
    // thiscall erase — ECX=map; updates *(&first) to successor internally
    MapNode_Val12* cur = first;
    StdTree_EraseAndRebalance_Val12(map, &first, cur);
    first = succ;
  }
  *outIt = first;
  // ret 0x0c
}
