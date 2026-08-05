// =============================================================================
// StdTree_IteratorIncrement_Isnil49
// -----------------------------------------------------------------------------
// Stable ID: aa_00568200
// Address:   0x00568200–0x0056824a  (autoassault.exe, image base 0x400000)
// System:    shared client::stdtree (MSVC _Tree_iterator::operator++)
// Generated: 2026-07-29 W22-B dual seal (from raw + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: In-place tree/map iterator successor (operator++).
//   Node layout: +0 left, +4 parent, +8 right, +0x49 is_nil.
//   Twin: StdTree_IteratorIncrement_Inferred (aa_004cb270) uses is_nil at +0x29.
//   Falsified role: journal mission-id vector fill (not this body).
//
// ABI: __fastcall; ECX = node**; ret (no stack args).
//
// Callers: Client_UpdateMissionJournal, FUN_00538780, FUN_00568c60,
//          FUN_00569560 (insert-with-hint successor probe).
//

#include <stdint.h>

// Node pointer stored in iterator object (*it).
// is_nil byte at node+0x49; links as MSVC _Tree_node header.

void __fastcall StdTree_IteratorIncrement_Isnil49(int32_t *it)
{
  char is_nil;
  int32_t parent;
  int32_t *right;
  int32_t *left_walk;

  int32_t node = *it;
  if (*(char *)(node + 0x49) == '\0') {
    right = *(int32_t **)(node + 8);
    if (*(char *)((int32_t)right + 0x49) == '\0') {
      is_nil = *(char *)(*right + 0x49);
      left_walk = (int32_t *)*right;
      while (is_nil == '\0') {
        is_nil = *(char *)(*left_walk + 0x49);
        right = left_walk;
        left_walk = (int32_t *)*left_walk;
      }
      *it = (int32_t)right;
      return;
    }
    parent = *(int32_t *)(node + 4);
    is_nil = *(char *)(parent + 0x49);
    while ((is_nil == '\0') && (*it == *(int32_t *)(parent + 8))) {
      *it = parent;
      parent = *(int32_t *)(parent + 4);
      is_nil = *(char *)(parent + 0x49);
    }
    *it = parent;
  }
  return;
}

// Scaffold alias
void __fastcall FUN_00568200(int32_t *param_1)
{
  StdTree_IteratorIncrement_Isnil49(param_1);
}
