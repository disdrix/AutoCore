// =============================================================================
// StdTree_Rrotate_Isnil29_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004192f0
// Address:   0x004192f0  (autoassault.exe, image base 0x400000)
// System:    MSVC std::_Tree right-rotate (isnil@+0x29)
// Generated: 2026-08-04 WQ9D-D dual (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher / not run).
// =============================================================================
//
// PURPOSE:
//   Right-rotate about node x in a red-black tree whose nodes use isnil at +0x29.
//   Promote x->left to x's former place; hang x as the new right child of y.
//   Leaf pointer-surgery only (no callees).
//
// Twin:  FUN_004192a0 left-rotate (same isnil family; WQ9D-C).
// Peer:  StdTree_Rrotate_Val12 @ 0x00418c10 (identical CF; isnil@+0x19).
//
// ABI: __thiscall; ECX=tree*; stack node* x; void; RET 4.
// Body: 0x004192f0–0x00419341 exclusive (81 B); pad CC.
//
// Dual: reviews/A|B_aa_004192f0_StdTree_Rrotate_Isnil29_Inferred.md

#include <cstdint>

// Node offsets (isnil@+0x29 family):
//   +0x00 left, +0x04 parent, +0x08 right
//   +0x29 isnil (0 = real node)
// Tree: this+4 → header; root = *(header+4)

// __thiscall
extern "C" void __thiscall StdTree_Rrotate_Isnil29_Inferred(
    std::int32_t tree,
    std::int32_t* x)
{
  std::int32_t y = *x;                                /* y = x->left */
  *x = *reinterpret_cast<std::int32_t*>(y + 8);       /* x->left = y->right */
  if (*reinterpret_cast<char*>(
          *reinterpret_cast<std::int32_t*>(y + 8) + 0x29) == '\0') {
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

// Legacy symbol alias.
extern "C" void __thiscall FUN_004192f0(std::int32_t tree, std::int32_t* x)
{
  StdTree_Rrotate_Isnil29_Inferred(tree, x);
}
