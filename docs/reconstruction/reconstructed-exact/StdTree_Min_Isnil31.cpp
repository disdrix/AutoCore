// =============================================================================
// StdTree_Min_Isnil31  (FUN_00409160)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409160
// Address:   0x00409160  (autoassault.exe, image base 0x400000)
// Body:      0x00409160 – 0x00409172 inclusive (19 B / 0x13); pad CC after
// System:    MSVC std::_Tree min / leftmost (isnil @ +0x31)
// Generated: 2026-08-05 WQ9J-E dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite from body bytes (read_memory).
//            Ghidra decompile is void / in_EAX phantom — NOT authoritative for
//            return (result is EAX).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Return the leftmost non-nil node in the subtree rooted at `node`
// (MSVC `_Tree_min`). Used by map erase FUN_00408ed0 (isnil@+0x31 family) to
// recompute head->left after unlinking the old leftmost.
// Twin: StdTree_Min_Isnil29 @ 0x0051b5d0 (isnil @ +0x29; stack-arg ABI).
// Family peer: StdTree_IteratorIncrement_Isnil31 @ 0x00408590.

#include <cstdint>

// Node offsets (isnil@+0x31 size class) — matches erase FUN_00408ed0
//   +0x00 left, +0x04 parent, +0x08 right
//   value payload +0x0C ..
//   color @ +0x30 (node[0xc] as char in decomp of erase), isnil @ +0x31

struct StdTreeNode_Isnil31 {
  StdTreeNode_Isnil31 *left;    // +0x00
  StdTreeNode_Isnil31 *parent;  // +0x04
  StdTreeNode_Isnil31 *right;   // +0x08
  // ... value ...
  // uint8_t color;  // +0x30
  // uint8_t isnil;  // +0x31
};

// Custom register ABI: EAX = node* on entry; returns node* in EAX; bare RET.
// Call site (FUN_00408ed0 @ 0x00408f9d): MOV EAX, EDI; CALL; MOV [EBX], EAX
extern "C" StdTreeNode_Isnil31 *StdTree_Min_Isnil31(StdTreeNode_Isnil31 *node /*EAX*/)
{
  StdTreeNode_Isnil31 *left =
      *reinterpret_cast<StdTreeNode_Isnil31 **>(node); // node->left

  if (*reinterpret_cast<char *>(reinterpret_cast<std::uintptr_t>(left) + 0x31) !=
      0) {
    return node; // left is nil sentinel → node is already minimum
  }

  do {
    node = left;
    left = *reinterpret_cast<StdTreeNode_Isnil31 **>(node);
  } while (*reinterpret_cast<char *>(
               reinterpret_cast<std::uintptr_t>(left) + 0x31) == 0);

  return node;
}

// Ghidra alias (decompiler void is wrong — see bytes / call-site MOV [EBX],EAX)
extern "C" StdTreeNode_Isnil31 *FUN_00409160(StdTreeNode_Isnil31 *param_1 /*EAX*/)
{
  return StdTree_Min_Isnil31(param_1);
}
