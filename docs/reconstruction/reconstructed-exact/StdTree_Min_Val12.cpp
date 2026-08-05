// =============================================================================
// StdTree_Min_Val12  (FUN_005adfa0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005adfa0
// Address:   0x005adfa0  (autoassault.exe, image base 0x400000)
// System:    MSVC std::_Tree min / leftmost (Val12 node, isnil@+0x19)
// Generated: 2026-07-29 W28-O seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite from body bytes (read_memory).
//            Ghidra decompile is void/walk-into-nil — NOT authoritative.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Return the leftmost non-nil node in the subtree rooted at `node`
// (MSVC `_Tree_min`). Used by Val12 erase to recompute head->left after unlink.
// Twin: StdTree_Max_Val12 @ 0x00418bf0.

#include <cstdint>

// Node offsets (Val12 / 0x1c) — matches StdTree_Buynode_Val12
//   +0x00 left, +0x04 parent, +0x08 right
//   +0x0c value[12], +0x18 color, +0x19 isnil

// __cdecl: stack = node*; returns node* in EAX; RET (no stack cleanup)
int32_t *StdTree_Min_Val12(int32_t *node)
{
  int32_t *left;

  left = (int32_t *)*node;                      /* node->left */
  if (*(char *)((uintptr_t)left + 0x19) != '\0') /* left isnil */
    return node;
  do {
    node = left;
    left = (int32_t *)*node;
  } while (*(char *)((uintptr_t)left + 0x19) == '\0');
  return node;
}

// Ghidra alias
int32_t *FUN_005adfa0(int32_t *param_1)
{
  return StdTree_Min_Val12(param_1);
}
