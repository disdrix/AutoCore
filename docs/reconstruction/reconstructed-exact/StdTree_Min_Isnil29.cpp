// =============================================================================
// StdTree_Min_Isnil29  (FUN_0051b5d0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b5d0
// Address:   0x0051b5d0  (autoassault.exe, image base 0x400000)
// Body:      0x0051b5d0 – 0x0051b5ea inclusive (27 B / 0x1b)
// System:    MSVC std::_Tree min / leftmost (isnil @ +0x29)
// Generated: 2026-08-04 WQ9D-B dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite from body bytes (read_memory).
//            Ghidra decompile is void/walk-into-nil — NOT authoritative for return.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Return the leftmost non-nil node in the subtree rooted at `node`
// (MSVC `_Tree_min`). Used by isnil@+0x29 erase helpers (e.g. Map_EraseNode
// FUN_0051cb40, FUN_00409220) to recompute head->left after unlink.
// Twin (smaller node): StdTree_Min_Val12 @ 0x005adfa0 (isnil @ +0x19).

#include <cstdint>

// Node offsets (isnil@+0x29 size class) — matches Map_EraseNode / erase family
//   +0x00 left, +0x04 parent, +0x08 right
//   value payload +0x0C .. (width per map instantiation)
//   +0x28 color (node[10] as char), +0x29 isnil

struct StdTreeNode_Isnil29 {
  StdTreeNode_Isnil29 *left;    // +0x00
  StdTreeNode_Isnil29 *parent;  // +0x04
  StdTreeNode_Isnil29 *right;   // +0x08
  // ... value ...
  // uint8_t color;  // +0x28
  // uint8_t isnil;  // +0x29
};

// __cdecl: stack = node*; returns node* in EAX; bare RET
extern "C" StdTreeNode_Isnil29 *StdTree_Min_Isnil29(StdTreeNode_Isnil29 *node)
{
  StdTreeNode_Isnil29 *left =
      *reinterpret_cast<StdTreeNode_Isnil29 **>(node); // node->left

  if (*reinterpret_cast<char *>(reinterpret_cast<std::uintptr_t>(left) + 0x29) !=
      0) {
    return node; // left is nil sentinel → node is already minimum
  }

  do {
    node = left;
    left = *reinterpret_cast<StdTreeNode_Isnil29 **>(node);
  } while (*reinterpret_cast<char *>(
               reinterpret_cast<std::uintptr_t>(left) + 0x29) == 0);

  return node;
}

// Ghidra alias (decompiler void is wrong — see bytes)
extern "C" StdTreeNode_Isnil29 *FUN_0051b5d0(StdTreeNode_Isnil29 *param_1)
{
  return StdTree_Min_Isnil29(param_1);
}
