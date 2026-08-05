// =============================================================================
// Tree_RotateLeft
// -----------------------------------------------------------------------------
// Purpose:  MSVC-style red-black / map-set LEFT rotate of node x under map head.
//           Nodes use isnil flag at +0x49 (staging 0x50-node family).
//
// Address:  0x00568b70  (autoassault.exe, image base 0x400000)
// Body:     0x00568b70–0x00568bbd (78 bytes)
// Stable:   aa_00568b70
// System:   container / map-set tree
// Ghidra:   FUN_00568b70
//
// ABI:      __thiscall  void Tree_RotateLeft(MapShell *map, Node *x)
//           ECX=map, [esp+4]=x; RET 4
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W19-K seal).
// =============================================================================

#include <cstdint>

struct TreeNode_Isnil049 {
  TreeNode_Isnil049 *left;    // +0x00
  TreeNode_Isnil049 *parent;  // +0x04
  TreeNode_Isnil049 *right;   // +0x08
  // ... value payload ...
  // +0x48 color, +0x49 isnil (layout sealed by sibling insert/ctor duals)
};

struct MapShell_Head4 {
  // +0x00 unused in this unit
  TreeNode_Isnil049 *head;  // +0x04 end/head sentinel
  // +0x08 size (not used here)
};

/* Tree_RotateLeft — pure structural left rotate (leaf).

   Parameters:
     map: MapShell with head sentinel at +4; root at head->parent (+4 of head)
     x:   node to rotate left about (must have non-nil right child as y)

   Algorithm (standard):
     y = x->right
     x->right = y->left
     if !isnil(y->left): y->left->parent = x
     y->parent = x->parent
     if x is root: root = y
     else if x is left child: parent->left = y
     else: parent->right = y
     y->left = x
     x->parent = y

   Returns: void */

void __thiscall Tree_RotateLeft(MapShell_Head4 *map, TreeNode_Isnil049 *x)
{
  TreeNode_Isnil049 *y = x->right;
  TreeNode_Isnil049 *yl = y->left;

  x->right = yl;
  // isnil @ +0x49 — only reparent real nodes
  if (*reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(yl) + 0x49) == 0) {
    yl->parent = x;
  }
  y->parent = x->parent;

  TreeNode_Isnil049 *head = map->head;
  if (x == head->parent) {
    head->parent = y;
  } else {
    TreeNode_Isnil049 *p = x->parent;
    if (x == p->left) {
      p->left = y;
    } else {
      p->right = y;
    }
  }
  y->left = x;
  x->parent = y;
}
