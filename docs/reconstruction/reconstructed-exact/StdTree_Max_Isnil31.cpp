// =============================================================================
// StdTree_Max_Isnil31  (FUN_004043e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004043e0
// Address:   0x004043e0  (autoassault.exe, image base 0x400000)
// Body:      0x004043e0 – 0x004043fb inclusive (28 B / 0x1c); pad CC after
// System:    MSVC std::_Tree max / rightmost (isnil @ +0x31)
// Generated: 2026-08-05 WQ9L-C dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite from body bytes (read_memory).
//            Ghidra decompile is void / in_EAX phantom — NOT authoritative for
//            return (result is EAX).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Return the rightmost non-nil node in the subtree rooted at `node`
// (MSVC `_Tree_max`). Used by map erase FUN_00408ed0 (isnil@+0x31 family) to
// recompute head->right after unlinking the old rightmost.
// Twin: StdTree_Min_Isnil31 @ 0x00409160 (leftmost; dualed WQ9J-E).
// Peer: StdTree_Max_Isnil29_Inferred @ 0x00421b50 (isnil @ +0x29; stack-arg ABI).

#include <cstdint>

// Node offsets (isnil@+0x31 size class) — matches erase FUN_00408ed0
//   +0x00 left, +0x04 parent, +0x08 right
//   value payload +0x0C ..
//   color @ +0x30, isnil @ +0x31

struct StdTreeNode_Isnil31 {
  StdTreeNode_Isnil31 *left;    // +0x00
  StdTreeNode_Isnil31 *parent;  // +0x04
  StdTreeNode_Isnil31 *right;   // +0x08
  // ... value ...
  // uint8_t color;  // +0x30
  // uint8_t isnil;  // +0x31
};

// Custom register ABI: EAX = node* on entry; returns node* in EAX; bare RET.
// Call site (FUN_00408ed0 @ 0x00408fbf): MOV EAX, EDI; CALL; MOV [EBX+8], EAX
extern "C" StdTreeNode_Isnil31 *StdTree_Max_Isnil31(StdTreeNode_Isnil31 *node /*EAX*/)
{
  StdTreeNode_Isnil31 *right =
      *reinterpret_cast<StdTreeNode_Isnil31 **>(
          reinterpret_cast<char *>(node) + 8); // node->right

  if (*reinterpret_cast<char *>(reinterpret_cast<std::uintptr_t>(right) + 0x31) !=
      0) {
    return node; // right is nil sentinel → node is already maximum
  }

  do {
    node = right;
    right = *reinterpret_cast<StdTreeNode_Isnil31 **>(
        reinterpret_cast<char *>(node) + 8);
  } while (*reinterpret_cast<char *>(
               reinterpret_cast<std::uintptr_t>(right) + 0x31) == 0);

  return node;
}

// Ghidra alias (decompiler void is wrong — see bytes / call-site MOV [EBX+8],EAX)
extern "C" StdTreeNode_Isnil31 *FUN_004043e0(StdTreeNode_Isnil31 *param_1 /*EAX*/)
{
  return StdTree_Max_Isnil31(param_1);
}
