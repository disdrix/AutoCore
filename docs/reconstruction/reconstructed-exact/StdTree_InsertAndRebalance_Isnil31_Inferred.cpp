// =============================================================================
// StdTree_InsertAndRebalance_Isnil31_Inferred  (FUN_00403250)
// -----------------------------------------------------------------------------
// Stable ID: aa_00403250
// Address:   0x00403250–0x004033d1 inclusive (386 B / 0x182)
// System:    MSVC std::_Tree always-insert + red-black rebalance (isnil@+0x31)
//            Chain nest: Client_NotifyActiveMissionChanged (missions-progression)
// Generated: 2026-08-05 MEGA-047 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Always-allocate insert under a parent hint + RB rebalance for the large-node
//   isnil@+0x31 family (node 0x38, color@+0x30, isnil@+0x31, value 0x20 @+0x10).
//   Parent (FUN_00402b30) owns lower-bound / uniqueness; this unit never compares keys.
//
// ABI: custom register (not pure thiscall-map):
//   EDI = map*; ECX = where*; stack (out**, addLeft, value*); RET 0xC; EAX = out.
// Max size: throw "map/set<T> too long" if size >= 0x7fffffe.
// Rotates: StdTree_Lrotate_Isnil31_Inferred (00403e90), FUN_00403ee0 (Rrotate).
// Buynode: FUN_00403f30 → operator_new(0x38) + FUN_00404360.
//
// Dual: reviews/A|B_aa_00403250_StdTree_InsertAndRebalance_Isnil31_Inferred.md
// Retire: Named_CalleeOf_Named_CalleeOf_Client_NotifyActiveMissionChanged_00403250

#include <cstdint>

struct NodeIsnil31 {
  NodeIsnil31* left;     // +0x00
  NodeIsnil31* parent;   // +0x04
  NodeIsnil31* right;    // +0x08
  // +0x0C pad / unused in link path
  std::uint32_t val[8];  // +0x10 .. +0x2F  (0x20-byte value; key often val[0])
  std::uint8_t color;    // +0x30  (0=red, 1=black)
  std::uint8_t isnil;    // +0x31
  // pad to 0x38
};

struct MapShellIsnil31 {
  void* proxy;             // +0x00
  NodeIsnil31* head;       // +0x04 sentinel (isnil=1); parent=root, left=Lmost, right=Rmost
  std::uint32_t size;      // +0x08
};

// UnOWN callees
extern "C" NodeIsnil31* FUN_00403f30(
    NodeIsnil31* left,
    NodeIsnil31* parent,
    NodeIsnil31* right,
    const void* value,
    std::uint8_t color);

// Dualed WQ9L-B: ECX=node, stack=map, RET 4
extern "C" void __thiscall StdTree_Lrotate_Isnil31_Inferred(
    NodeIsnil31* x, MapShellIsnil31* map);
// Ghidra: FUN_00403e90

// Residual twin: ECX=node, stack=map, RET 4
extern "C" void __thiscall FUN_00403ee0(NodeIsnil31* x, MapShellIsnil31* map);

// Throw path: basic_string("map/set<T> too long") + FUN_00401a40 +
// _CxxThrowException(DAT_00acc388).

// Custom ABI: EDI=map, ECX=where (MSVC tree insert register form)
extern "C" NodeIsnil31** StdTree_InsertAndRebalance_Isnil31_Inferred(
    MapShellIsnil31* map /*EDI*/,
    NodeIsnil31* where /*ECX*/,
    NodeIsnil31** out,
    char addLeft,
    const void* value)
{
  if (map->size >= 0x7fffffeu) {
    // non-returning length_error — plate sealed
    return out;
  }

  NodeIsnil31* head = map->head;
  // buynode: left=head, parent=where, right=head, color=red(0), copy value 0x20, isnil=0
  NodeIsnil31* n = FUN_00403f30(head, where, head, value, /*red*/ 0);
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

  NodeIsnil31* x = n;
  while (x->parent->color == 0) {
    NodeIsnil31* p = x->parent;
    NodeIsnil31* g = p->parent;
    if (p == g->left) {
      NodeIsnil31* uncle = g->right;
      if (uncle->color == 0) {
        p->color = 1;
        uncle->color = 1;
        g->color = 0;
        x = g;
      } else {
        if (x == p->right) {
          StdTree_Lrotate_Isnil31_Inferred(p, map);
          x = p;
          p = x->parent;
        }
        p->color = 1;
        p->parent->color = 0;
        FUN_00403ee0(p->parent, map);
      }
    } else {
      NodeIsnil31* uncle = g->left;
      if (uncle->color == 0) {
        p->color = 1;
        uncle->color = 1;
        g->color = 0;
        x = g;
      } else {
        if (x == p->left) {
          FUN_00403ee0(p, map);
          x = p;
          p = x->parent;
        }
        p->color = 1;
        p->parent->color = 0;
        StdTree_Lrotate_Isnil31_Inferred(p->parent, map);
      }
    }
  }

  head->parent->color = 1;  // root black
  *out = n;
  return out;  // RET 0xC; EAX = out
}
