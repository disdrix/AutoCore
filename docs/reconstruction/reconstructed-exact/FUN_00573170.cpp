// =============================================================================
// FUN_00573170  →  StdTree_Lrotate_Val12
// -----------------------------------------------------------------------------
// Stable ID: aa_00573170
// Address:   0x00573170  (autoassault.exe, image base 0x400000)
// System:    MSVC std::_Tree left-rotate (Val12 node, isnil@+0x19)
// Generated: 2026-07-29 W26-Q seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Left-rotate about node x in a red-black tree whose nodes are Val12
// (0x1c bytes: left/parent/right + 12-byte value + color + isnil).
// Twin: StdTree_Rrotate_Val12 @ 0x00418c10.
// Consumers: Map_TreeInsertAndRebalance_Val12 and other Val12 insert/erase paths.

#include <cstdint>

// Node offsets (Val12 / 0x1c) — matches StdTree_Buynode_Val12
//   +0x00 left, +0x04 parent, +0x08 right
//   +0x0c value[12], +0x18 color, +0x19 isnil

// __thiscall: ECX = tree*, stack = node* x; void; RET 4
void __thiscall StdTree_Lrotate_Val12(int32_t tree, int32_t x)
{
  int32_t *y;
  int32_t *parent;

  y = *(int32_t **)(x + 8);                 /* y = x->right */
  *(int32_t *)(x + 8) = *y;                 /* x->right = y->left */
  if (*(char *)(*y + 0x19) == '\0') {       /* if y->left not isnil */
    *(int32_t *)(*y + 4) = x;               /* y->left->parent = x */
  }
  y[1] = *(int32_t *)(x + 4);               /* y->parent = x->parent */
  if (x == *(int32_t *)(*(int32_t *)(tree + 4) + 4)) {
    /* x was root: root = y */
    *(int32_t **)(*(int32_t *)(tree + 4) + 4) = y;
    *y = x;                                 /* y->left = x */
    *(int32_t **)(x + 4) = y;               /* x->parent = y */
    return;
  }
  parent = *(int32_t **)(x + 4);
  if (x == *parent) {
    /* x was left child of parent */
    *parent = (int32_t)y;
    *y = x;
    *(int32_t **)(x + 4) = y;
    return;
  }
  /* x was right child of parent */
  parent[2] = (int32_t)y;
  *y = x;
  *(int32_t **)(x + 4) = y;
  return;
}

// Ghidra alias
void __thiscall FUN_00573170(int32_t param_1, int32_t param_2)
{
  StdTree_Lrotate_Val12(param_1, param_2);
}
