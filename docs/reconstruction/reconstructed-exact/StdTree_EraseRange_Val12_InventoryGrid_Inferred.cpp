// =============================================================================
// StdTree_EraseRange_Val12_InventoryGrid_Inferred  (aa_00573700)
// -----------------------------------------------------------------------------
// Address:   0x00573700 – 0x005737b3 inclusive (180 B / 0xB4)
//            autoassault.exe, image base 0x400000
// Wave:      MEGA-120 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite from live decompile + full-body
//            read_memory + disassemble_function. Peer clone of
//            StdTree_EraseRange_Val12 @ 0x0040d700 (W32-C) with free=005731c0
//            and single-erase=StdTree_Erase_Val12 @ 0x00573250 (W27-S).
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       __thiscall; ECX=map*; stack (outIt, first, last); RET 0x0C
// System:    inventory-transfer (InventoryGrid placement / partial maps)
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
  void* unused0;              // +0x00  (InventoryGrid: shell at grid+0x5c)
  StdTreeNode_Val12* head;    // +0x04  (InventoryGrid: head at grid+0x60)
  std::uint32_t size;         // +0x08  (InventoryGrid: size at grid+0x64)
};

// Free entire non-nil subtree (isnil@+0x19). Live: thiscall ECX=tree_base,
// stack node*, RET 4. Decompiler drops left-walk after false noreturn.
extern "C" void __thiscall FUN_005731c0(void* tree_base,
                                        StdTreeNode_Val12* node);

// Dualed W27-S: single-node erase + rebalance + operator_delete; RET 8.
extern "C" void __thiscall StdTree_Erase_Val12(
    StdTreeShell_Val12* map,
    StdTreeNode_Val12** outIt,
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

// Retail: FUN_00573700
// Partition hint alias: InventoryGrid_DestroyItemList (full-clear use only)
extern "C" void __thiscall StdTree_EraseRange_Val12_InventoryGrid_Inferred(
    StdTreeShell_Val12* map,
    StdTreeNode_Val12** outIt,
    StdTreeNode_Val12* first,
    StdTreeNode_Val12* last)
{
  StdTreeNode_Val12* head = map->head;

  // Full-range: [begin, end) == [head->left, head)
  if (first == head->left && last == head) {
    FUN_005731c0(map, head->parent);
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
    StdTree_Erase_Val12(map, &slot, first);
    first = next;
  }

  *outIt = first;
  return; // ret 0x0c
}

// Scaffold / Ghidra alias
extern "C" void __thiscall FUN_00573700(
    StdTreeShell_Val12* map,
    StdTreeNode_Val12** outIt,
    StdTreeNode_Val12* first,
    StdTreeNode_Val12* last)
{
  StdTree_EraseRange_Val12_InventoryGrid_Inferred(map, outIt, first, last);
}
