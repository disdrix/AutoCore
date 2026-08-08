// =============================================================================
// StdTree_EraseRange_Isnil21_Inferred  (aa_004e52a0)
// -----------------------------------------------------------------------------
// Address:   0x004e52a0 – 0x004e5353 inclusive (180 B / 0xB4)
//            autoassault.exe, image base 0x400000
// Wave:      R13-025 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite from live decompile + full-body
//            read_memory. Parent dual erase: 0x004e3e70
//            StdTree_EraseAndRebalance_Isnil21_Inferred.
//            Sibling clone: FUN_004e4e10 (free=004e2e00; R13-024).
//            Peer family: StdTree_EraseRange_Val12 @ 0x0040d700 (isnil@+0x19).
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       __thiscall; ECX=map*; stack (outIt, first, last); RET 0x0C
// Name:      Inferred — never Runtime Confirmed.
// =============================================================================

#include <cstdint>

struct MapNode_Isnil21 {
  MapNode_Isnil21* left;    // +0x00
  MapNode_Isnil21* parent;  // +0x04
  MapNode_Isnil21* right;   // +0x08
  // value payload @ +0x10 (Val16 family; not touched here)
  // color @ +0x20, isnil @ +0x21 (0 = real node)
  std::uint8_t pad_0c[0x14];
  std::uint8_t color;       // +0x20
  std::uint8_t isnil;       // +0x21
};

struct MapShell_Isnil21 {
  void* unused0;            // +0x00
  MapNode_Isnil21* head;    // +0x04 sentinel
  std::uint32_t size;       // +0x08
};

// Free-subtree for isnil@+0x21 (ECX=map threaded; stack node*; RET 4).
// Ghidra: FUN_004e2e40 — not dualed this wave.
extern "C" void __thiscall FUN_004e2e40(MapShell_Isnil21* map,
                                        MapNode_Isnil21* node);

// Single-node erase + RB rebalance + operator_delete (parent dual R12-013).
// Ghidra: FUN_004e3e70 — StdTree_EraseAndRebalance_Isnil21_Inferred; RET 8.
extern "C" void __thiscall StdTree_EraseAndRebalance_Isnil21_Inferred(
    MapShell_Isnil21* map,
    MapNode_Isnil21** outIt,
    MapNode_Isnil21* node);

static MapNode_Isnil21* TreeSuccessor_Isnil21(MapNode_Isnil21* node)
{
  if (node->isnil == 0) {
    MapNode_Isnil21* r = node->right;
    if (r->isnil == 0) {
      MapNode_Isnil21* cur = r;
      MapNode_Isnil21* left = cur->left;
      while (left->isnil == 0) {
        cur = left;
        left = left->left;
      }
      return cur;
    }
    MapNode_Isnil21* parent = node->parent;
    MapNode_Isnil21* cur = node;
    while (parent->isnil == 0 && cur == parent->right) {
      cur = parent;
      parent = parent->parent;
    }
    return parent;
  }
  return node;
}

// Retail: FUN_004e52a0
extern "C" void __thiscall StdTree_EraseRange_Isnil21_Inferred(
    MapShell_Isnil21* map,
    MapNode_Isnil21** outIt,
    MapNode_Isnil21* first,
    MapNode_Isnil21* last)
{
  MapNode_Isnil21* head = map->head;

  // Full-range: [begin, end) == [head->left, head)
  if (first == head->left && last == head) {
    FUN_004e2e40(map, head->parent);
    head->parent = head;
    map->size = 0;
    head->left = head;
    head->right = head;
    *outIt = head->left;
    return; // ret 0x0c
  }

  while (first != last) {
    MapNode_Isnil21* next = TreeSuccessor_Isnil21(first);
    // Retail passes &stack_first as the middle formal (iterator slot).
    MapNode_Isnil21* slot = first;
    StdTree_EraseAndRebalance_Isnil21_Inferred(map, &slot, first);
    first = next;
  }

  *outIt = first;
  return; // ret 0x0c
}

// Scaffold / Ghidra alias
extern "C" void __thiscall FUN_004e52a0(
    MapShell_Isnil21* map,
    MapNode_Isnil21** outIt,
    MapNode_Isnil21* first,
    MapNode_Isnil21* last)
{
  StdTree_EraseRange_Isnil21_Inferred(map, outIt, first, last);
}
