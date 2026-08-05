// =============================================================================
// FUN_0058da00  — scaffold twin of MapFloatTfid_FreeSubtree_Isnil29_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0058da00
// Address:   0x0058da00 – 0x0058da34  (autoassault.exe, image base 0x400000)
// System:    shared tree helper / MapFloatTfid
// Generated: 2026-07-29 W24-T (twin; byte-correct left-walk restored)
// Exactness: Overrides incomplete Ghidra decompile with read_memory CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <stdint.h>

extern void operator_delete(void *p);

void FUN_0058da00(void *param_1)
{
  void *node = param_1;

  /* Ghidra raw decompile only showed right-recurse + delete once.
     Bytes: after delete, walk left @ +0 and loop while !isnil(+0x29). */
  if (*(char *)((int)node + 0x29) != '\0') {
    return;
  }
  for (;;) {
    FUN_0058da00(*(void **)((int)node + 8));
    {
      void *left = *(void **)node;
      operator_delete(node);
      node = left;
    }
    if (*(char *)((int)node + 0x29) != '\0') {
      break;
    }
  }
}
