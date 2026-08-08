// =============================================================================
// FUN_00421b50 — scaffold twin of StdTree_Max_Isnil29_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00421b50
// Address:   0x00421b50  (autoassault.exe, image base 0x400000)
// System:    MSVC std::_Tree max / rightmost (isnil@+0x29)
// Generated: 2026-08-04 WQ9D-G seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite from body bytes (read_memory).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Rightmost non-nil of subtree (MSVC `_Tree_max`). Prefer named unit
// StdTree_Max_Isnil29_Inferred.cpp for product documentation.

#include <cstdint>

// __cdecl; node* → node*; RET
std::int32_t *FUN_00421b50(std::int32_t *node)
{
  std::int32_t *right;

  right = (std::int32_t *)node[2];
  if (*(char *)((std::uintptr_t)right + 0x29) != '\0')
    return node;
  do {
    node = right;
    right = (std::int32_t *)node[2];
  } while (*(char *)((std::uintptr_t)right + 0x29) == '\0');
  return node;
}
