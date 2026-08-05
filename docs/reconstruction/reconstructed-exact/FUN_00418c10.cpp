// =============================================================================
// FUN_00418c10  →  StdTree_Rrotate_Val12
// -----------------------------------------------------------------------------
// Stable ID: aa_00418c10
// Address:   0x00418c10  (autoassault.exe, image base 0x400000)
// System:    MSVC std::_Tree right-rotate (Val12 node, isnil@+0x19)
// Generated: 2026-07-29 W26-Q seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Right-rotate about node x in a red-black tree whose nodes are Val12
// (0x1c bytes: left/parent/right + 12-byte value + color + isnil).
// Twin: StdTree_Lrotate_Val12 @ 0x00573170.
// Consumers: Map_TreeInsertAndRebalance_Val12 and other Val12 insert/erase paths.

#include <cstdint>

// Node offsets (Val12 / 0x1c) — matches StdTree_Buynode_Val12
//   +0x00 left, +0x04 parent, +0x08 right
//   +0x0c value[12], +0x18 color, +0x19 isnil

// __thiscall: ECX = tree*, stack = node* x; void; RET 4
void __thiscall StdTree_Rrotate_Val12(int32_t tree, int32_t *x)
{
  int32_t y;
  int32_t *parent;

  y = *x;                                   /* y = x->left */
  *x = *(int32_t *)(y + 8);                 /* x->left = y->right */
  if (*(char *)(*(int32_t *)(y + 8) + 0x19) == '\0') {
    *(int32_t **)(*(int32_t *)(y + 8) + 4) = x;  /* y->right->parent = x */
  }
  *(int32_t *)(y + 4) = x[1];               /* y->parent = x->parent */
  if (x == *(int32_t **)(*(int32_t *)(tree + 4) + 4)) {
    /* x was root: root = y */
    *(int32_t *)(*(int32_t *)(tree + 4) + 4) = y;
    *(int32_t **)(y + 8) = x;               /* y->right = x */
    x[1] = y;                               /* x->parent = y */
    return;
  }
  parent = (int32_t *)x[1];
  if (x == (int32_t *)parent[2]) {
    /* x was right child of parent */
    parent[2] = y;
    *(int32_t **)(y + 8) = x;
    x[1] = y;
    return;
  }
  /* x was left child of parent */
  *parent = y;
  *(int32_t **)(y + 8) = x;
  x[1] = y;
  return;
}

// Ghidra alias
void __thiscall FUN_00418c10(int32_t param_1, int32_t *param_2)
{
  StdTree_Rrotate_Val12(param_1, param_2);
}
