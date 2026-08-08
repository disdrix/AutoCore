// =============================================================================
// StdTree_Max_Isnil29_Inferred  (FUN_00421b50)
// -----------------------------------------------------------------------------
// Stable ID: aa_00421b50
// Address:   0x00421b50  (autoassault.exe, image base 0x400000)
// Body:      0x00421b50–0x00421b6c exclusive (28 B); C3; CC pad
// System:    MSVC std::_Tree max / rightmost (isnil@+0x29 node family)
// Generated: 2026-08-04 WQ9D-G dual (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite from body bytes (read_memory).
//            Ghidra decompile is void / walk-into-nil — NOT ABI-authoritative.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher / not run).
// =============================================================================
//
// PURPOSE:
//   Return the rightmost non-nil node of the subtree rooted at `node`
//   (MSVC `_Tree_max`). Map/set erase paths use this to recompute head->right
//   (rightmost) when the erased node was the old rightmost.
//
// Twin: FUN_0051b5d0 (leftmost / min, isnil@+0x29; OWN WQ9D-B).
// Peer: StdTree_Max_Val12 @ 0x00418bf0 (same algorithm, isnil@+0x19).
//
// ABI: __cdecl; stack node*; RET; EAX = result node*.
// Leaf: no callees.
//
// Dual: reviews/A|B_aa_00421b50_StdTree_Max_Isnil29_Inferred.md

#include <cstdint>

// Node (isnil@0x29 family):
//   +0x00 left, +0x04 parent, +0x08 right
//   +0x28 color, +0x29 isnil (0 = real node)

// __cdecl
extern "C" std::int32_t *StdTree_Max_Isnil29_Inferred(std::int32_t *node)
{
  std::int32_t *right = reinterpret_cast<std::int32_t *>(node[2]); /* +8 */
  if (*reinterpret_cast<char *>(reinterpret_cast<std::uintptr_t>(right) + 0x29) != '\0') {
    return node; /* right is nil → start is rightmost */
  }
  do {
    node = right;
    right = reinterpret_cast<std::int32_t *>(node[2]);
  } while (*reinterpret_cast<char *>(reinterpret_cast<std::uintptr_t>(right) + 0x29) == '\0');
  return node;
}

// Ghidra alias
extern "C" std::int32_t *FUN_00421b50(std::int32_t *param_1)
{
  return StdTree_Max_Isnil29_Inferred(param_1);
}
