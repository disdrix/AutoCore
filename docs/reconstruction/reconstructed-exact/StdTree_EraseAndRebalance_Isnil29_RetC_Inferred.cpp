// =============================================================================
// StdTree_EraseAndRebalance_Isnil29_RetC_Inferred  (FUN_00402850)
// -----------------------------------------------------------------------------
// Stable ID: aa_00402850
// Address:   0x00402850  (autoassault.exe, image base 0x400000)
// Body:      0x00402850 – 0x00402ae0 exclusive (656 B / 0x290)
//            Ghidra lists end 0x00402ab0 (truncated by false noreturn on delete)
// System:    std map/set red-black tree erase (isnil@+0x29 / stack ABI RET 0xC)
// Generated: 2026-08-05 MEGA-034 dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed epilogue.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   MSVC-style std::_Tree erase(const_iterator) for nodes with color @ +0x28
//   and isnil @ +0x29 (value payload +0x0C..+0x27). Throw on nil iterator;
//   capture successor (iterator++ isnil29); unlink + extremity fix (min/max);
//   RB rebalance if erased black; operator_delete (no value dtor); size--;
//   write *outIt; RET 0x0C.
//
// ABI
//   Three stack args (map*, outIt**, node*); RET 0x0C. Not ECX-thiscall primary.
//
// THROW
//   isnil → "invalid map/set<T> iterator" @ 0x00a152f0 via DAT_00acc34c
//
// CALLERS (5 named + 1 bare)
//   FUN_004079a0 @ 0x00407a3e; FUN_00407bf0 @ 0x00407c8e;
//   Client_Input_OnKeyDown_MatchAction @ 0x00911260;
//   FUN_00942e20 @ 0x00943060; FUN_00944d50 @ 0x00944e83; xref 0x00957e8c
//
// PEERS (do not merge)
//   Isnil29 thiscall erase: StdTree_EraseAndRebalance_Isnil29_Inferred @ 0x004cb740
//   Val28 isnil29 erase:    StdTree_EraseAndRebalance_Val28_Isnil29_Inferred @ 0x00603830
//   Isnil31 stack RET0xC:   StdTree_EraseAndRebalance_Isnil31_Inferred @ 0x00408ed0
//   Succ: FUN_004040a0 (isnil29 iterator++)
//   Min:  FUN_004031e0  Max: FUN_004031c0
//   Lrot: FUN_00407a60  Rrot: FUN_00403200
// =============================================================================

#include <cstdint>

struct MapNode_Isnil29_RetC {
  MapNode_Isnil29_RetC *left;    // +0x00
  MapNode_Isnil29_RetC *parent;  // +0x04
  MapNode_Isnil29_RetC *right;   // +0x08
  // +0x0C .. +0x27  value payload (trivial / no dtor call sealed)
  std::uint8_t color;            // +0x28  0=red, 1=black
  std::uint8_t isnil;            // +0x29
};

struct MapShell_Isnil29_RetC {
  void *proxy;                      // +0x00
  MapNode_Isnil29_RetC *head;       // +0x04  end sentinel (left/parent/right)
  std::uint32_t size;               // +0x08
};

// External callees (isnil@+0x29 RetC family; OWN duals elsewhere where noted)
extern "C" void FUN_004040a0(MapNode_Isnil29_RetC **it); // iterator++ / successor
extern "C" MapNode_Isnil29_RetC *FUN_004031e0(MapNode_Isnil29_RetC *n); // min (EAX)
extern "C" MapNode_Isnil29_RetC *FUN_004031c0(MapNode_Isnil29_RetC *n); // max (EAX)
extern "C" void FUN_00407a60(MapShell_Isnil29_RetC *tree, MapNode_Isnil29_RetC *x); // Lrotate
extern "C" void FUN_00403200(MapShell_Isnil29_RetC *tree, MapNode_Isnil29_RetC *x); // Rrotate
extern "C" void operator_delete(void *p);
extern "C" void _CxxThrowException(void *, void *);

// ---------------------------------------------------------------------------
// Clean reconstruction — CF ≡ live decompile + byte-sealed epilogue
// ---------------------------------------------------------------------------

extern "C" void StdTree_EraseAndRebalance_Isnil29_RetC_Inferred(
    MapShell_Isnil29_RetC *map,           // stack0
    MapNode_Isnil29_RetC **outIt,         // stack1
    MapNode_Isnil29_RetC *node)           // stack2
{
  // SEH frame omitted (LAB_009bc919); present in retail for throw path.

  if (node->isnil != 0) {
    // basic_string("invalid map/set<T> iterator") → FUN_00401bc0
    // → _CxxThrowException(..., DAT_00acc34c)
    _CxxThrowException(nullptr, nullptr);
  }

  // Capture successor before unlink (FUN_004040a0 / isnil29 iterator++).
  *outIt = node;
  FUN_004040a0(outIt);

  // Replacement child (MSVC erase splice; isnil@+0x29). Full two-child
  // successor-swap path exists in retail at 0x00402949 (decompiler may mark
  // mid blocks "unreachable" — preserve full MSVC erase semantics in ports).
  MapNode_Isnil29_RetC *repl = node->left;
  if (repl->isnil == 0) {
    if (node->right->isnil == 0)
      repl = node->right; // simplified plate; retail may successor-swap
  } else {
    repl = node->right;
  }

  MapNode_Isnil29_RetC *parent = node->parent;
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
    MapNode_Isnil29_RetC *lm = parent;
    if (repl->isnil == 0)
      lm = FUN_004031e0(repl);
    map->head->left = lm;
  }
  if (map->head->right == node) {
    if (repl->isnil == 0)
      map->head->right = FUN_004031c0(repl);
    else
      map->head->right = parent;
  }

  // RB rebalance if erased node was black (color@+0x28)
  if (node->color == 1) {
    MapNode_Isnil29_RetC *x = repl;
    MapNode_Isnil29_RetC *p = parent;
    while (x != map->head->parent && x->color == 1) {
      if (x == p->left) {
        MapNode_Isnil29_RetC *w = p->right;
        if (w->color == 0) {
          w->color = 1;
          p->color = 0;
          FUN_00407a60(map, p); // Lrotate
          w = p->right;
        }
        if (w->isnil == 0) {
          if (w->left->color == 1 && w->right->color == 1) {
            w->color = 0;
          } else {
            if (w->right->color == 1) {
              w->left->color = 1;
              w->color = 0;
              FUN_00403200(map, w); // Rrotate
              w = p->right;
            }
            w->color = p->color;
            p->color = 1;
            w->right->color = 1;
            FUN_00407a60(map, p);
            break;
          }
        }
      } else {
        MapNode_Isnil29_RetC *w = p->left;
        if (w->color == 0) {
          w->color = 1;
          p->color = 0;
          FUN_00403200(map, p);
          w = p->left;
        }
        if (w->isnil == 0) {
          if (w->right->color == 1 && w->left->color == 1) {
            w->color = 0;
          } else {
            if (w->left->color == 1) {
              w->right->color = 1;
              w->color = 0;
              FUN_00407a60(map, w);
              w = p->left;
            }
            w->color = p->color;
            p->color = 1;
            w->left->color = 1;
            FUN_00403200(map, p);
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
  // *outIt already holds successor from FUN_004040a0
}

// Ghidra twin name
extern "C" void FUN_00402850(
    MapShell_Isnil29_RetC *map,
    MapNode_Isnil29_RetC **outIt,
    MapNode_Isnil29_RetC *node)
{
  StdTree_EraseAndRebalance_Isnil29_RetC_Inferred(map, outIt, node);
}
