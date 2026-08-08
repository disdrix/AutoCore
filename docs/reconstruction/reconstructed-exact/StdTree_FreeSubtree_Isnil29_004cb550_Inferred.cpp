// =============================================================================
// StdTree_FreeSubtree_Isnil29_Inferred  (FUN_004cb550 / aa_004cb550)
// VA-suffixed clean: erase-range free path; peer clones 00406c00 / 0051bbc0
// =============================================================================
// =============================================================================
// FUN_004cb550  (scaffold twin of StdTree_FreeSubtree_Isnil29_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cb550
// Address:   0x004cb550–0x004cb584 inclusive (53 B / 0x35)
// Wave:      2026-08-04 WQ9G-A OWN dual A/B
// Named:     reconstructed-exact/StdTree_FreeSubtree_Isnil29_Inferred.cpp
// Exactness: Byte-corrected free-subtree (left walk sealed). Decompiler incomplete.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct MapNode_Isnil29 {
  MapNode_Isnil29 *left;    // +0x00
  MapNode_Isnil29 *parent;  // +0x04
  MapNode_Isnil29 *right;   // +0x08
};

extern "C" void __cdecl operator_delete(void *p);

// ECX = tree_base; stack = node*; RET 4; void
extern "C" void __fastcall FUN_004cb550(void *tree_base, MapNode_Isnil29 *node)
{
  (void)tree_base;
  if (*reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(node) + 0x29) != 0)
    return;

  for (;;) {
    FUN_004cb550(
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
