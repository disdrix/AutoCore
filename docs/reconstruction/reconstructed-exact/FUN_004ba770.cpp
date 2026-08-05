// =============================================================================
// FUN_004ba770  (scaffold / Ghidra leave-name)
// Canonical: StdMap_FreeSubtree_Isnil15_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004ba770
// Address:   0x004ba770 – 0x004ba7a4  (autoassault.exe, image base 0x400000)
// System:    STL map/set node teardown (isnil +0x15 family)
// Generated: 2026-07-29 W20-N OWN-ONLY dual (decompile + read_memory)
// Exactness: Byte-corrected CF (left-walk). Named twin:
//            StdMap_FreeSubtree_Isnil15_Inferred.cpp
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <stdint.h>

extern void operator_delete(void *p);

void FUN_004ba770(void *param_1)
{
  void *node = param_1;

  if (*(uint8_t *)((char *)node + 0x15) != 0)
    return;

  for (;;) {
    FUN_004ba770(*(void **)((char *)node + 8));
    {
      void *left = *(void **)node;
      operator_delete(node);
      node = left;
    }
    if (*(uint8_t *)((char *)node + 0x15) != 0)
      break;
  }
}
