// =============================================================================
// StdTree_IteratorIncrement_Isnil131
// -----------------------------------------------------------------------------
// Stable ID: aa_00404000
// Address:   0x00404000–0x00404057 inclusive  (88 B / 0x58)
// Module:    autoassault.exe (image base 0x400000)
// System:    shared client::stdtree (MSVC _Tree_iterator::operator++)
// Generated: 2026-08-05 WQ9L-A dual seal (from raw + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Runtime / differential: OPEN
//
// PURPOSE: In-place tree/map iterator successor (operator++).
//   Node layout: +0 left, +4 parent, +8 right, +0x131 is_nil.
//   Twins: StdTree_IteratorIncrement_Isnil31 (aa_00408590, isnil+0x31);
//          StdTree_IteratorIncrement_Isnil19 (aa_00457cc0, isnil+0x19);
//          StdTree_IteratorIncrement_Inferred (aa_004cb270, isnil+0x29);
//          StdTree_IteratorIncrement_Isnil49 (aa_00568200, isnil+0x49).
//
// ABI: EDX = node**; ECX unused at entry; void; plain RET (C3).
//      Call sites LEA EDX,[stack_it] then CALL.
//
// Callers: FUN_00407b70 @ 0x00407bc6 (erase-range);
//          FUN_00408ad0 @ 0x00408b37 (erase single — OWN peer);
//          FUN_00957820 @ 0x00957928 / 0x00957a9e / 0x00957c34 / 0x00957d9e.
// =============================================================================

#include <stdint.h>

// Node pointer stored in iterator object (*it).
// is_nil byte at node+0x131; links as MSVC _Tree_node header.

void StdTree_IteratorIncrement_Isnil131(int32_t *it /*EDX*/)
{
  char is_nil;
  int32_t parent;
  int32_t *right;
  int32_t *left_walk;

  int32_t node = *it;
  if (*(char *)(node + 0x131) == '\0') {
    right = *(int32_t **)(node + 8);
    if (*(char *)((int32_t)right + 0x131) == '\0') {
      is_nil = *(char *)(*right + 0x131);
      left_walk = (int32_t *)*right;
      while (is_nil == '\0') {
        is_nil = *(char *)(*left_walk + 0x131);
        right = left_walk;
        left_walk = (int32_t *)*left_walk;
      }
      *it = (int32_t)right;
      return;
    }
    parent = *(int32_t *)(node + 4);
    is_nil = *(char *)(parent + 0x131);
    while ((is_nil == '\0') && (*it == *(int32_t *)(parent + 8))) {
      *it = parent;
      parent = *(int32_t *)(parent + 4);
      is_nil = *(char *)(parent + 0x131);
    }
    *it = parent;
  }
  return;
}

// Scaffold alias (Ghidra FUN name)
void __fastcall FUN_00404000(uint32_t /*ecx unused*/, int32_t *it /*EDX*/)
{
  (void)0; /* ecx phantom */
  StdTree_IteratorIncrement_Isnil131(it);
}
