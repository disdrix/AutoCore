// =============================================================================
// StdTree_IteratorDecrement
// -----------------------------------------------------------------------------
// Stable ID: aa_004313d0
// Address:   0x004313d0  (autoassault.exe, image base 0x400000)
// System:    shared client::stdtree (MSVC _Tree predecessor / operator--)
// Generated: 2026-07-29 W22-O dual seal (from raw + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
//
// Purpose:  In-place tree/map iterator decrement (predecessor).
//           Nil at node+0x2D; left@0 parent@4 right@8.
//           end()/header: *it = node->right (rightmost).
//
// Convention:
//   EDX = node**  (iterator storage)
//   ECX unused
//   return void; plain RET
//
// Related:
//   StdMap_StringKey_InsertOrFind (0x004309c0) — uses predecessor after goLeft
//   StdTree_IteratorIncrement_Inferred (0x004cb270) — successor; nil@+0x29
//   reviews/A|B_aa_004313d0_StdTree_IteratorDecrement.md
// =============================================================================

struct StdTreeNode_Isnil2d {
  StdTreeNode_Isnil2d *left;   // +0x00
  StdTreeNode_Isnil2d *parent; // +0x04
  StdTreeNode_Isnil2d *right;  // +0x08
  // ... payload / color ...
  // uint8_t isnil at +0x2d
};

// Ghidra scaffold name retained for call-graph matching:
//   void __fastcall FUN_004313d0(undefined4, int *param_2 /*EDX*/)

void StdTree_IteratorDecrement(StdTreeNode_Isnil2d **it /*EDX*/)
{
  StdTreeNode_Isnil2d *node = *it;

  if (*(char *)((int)node + 0x2d) != '\0') {
    *it = node->right;
    return;
  }

  StdTreeNode_Isnil2d *left = node->left;
  if (*(char *)((int)left + 0x2d) == '\0') {
    char isnil = *(char *)((int)left->right + 0x2d);
    StdTreeNode_Isnil2d *walk = left->right;
    while (isnil == '\0') {
      isnil = *(char *)((int)walk->right + 0x2d);
      left = walk;
      walk = walk->right;
    }
    *it = left;
    return;
  }

  StdTreeNode_Isnil2d *parent = node->parent;
  if (*(char *)((int)parent + 0x2d) == '\0') {
    do {
      if (*it != parent->left)
        break;
      *it = parent;
      parent = parent->parent;
    } while (*(char *)((int)parent + 0x2d) == '\0');
    if (*(char *)((int)parent + 0x2d) == '\0') {
      *it = parent;
    }
  }
}
