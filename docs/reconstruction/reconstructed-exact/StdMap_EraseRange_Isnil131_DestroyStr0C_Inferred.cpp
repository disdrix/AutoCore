// =============================================================================
// StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred  (FUN_00407b70)
// -----------------------------------------------------------------------------
// Stable ID: aa_00407b70
// Address:   0x00407b70–0x00407bea exclusive (122 B / 0x7A)
// System:    MSVC std::_Tree range erase (isnil@+0x131, string destroy @+0x0c)
// Dual A/B:  2026-08-05 WQ9K-B
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Erase [first, last) from an MSVC-style map/set whose nodes use isnil@+0x131
//   and carry a std::string at +0x0c. Full-range fast path frees the whole tree
//   via dualed StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred (0x00409920),
//   then resets head/size. Partial path advances with residual successor
//   FUN_00404000 then residual single-erase FUN_00408ad0.
//
// ABI
//   Register-this: ESI = map* (not ECX thiscall).
//   Stack: (Node** outIt, Node* first, Node* last); RET 0x0c; returns outIt.
//
// Callers
//   FUN_00405110 @ 0x0040513e, FUN_00405df0 @ 0x00405e00
//   (map tidy/dtor full-range clear sites; then operator_delete(head)).
//
// Family
//   Free twin: 0x00409920 (isnil131 DestroyStr0C). Do not merge with isnil2d
//   erase-range peer 0x00407f90 or isnil29 Map_EraseRange_C 0x00407d70.
// =============================================================================

#include <cstdint>

struct NodeIsnil131 {
  NodeIsnil131* left;     // +0x00
  NodeIsnil131* parent;   // +0x04
  NodeIsnil131* right;    // +0x08
  // +0x0c std::string key/value (destroyed by free/erase chain)
  // ... large payload through ...
  // isnil @ +0x131
};

struct MapShell {
  void* proxy;            // +0x00
  NodeIsnil131* head;     // +0x04 sentinel
  std::uint32_t size;     // +0x08
};

// Dualed WQ9J-I free-subtree (isnil@+0x131 + DestroyStr0C). ECX=map, stack root.
extern "C" void __fastcall StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred(
    MapShell* map, NodeIsnil131* root /* stack in real ABI: RET 4 */);

// Residual isnil131 successor (updates *pIt).
extern "C" void FUN_00404000(NodeIsnil131** pIt /* EDX / fastcall-ish */);

// Residual isnil131 single erase+rebalance (~string @+0x0c).
extern "C" void FUN_00408ad0(
    MapShell* map, NodeIsnil131** pOutIt, NodeIsnil131* node);

// Binary entry: this in ESI (callers pre-load). Clean signature documents contract.
extern "C" NodeIsnil131** StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred(
    MapShell* map_esi,
    NodeIsnil131** out_it,
    NodeIsnil131* first,
    NodeIsnil131* last)
{
  NodeIsnil131* head = map_esi->head;

  // Full clear: [begin, end) == [*head, head]
  if (first == head->left && last == head) {
    // Bytes: PUSH head->parent; MOV ECX,ESI; CALL 00409920
    StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred(map_esi, head->parent);
    head->parent = head;
    map_esi->size = 0;
    head->left = head;
    head->right = head;
    *out_it = head->left;
    return out_it;
  }

  while (first != last) {
    NodeIsnil131* cur = first;
    // Bytes: LEA EDX,&first; MOV EDI,cur; CALL 00404000  (advances first)
    FUN_00404000(&first);
    // Bytes: PUSH cur; LEA EAX,&first; PUSH EAX; PUSH ESI; CALL 00408ad0
    FUN_00408ad0(map_esi, &first, cur);
  }
  *out_it = first;
  return out_it;
}
