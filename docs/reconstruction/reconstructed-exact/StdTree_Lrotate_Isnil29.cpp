// =============================================================================
// StdTree_Lrotate_Isnil29  (FUN_004192a0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004192a0
// Address:   0x004192a0  (autoassault.exe, image base 0x400000)
// System:    MSVC std::_Tree left-rotate (isnil@+0x29 / color@+0x28 family)
// Generated: 2026-08-04 WQ9D-C dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Left-rotate about node x in a red-black tree whose nodes carry
// isnil at +0x29 (color at +0x28). Classical _Lrotate: promote x->right to
// x's position; hang x as the new left child of that node.
// Twin: FUN_004192f0 (Rrotate, same layout; OWN of sibling partition).
// Consumers: Map_EraseNode (aa_0051cb40), insert/rebalance maps, aggro prune.

#include <cstdint>

// Node offsets (isnil@+0x29 family)
//   +0x00 left, +0x04 parent, +0x08 right
//   +0x28 color, +0x29 isnil
//   value/key between +0x0c and +0x28 (payload family shared with Map_EraseNode)

// __thiscall: ECX = tree*, stack = node* x; void; RET 4
void __thiscall StdTree_Lrotate_Isnil29(std::int32_t tree, std::int32_t x)
{
  std::int32_t *y;
  std::int32_t *parent;

  y = *reinterpret_cast<std::int32_t **>(x + 8);       /* y = x->right */
  *reinterpret_cast<std::int32_t *>(x + 8) = *y;       /* x->right = y->left */
  if (*reinterpret_cast<char *>(*y + 0x29) == '\0') {  /* if y->left not isnil */
    *reinterpret_cast<std::int32_t *>(*y + 4) = x;     /* y->left->parent = x */
  }
  y[1] = *reinterpret_cast<std::int32_t *>(x + 4);     /* y->parent = x->parent */
  if (x == *reinterpret_cast<std::int32_t *>(
               *reinterpret_cast<std::int32_t *>(tree + 4) + 4)) {
    /* x was root: root = y */
    *reinterpret_cast<std::int32_t **>(
        *reinterpret_cast<std::int32_t *>(tree + 4) + 4) = y;
    *y = x;                                            /* y->left = x */
    *reinterpret_cast<std::int32_t **>(x + 4) = y;     /* x->parent = y */
    return;
  }
  parent = *reinterpret_cast<std::int32_t **>(x + 4);
  if (x == *parent) {
    /* x was left child of parent */
    *parent = reinterpret_cast<std::int32_t>(y);
    *y = x;
    *reinterpret_cast<std::int32_t **>(x + 4) = y;
    return;
  }
  /* x was right child of parent */
  parent[2] = reinterpret_cast<std::int32_t>(y);
  *y = x;
  *reinterpret_cast<std::int32_t **>(x + 4) = y;
  return;
}

// Ghidra alias
void __thiscall FUN_004192a0(std::int32_t param_1, std::int32_t param_2)
{
  StdTree_Lrotate_Isnil29(param_1, param_2);
}
