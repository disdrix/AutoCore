// =============================================================================
// StdTree_EraseRange_Val12  (aa_0040d700)
// -----------------------------------------------------------------------------
// Address:   0x0040d700 – 0x0040d7b3 inclusive (180 B / 0xB4)
//            autoassault.exe, image base 0x400000
// Wave:      W32-C OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from live decompile + full-body
//            read_memory. Peer of StdMap_EraseRange_Val12 @ 0x004e5120 (W28-P)
//            with free=0040d630 and single-erase=004188e0.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       __thiscall; ECX=map*; stack (outIt, first, last); RET 0x0C
// =============================================================================

#include <cstdint>

struct StdTreeNode_Val12 {
  StdTreeNode_Val12* left;    // +0x00
  StdTreeNode_Val12* parent;  // +0x04
  StdTreeNode_Val12* right;   // +0x08
  // color @ +0x18, isnil @ +0x19 (0 = real node)
  std::uint8_t pad_0c[12];
  std::uint8_t color;         // +0x18
  std::uint8_t isnil;         // +0x19
};

struct StdTreeShell_Val12 {
  void* unused0;              // +0x00
  StdTreeNode_Val12* head;    // +0x04 sentinel
  std::uint32_t size;         // +0x08
};

// W31-A sealed free-subtree (ECX=tree_base threaded; stack node*; RET 4).
extern "C" void __fastcall StdTree_FreeSubtree_Val12(void* tree_base,
                                                     StdTreeNode_Val12* node);
// Single-node erase + rebalance + operator_delete (leave-FUN; skills/map util).
extern "C" void __thiscall FUN_004188e0(StdTreeShell_Val12* map,
                                        StdTreeNode_Val12** out_or_slot,
                                        StdTreeNode_Val12* node);

static StdTreeNode_Val12* TreeSuccessor_Val12(StdTreeNode_Val12* node)
{
  if (node->isnil == 0) {
    StdTreeNode_Val12* r = node->right;
    if (r->isnil == 0) {
      StdTreeNode_Val12* cur = r;
      StdTreeNode_Val12* left = cur->left;
      while (left->isnil == 0) {
        cur = left;
        left = left->left;
      }
      return cur;
    }
    StdTreeNode_Val12* parent = node->parent;
    StdTreeNode_Val12* cur = node;
    while (parent->isnil == 0 && cur == parent->right) {
      cur = parent;
      parent = parent->parent;
    }
    return parent;
  }
  return node;
}

// Retail: FUN_0040d700
extern "C" void __thiscall StdTree_EraseRange_Val12(
    StdTreeShell_Val12* map,
    StdTreeNode_Val12** outIt,
    StdTreeNode_Val12* first,
    StdTreeNode_Val12* last)
{
  StdTreeNode_Val12* head = map->head;

  // Full-range: [begin, end) == [head->left, head)
  if (first == head->left && last == head) {
    StdTree_FreeSubtree_Val12(map, head->parent);
    head->parent = head;
    map->size = 0;
    head->left = head;
    head->right = head;
    *outIt = head->left;
    return; // ret 0x0c
  }

  while (first != last) {
    StdTreeNode_Val12* next = TreeSuccessor_Val12(first);
    // Retail passes &stack_first as the middle formal (iterator slot).
    StdTreeNode_Val12* slot = first;
    FUN_004188e0(map, &slot, first);
    first = next;
  }

  *outIt = first;
  return; // ret 0x0c
}

// Scaffold / Ghidra alias
extern "C" void __thiscall FUN_0040d700(
    StdTreeShell_Val12* map,
    StdTreeNode_Val12** outIt,
    StdTreeNode_Val12* first,
    StdTreeNode_Val12* last)
{
  StdTree_EraseRange_Val12(map, outIt, first, last);
}
