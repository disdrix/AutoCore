// =============================================================================
// StdTree_Rrotate_Isnil21_Inferred  (FUN_005a27f0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005a27f0
// Address:   0x005a27f0  (autoassault.exe, image base 0x400000)
// Body:      0x005a27f0–0x005a2841 inclusive (82 B / 0x52); pad CC
// System:    MSVC std::_Tree right-rotate (isnil@+0x21 / color@+0x20 family)
// Generated: 2026-08-05 R11-007 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Right-rotate about node x in a red-black tree whose nodes carry
// isnil at +0x21 (color at +0x20). Classical _Rrotate: promote x->left to
// x's position; hang x as the new right child of that node.
// Twin: StdTree_Lrotate_Isnil21_Inferred / FUN_0050e9f0 (R10-030 dualed).
// Consumers: StdTree_InsertAndRebalance_Isnil21_Inferred (0x00407200) and
// many other isnil21 insert/erase rebalance shells (14 callers / 35 xrefs).

#include <cstdint>

// Node offsets (isnil@+0x21 family; node 0x28 with Val16 from buynode dual)
//   +0x00 left, +0x04 parent, +0x08 right
//   +0x20 color, +0x21 isnil
// Tree: this+4 = head; head+4 = root

// __thiscall: ECX = tree*, stack = node* x; void; RET 4
void __thiscall StdTree_Rrotate_Isnil21_Inferred(std::int32_t tree, std::int32_t *x)
{
  std::int32_t y;
  std::int32_t *parent;

  y = *x;                                                  /* y = x->left */
  *x = *reinterpret_cast<std::int32_t *>(y + 8);           /* x->left = y->right */
  if (*reinterpret_cast<char *>(
          *reinterpret_cast<std::int32_t *>(y + 8) + 0x21) == '\0') {
    /* if y->right not isnil */
    *reinterpret_cast<std::int32_t **>(
        *reinterpret_cast<std::int32_t *>(y + 8) + 4) = x; /* y->right->parent = x */
  }
  *reinterpret_cast<std::int32_t *>(y + 4) = x[1];         /* y->parent = x->parent */
  if (x == *reinterpret_cast<std::int32_t **>(
               *reinterpret_cast<std::int32_t *>(tree + 4) + 4)) {
    /* x was root: root = y */
    *reinterpret_cast<std::int32_t *>(
        *reinterpret_cast<std::int32_t *>(tree + 4) + 4) = y;
    *reinterpret_cast<std::int32_t **>(y + 8) = x;         /* y->right = x */
    x[1] = y;                                              /* x->parent = y */
    return;
  }
  parent = reinterpret_cast<std::int32_t *>(x[1]);
  if (x == reinterpret_cast<std::int32_t *>(parent[2])) {
    /* x was right child of parent */
    parent[2] = y;
    *reinterpret_cast<std::int32_t **>(y + 8) = x;
    x[1] = y;
    return;
  }
  /* x was left child of parent */
  *parent = y;
  *reinterpret_cast<std::int32_t **>(y + 8) = x;
  x[1] = y;
  return;
}

// Ghidra alias
void __thiscall FUN_005a27f0(std::int32_t param_1, std::int32_t *param_2)
{
  StdTree_Rrotate_Isnil21_Inferred(param_1, param_2);
}
