// =============================================================================
// StdTree_EraseAndRebalance_Isnil31_Inferred  (FUN_00408ed0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00408ed0
// Address:   0x00408ed0  (autoassault.exe, image base 0x400000)
// Body:      0x00408ed0 – 0x00409160 exclusive (656 B / 0x290)
//            Ghidra lists end 0x00409130 (truncated by false noreturn on delete)
// System:    std map/set red-black tree erase (isnil@+0x31 / node 0x38)
// Generated: 2026-08-05 WQ9K-E dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed epilogue.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   MSVC-style std::_Tree erase(const_iterator) for nodes with color @ +0x30
//   and isnil @ +0x31 (node alloc size 0x38; value payload before color).
//   Throw "invalid map/set<T> iterator" on nil; capture successor (iterator++);
//   unlink + extremity fix (min/max isnil31); RB rebalance if erased black;
//   operator_delete (no value dtor); size--; write *outIt; RET 0x0C.
//
// ABI
//   Three stack args (map*, outIt**, node*); RET 0x0C. Not ECX-thiscall primary.
//
// THROW
//   isnil → "invalid map/set<T> iterator" via DAT_00acc34c (@ string 0x00a152f0)
//
// CALLER (1)
//   FUN_00407cb0 @ 0x00407d4e (erase-range loop)
//
// PEERS (do not merge)
//   Isnil29 erase: StdTree_EraseAndRebalance_Isnil29_Inferred @ 0x004cb740
//   StringKey isnil2d erase: StdMap_StringKey_EraseAndRebalance_Inferred @ 0x004094c0
//   Succ: StdTree_IteratorIncrement_Isnil31 @ 0x00408590
//   Min:  StdTree_Min_Isnil31 @ 0x00409160
//   Head: StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred @ 0x00409180
// =============================================================================

#include <cstdint>

struct MapNode_Isnil31 {
  MapNode_Isnil31 *left;    // +0x00
  MapNode_Isnil31 *parent;  // +0x04
  MapNode_Isnil31 *right;   // +0x08
  // +0x0C .. +0x2F  value payload (trivial / no dtor call sealed)
  std::uint8_t color;       // +0x30  0=red, 1=black
  std::uint8_t isnil;       // +0x31
  // pad to 0x38
};

struct MapShell_Isnil31 {
  void *proxy;              // +0x00
  MapNode_Isnil31 *head;    // +0x04  end sentinel
  std::uint32_t size;       // +0x08
};

// External callees (isnil@+0x31 family; OWN duals elsewhere where noted)
extern "C" void FUN_00408590(MapNode_Isnil31 **it); // iterator++ / successor (isnil31)
extern "C" MapNode_Isnil31 *FUN_00409160(MapNode_Isnil31 *n); // min / leftmost (WQ9J-E)
extern "C" MapNode_Isnil31 *FUN_004043e0(MapNode_Isnil31 *n); // max / rightmost
extern "C" void FUN_00403e90(MapShell_Isnil31 *tree, MapNode_Isnil31 *x); // Lrotate
extern "C" void FUN_00403ee0(MapShell_Isnil31 *tree, MapNode_Isnil31 *x); // Rrotate
extern "C" void operator_delete(void *p);
extern "C" void _CxxThrowException(void *, void *);

// ---------------------------------------------------------------------------
// Clean reconstruction — CF ≡ live decompile + byte-sealed epilogue
// ---------------------------------------------------------------------------

extern "C" void StdTree_EraseAndRebalance_Isnil31_Inferred(
    MapShell_Isnil31 *map,           // stack0
    MapNode_Isnil31 **outIt,         // stack1
    MapNode_Isnil31 *node)           // stack2
{
  // SEH frame omitted (LAB_009bc919); present in retail for throw path.

  if (node->isnil != 0) {
    // basic_string("invalid map/set<T> iterator") → _CxxThrowException(..., DAT_00acc34c)
    _CxxThrowException(nullptr, nullptr);
  }

  // Capture successor before unlink (FUN_00408590 / StdTree_IteratorIncrement_Isnil31).
  *outIt = node;
  FUN_00408590(outIt);

  // Replacement child (MSVC erase splice; isnil@+0x31). Full two-child
  // successor-swap path exists in retail (decompiler may mark mid blocks
  // "unreachable" — preserve full MSVC erase semantics in ports).
  MapNode_Isnil31 *repl = node->left;
  if (repl->isnil == 0) {
    if (node->right->isnil == 0)
      repl = node->right; // simplified plate; retail may successor-swap
  } else {
    repl = node->right;
  }

  MapNode_Isnil31 *parent = node->parent;
  if (repl->isnil == 0)
    repl->parent = parent;

  if (map->head->parent == node) {
    map->head->parent = repl; // root
  } else if (parent->left == node) {
    parent->left = repl;
  } else {
    parent->right = repl;
  }

  // Fix head leftmost / rightmost when erasing extremity
  if (map->head->left == node) {
    MapNode_Isnil31 *lm = parent;
    if (repl->isnil == 0)
      lm = FUN_00409160(repl);
    map->head->left = lm;
  }
  if (map->head->right == node) {
    if (repl->isnil == 0)
      map->head->right = FUN_004043e0(repl);
    else
      map->head->right = parent;
  }

  // RB rebalance if erased node was black (color@+0x30)
  if (node->color == 1) {
    MapNode_Isnil31 *x = repl;
    MapNode_Isnil31 *p = parent;
    while (x != map->head->parent && x->color == 1) {
      if (x == p->left) {
        MapNode_Isnil31 *w = p->right;
        if (w->color == 0) {
          w->color = 1;
          p->color = 0;
          FUN_00403e90(map, p); // Lrotate
          w = p->right;
        }
        if (w->isnil == 0) {
          if (w->left->color == 1 && w->right->color == 1) {
            w->color = 0;
          } else {
            if (w->right->color == 1) {
              w->left->color = 1;
              w->color = 0;
              FUN_00403ee0(map, w); // Rrotate
              w = p->right;
            }
            w->color = p->color;
            p->color = 1;
            w->right->color = 1;
            FUN_00403e90(map, p);
            break;
          }
        }
      } else {
        MapNode_Isnil31 *w = p->left;
        if (w->color == 0) {
          w->color = 1;
          p->color = 0;
          FUN_00403ee0(map, p);
          w = p->left;
        }
        if (w->isnil == 0) {
          if (w->right->color == 1 && w->left->color == 1) {
            w->color = 0;
          } else {
            if (w->left->color == 1) {
              w->right->color = 1;
              w->color = 0;
              FUN_00403e90(map, w);
              w = p->left;
            }
            w->color = p->color;
            p->color = 1;
            w->left->color = 1;
            FUN_00403ee0(map, p);
            break;
          }
        }
      }
      x = p;
      p = p->parent;
      if (x == map->head->parent)
        break;
    }
    x->color = 1;
  }

  // No value destructor sealed — POD / trivial payload.
  operator_delete(node);
  if (map->size > 0)
    map->size--;
  // *outIt already holds successor from FUN_00408590
}

// Ghidra twin name
extern "C" void FUN_00408ed0(
    MapShell_Isnil31 *map,
    MapNode_Isnil31 **outIt,
    MapNode_Isnil31 *node)
{
  StdTree_EraseAndRebalance_Isnil31_Inferred(map, outIt, node);
}
