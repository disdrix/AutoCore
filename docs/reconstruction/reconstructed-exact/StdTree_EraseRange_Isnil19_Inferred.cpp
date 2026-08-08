// =============================================================================
// StdTree_EraseRange_Isnil19_Inferred  (FUN_0040bc10)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040bc10
// Address:   0x0040bc10–0x0040bcc2 exclusive (178 B / 0xB2)
// System:    MSVC std::_Tree range erase (isnil@+0x19 / Val12 family)
// Partition: inventory-transfer R13-020 (unit itself is generic STL)
// Dual A/B:  2026-08-05 R13-020 OWN
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Erase [first, last) from an MSVC-style map/set whose nodes use isnil@+0x19
//   and color@+0x18 (Val12 layout). Full-range fast path frees the whole tree
//   via residual FUN_0040c100, then resets head/size. Partial path inlines
//   in-order successor (isnil@+0x19) then residual single-erase FUN_0040b440.
//
// ABI
//   Register-this: EDI = map* (not ECX thiscall).
//   Stack: (Node** outIt, Node* first, Node* last); RET 0x0C; returns outIt.
//
// Callers
//   FUN_0040b2d0 @ 0x0040b2fe, FUN_0040b410 @ 0x0040b420 (tidy full-clear),
//   FUN_0092b2a0 @ 0x0092b8fc / 0x0092b947 (parent shell; LEA EDI, local map).
//
// Family
//   Free residual: 0x0040c100 (isnil19 free-subtree). Erase residual: 0x0040b440.
//   Peer dualed ECX plate: StdTree_EraseRange_Val12 @ 0x0040d700 — do not merge.
// =============================================================================

#include <cstdint>

struct NodeIsnil19 {
  NodeIsnil19* left;     // +0x00
  NodeIsnil19* parent;   // +0x04
  NodeIsnil19* right;    // +0x08
  // +0x0c .. +0x17 : 12-byte value region (Val12)
  std::uint8_t color;    // +0x18
  std::uint8_t isnil;    // +0x19  (0 = real node)
};

struct MapShell {
  void* proxy;           // +0x00
  NodeIsnil19* head;     // +0x04 sentinel
  std::uint32_t size;    // +0x08
};

// Residual free-subtree isnil@+0x19. Retail: ECX=map threaded; stack root; RET 4.
// Bytes: right-recurse, operator_delete(node), left-walk (decomp damaged by noreturn).
extern "C" void __fastcall FUN_0040c100(MapShell* map_ecx, NodeIsnil19* root);

// Residual single erase+rebalance isnil@+0x19 / color@+0x18 (R13-018 queue).
// Retail: stack (map, outIt**, node); invalid-iterator throw; operator_delete.
extern "C" void FUN_0040b440(
    MapShell* map, NodeIsnil19** pOutIt, NodeIsnil19* node);

static NodeIsnil19* TreeSuccessor_Isnil19(NodeIsnil19* node)
{
  if (node->isnil == 0) {
    NodeIsnil19* r = node->right;
    if (r->isnil == 0) {
      NodeIsnil19* cur = r;
      NodeIsnil19* left = cur->left;
      while (left->isnil == 0) {
        cur = left;
        left = left->left;
      }
      return cur;
    }
    NodeIsnil19* parent = node->parent;
    NodeIsnil19* cur = node;
    while (parent->isnil == 0 && cur == parent->right) {
      cur = parent;
      parent = parent->parent;
    }
    return parent;
  }
  return node;
}

// Binary entry: this in EDI (callers pre-load). Clean signature documents contract.
extern "C" NodeIsnil19** StdTree_EraseRange_Isnil19_Inferred(
    MapShell* map_edi,
    NodeIsnil19** out_it,
    NodeIsnil19* first,
    NodeIsnil19* last)
{
  NodeIsnil19* head = map_edi->head;

  // Full clear: [begin, end) == [*head, head]
  if (first == head->left && last == head) {
    // Bytes: PUSH head->parent; MOV ECX,EDI; CALL 0040c100
    FUN_0040c100(map_edi, head->parent);
    head->parent = head;
    map_edi->size = 0;
    head->left = head;
    head->right = head;
    *out_it = head->left;
    return out_it; // ret 0x0c
  }

  while (first != last) {
    NodeIsnil19* cur = first;
    // Bytes: inline successor into ESI; then
    // PUSH cur; LEA EAX,&outIt; PUSH EAX; PUSH EDI; CALL 0040b440
    first = TreeSuccessor_Isnil19(first);
    FUN_0040b440(map_edi, out_it, cur);
  }
  *out_it = first;
  return out_it; // ret 0x0c
}

// Scaffold / Ghidra alias
extern "C" NodeIsnil19** FUN_0040bc10(
    MapShell* map_edi,
    NodeIsnil19** out_it,
    NodeIsnil19* first,
    NodeIsnil19* last)
{
  return StdTree_EraseRange_Isnil19_Inferred(map_edi, out_it, first, last);
}
