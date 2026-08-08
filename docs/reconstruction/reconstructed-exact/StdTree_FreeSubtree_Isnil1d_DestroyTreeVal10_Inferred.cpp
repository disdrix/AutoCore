// =============================================================================
// StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00440c90
// Address:   0x00440c90–0x00440cca inclusive (59 B / 0x3B)
// System:    skills-abilities / STL tree free (gfxUIWindow shell@+0x10 family)
// Dual A/B:  2026-08-05 MEGA-131 OWN-ONLY
// Exactness: Byte-corrected CF. Decompiler omits left-walk; bytes authoritative.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Free an MSVC-style red-black tree subtree for the mid-size node family
//   (isnil @ +0x1d; left +0; right +8). Before each node delete, destroy the
//   embedded tree value shell at node+0x10 via FUN_00442730 (nested erase
//   isnil@+0x3d + delete head + zero head/size).
//
// ABI
//   ECX = tree_shell (threaded; unused in body except recursive pass)
//   stack = node*; RET 4; void
//
// Callers
//   FUN_00441720 erase-range full-clear @ 0x00441740 (push head->parent)
//   gfxUIWindow_CompleteDtor (0x00759de0) clear shell this+0x10 @ 0x00759e20
//   FUN_00758c80 clear shell this+0x10 @ 0x00758d82
//
// Peers (do not merge)
//   Map_FreeSubtree_Isnil1d @ 0x0051be10 — same isnil/walk, no value dtor
//   FUN_00440ab0 — shell+0x04 free, isnil@+0x3d + FUN_00442720
// =============================================================================

#include <cstdint>

struct StdTreeNode_Isnil1d_TreeVal10 {
  StdTreeNode_Isnil1d_TreeVal10* left;    // +0x00
  StdTreeNode_Isnil1d_TreeVal10* parent;  // +0x04
  StdTreeNode_Isnil1d_TreeVal10* right;   // +0x08
  // +0x10: embedded nested tree shell (head @ +0x14, size @ +0x18)
  // isnil at +0x1d (0 = real node)
};

// EAX = node; destroys embedded tree at node+0x10 (OWN residual callee)
extern "C" void __fastcall FUN_00442730_DestroyTreeVal10_Eax(void* /*eax_node*/);
extern "C" void __cdecl operator_delete(void* p);

// ECX = tree_shell; stack = node*; RET 4; void
extern "C" void __fastcall StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred(
    void* tree_shell,
    StdTreeNode_Isnil1d_TreeVal10* node)
{
  (void)tree_shell;
  if (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(node) + 0x1d) != 0)
    return;

  for (;;) {
    StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred(
        tree_shell,
        *reinterpret_cast<StdTreeNode_Isnil1d_TreeVal10**>(
            reinterpret_cast<char*>(node) + 8));
    {
      StdTreeNode_Isnil1d_TreeVal10* left =
          *reinterpret_cast<StdTreeNode_Isnil1d_TreeVal10**>(
              reinterpret_cast<char*>(node) + 0);
      // CALL FUN_00442730 with EAX = node (register this)
      FUN_00442730_DestroyTreeVal10_Eax(node);
      operator_delete(node);
      node = left;
    }
    if (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(node) + 0x1d) != 0)
      break;
  }
}
