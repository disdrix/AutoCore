// =============================================================================
// Tree_RotateLeft_Isnil15
// -----------------------------------------------------------------------------
// Purpose:  MSVC-style red-black / map-set LEFT rotate of node x under map head.
//           Nodes use isnil flag at +0x15 (0x18 / small-value map family).
//
// Address:  0x004e22d0  (autoassault.exe, image base 0x400000)
// Body:     0x004e22d0–0x004e231d (78 bytes)
// Stable:   aa_004e22d0
// System:   container / map-set tree
// Ghidra:   FUN_004e22d0
//
// ABI:      __thiscall  void Tree_RotateLeft_Isnil15(MapShell *map, Node *x)
//           ECX=map, [esp+4]=x; RET 4
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W24-O seal).
// Twin:     Tree_RotateRight_Isnil15 @ 0x006753b0 (W24-O)
// Staging:  Tree_RotateLeft @ 0x00568b70 (isnil +0x49; W19-K)
// =============================================================================

#include <cstdint>

struct TreeNode_Isnil15 {
  TreeNode_Isnil15 *left;    // +0x00
  TreeNode_Isnil15 *parent;  // +0x04
  TreeNode_Isnil15 *right;   // +0x08
  // ... value payload (e.g. int key + ptr @ +0x0C/+0x10 for 0x18 nodes) ...
  // +0x14 color (0=red, 1=black), +0x15 isnil
};

struct MapShell_Head4 {
  // +0x00 unused in this unit
  TreeNode_Isnil15 *head;  // +0x04 end/head sentinel
  // +0x08 size (not used here)
};

/* Tree_RotateLeft_Isnil15 — pure structural left rotate (leaf).

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

void __thiscall Tree_RotateLeft_Isnil15(MapShell_Head4 *map, TreeNode_Isnil15 *x)
{
  TreeNode_Isnil15 *y = x->right;
  TreeNode_Isnil15 *yl = y->left;

  x->right = yl;
  // isnil @ +0x15 — only reparent real nodes
  if (*reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(yl) + 0x15) == 0) {
    yl->parent = x;
  }
  y->parent = x->parent;

  TreeNode_Isnil15 *head = map->head;
  if (x == head->parent) {
    head->parent = y;
  } else {
    TreeNode_Isnil15 *p = x->parent;
    if (x == p->left) {
      p->left = y;
    } else {
      p->right = y;
    }
  }
  y->left = x;
  x->parent = y;
}
