// =============================================================================
// Tree_RotateRight_Isnil15
// -----------------------------------------------------------------------------
// Purpose:  MSVC-style red-black / map-set RIGHT rotate of node x under map head.
//           Nodes use isnil flag at +0x15 (0x18 / small-value map family).
//
// Address:  0x006753b0  (autoassault.exe, image base 0x400000)
// Body:     0x006753b0–0x00675401 (82 bytes)
// Stable:   aa_006753b0
// System:   container / map-set tree
// Ghidra:   FUN_006753b0
//
// ABI:      __thiscall  void Tree_RotateRight_Isnil15(MapShell *map, Node *x)
//           ECX=map, [esp+4]=x; RET 4
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W24-O seal).
// Twin:     Tree_RotateLeft_Isnil15 @ 0x004e22d0 (W24-O)
// Staging:  Tree_RotateRight @ 0x005681a0 (isnil +0x49; W23-B)
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

/* Tree_RotateRight_Isnil15 — pure structural right rotate (leaf).

   Parameters:
     map: MapShell with head sentinel at +4; root at head->parent (+4 of head)
     x:   node to rotate right about (must have non-nil left child as y)

   Algorithm (standard):
     y = x->left
     x->left = y->right
     if !isnil(y->right): y->right->parent = x
     y->parent = x->parent
     if x is root: root = y
     else if x is right child: parent->right = y
     else: parent->left = y
     y->right = x
     x->parent = y

   Returns: void */

void __thiscall Tree_RotateRight_Isnil15(MapShell_Head4 *map, TreeNode_Isnil15 *x)
{
  TreeNode_Isnil15 *y = x->left;
  TreeNode_Isnil15 *yr = y->right;

  x->left = yr;
  // isnil @ +0x15 — only reparent real nodes
  if (*reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(yr) + 0x15) == 0) {
    yr->parent = x;
  }
  y->parent = x->parent;

  TreeNode_Isnil15 *head = map->head;
  if (x == head->parent) {
    head->parent = y;
  } else {
    TreeNode_Isnil15 *p = x->parent;
    if (x == p->right) {
      p->right = y;
    } else {
      p->left = y;
    }
  }
  y->right = x;
  x->parent = y;
}
