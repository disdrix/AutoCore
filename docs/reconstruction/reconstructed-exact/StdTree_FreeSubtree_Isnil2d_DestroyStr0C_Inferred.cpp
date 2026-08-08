// =============================================================================
// StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00409970
// Address:   0x00409970–0x004099aa inclusive (59 B / 0x3B)
//            autoassault.exe, image base 0x400000
// Wave:      2026-08-05 WQ9J-I OWN dual A/B seal
// Exactness: Byte-corrected CF. Decompiler omits left-walk + false noreturn.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Free an MSVC-style red-black tree subtree for the compact-node family
//   (isnil @ +0x2d; left +0; right +8) with value destroy of std::basic_string
//   at node+0x0c via shared FUN_00409b80 before operator_delete.
//   Sole external caller: FUN_00407f90 full-clear (push head->parent).
//
// ABI
//   ECX = tree_base (threaded, unused in body); stack node*; RET 4; void
//
// Twin CF (do not merge)
//   StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred @ 0x00409920 (isnil +0x131)
//   StdTree_FreeSubtree_Isnil29_Inferred @ 0x00406c00 (no value destroy)
// =============================================================================

#include <cstdint>

struct MapNode_Isnil2d {
  MapNode_Isnil2d *left;    // +0x00
  MapNode_Isnil2d *parent;  // +0x04
  MapNode_Isnil2d *right;   // +0x08
  // std::basic_string value starts @ +0x0c (destroyed by FUN_00409b80)
  // ... compact value fields ...
  // uint8_t color;         // +0x2c (inferred)
  // uint8_t isnil;         // +0x2d
};

extern "C" void __cdecl operator_delete(void *p);
extern "C" void __stdcall FUN_00409b80(void *node);

// ECX = tree_base; stack = node*; RET 4; void
extern "C" void __fastcall StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred(
    void *tree_base,
    MapNode_Isnil2d *node)
{
  (void)tree_base;
  if (*reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(node) + 0x2d) != 0)
    return;

  for (;;) {
    StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred(
        tree_base,
        *reinterpret_cast<MapNode_Isnil2d **>(reinterpret_cast<char *>(node) + 8));
    {
      MapNode_Isnil2d *left =
          *reinterpret_cast<MapNode_Isnil2d **>(reinterpret_cast<char *>(node) + 0);
      FUN_00409b80(node);
      operator_delete(node);
      node = left;
    }
    if (*reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(node) + 0x2d) != 0)
      break;
  }
}

// Scaffold / Ghidra alias (same ABI)
extern "C" void __fastcall FUN_00409970(void *tree_base, MapNode_Isnil2d *node)
{
  StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred(tree_base, node);
}
