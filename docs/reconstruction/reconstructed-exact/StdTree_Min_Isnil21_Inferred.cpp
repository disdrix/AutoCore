// =============================================================================
// StdTree_Min_Isnil21_Inferred  (FUN_004cb2c0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cb2c0
// Address:   0x004cb2c0  (autoassault.exe, image base 0x400000)
// Body:      0x004cb2c0 – 0x004cb2da inclusive (27 B / 0x1b); pad CC after
// System:    MSVC std::_Tree min / leftmost (isnil @ +0x21)
// Partition: R13-002 residual dual (parent 0x00405650 erase isnil21)
// Generated: 2026-08-05 R13-002 dual seal (decompile_function + read_memory
//            + disassemble_function + callers/xrefs + get_assembly_context)
// Exactness: Behavior-preserving rewrite from body bytes (read_memory).
//            Ghidra decompile is void — NOT authoritative for return (EAX).
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: NOT claimed.
// =============================================================================

// PURPOSE: Return the leftmost non-nil node in the subtree rooted at `node`
// (MSVC `_Tree_min`). Used by isnil@+0x21 map erase helpers (parent
// StdTree_EraseAndRebalance_Isnil21_Inferred @ 0x00405650 and six peer erase
// plates) to recompute head->left after unlinking the old leftmost.
// Family twins: StdTree_Min_Isnil29 @ 0x0051b5d0 (stack ABI, isnil+0x29);
//               StdTree_Min_Isnil31 @ 0x00409160 (EAX ABI, isnil+0x31).
// Max peer residual: FUN_00421a60 (R13-001).

#include <cstdint>

// Node offsets (isnil@+0x21 size class) — matches erase parent 0x00405650
//   +0x00 left, +0x04 parent, +0x08 right
//   value payload +0x0C ..
//   color @ +0x20, isnil @ +0x21
//   node size 0x28 (Val16) per parent dual

struct StdTreeNode_Isnil21 {
  StdTreeNode_Isnil21 *left;    // +0x00
  StdTreeNode_Isnil21 *parent;  // +0x04
  StdTreeNode_Isnil21 *right;   // +0x08
  // ... value ...
  // uint8_t color;  // +0x20
  // uint8_t isnil;  // +0x21
};

// __cdecl-like: stack = node*; returns node* in EAX; bare RET; caller ADD ESP,4
// Call plate (all 7 sites): PUSH EDI; CALL; ADD ESP,4; MOV [EBX],EAX
extern "C" StdTreeNode_Isnil21 *StdTree_Min_Isnil21_Inferred(
    StdTreeNode_Isnil21 *node)
{
  StdTreeNode_Isnil21 *left =
      *reinterpret_cast<StdTreeNode_Isnil21 **>(node); // node->left

  if (*reinterpret_cast<char *>(reinterpret_cast<std::uintptr_t>(left) + 0x21) !=
      0) {
    return node; // left is nil sentinel → node is already minimum
  }

  do {
    node = left;
    left = *reinterpret_cast<StdTreeNode_Isnil21 **>(node);
  } while (*reinterpret_cast<char *>(
               reinterpret_cast<std::uintptr_t>(left) + 0x21) == 0);

  return node;
}

// Ghidra alias (decompiler void is wrong — see bytes / call-site MOV [EBX],EAX)
extern "C" StdTreeNode_Isnil21 *FUN_004cb2c0(StdTreeNode_Isnil21 *param_1)
{
  return StdTree_Min_Isnil21_Inferred(param_1);
}
