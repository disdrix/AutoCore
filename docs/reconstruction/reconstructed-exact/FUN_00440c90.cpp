// =============================================================================
// FUN_00440c90  (Ghidra twin of StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00440c90
// Address:   0x00440c90–0x00440cca inclusive (59 B / 0x3B)
// System:    skills-abilities / STL tree free (gfxUIWindow shell@+0x10 family)
// Dual A/B:  2026-08-05 MEGA-131 OWN-ONLY
// Exactness: Byte-corrected CF. Decompiler omits left-walk; bytes authoritative.
// Bit-for-bit / runtime / diff: OPEN
// Canonical: StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred
// =============================================================================

#include <cstdint>

struct Node_Isnil1d {
  Node_Isnil1d* left;    // +0x00
  Node_Isnil1d* parent;  // +0x04
  Node_Isnil1d* right;   // +0x08
  // embedded tree shell @ +0x10; isnil @ +0x1d
};

extern "C" void __fastcall FUN_00442730(void* /*eax_node*/);
extern "C" void __cdecl operator_delete(void* p);

// ECX = tree_shell; stack = node*; RET 4; void
extern "C" void __fastcall FUN_00440c90(void* tree_shell, Node_Isnil1d* node)
{
  (void)tree_shell;
  if (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(node) + 0x1d) != 0)
    return;

  for (;;) {
    FUN_00440c90(
        tree_shell,
        *reinterpret_cast<Node_Isnil1d**>(reinterpret_cast<char*>(node) + 8));
    {
      Node_Isnil1d* left =
          *reinterpret_cast<Node_Isnil1d**>(reinterpret_cast<char*>(node) + 0);
      FUN_00442730(node); // EAX = node
      operator_delete(node);
      node = left;
    }
    if (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(node) + 0x1d) != 0)
      break;
  }
}
