// =============================================================================
// StdTree_Lrotate_Isnil31_Inferred  (FUN_00403e90)
// -----------------------------------------------------------------------------
// Stable ID: aa_00403e90
// Address:   0x00403e90–0x00403edb inclusive (76 B / 0x4C); pad CC after
// Module:    autoassault.exe (image base 0x400000)
// System:    MSVC std _Tree left-rotate (isnil@+0x31 / color@+0x30 / node 0x38)
// Generated: 2026-08-05 WQ9L-B dual seal (batch_decompile + disassemble_function + read_memory)
// Exactness: Behavior-preserving rewrite from decompile + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Classic left rotate on node X for the isnil@+0x31 tree family
// (node size 0x38: color@+0x30, isnil@+0x31). Used by dualed erase
// StdTree_EraseAndRebalance_Isnil31_Inferred (0x00408ed0) and insert/rebalance
// FUN_00403250. Right-rotate twin: FUN_00403ee0 (WQ9L-C OWN residual).
//
// Node links: left@+0, parent@+4, right@+8.
// Map shell: myhead = *(map+4); root = *(myhead+4).
// No color mutation inside this leaf — callers recolor at +0x30.
//
// Peer families (do not merge): isnil29 StdTree_Lrotate_Isnil29 0x004192a0;
// isnil2D StdTree_LeftRotate_Isnil2D_Inferred 0x0044e010.

#include <cstdint>

struct StdTreeNode_Isnil31 {
  StdTreeNode_Isnil31 *left;   // +0x00
  StdTreeNode_Isnil31 *parent; // +0x04
  StdTreeNode_Isnil31 *right;  // +0x08
  // ... payload @ +0x0C .. +0x2F ...
  // uint8_t color @ +0x30;
  // uint8_t isnil @ +0x31;
  // pad to 0x38
};

struct StdTreeMapShell_Isnil31 {
  void *pad0;
  StdTreeNode_Isnil31 *myhead; // +0x04; root = myhead->parent
};

// isnil byte at +0x31 (sealed via CMP BYTE PTR [reg+0x31],0)
inline bool node_is_nil_31(const StdTreeNode_Isnil31 *n)
{
  return *reinterpret_cast<const std::uint8_t *>(
             reinterpret_cast<const std::uint8_t *>(n) + 0x31) != 0;
}

// __thiscall: ECX = x; stack map*; RET 4; void
extern "C" void __thiscall StdTree_Lrotate_Isnil31_Inferred(
    StdTreeNode_Isnil31 *x, StdTreeMapShell_Isnil31 *map)
{
  StdTreeNode_Isnil31 *y = x->right; // ECX+8
  x->right = y->left;
  if (!node_is_nil_31(y->left)) {
    y->left->parent = x;
  }
  y->parent = x->parent;

  StdTreeNode_Isnil31 *head = map->myhead;
  if (x == head->parent) {
    // x was root
    head->parent = y;
  } else if (x == x->parent->left) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }

  y->left = x;
  x->parent = y;
}
