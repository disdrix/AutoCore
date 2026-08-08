// =============================================================================
// StdTree_LeftRotate_Isnil2D_Inferred  (FUN_0044e010)
// -----------------------------------------------------------------------------
// Stable ID: aa_0044e010
// Address:   0x0044e010  (autoassault.exe, image base 0x400000)
// Body:      0x0044e010 – 0x0044e05b inclusive (76 B / 0x4C); pad CC after
// System:    MSVC std _Tree left-rotate (isnil@+0x2D family)
// Generated: 2026-08-05 WQ9K-I dual seal (batch_decompile + read_memory)
// Exactness: Behavior-preserving rewrite from decompile + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Classic left rotate on node X for the isnil@+0x2D tree family
// (StringKey map 0x30 nodes: color@+0x2C, isnil@+0x2D). Used by insert
// FUN_00430b60, erase FUN_004094c0, and rebalance peers FUN_0042a930 /
// FUN_00401db0. Right-rotate twin: FUN_0042a840 (WQ9K-J OWN).
//
// Node links: left@+0, parent@+4, right@+8.
// Map shell: myhead = *(map+4); root = *(myhead+4).
// No color mutation inside this leaf — callers recolor.

#include <cstdint>

struct StdTreeNode_Isnil2D {
  StdTreeNode_Isnil2D *left;   // +0x00
  StdTreeNode_Isnil2D *parent; // +0x04
  StdTreeNode_Isnil2D *right;  // +0x08
  // ... payload / string key @ +0x0C ...
  // uint8_t color @ +0x2C;
  // uint8_t isnil @ +0x2D;
};

struct StdTreeMapShell_Isnil2D {
  // layout used only via +4 → head
  void *pad0;
  StdTreeNode_Isnil2D *myhead; // +0x04; root = myhead->parent
};

// isnil byte at +0x2D (sealed via CMP BYTE PTR [reg+0x2D],0)
inline bool node_is_nil(const StdTreeNode_Isnil2D *n)
{
  return *reinterpret_cast<const uint8_t *>(
             reinterpret_cast<const uint8_t *>(n) + 0x2D) != 0;
}

// __thiscall: ECX = x; stack map*; RET 4; void
extern "C" void __thiscall StdTree_LeftRotate_Isnil2D_Inferred(
    StdTreeNode_Isnil2D *x, StdTreeMapShell_Isnil2D *map)
{
  StdTreeNode_Isnil2D *y = x->right; // ECX+8
  x->right = y->left;
  if (!node_is_nil(y->left)) {
    y->left->parent = x;
  }
  y->parent = x->parent;

  StdTreeNode_Isnil2D *head = map->myhead;
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

// Ghidra alias
extern "C" void __thiscall FUN_0044e010(StdTreeNode_Isnil2D *x,
                                        StdTreeMapShell_Isnil2D *map)
{
  StdTree_LeftRotate_Isnil2D_Inferred(x, map);
}
