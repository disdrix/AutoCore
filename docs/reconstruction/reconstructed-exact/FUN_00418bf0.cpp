// =============================================================================
// FUN_00418bf0 — scaffold twin of StdTree_Max_Val12
// -----------------------------------------------------------------------------
// Stable ID: aa_00418bf0
// Address:   0x00418bf0  (autoassault.exe, image base 0x400000)
// System:    MSVC std::_Tree max / rightmost (Val12 node, isnil@+0x19)
// Generated: 2026-07-29 W28-O seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite from body bytes (read_memory).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Rightmost non-nil of subtree (MSVC `_Tree_max`). Prefer named unit
// StdTree_Max_Val12.cpp for product documentation.

#include <cstdint>

// __cdecl; node* → node*; RET
int32_t *FUN_00418bf0(int32_t *node)
{
  int32_t *right;

  right = (int32_t *)node[2];
  if (*(char *)((uintptr_t)right + 0x19) != '\0')
    return node;
  do {
    node = right;
    right = (int32_t *)node[2];
  } while (*(char *)((uintptr_t)right + 0x19) == '\0');
  return node;
}
