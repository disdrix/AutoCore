// =============================================================================
// StdTree_Rrotate_Isnil2D_Inferred  (FUN_0042a840)
// -----------------------------------------------------------------------------
// Stable ID: aa_0042a840
// Address:   0x0042a840–0x0042a88f inclusive (80 B / 0x50)
// System:    MSVC std::_Tree right-rotate (isnil@+0x2D)
// Dual A/B:  2026-08-05 WQ9K-J
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Right-rotate about node x in a red-black tree whose nodes use isnil at +0x2D.
//   Promote x->left to x's former place; hang x as the new right child of y.
//   Leaf pointer-surgery only (no callees, no recolor).
//
// ABI
//   ECX = node x*; stack tree/map*; void; RET 4.
//   **Trap:** isnil29 rotates use ECX=tree / stack=node (inverted).
//
// Twin L-rotate (same family): FUN_0044e010 (residual dual if needed)
// Callers: StringKey insert 00430b60, erase 004094c0, peers 00401db0 / 0042a930
// =============================================================================

#include <cstdint>

// Node offsets (isnil@+0x2D family):
//   +0x00 left, +0x04 parent, +0x08 right
//   +0x2C color (not touched here)
//   +0x2D isnil (0 = real node)
// Tree: tree+4 → header; root = *(header+4)

// __thiscall on node (ECX = x); stack tree; RET 4
extern "C" void __thiscall StdTree_Rrotate_Isnil2D_Inferred(
    std::int32_t* x /*ECX*/,
    std::int32_t tree /*stack*/)
{
  std::int32_t y = *x;                                /* y = x->left */
  *x = *reinterpret_cast<std::int32_t*>(y + 8);       /* x->left = y->right */
  if (*reinterpret_cast<char*>(
          *reinterpret_cast<std::int32_t*>(y + 8) + 0x2d) == '\0') {
    *reinterpret_cast<std::int32_t**>(
        *reinterpret_cast<std::int32_t*>(y + 8) + 4) = x; /* y->right->parent = x */
  }
  *reinterpret_cast<std::int32_t*>(y + 4) = x[1];     /* y->parent = x->parent */

  if (x == *reinterpret_cast<std::int32_t**>(
          *reinterpret_cast<std::int32_t*>(tree + 4) + 4)) {
    /* x was root → root = y */
    *reinterpret_cast<std::int32_t*>(
        *reinterpret_cast<std::int32_t*>(tree + 4) + 4) = y;
    *reinterpret_cast<std::int32_t**>(y + 8) = x;     /* y->right = x */
    x[1] = y;                                         /* x->parent = y */
    return;
  }

  std::int32_t* parent = reinterpret_cast<std::int32_t*>(x[1]);
  if (x == reinterpret_cast<std::int32_t*>(parent[2])) {
    /* x was right child of parent */
    parent[2] = y;
    *reinterpret_cast<std::int32_t**>(y + 8) = x;
    x[1] = y;
    return;
  }

  /* x was left child of parent */
  *parent = y;
  *reinterpret_cast<std::int32_t**>(y + 8) = x;
  x[1] = y;
}

// Ghidra placeholder twin: FUN_0042a840.cpp
