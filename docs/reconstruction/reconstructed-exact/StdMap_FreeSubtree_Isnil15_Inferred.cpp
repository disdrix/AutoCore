// =============================================================================
// StdMap_FreeSubtree_Isnil15_Inferred  (Ghidra: FUN_004ba770)
// -----------------------------------------------------------------------------
// Stable ID: aa_004ba770
// Address:   0x004ba770 – 0x004ba7a4  (autoassault.exe, image base 0x400000)
// System:    STL map/set node teardown (isnil +0x15 family)
// Generated: 2026-07-29 W20-N OWN-ONLY dual (decompile + read_memory)
// Exactness: Byte-corrected CF. Decompiler omits left-walk; bytes authoritative.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Free an MSVC-style red-black map/set subtree.
 * ABI: stack node*; ret 4; ECX threaded unused.
 * isnil @ +0x15; right @ +8; left @ +0.
 * Callers: StdMap_EraseRange_Inferred (full clear), NDSpecialFX child-map clear.
 */

#include <stdint.h>

extern void operator_delete(void *p);

void StdMap_FreeSubtree_Isnil15_Inferred(void *param_1 /* node* */)
{
  void *node = param_1;

  if (*(uint8_t *)((char *)node + 0x15) != 0)
    return;

  for (;;) {
    /* recurse right child */
    StdMap_FreeSubtree_Isnil15_Inferred(*(void **)((char *)node + 8));
    {
      void *left = *(void **)node; /* left @ +0 before free */
      operator_delete(node);
      node = left;
    }
    if (*(uint8_t *)((char *)node + 0x15) != 0)
      break;
  }
}
