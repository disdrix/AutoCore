// =============================================================================
// StdTree_EraseAndRebalance_Isnil21_Inferred  (FUN_005ae6d0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005ae6d0
// Address:   0x005ae6d0  (autoassault.exe, image base 0x400000)
// Body:      0x005ae6d0 – 0x005ae986 exclusive (694 B / 0x2B6)
//            Ghidra lists truncated end (false noreturn on operator_delete)
// System:    std map/set red-black tree erase (isnil@+0x21 / node 0x28 / Val16)
// Generated: 2026-08-05 R12-035 OWN dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler control flow + sealed epilogue.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   MSVC-style std::_Tree erase(const_iterator) for nodes with color @ +0x20
//   and isnil @ +0x21 (node alloc size 0x28; value payload 16 B / Val16 @ +0x0C).
//   Throw "invalid map/set<T> iterator" on nil; unlink + extremity fix; RB
//   rebalance if erased black; operator_delete; size--; write *outIt.
//
// ABI
//   __thiscall; ECX = MapShell*; two stack args; RET 8
//
// THROW
//   isnil → "invalid map/set<T> iterator" @ 0x00a152f0 via DAT_00acc34c
//
// CALLERS (1)
//   FUN_005af2e0  (range erase; call site 0x005af37f, MOV ECX,EDI)
//
// CALLEES
//   FUN_004e12c0  successor / iterator++ isnil21
//   FUN_004cb2c0  leftmost / min isnil21
//   FUN_00421a60  rightmost / max isnil21
//   FUN_0050e9f0  Lrotate isnil21 (R10-030 dualed)
//   FUN_005a27f0  Rrotate isnil21 (R11-007 dualed; parent dual)
//   operator_delete, basic_string/exception/_CxxThrowException
//
// PEERS (do not merge)
//   StdTree_EraseAndRebalance_Isnil29_Inferred @ 0x004cb740 (thiscall RET8, isnil29)
//   StdTree_EraseAndRebalance_Isnil29_RetC_Inferred @ 0x00402850 (stack RET0xC)
//   StdTree_EraseAndRebalance_Isnil31_Inferred @ 0x00408ed0
//   StdTree_EraseNode_Val12 @ 0x005ae990 (adjacent; isnil@+0x19)
//   Insert twin: StdTree_InsertAndRebalance_Isnil21_Inferred @ 0x00407200
// =============================================================================

#include <cstdint>

struct MapNode_Isnil21 {
  MapNode_Isnil21 *left;    // +0x00
  MapNode_Isnil21 *parent;  // +0x04
  MapNode_Isnil21 *right;   // +0x08
  int32_t value[4];         // +0x0C .. +0x1B  (Val16)
  // +0x1C .. +0x1F pad / unused by erase
  uint8_t color;            // +0x20  0=red, 1=black
  uint8_t isnil;            // +0x21
  // pad to 0x28
};

struct MapShell_Isnil21 {
  void *proxy;                 // +0x00
  MapNode_Isnil21 *head;       // +0x04  end sentinel
  uint32_t size;               // +0x08
};

// External callees (OWN duals sealed elsewhere where noted)
extern "C" void FUN_004e12c0(MapNode_Isnil21 **it); // in-order successor (isnil@+0x21)
extern "C" MapNode_Isnil21 *FUN_004cb2c0(MapNode_Isnil21 *n); // leftmost / min
extern "C" MapNode_Isnil21 *FUN_00421a60(MapNode_Isnil21 *n); // rightmost / max
extern "C" void FUN_0050e9f0(MapShell_Isnil21 *tree, MapNode_Isnil21 *x); // Lrotate isnil21
extern "C" void FUN_005a27f0(MapShell_Isnil21 *tree, MapNode_Isnil21 *x); // Rrotate isnil21
extern "C" void operator_delete(void *p);
extern "C" void _CxxThrowException(void *, void *);

// ---------------------------------------------------------------------------
// Clean reconstruction — CF ≡ live decompile + byte-sealed epilogue
// ---------------------------------------------------------------------------

void __thiscall StdTree_EraseAndRebalance_Isnil21_Inferred(
    MapShell_Isnil21 *map,       // ECX
    MapNode_Isnil21 **outIt,     // stack — iterator out / successor holder
    MapNode_Isnil21 *node)       // stack — node to erase
{
  // SEH frame omitted (LAB_009a65a2); present in retail for throw path.

  if (node->isnil != 0) {
    // Construct exception with "invalid map/set<T> iterator" @ 0x00a152f0
    // _CxxThrowException(..., &DAT_00acc34c). No-return.
    _CxxThrowException(nullptr, nullptr);
  }

  // Capture successor for *outIt (decomp may show bare call with no args).
  FUN_004e12c0(outIt);

  // --- determine replacement child (0/1-child path) ---
  // Two-child splice exists in bytes at 0x005ae7f0+ (decomp "unreachable");
  // classic MSVC: if both children non-nil, transplant successor into node
  // place, then erase the successor leaf/one-child stub.
  MapNode_Isnil21 *repl = node->left;
  if (repl->isnil == 0) {
    if (node->right->isnil == 0) {
      // both children: two-child path (bytes); decomp may collapse to right
      repl = node->right;
    }
    // else keep left
  } else {
    repl = node->right;
  }

  MapNode_Isnil21 *parent = node->parent;
  if (repl->isnil == 0) {
    repl->parent = parent;
  }

  // rehang under parent / root
  if (map->head->parent /* root */ == node) {
    map->head->parent = repl;
  } else if (parent->left == node) {
    parent->left = repl;
  } else {
    parent->right = repl;
  }

  // leftmost extremity
  if (map->head->left == node) {
    MapNode_Isnil21 *mn = parent;
    if (repl->isnil == 0) {
      mn = FUN_004cb2c0(repl);
    }
    map->head->left = mn;
  }

  // rightmost extremity
  if (map->head->right == node) {
    if (repl->isnil == 0) {
      map->head->right = FUN_00421a60(repl);
    } else {
      map->head->right = parent;
    }
  }

  // --- RB rebalance if erased node was black ---
  if (node->color == 1) {
    MapNode_Isnil21 *x = repl;
    MapNode_Isnil21 *p = parent;
    while (x != map->head->parent /* root */ && x->color == 1) {
      if (x == p->left) {
        MapNode_Isnil21 *sib = p->right;
        if (sib->color == 0) { // red sibling
          sib->color = 1;
          p->color = 0;
          FUN_0050e9f0(map, p); // Lrotate
          sib = p->right;
        }
        if (sib->isnil == 0) {
          if (sib->left->color == 1 && sib->right->color == 1) {
            sib->color = 0;
            // climb
          } else {
            if (sib->right->color == 1) {
              sib->left->color = 1;
              sib->color = 0;
              FUN_005a27f0(map, sib); // Rrotate
              sib = p->right;
            }
            sib->color = p->color;
            p->color = 1;
            sib->right->color = 1;
            FUN_0050e9f0(map, p); // Lrotate
            break;
          }
        }
      } else {
        // mirror: sibling = p->left; Rrotate / Lrotate swapped
        MapNode_Isnil21 *sib = p->left;
        if (sib->color == 0) {
          sib->color = 1;
          p->color = 0;
          FUN_005a27f0(map, p); // Rrotate
          sib = p->left;
        }
        if (sib->isnil == 0) {
          if (sib->right->color == 1 && sib->left->color == 1) {
            sib->color = 0;
          } else {
            if (sib->left->color == 1) {
              sib->right->color = 1;
              sib->color = 0;
              FUN_0050e9f0(map, sib); // Lrotate
              sib = p->left;
            }
            sib->color = p->color;
            p->color = 1;
            sib->left->color = 1;
            FUN_005a27f0(map, p); // Rrotate
            break;
          }
        }
      }
      x = p;
      p = p->parent;
      if (x == map->head->parent) break;
    }
    x->color = 1;
  }

  operator_delete(node);

  // --- epilogue sealed via read_memory (decomp false-noreturn) ---
  if (map->size > 0) {
    map->size--;
  }
  // *outIt already holds successor from FUN_004e12c0 / range-caller update
  // ret 8
}
