// =============================================================================
// StdTree_FreeSubtree_Val12  (aa_0040d630)
// -----------------------------------------------------------------------------
// Address:   0x0040d630  (autoassault.exe, image base 0x400000)
// Wave:      W31-A OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
//            Free path uses bytes (decompiler false-noreturn collapsed left-walk).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct StdTreeNode_Val12 {
  StdTreeNode_Val12* left;    // +0x00
  StdTreeNode_Val12* parent;  // +0x04
  StdTreeNode_Val12* right;   // +0x08
  // isnil at +0x19 (0 = real node)
};

extern "C" void __cdecl operator_delete(void* p);

// ECX = tree_base (threaded from callers as host+4; unused in body except recursive pass).
// Stack arg = subtree root node*. Callee cleans 4 bytes (RET 4). void.
// For each node on the left spine of the given root: free right subtree recursively,
// operator_delete(node), advance to left. Stops at isnil sentinel.
extern "C" void __fastcall StdTree_FreeSubtree_Val12(void* tree_base,
                                                     StdTreeNode_Val12* node)
{
  (void)tree_base;
  if (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(node) + 0x19) != 0) {
    return;
  }

  for (;;) {
    StdTreeNode_Val12* right =
        *reinterpret_cast<StdTreeNode_Val12**>(reinterpret_cast<char*>(node) + 8);
    StdTree_FreeSubtree_Val12(tree_base, right);

    StdTreeNode_Val12* left =
        *reinterpret_cast<StdTreeNode_Val12**>(reinterpret_cast<char*>(node) + 0);
    operator_delete(node);
    node = left;

    if (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(node) + 0x19) != 0) {
      break;
    }
  }
}

// Scaffold / Ghidra alias (same ABI)
extern "C" void __fastcall FUN_0040d630(void* tree_base, StdTreeNode_Val12* node)
{
  StdTree_FreeSubtree_Val12(tree_base, node);
}
