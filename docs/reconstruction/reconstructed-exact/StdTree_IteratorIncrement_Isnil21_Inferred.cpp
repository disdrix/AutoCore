// =============================================================================
// StdTree_IteratorIncrement_Isnil21_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004e12c0
// Address:   0x004e12c0–0x004e130b exclusive  (75 B / 0x4B)
// Module:    autoassault.exe (image base 0x400000)
// System:    skills-abilities partition / shared client::stdtree (role)
// Generated: 2026-08-05 R13-003 dual seal (from raw + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Runtime / differential: OPEN (not Runtime Confirmed)
//
// PURPOSE: In-place tree/map iterator successor (operator++).
//   Node layout: +0 left, +4 parent, +8 right, +0x21 is_nil.
//   Family (isnil21): parent erase 0x00405650; Lrotate 0x0050e9f0;
//     Rrotate 0x005a27f0; insert 0x00407200.
//   Twins (same CF, different isnil):
//     Isnil19  aa_00457cc0 (+0x19)
//     Isnil29  aa_004cb270 (+0x29)
//     Isnil31  aa_00408590 (+0x31, EDX ABI)
//     Isnil49  aa_00568200 (+0x49, ECX ABI)
//     Isnil131 aa_00404000 (+0x131, EDX ABI)
//   Related: StdTree_IteratorDecrement aa_004313d0 (predecessor polarity).
//
// ABI: ECX = node**; void; plain RET (C3).
//      Call sites LEA ECX,[stack_it] then CALL (8 xrefs).
//
// Callers (8): FUN_00405650, FUN_00406560, FUN_004e3e70, FUN_00511c00,
//   FUN_0059d300, FUN_005a2ea0, FUN_005a4590, FUN_005ae6d0.
// =============================================================================

#include <stdint.h>

// Node pointer stored in iterator object (*it).
// is_nil byte at node+0x21; links as MSVC _Tree_node header.

void StdTree_IteratorIncrement_Isnil21_Inferred(int32_t *it /*ECX*/)
{
  char is_nil;
  int32_t parent;
  int32_t *right;
  int32_t *left_walk;

  int32_t node = *it;
  if (*(char *)(node + 0x21) == '\0') {
    right = *(int32_t **)(node + 8);
    if (*(char *)((int32_t)right + 0x21) == '\0') {
      is_nil = *(char *)(*right + 0x21);
      left_walk = (int32_t *)*right;
      while (is_nil == '\0') {
        is_nil = *(char *)(*left_walk + 0x21);
        right = left_walk;
        left_walk = (int32_t *)*left_walk;
      }
      *it = (int32_t)right;
      return;
    }
    parent = *(int32_t *)(node + 4);
    is_nil = *(char *)(parent + 0x21);
    while ((is_nil == '\0') && (*it == *(int32_t *)(parent + 8))) {
      *it = parent;
      parent = *(int32_t *)(parent + 4);
      is_nil = *(char *)(parent + 0x21);
    }
    *it = parent;
  }
  return;
}
