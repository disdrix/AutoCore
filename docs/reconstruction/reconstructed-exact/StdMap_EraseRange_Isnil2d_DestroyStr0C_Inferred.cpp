// =============================================================================
// StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred  (FUN_00407f90)
// -----------------------------------------------------------------------------
// Stable ID: aa_00407f90
// Address:   0x00407f90–0x00408042 exclusive (178 B / 0xB2)
// System:    MSVC std::_Tree range erase (isnil@+0x2d, string destroy @+0x0c)
// Dual A/B:  2026-08-05 WQ9K-B
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Erase [first, last) from an MSVC-style string-key map/set with isnil@+0x2d.
//   Full-range fast path frees the whole tree via dualed
//   StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred (0x00409970), then resets
//   head/size. Partial path inlines successor (isnil@+0x2d) then calls dualed
//   StdMap_StringKey_EraseAndRebalance_Inferred (0x004094c0).
//
// ABI
//   Register-this: EDI = map* (not ECX thiscall).
//   Stack: (Node** outIt, Node* first, Node* last); RET 0x0c; returns outIt.
//
// Callers
//   FUN_00404ec0 @ 0x00404eee, FUN_004061f0 @ 0x00406200
//   (map tidy/dtor full-range clear sites; then operator_delete(head)).
//
// Family
//   Free twin: 0x00409970. Single erase: 0x004094c0 (WQ9J-F). Do not merge with
//   isnil131 erase-range peer 0x00407b70 or isnil29 Map_EraseRange_C 0x00407d70.
// =============================================================================

#include <cstdint>

struct NodeIsnil2d {
  NodeIsnil2d* left;      // +0x00
  NodeIsnil2d* parent;    // +0x04
  NodeIsnil2d* right;     // +0x08
  // +0x0c std::string key
  // +0x2c color
  // +0x2d isnil
};

static inline std::uint8_t node_isnil(const NodeIsnil2d* n)
{
  return *reinterpret_cast<const std::uint8_t*>(
      reinterpret_cast<const char*>(n) + 0x2d);
}

struct MapShell {
  void* proxy;            // +0x00
  NodeIsnil2d* head;      // +0x04 sentinel
  std::uint32_t size;     // +0x08
};

// Dualed WQ9J-I free-subtree (isnil@+0x2d + DestroyStr0C). ECX=map, stack root, RET 4.
extern "C" void StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred(
    /*ECX*/ MapShell* map, NodeIsnil2d* root);

// Dualed WQ9J-F StringKey single erase+rebalance (3 stack args, RET 0x0c).
extern "C" NodeIsnil2d** StdMap_StringKey_EraseAndRebalance_Inferred(
    MapShell* map, NodeIsnil2d** outIt, NodeIsnil2d* node);

// In-order successor for non-nil nodes (MSVC tree walk; isnil@+0x2d).
// Inlined in binary; extracted here for readability only.
static NodeIsnil2d* tree_successor(NodeIsnil2d* node)
{
  if (node_isnil(node) != 0)
    return node;

  NodeIsnil2d* right = node->right;
  if (node_isnil(right) == 0) {
    NodeIsnil2d* succ = right;
    NodeIsnil2d* left = right->left;
    while (node_isnil(left) == 0) {
      succ = left;
      left = left->left;
    }
    return succ;
  }

  NodeIsnil2d* parent = node->parent;
  NodeIsnil2d* cur = node;
  while (node_isnil(parent) == 0 && cur == parent->right) {
    cur = parent;
    parent = parent->parent;
  }
  return parent;
}

// Binary entry: this in EDI (callers pre-load).
extern "C" NodeIsnil2d** StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred(
    MapShell* map_edi,
    NodeIsnil2d** out_it,
    NodeIsnil2d* first,
    NodeIsnil2d* last)
{
  NodeIsnil2d* head = map_edi->head;

  // Full clear: [begin, end) == [*head, head]
  if (first == head->left && last == head) {
    // Bytes: PUSH head->parent; MOV ECX,EDI; CALL 00409970
    StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred(map_edi, head->parent);
    head->parent = head;
    map_edi->size = 0;
    head->left = head;
    head->right = head;
    *out_it = head->left;
    return out_it;
  }

  while (first != last) {
    NodeIsnil2d* cur = first;                 // bytes: MOV ECX,ESI at loop head
    NodeIsnil2d* succ = tree_successor(first); // inlined isnil@+0x2d walk → ESI
    // Bytes: PUSH cur; LEA EAX,&stack_first; PUSH EAX; PUSH EDI; CALL 004094c0
    StdMap_StringKey_EraseAndRebalance_Inferred(map_edi, &first, cur);
    first = succ;                             // loop control uses ESI=succ
  }
  *out_it = first;
  return out_it;
}
