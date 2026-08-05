// =============================================================================
// FUN_00457cc0  (scaffold twin of StdTree_IteratorIncrement_Isnil19)
// -----------------------------------------------------------------------------
// Stable ID: aa_00457cc0
// Address:   0x00457cc0–0x00457d0b exclusive  (75 B)
// Canonical named twin: reconstructed-exact/StdTree_IteratorIncrement_Isnil19.cpp
// Generated: 2026-08-04 W38-B dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

#include <stdint.h>

// ABI: EDX = node** (iterator); plain RET; leaf; is_nil @ +0x19
// Ghidra: void __fastcall FUN_00457cc0(undefined4, int *param_2)

void __fastcall FUN_00457cc0(uint32_t /*ecx_unused*/, int32_t *it)
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
