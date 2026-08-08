// =============================================================================
// StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00409920
// Address:   0x00409920–0x00409960 inclusive (65 B / 0x41)
//            autoassault.exe, image base 0x400000
// Wave:      2026-08-05 WQ9J-I OWN dual A/B seal
// Exactness: Byte-corrected CF. Decompiler omits left-walk + false noreturn;
//            disassemble_function also drops loop-tail; read_memory authoritative.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Free an MSVC-style red-black tree subtree for the large-node family
//   (isnil @ +0x131; left +0; right +8) with value destroy of std::basic_string
//   at node+0x0c via FUN_00409b80 before operator_delete.
//   Sole external caller: FUN_00407b70 full-clear (push head->parent).
//
// ABI
//   ECX = tree_base (threaded, unused in body); stack node*; RET 4; void
//
// Twin CF (do not merge)
//   StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred @ 0x00409970 (isnil +0x2d)
//   StdTree_FreeSubtree_Isnil29_Inferred @ 0x00406c00 (no value destroy)
//   Map_FreeSubtree_Isnil29 @ 0x0051bbc0
//   StdTree_FreeSubtree_Val12 @ 0x0040d630 (isnil +0x19; no string dtor)
// =============================================================================

#include <cstdint>

struct MapNode_Isnil131 {
  MapNode_Isnil131 *left;    // +0x00
  MapNode_Isnil131 *parent;  // +0x04
  MapNode_Isnil131 *right;   // +0x08
  // std::basic_string value starts @ +0x0c (destroyed by FUN_00409b80)
  // ... large POD payload ...
  // uint8_t color;          // +0x130 (inferred)
  // uint8_t isnil;          // +0x131
};

extern "C" void __cdecl operator_delete(void *p);
// stdcall RET 4 — destroys basic_string at node+0x0c only
extern "C" void __stdcall FUN_00409b80(void *node);

// ECX = tree_base; stack = node*; RET 4; void
extern "C" void __fastcall StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred(
    void *tree_base,
    MapNode_Isnil131 *node)
{
  (void)tree_base;
  if (*reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(node) + 0x131) != 0)
    return;

  for (;;) {
    StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred(
        tree_base,
        *reinterpret_cast<MapNode_Isnil131 **>(reinterpret_cast<char *>(node) + 8));
    {
      MapNode_Isnil131 *left =
          *reinterpret_cast<MapNode_Isnil131 **>(reinterpret_cast<char *>(node) + 0);
      FUN_00409b80(node);
      operator_delete(node);
      node = left;
    }
    if (*reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(node) + 0x131) != 0)
      break;
  }
}

// Scaffold / Ghidra alias (same ABI)
extern "C" void __fastcall FUN_00409920(void *tree_base, MapNode_Isnil131 *node)
{
  StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred(tree_base, node);
}
