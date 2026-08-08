// =============================================================================
// StdTree_FreeSubtree_Isnil29_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004cb550
// Address:   0x004cb550–0x004cb584 inclusive (53 B / 0x35)
//            autoassault.exe, image base 0x400000
// Wave:      2026-08-04 WQ9G-A OWN dual A/B seal
// Exactness: Byte-corrected CF. Decompiler omits left-walk; bytes authoritative.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Free an MSVC-style red-black tree subtree for the large-node family
//   (isnil @ +0x29; left +0; right +8). No value destroy.
//   Sole external caller: StdTree_EraseRange_Isnil29_Inferred full-clear
//   (push head->parent).
//
// ABI
//   ECX = tree_base (threaded, unused in body); stack node*; RET 4; void
//
// Twin CF (do not merge)
//   Map_FreeSubtree_Isnil29 @ 0x0051bbc0 (Map_EraseRange free pair)
//   MapFloatTfid_FreeSubtree_Isnil29_Inferred @ 0x0058da00
//   StdTree_FreeSubtree_Val12 @ 0x0040d630 (isnil +0x19)
//
// Rejected aliases
//   Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004cb550 (scaffold)
// =============================================================================

#include <cstdint>

struct MapNode_Isnil29 {
  MapNode_Isnil29 *left;    // +0x00
  MapNode_Isnil29 *parent;  // +0x04
  MapNode_Isnil29 *right;   // +0x08
  // value payload @ +0x10 ..
  // uint8_t color;         // +0x28
  // uint8_t isnil;         // +0x29
};

extern "C" void __cdecl operator_delete(void *p);

// ECX = tree_base; stack = node*; RET 4; void
extern "C" void __fastcall StdTree_FreeSubtree_Isnil29_Inferred(
    void *tree_base,
    MapNode_Isnil29 *node)
{
  (void)tree_base;
  if (*reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(node) + 0x29) != 0)
    return;

  for (;;) {
    StdTree_FreeSubtree_Isnil29_Inferred(
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
