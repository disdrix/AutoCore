// =============================================================================
// StdTree_InsertAndRebalance_Isnil2D_Inferred  (FUN_00401db0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00401db0
// Address:   0x00401db0–0x00401f31 exclusive (385 B / 0x181)
// System:    MSVC std::_Tree always-insert + red-black rebalance (isnil@+0x2D)
// Generated: 2026-08-05 MEGA-066 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed assembly ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Always-allocate insert under a parent hint + RB rebalance for the isnil@+0x2D
//   node family (node 0x30, color@+0x2C, isnil@+0x2D, string key @+0x0C).
//   Parent FUN_00401c50 owns lower-bound / uniqueness (string operator<); this unit
//   never compares keys.
//
// ABI (byte-sealed):
//   EDI = MapShell* map  (caller register; NOT mov edi,ecx thiscall-on-map)
//   ECX = Node* where
//   stack: (Node** out, char addLeft, const void* value)
//   RET 0x0C  (C2 0C 00 @ 0x00401f2f)
//
// Max size: throw "map/set<T> too long" if size > 0x7FFFFFD
//   (cmp [edi+8], 0x7FFFFFE / jb continue).
//
// Rotates: StdTree_LeftRotate_Isnil2D_Inferred (0044e010),
//          StdTree_Rrotate_Isnil2D_Inferred (0042a840)
//          — ECX=node, stack=map (PUSH EDI).
// Buynode: FUN_00401f40 → operator_new(0x30) + FUN_00401fe0.
//
// Clone peer: StdMap_StringKey_InsertNodeAndRebalance (0x00430b60) — same family
// ABI/threshold; different buynode (FUN_0042a890).
//
// Dual: reviews/A|B_aa_00401db0_StdTree_InsertAndRebalance_Isnil2D_Inferred.md
// Reject: Named_CalleeOf_*Mission*null*dialog* product alias; isnil29 merge.

#include <cstdint>

struct NodeIsnil2D {
  NodeIsnil2D* left;     // +0x00
  NodeIsnil2D* parent;   // +0x04
  NodeIsnil2D* right;    // +0x08
  // +0x0C .. string key (std::basic_string) — copied by FUN_00402040
  // +0x28 optional mapped dword (peer 00430b60); not written in this plate
  std::uint8_t color;    // +0x2C  (0=red, 1=black)
  std::uint8_t isnil;    // +0x2D
  // pad to 0x30
};

struct MapShellIsnil2D {
  void* proxy;             // +0x00
  NodeIsnil2D* head;       // +0x04 sentinel (isnil=1); parent=root, left=Lmost, right=Rmost
  std::uint32_t size;      // +0x08
};

// UnOWN callees
extern "C" NodeIsnil2D* FUN_00401f40(
    NodeIsnil2D* left,
    NodeIsnil2D* parent,
    NodeIsnil2D* right,
    const void* value,
    std::uint8_t color);

extern "C" void __thiscall StdTree_LeftRotate_Isnil2D_Inferred(
    NodeIsnil2D* x, MapShellIsnil2D* map);
extern "C" void __thiscall StdTree_Rrotate_Isnil2D_Inferred(
    NodeIsnil2D* x, MapShellIsnil2D* map);
// Ghidra: FUN_0044e010 / FUN_0042a840

// Throw path: basic_string("map/set<T> too long") + FUN_00401a40 +
// _CxxThrowException(DAT_00acc388). Non-returning.

// Custom register ABI: first explicit arg is map (EDI at call site);
// ECX = where. MSVC plate models EDI as an explicit parameter for clarity.
extern "C" void StdTree_InsertAndRebalance_Isnil2D_Inferred(
    /*EDI*/ MapShellIsnil2D* map,
    /*ECX*/ NodeIsnil2D* where,
    NodeIsnil2D** out,
    char addLeft,
    const void* value)
{
  if (map->size > 0x7fffffdU) {
    // non-returning length_error — plate sealed
    return;
  }

  NodeIsnil2D* head = map->head;
  // buynode: left=head, parent=where, right=head, color=red(0), copy value, isnil=0
  NodeIsnil2D* n = FUN_00401f40(head, where, head, value, /*red*/ 0);
  map->size += 1;

  if (where == head) {
    head->parent = n;
    head->left = n;
    head->right = n;
  } else if (addLeft == 0) {
    where->right = n;
    if (where == head->right)
      head->right = n;
  } else {
    where->left = n;
    if (where == head->left)
      head->left = n;
  }

  // RB fixup while parent is red (color @ +0x2C)
  NodeIsnil2D* x = n;
  while (x->parent->color == 0) {
    NodeIsnil2D* p = x->parent;
    NodeIsnil2D* gp = p->parent;
    if (p == gp->left) {
      NodeIsnil2D* uncle = gp->right;
      if (uncle->color == 0) {
        p->color = 1;
        uncle->color = 1;
        gp->color = 0;
        x = gp;
      } else {
        if (x == p->right) {
          StdTree_LeftRotate_Isnil2D_Inferred(p, map);
          x = p;
        }
        x->parent->color = 1;
        x->parent->parent->color = 0;
        StdTree_Rrotate_Isnil2D_Inferred(x->parent->parent, map);
      }
    } else {
      NodeIsnil2D* uncle = gp->left;
      if (uncle->color == 0) {
        p->color = 1;
        uncle->color = 1;
        gp->color = 0;
        x = gp;
      } else {
        if (x == p->left) {
          StdTree_Rrotate_Isnil2D_Inferred(p, map);
          x = p;
        }
        x->parent->color = 1;
        x->parent->parent->color = 0;
        StdTree_LeftRotate_Isnil2D_Inferred(x->parent->parent, map);
      }
    }
  }

  map->head->parent->color = 1;
  *out = n;
}
