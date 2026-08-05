// =============================================================================
// StdMap_FreeSubtree_Val12  (Ghidra: FUN_004e2940)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e2940
// Address:   0x004e2940 – 0x004e2975  (autoassault.exe, image base 0x400000)
// System:    STL map/set node teardown (Val12 / isnil +0x19 family)
// Generated: 2026-07-29 W29-L OWN-ONLY dual (decompile + read_memory)
// Exactness: Byte-corrected CF. Decompiler omits left-walk + false-noreturn on delete.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Free an MSVC-style red-black map/set subtree (Val12 node).
 * ABI: stack node*; ret 4; ECX threaded unused (same as isnil15 peer 0x004ba770).
 * isnil @ +0x19; right @ +8; left @ +0.
 * Caller: StdMap_EraseRange_Val12 (0x004e5120) full-clear path.
 * Peer: StdMap_FreeSubtree_Isnil15_Inferred (0x004ba770) — different isnil offset.
 */

#include <stdint.h>

extern void operator_delete(void *p);

void StdMap_FreeSubtree_Val12(void *param_1 /* node* */)
{
  void *node = param_1;

  if (*(uint8_t *)((char *)node + 0x19) != 0)
    return;

  for (;;) {
    /* recurse right child */
    StdMap_FreeSubtree_Val12(*(void **)((char *)node + 8));
    {
      void *left = *(void **)node; /* left @ +0 before free */
      operator_delete(node);
      node = left;
    }
    if (*(uint8_t *)((char *)node + 0x19) != 0)
      break;
  }
}
