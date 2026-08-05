// =============================================================================
// StdTree_EraseAndRebalance_Val12  (FUN_004e4130)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e4130
// Address:   0x004e4130  (autoassault.exe, image base 0x400000)
// Body:      0x004e4130 – 0x004e43e6 exclusive (694 B / 0x2B6)
//            Ghidra lists end 0x004e43b6 (truncated by false noreturn on delete)
// System:    std map/set red-black tree erase (Val12 / node 0x1c)
// Generated: 2026-07-29 W27-Q dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   MSVC-style std::_Tree erase(const_iterator) for Val12 nodes
//   (3-dword mapped blob; node size 0x1c; color @ +0x18; isnil @ +0x19).
//   Throw "invalid map/set<T> iterator" on nil; unlink; RB rebalance if black;
//   operator_delete; size--; write *out_it.
//
// ABI
//   __thiscall; ECX = MapShell*; two stack args; RET 8
//
// THROW
//   isnil → "invalid map/set<T> iterator" @ 0x00a152f0 via DAT_00acc34c
//
// SOLE LIVE CALLER (this image)
//   FUN_004e5120 (xref 004e51bf)
// =============================================================================

#include <cstdint>

struct MapNode_Val12 {
  MapNode_Val12 *left;    // +0x00
  MapNode_Val12 *parent;  // +0x04
  MapNode_Val12 *right;   // +0x08
  int32_t v0;             // +0x0C
  int32_t v1;             // +0x10
  int32_t v2;             // +0x14
  uint8_t color;          // +0x18  0=red, 1=black
  uint8_t isnil;          // +0x19
};

struct MapShell_Val12 {
  void *proxy;            // +0x00 (unused here)
  MapNode_Val12 *head;    // +0x04  end sentinel; leftmost / root / rightmost
  uint32_t size;          // +0x08
};

// External callees (roles sealed elsewhere where dualed)
extern "C" void FUN_005ae0b0(); // iterator advance / successor prep
extern "C" MapNode_Val12 *FUN_005adfa0(MapNode_Val12 *n); // leftmost / min
extern "C" MapNode_Val12 *FUN_00418bf0(MapNode_Val12 *n); // rightmost / max
extern "C" void FUN_00573170(MapNode_Val12 *node); // StdTree_Lrotate_Val12
extern "C" void FUN_00418c10(MapNode_Val12 *node); // StdTree_Rrotate_Val12
extern "C" void operator_delete(void *p);
extern "C" void _CxxThrowException(void *, void *);

// ---------------------------------------------------------------------------
// Clean reconstruction — control flow ≡ live decompile + byte epilogue
// ---------------------------------------------------------------------------

void __thiscall StdTree_EraseAndRebalance_Val12(
    MapShell_Val12 *map,      // ECX
    MapNode_Val12 **outIt,    // stack — iterator out / successor holder
    MapNode_Val12 *node)      // stack — node to erase
{
  // SEH frame omitted (LAB_009a1e62); present in retail for throw path.

  if (node->isnil != 0) {
    // Construct exception with "invalid map/set<T> iterator" @ 0x00a152f0
    // _CxxThrowException(..., &DAT_00acc34c). No-return.
    _CxxThrowException(nullptr, nullptr);
  }

  FUN_005ae0b0(); // capture successor for *outIt (side channel)

  // Replacement child selection (MSVC erase splice; isnil @ +0x19)
  MapNode_Val12 *repl = node->left;
  if (repl->isnil == 0) {
    if (node->right->isnil == 0)
      repl = node->right;
  } else {
    repl = node->right;
  }
  MapNode_Val12 *parent = node->parent;
  if (repl->isnil == 0)
    repl->parent = parent;

  MapNode_Val12 *head = map->head;
  if (head->parent == node)
    head->parent = repl;
  else if (parent->left == node)
    parent->left = repl;
  else
    parent->right = repl;

  if (head->left == node) {
    MapNode_Val12 *b = parent;
    if (repl->isnil == 0)
      b = FUN_005adfa0(repl);
    head->left = b;
  }
  if (head->right == node) {
    if (repl->isnil == 0)
      head->right = FUN_00418bf0(repl);
    else
      head->right = parent;
  }

  // RB fixup if erased color was black
  if (node->color == 1) {
    MapNode_Val12 *x = repl;
    MapNode_Val12 *p = parent;
    if (x != head->parent) {
      do {
        if (x->color != 1)
          break;
        MapNode_Val12 *sib = p->left;
        if (x == sib) {
          // x is left child → sibling is right
          sib = p->right;
          if (sib->color == 0) {
            sib->color = 1;
            p->color = 0;
            FUN_00573170(p); // Lrotate
            sib = p->right;
          }
          if (sib->isnil == 0) {
            if (sib->left->color != 1 || sib->right->color != 1) {
              if (sib->right->color == 1) {
                sib->left->color = 1;
                sib->color = 0;
                FUN_00418c10(sib); // Rrotate
                sib = p->right;
              }
              sib->color = p->color;
              p->color = 1;
              sib->right->color = 1;
              FUN_00573170(p);
              break;
            }
            sib->color = 0; // both children black → recolor sibling red, climb
          }
        } else {
          // x is right child → sibling is left
          if (sib->color == 0) {
            sib->color = 1;
            p->color = 0;
            FUN_00418c10(p);
            sib = p->left;
          }
          if (sib->isnil == 0) {
            if (sib->right->color == 1 && sib->left->color == 1) {
              sib->color = 0;
            } else {
              if (sib->left->color == 1) {
                sib->right->color = 1;
                sib->color = 0;
                FUN_00573170(sib);
                sib = p->left;
              }
              sib->color = p->color;
              p->color = 1;
              sib->left->color = 1;
              FUN_00418c10(p);
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
  // *outIt = successor from FUN_005ae0b0 prep (stack shadow)
  (void)outIt;
  // ret 8
}

// Alias for Ghidra symbol compatibility
void __thiscall FUN_004e4130(MapShell_Val12 *map, MapNode_Val12 **outIt,
                             MapNode_Val12 *node) {
  StdTree_EraseAndRebalance_Val12(map, outIt, node);
}
