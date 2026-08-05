// =============================================================================
// FUN_005adfa0 — scaffold twin of StdTree_Min_Val12
// -----------------------------------------------------------------------------
// Stable ID: aa_005adfa0
// Address:   0x005adfa0  (autoassault.exe, image base 0x400000)
// System:    MSVC std::_Tree min / leftmost (Val12 node, isnil@+0x19)
// Generated: 2026-07-29 W28-O seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite from body bytes (read_memory).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Leftmost non-nil of subtree (MSVC `_Tree_min`). Prefer named unit
// StdTree_Min_Val12.cpp for product documentation.

#include <cstdint>

// __cdecl; node* → node*; RET
int32_t *FUN_005adfa0(int32_t *node)
{
  int32_t *left;

  left = (int32_t *)*node;
  if (*(char *)((uintptr_t)left + 0x19) != '\0')
    return node;
  do {
    node = left;
    left = (int32_t *)*node;
  } while (*(char *)((uintptr_t)left + 0x19) == '\0');
  return node;
}
