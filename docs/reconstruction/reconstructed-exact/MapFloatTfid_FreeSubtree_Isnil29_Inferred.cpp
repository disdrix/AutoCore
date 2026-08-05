// =============================================================================
// MapFloatTfid_FreeSubtree_Isnil29_Inferred  (Ghidra: FUN_0058da00)
// -----------------------------------------------------------------------------
// Stable ID: aa_0058da00
// Address:   0x0058da00 – 0x0058da34  (53 B; autoassault.exe base 0x400000)
// System:    shared tree helper / MapFloatTfid gather distance map
// Generated: 2026-07-29 W24-T OWN-ONLY dual (decompile + read_memory)
// Exactness: Byte-corrected CF. Decompiler omits left-walk; bytes authoritative.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Free an MSVC-style red-black map subtree for the MapFloatTfid node family
 * (isnil @ +0x29; left +0; right +8).
 *
 * Sole external caller: MapFloatTfid_EraseRange_Inferred full-clear path
 *   FUN_0058da00(head[1])  // root
 *
 * Twin CF: StdMap_FreeSubtree_Isnil15_Inferred @ 0x004ba770 (isnil +0x15).
 * ABI: stack node*; RET 4; ECX threaded unused.
 */

#include <stdint.h>

extern void operator_delete(void *p);

void MapFloatTfid_FreeSubtree_Isnil29_Inferred(void *param_1 /* node* */)
{
  void *node = param_1;

  if (*(uint8_t *)((char *)node + 0x29) != 0)
    return;

  for (;;) {
    /* recurse right child */
    MapFloatTfid_FreeSubtree_Isnil29_Inferred(*(void **)((char *)node + 8));
    {
      void *left = *(void **)node; /* left @ +0 before free */
      operator_delete(node);
      node = left;
    }
    if (*(uint8_t *)((char *)node + 0x29) != 0)
      break;
  }
}
