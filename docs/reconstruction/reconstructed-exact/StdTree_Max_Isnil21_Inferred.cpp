// =============================================================================
// StdTree_Max_Isnil21_Inferred  (FUN_00421a60)
// -----------------------------------------------------------------------------
// Stable ID: aa_00421a60
// Address:   0x00421a60  (autoassault.exe, image base 0x400000)
// Body:      0x00421a60–0x00421a7c exclusive (28 B); C3; CC pad
// System:    MSVC std::_Tree max / rightmost (isnil@+0x21 node family)
// Generated: 2026-08-05 R13-001 dual (live decompile + read_memory + disasm)
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
// Twin: FUN_004cb2c0 (leftmost / min, isnil@+0x21; residual R13-002).
// Peers: StdTree_Max_Isnil29_Inferred @ 0x00421b50;
//        StdTree_Max_Isnil31 @ 0x004043e0;
//        StdTree_Max_Val12 @ 0x00418bf0.
// Parent erase: StdTree_EraseAndRebalance_Isnil21_Inferred @ 0x00405650.
//
// ABI: __cdecl; stack node*; RET; EAX = result node*.
// Leaf: no callees.
//
// Dual: reviews/A|B_aa_00421a60_StdTree_Max_Isnil21_Inferred.md

#include <cstdint>

// Node (isnil@0x21 family / node 0x28):
//   +0x00 left, +0x04 parent, +0x08 right
//   +0x20 color, +0x21 isnil (0 = real node)

// __cdecl
extern "C" std::int32_t *StdTree_Max_Isnil21_Inferred(std::int32_t *node)
{
  std::int32_t *right = reinterpret_cast<std::int32_t *>(node[2]); /* +8 */
  if (*reinterpret_cast<char *>(reinterpret_cast<std::uintptr_t>(right) + 0x21) != '\0') {
    return node; /* right is nil → start is rightmost */
  }
  do {
    node = right;
    right = reinterpret_cast<std::int32_t *>(node[2]);
  } while (*reinterpret_cast<char *>(reinterpret_cast<std::uintptr_t>(right) + 0x21) == '\0');
  return node;
}
