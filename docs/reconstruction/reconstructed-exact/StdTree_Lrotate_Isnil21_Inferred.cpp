// =============================================================================
// StdTree_Lrotate_Isnil21_Inferred  (FUN_0050e9f0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0050e9f0
// Address:   0x0050e9f0  (autoassault.exe, image base 0x400000)
// Body:      0x0050e9f0–0x0050ea3d inclusive (78 B / 0x4E); pad CC CC
// System:    MSVC std::_Tree left-rotate (isnil@+0x21 / color@+0x20 family)
// Generated: 2026-08-05 R10-030 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Left-rotate about node x in a red-black tree whose nodes carry
// isnil at +0x21 (color at +0x20). Classical _Lrotate: promote x->right to
// x's position; hang x as the new left child of that node.
// Twin: FUN_005a27f0 (Rrotate, same layout; residual, not OWN of this dual).
// Consumers: StdTree_InsertAndRebalance_Isnil21_Inferred (0x00407200) and
// many other isnil21 insert/erase rebalance shells (14 callers / 30 xrefs).

#include <cstdint>

// Node offsets (isnil@+0x21 family; node 0x28 with Val16 from buynode dual)
//   +0x00 left, +0x04 parent, +0x08 right
//   +0x20 color, +0x21 isnil
// Tree: this+4 = head; head+4 = root

// __thiscall: ECX = tree*, stack = node* x; void; RET 4
void __thiscall StdTree_Lrotate_Isnil21_Inferred(std::int32_t tree, std::int32_t x)
{
  std::int32_t *y;
  std::int32_t *parent;

  y = *reinterpret_cast<std::int32_t **>(x + 8);       /* y = x->right */
  *reinterpret_cast<std::int32_t *>(x + 8) = *y;       /* x->right = y->left */
  if (*reinterpret_cast<char *>(*y + 0x21) == '\0') {  /* if y->left not isnil */
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
void __thiscall FUN_0050e9f0(std::int32_t param_1, std::int32_t param_2)
{
  StdTree_Lrotate_Isnil21_Inferred(param_1, param_2);
}
