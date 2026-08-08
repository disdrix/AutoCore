// =============================================================================
// StdTree_EraseAndRebalance_Isnil29_Inferred  (FUN_004cb740)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cb740
// Address:   0x004cb740  (autoassault.exe, image base 0x400000)
// Body:      0x004cb740 – 0x004cb9f5 exclusive (693 B / 0x2B5)
//            Ghidra lists end 0x004cb9c6 (truncated by false noreturn on delete)
// System:    std map/set red-black tree erase (isnil@+0x29 / node 0x30)
// Generated: 2026-08-04 WQ9E-E dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler control flow + sealed epilogue.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   MSVC-style std::_Tree erase(const_iterator) for nodes with color @ +0x28
//   and isnil @ +0x29 (node alloc size 0x30; value payload 6 dwords @ +0x10).
//   Throw "invalid map/set<T> iterator" on nil; unlink; RB rebalance if black;
//   operator_delete; size--; write *outIt.
//
// ABI
//   __thiscall; ECX = MapShell*; two stack args; RET 8
//
// THROW
//   isnil → "invalid map/set<T> iterator" via DAT_00acc34c
//
// CALLERS (3)
//   FUN_004c8610, FUN_004c8780, FUN_004cbaa0
//
// PEERS (do not merge)
//   StdTree_EraseAndRebalance_Val12 @ 0x004e4130 (isnil@+0x19)
//   Insert twin: StdTree_InsertAndRebalance_Isnil29_Inferred @ 0x004cbb60
// =============================================================================

#include <cstdint>

struct MapNode_Isnil29 {
  MapNode_Isnil29 *left;    // +0x00
  MapNode_Isnil29 *parent;  // +0x04
  MapNode_Isnil29 *right;   // +0x08
  // +0x0C unwritten by peery buynode; value starts +0x10
  int32_t v[6];             // +0x10 .. +0x27
  uint8_t color;            // +0x28  0=red, 1=black
  uint8_t isnil;            // +0x29
  // pad to 0x30
};

struct MapShell_Isnil29 {
  void *proxy;                 // +0x00
  MapNode_Isnil29 *head;       // +0x04  end sentinel
  uint32_t size;               // +0x08
};

// External callees (OWN duals sealed elsewhere where noted)
extern "C" void FUN_004cb270(MapNode_Isnil29 **it); // in-order successor (isnil@+0x29)
extern "C" MapNode_Isnil29 *FUN_0051b5d0(MapNode_Isnil29 *n); // leftmost / min (WQ9D-B)
extern "C" MapNode_Isnil29 *FUN_00421b50(MapNode_Isnil29 *n); // rightmost / max (WQ9D-G)
extern "C" void FUN_004192a0(MapShell_Isnil29 *tree, MapNode_Isnil29 *x); // Lrotate isnil29
extern "C" void FUN_004192f0(MapShell_Isnil29 *tree, MapNode_Isnil29 *x); // Rrotate isnil29 (WQ9D-D)
extern "C" void operator_delete(void *p);
extern "C" void _CxxThrowException(void *, void *);

// ---------------------------------------------------------------------------
// Clean reconstruction — CF ≡ live decompile + byte-sealed epilogue
// ---------------------------------------------------------------------------

void __thiscall StdTree_EraseAndRebalance_Isnil29_Inferred(
    MapShell_Isnil29 *map,       // ECX
    MapNode_Isnil29 **outIt,     // stack — iterator out / successor holder
    MapNode_Isnil29 *node)       // stack — node to erase
{
  // SEH frame omitted (LAB_009a1e42); present in retail for throw path.

  if (node->isnil != 0) {
    // Construct exception with "invalid map/set<T> iterator"
    // _CxxThrowException(..., &DAT_00acc34c). No-return.
    _CxxThrowException(nullptr, nullptr);
  }

  FUN_004cb270(outIt); // capture successor for *outIt (side channel / shadow)

  // Replacement child selection (MSVC erase splice; isnil @ +0x29)
  MapNode_Isnil29 *repl = node->left;
  if (repl->isnil == 0) {
    if (node->right->isnil == 0)
      repl = node->right;
  } else {
    repl = node->right;
  }
  MapNode_Isnil29 *parent = node->parent;
  if (repl->isnil == 0)
    repl->parent = parent;

  MapNode_Isnil29 *head = map->head;
  if (head->parent == node)
    head->parent = repl;
  else if (parent->left == node)
    parent->left = repl;
  else
    parent->right = repl;

  if (head->left == node) {
    MapNode_Isnil29 *b = parent;
    if (repl->isnil == 0)
      b = FUN_0051b5d0(repl);
    head->left = b;
  }
  if (head->right == node) {
    if (repl->isnil == 0)
      head->right = FUN_00421b50(repl);
    else
      head->right = parent;
  }

  // RB fixup if erased color was black
  if (node->color == 1) {
    MapNode_Isnil29 *x = repl;
    MapNode_Isnil29 *p = parent;
    if (x != head->parent) {
      do {
        if (x->color != 1)
          break;
        MapNode_Isnil29 *sib = p->left;
        if (x == sib) {
          // x is left child → sibling is right
          sib = p->right;
          if (sib->color == 0) {
            sib->color = 1;
            p->color = 0;
            FUN_004192a0(map, p); // Lrotate
            sib = p->right;
          }
          if (sib->isnil == 0) {
            if (sib->left->color != 1 || sib->right->color != 1) {
              if (sib->right->color == 1) {
                sib->left->color = 1;
                sib->color = 0;
                FUN_004192f0(map, sib); // Rrotate
                sib = p->right;
              }
              sib->color = p->color;
              p->color = 1;
              sib->right->color = 1;
              FUN_004192a0(map, p); // Lrotate
              break;
            }
            sib->color = 0;
          }
        } else {
          // x is right child → sibling is left
          if (sib->color == 0) {
            sib->color = 1;
            p->color = 0;
            FUN_004192f0(map, p); // Rrotate
            sib = p->left;
          }
          if (sib->isnil == 0) {
            if (sib->right->color == 1 && sib->left->color == 1) {
              sib->color = 0;
            } else {
              if (sib->left->color == 1) {
                sib->right->color = 1;
                sib->color = 0;
                FUN_004192a0(map, sib); // Lrotate
                sib = p->left;
              }
              sib->color = p->color;
              p->color = 1;
              sib->left->color = 1;
              FUN_004192f0(map, p); // Rrotate
              break;
            }
          }
        }
        x = p;
        p = p->parent;
      } while (x != head->parent);
    }
    x->color = 1;
  }

  operator_delete(node);
  // BYTE-SEALED epilogue (decomp false-noreturn miss):
  if (map->size > 0)
    map->size -= 1;
  // *outIt = successor prepared by FUN_004cb270 (stack shadow)
  (void)outIt;
  // ret 8
}

// Alias for Ghidra symbol compatibility
void __thiscall FUN_004cb740(MapShell_Isnil29 *map, MapNode_Isnil29 **outIt,
                             MapNode_Isnil29 *node) {
  StdTree_EraseAndRebalance_Isnil29_Inferred(map, outIt, node);
}
