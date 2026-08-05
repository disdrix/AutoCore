// =============================================================================
// StdTree_IteratorIncrement_Isnil19
// -----------------------------------------------------------------------------
// Stable ID: aa_00457cc0
// Address:   0x00457cc0–0x00457d0b exclusive  (75 B / 0x4B)
// Module:    autoassault.exe (image base 0x400000)
// System:    shared client::stdtree (MSVC _Tree_iterator::operator++)
// Generated: 2026-08-04 W38-B dual seal (from raw + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Runtime / differential: OPEN
//
// PURPOSE: In-place tree/map iterator successor (operator++).
//   Node layout: +0 left, +4 parent, +8 right, +0x19 is_nil.
//   Twins: StdTree_IteratorIncrement_Inferred (aa_004cb270, isnil+0x29);
//          StdTree_IteratorIncrement_Isnil49 (aa_00568200, isnil+0x49).
//   Related: StdTree_IteratorDecrement (aa_004313d0, predecessor; EDX ABI).
//
// ABI: EDX = node**; ECX unused; void; plain RET (C3).
//      Call sites LEA EDX,[stack_it] then CALL.
//
// Callers (9): FUN_0040b440, FUN_0043be60, FUN_0043d7d0, FUN_00447350,
//              FUN_0046c450, FUN_0046f6e0, FUN_00970e50, FUN_00971050,
//              FUN_00971480 (AssPreloader walks among them).
// =============================================================================

#include <stdint.h>

// Node pointer stored in iterator object (*it).
// is_nil byte at node+0x19; links as MSVC _Tree_node header (Val12 family).

void StdTree_IteratorIncrement_Isnil19(int32_t *it /*EDX*/)
{
  char is_nil;
  int32_t parent;
  int32_t *right;
  int32_t *left_walk;

  int32_t node = *it;
  if (*(char *)(node + 0x19) == '\0') {
    right = *(int32_t **)(node + 8);
    if (*(char *)((int32_t)right + 0x19) == '\0') {
      is_nil = *(char *)(*right + 0x19);
      left_walk = (int32_t *)*right;
      while (is_nil == '\0') {
        is_nil = *(char *)(*left_walk + 0x19);
        right = left_walk;
        left_walk = (int32_t *)*left_walk;
      }
      *it = (int32_t)right;
      return;
    }
    parent = *(int32_t *)(node + 4);
    is_nil = *(char *)(parent + 0x19);
    while ((is_nil == '\0') && (*it == *(int32_t *)(parent + 8))) {
      *it = parent;
      parent = *(int32_t *)(parent + 4);
      is_nil = *(char *)(parent + 0x19);
    }
    *it = parent;
  }
  return;
}

// Scaffold alias (Ghidra FUN name)
void __fastcall FUN_00457cc0(uint32_t /*ecx unused*/, int32_t *it /*EDX*/)
{
  (void)0; /* ecx phantom */
  StdTree_IteratorIncrement_Isnil19(it);
}
