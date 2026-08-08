// =============================================================================
// StdTree_FreeSubtree_Isnil11_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00440d20
// Address:   0x00440d20–0x00440d54 inclusive (53 B / 0x35)
//            autoassault.exe, image base 0x400000
// Wave:      2026-08-05 MEGA-132 OWN dual A/B seal
// Exactness: Byte-corrected CF. Decompiler omits left-walk; bytes authoritative.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Free an MSVC-style red-black tree subtree for the small-node family
//   (isnil @ +0x11; left +0; right +8). No value destroy.
//   Primary host usage: clear root of gfxUIWindow tree shell @ +0xA4
//   (partition alias StdTree_ClearShell_AtA4). Also called from erase-all
//   full-clear FUN_00441960 and UI rebuild FUN_00759090.
//
// ABI
//   ECX = tree_base (threaded, unused in body); stack node*; RET 4; void
//
// Twin CF (do not merge symbols)
//   StdTree_FreeSubtree_Isnil29_Inferred @ 0x00406c00 (isnil +0x29)
//   Map_FreeSubtree_Isnil29 @ 0x0051bbc0
//   StdTree_FreeSubtree_Val12 @ 0x0040d630 (isnil +0x19)
//   Siblings with value-dtor: FUN_00440ab0 (isnil +0x3d), FUN_00440c90 (isnil +0x1d)
//
// Rejected aliases
//   Named_CalleeOf_Named_gfxUIWindow_00440d20 (scaffold)
// =============================================================================

#include <cstdint>

struct TreeNode_Isnil11 {
  TreeNode_Isnil11 *left;    // +0x00
  TreeNode_Isnil11 *parent;  // +0x04
  TreeNode_Isnil11 *right;   // +0x08
  // value payload @ +0x0C (width product-open; isnil sealed @ +0x11)
  // uint8_t color;          // +0x10 (inferred layout)
  // uint8_t isnil;          // +0x11
};

extern "C" void __cdecl operator_delete(void *p);

// ECX = tree_base; stack = node*; RET 4; void
extern "C" void __fastcall StdTree_FreeSubtree_Isnil11_Inferred(
    void *tree_base,
    TreeNode_Isnil11 *node)
{
  (void)tree_base;
  if (*reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(node) + 0x11) != 0)
    return;

  for (;;) {
    StdTree_FreeSubtree_Isnil11_Inferred(
        tree_base,
        *reinterpret_cast<TreeNode_Isnil11 **>(reinterpret_cast<char *>(node) + 8));
    {
      TreeNode_Isnil11 *left =
          *reinterpret_cast<TreeNode_Isnil11 **>(reinterpret_cast<char *>(node) + 0);
      operator_delete(node);
      node = left;
    }
    if (*reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(node) + 0x11) != 0)
      break;
  }
}
