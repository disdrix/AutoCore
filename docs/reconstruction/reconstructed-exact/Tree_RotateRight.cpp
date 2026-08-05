// =============================================================================
// Tree_RotateRight
// -----------------------------------------------------------------------------
// Purpose:  MSVC-style red-black / map-set RIGHT rotate of node x under map head.
//           Nodes use isnil flag at +0x49 (staging 0x50-node family).
//
// Address:  0x005681a0  (autoassault.exe, image base 0x400000)
// Body:     0x005681a0–0x005681f1 (82 bytes)
// Stable:   aa_005681a0
// System:   container / map-set tree
// Ghidra:   FUN_005681a0
//
// ABI:      __thiscall  void Tree_RotateRight(MapShell *map, Node *x)
//           ECX=map, [esp+4]=x; RET 4
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W23-B seal).
// Twin:     Tree_RotateLeft @ 0x00568b70 (W19-K)
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

/* Tree_RotateRight — pure structural right rotate (leaf).

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

void __thiscall Tree_RotateRight(MapShell_Head4 *map, TreeNode_Isnil049 *x)
{
  TreeNode_Isnil049 *y = x->left;
  TreeNode_Isnil049 *yr = y->right;

  x->left = yr;
  // isnil @ +0x49 — only reparent real nodes
  if (*reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(yr) + 0x49) == 0) {
    yr->parent = x;
  }
  y->parent = x->parent;

  TreeNode_Isnil049 *head = map->head;
  if (x == head->parent) {
    head->parent = y;
  } else {
    TreeNode_Isnil049 *p = x->parent;
    if (x == p->right) {
      p->right = y;
    } else {
      p->left = y;
    }
  }
  y->right = x;
  x->parent = y;
}
