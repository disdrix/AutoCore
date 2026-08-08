// =============================================================================
// StdTree_Rrotate_Isnil31_Inferred  (FUN_00403ee0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00403ee0
// Address:   0x00403ee0–0x00403f2f inclusive (80 B / 0x50)
// System:    MSVC std::_Tree right-rotate (isnil@+0x31)
// Dual A/B:  2026-08-05 WQ9L-C
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Right-rotate about node x in a red-black tree whose nodes use isnil at +0x31.
//   Promote x->left to x's former place; hang x as the new right child of y.
//   Leaf pointer-surgery only (no callees, no recolor).
//
// ABI
//   ECX = node x*; stack tree/map*; void; RET 4.
//   **Trap:** isnil29 rotates use ECX=tree / stack=node (inverted).
//
// Twin L-rotate (same family): FUN_00403e90
// Callers: erase FUN_00408ed0 (StdTree_EraseAndRebalance_Isnil31_Inferred);
//          insert/rebalance peer FUN_00403250
// =============================================================================

#include <cstdint>

// Node offsets (isnil@+0x31 / color@+0x30 / node size 0x38 family):
//   +0x00 left, +0x04 parent, +0x08 right
//   +0x30 color (not touched here)
//   +0x31 isnil (0 = real node)
// Tree: tree+4 → header; root = *(header+4)

// __thiscall on node (ECX = x); stack tree; RET 4
extern "C" void __thiscall StdTree_Rrotate_Isnil31_Inferred(
    std::int32_t* x /*ECX*/,
    std::int32_t tree /*stack*/)
{
  std::int32_t y = *x;                                /* y = x->left */
  *x = *reinterpret_cast<std::int32_t*>(y + 8);       /* x->left = y->right */
  if (*reinterpret_cast<char*>(
          *reinterpret_cast<std::int32_t*>(y + 8) + 0x31) == '\0') {
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

// Ghidra placeholder twin: FUN_00403ee0.cpp
