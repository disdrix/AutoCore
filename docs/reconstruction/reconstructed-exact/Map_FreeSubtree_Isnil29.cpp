// =============================================================================
// Map_FreeSubtree_Isnil29
// -----------------------------------------------------------------------------
// Stable ID: aa_0051bbc0
// Address:   0x0051bbc0–0x0051bbf4  (53 B; autoassault.exe base 0x400000)
// System:    STL map free-subtree / isnil@+0x29 (Map_EraseRange family)
// Dual A/B:  2026-08-04 WQ9E-H
// Exactness: Byte-corrected CF. Decompiler omits left-walk; bytes authoritative.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Free an MSVC-style red-black map subtree for the large-node family
//   (isnil @ +0x29; left +0; right +8). No value destroy.
//
// ABI
//   ECX = tree_base (threaded, unused in body); stack node*; RET 4; void
//
// Callers
//   Map_EraseRange (0x0051c7c0) full-clear: free(head->parent)
//
// Twin CF (distinct VA)
//   MapFloatTfid_FreeSubtree_Isnil29_Inferred @ 0x0058da00
//   StdTree_FreeSubtree_Val12 @ 0x0040d630 (isnil +0x19)
//
// Rejected aliases
//   Named_CalleeOf_Named_CalleeOf_CVOGHBAIBase_GetTargetFromAggro_0051bbc0
// =============================================================================

#include <cstdint>

struct MapNode_Isnil29 {
  MapNode_Isnil29 *left;    // +0x00
  MapNode_Isnil29 *parent;  // +0x04
  MapNode_Isnil29 *right;   // +0x08
  // isnil at +0x29 (0 = real node)
};

extern "C" void __cdecl operator_delete(void *p);

// ECX = tree_base; stack = node*; RET 4; void
extern "C" void __fastcall Map_FreeSubtree_Isnil29(void *tree_base,
                                                   MapNode_Isnil29 *node)
{
  (void)tree_base;
  if (*reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(node) + 0x29) != 0)
    return;

  for (;;) {
    Map_FreeSubtree_Isnil29(
        tree_base,
        *reinterpret_cast<MapNode_Isnil29 **>(reinterpret_cast<char *>(node) + 8));
    {
      MapNode_Isnil29 *left =
          *reinterpret_cast<MapNode_Isnil29 **>(reinterpret_cast<char *>(node) + 0);
      operator_delete(node);
      node = left;
    }
    if (*reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(node) + 0x29) != 0)
      break;
  }
}
