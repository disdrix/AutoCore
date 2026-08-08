// =============================================================================
// Map_FreeSubtree_Isnil1d
// -----------------------------------------------------------------------------
// Stable ID: aa_0051be10
// Address:   0x0051be10–0x0051be44 inclusive (53 B / 0x35)
// System:    STL map free-subtree / isnil@+0x1d (Map_EraseRange_Isnil1d family)
// Dual A/B:  2026-08-04 WQ9F-E
// Exactness: Byte-corrected CF. Decompiler omits left-walk; bytes authoritative.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Free an MSVC-style red-black map subtree for the mid-size node family
//   (isnil @ +0x1d; left +0; right +8). No value destroy.
//
// ABI
//   ECX = tree_base (threaded, unused in body); stack node*; RET 4; void
//
// Callers
//   Map_EraseRange_Isnil1d_Inferred (0x0051d700) full-clear: free(head->parent)
//
// Twin CF peers (distinct VA / isnil)
//   Map_FreeSubtree_Isnil29 @ 0x0051bbc0 (isnil +0x29)
//   Map_FreeSubtree_B @ 0x0051be90 (isnil +0x29)
//   MapFloatTfid_FreeSubtree_Isnil29_Inferred @ 0x0058da00
// =============================================================================

#include <cstdint>

struct MapNode_Isnil1d {
  MapNode_Isnil1d* left;    // +0x00
  MapNode_Isnil1d* parent;  // +0x04
  MapNode_Isnil1d* right;   // +0x08
  // payload ...
  // isnil at +0x1d (0 = real node)
};

extern "C" void __cdecl operator_delete(void* p);

// ECX = tree_base; stack = node*; RET 4; void
extern "C" void __fastcall Map_FreeSubtree_Isnil1d(void* tree_base,
                                                   MapNode_Isnil1d* node)
{
  (void)tree_base;
  if (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(node) + 0x1d) != 0)
    return;

  for (;;) {
    Map_FreeSubtree_Isnil1d(
        tree_base,
        *reinterpret_cast<MapNode_Isnil1d**>(reinterpret_cast<char*>(node) + 8));
    {
      MapNode_Isnil1d* left =
          *reinterpret_cast<MapNode_Isnil1d**>(reinterpret_cast<char*>(node) + 0);
      operator_delete(node);
      node = left;
    }
    if (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(node) + 0x1d) != 0)
      break;
  }
}
