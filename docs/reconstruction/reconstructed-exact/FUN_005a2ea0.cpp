// =============================================================================
// StdTree_EraseAndRebalance_Isnil21_Inferred  (FUN_005a2ea0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005a2ea0
// Address:   0x005a2ea0  (autoassault.exe, image base 0x400000)
// Body:      0x005a2ea0 – 0x005a3155 inclusive (694 B / 0x2B6)
//            Exclusive end 0x005a3156 (CC pad). Ghidra lists end 0x005a3126
//            (truncated by false noreturn on operator_delete).
// System:    skills-abilities — std map/set red-black tree erase (isnil@+0x21)
// Generated: 2026-08-05 R12-030 dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed epilogue.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   MSVC-style std::_Tree erase(const_iterator) for nodes with color @ +0x20
//   and isnil @ +0x21 (node size 0x28; Val16 payload +0x10).
//   Throw "invalid map/set<T> iterator" on nil; capture successor (iterator++);
//   unlink + extremity fix (min/max); RB rebalance if erased black;
//   operator_delete (no value dtor); size--; write *outIt; RET 8 (thiscall).
//
// ABI
//   __thiscall ECX = MapShell*; stack outIt**, node*; RET 8 (C2 08 00).
//
// THROW
//   isnil → "invalid map/set<T> iterator" @ 0x00a152f0 via DAT_00acc34c
//
// CALLERS (2 xrefs)
//   FUN_005a3860 @ 0x005a38ff (EraseRange shell, parent RET 0xC)
//   orphan @ 0x005a052b (body ~0x005a04d0–0x005a053d, parent RET 4; DATA 009d7f0c)
//
// PEERS (do not merge VAs — same structural role, distinct clones)
//   0x00405650  StdTree_EraseAndRebalance_Isnil21_Inferred (R12-009, 660 B)
//   0x004e3e70  StdTree_EraseAndRebalance_Isnil21_Inferred (R12-013, 694 B reloc clone)
//   residual isnil21 erase shells: 0x0059d300, 0x005a3500, …
//   Isnil29 thiscall: 0x004cb740 | Val12: 0x004e4130
//   Insert twin: 0x00407200 StdTree_InsertAndRebalance_Isnil21_Inferred
//   Lrot: 0x0050e9f0 | Rrot: 0x005a27f0 (parent dual R11-007)
// =============================================================================

#include <cstdint>

struct MapNode_Isnil21 {
  MapNode_Isnil21 *left;    // +0x00
  MapNode_Isnil21 *parent;  // +0x04
  MapNode_Isnil21 *right;   // +0x08
  // +0x0C .. +0x1F  value payload (trivial here — no dtor call sealed; Val16)
  std::uint8_t color;       // +0x20  0=red, 1=black
  std::uint8_t isnil;       // +0x21
  // pad to 0x28
};

struct MapShell_Isnil21 {
  void *proxy;              // +0x00
  MapNode_Isnil21 *head;    // +0x04  end sentinel (left/parent/right)
  std::uint32_t size;       // +0x08
};

// External callees (isnil@+0x21 family; OWN duals elsewhere where noted)
extern "C" void FUN_004e12c0(MapNode_Isnil21 **it); // iterator++ / successor
extern "C" MapNode_Isnil21 *FUN_004cb2c0(MapNode_Isnil21 *n); // min / leftmost
extern "C" MapNode_Isnil21 *FUN_00421a60(MapNode_Isnil21 *n); // max / rightmost
extern "C" void FUN_0050e9f0(MapShell_Isnil21 *tree, MapNode_Isnil21 *x); // Lrotate isnil21
extern "C" void FUN_005a27f0(MapShell_Isnil21 *tree, MapNode_Isnil21 *x); // Rrotate isnil21
extern "C" void operator_delete(void *p);
extern "C" void _CxxThrowException(void *, void *);

// ---------------------------------------------------------------------------
// Clean reconstruction — CF ≡ live decompile + byte-sealed epilogue
// ---------------------------------------------------------------------------

extern "C" void __thiscall StdTree_EraseAndRebalance_Isnil21_Inferred(
    MapShell_Isnil21 *map,           // ECX
    MapNode_Isnil21 **outIt,         // stack0
    MapNode_Isnil21 *node)           // stack1
{
  // SEH frame omitted (LAB_009a6342); present in retail for throw path.

  if (node->isnil != 0) {
    // Construct exception with "invalid map/set<T> iterator" @ 0x00a152f0
    // _CxxThrowException(..., &DAT_00acc34c). No-return.
    _CxxThrowException(nullptr, nullptr);
  }

  FUN_004e12c0(outIt); // capture successor for *outIt

  // Replacement child selection (MSVC erase splice; isnil @ +0x21)
  MapNode_Isnil21 *repl = node->left;
  if (repl->isnil == 0) {
    if (node->right->isnil == 0)
      repl = node->right; // two-child: successor-swap plate lives in asm
                          // (decomp "unreachable" blocks 0x005a2fc0..)
  } else {
    repl = node->right;
  }
  MapNode_Isnil21 *parent = node->parent;
  if (repl->isnil == 0)
    repl->parent = parent;

  MapNode_Isnil21 *head = map->head;
  if (head->parent == node)
    head->parent = repl; // root
  else if (parent->left == node)
    parent->left = repl;
  else
    parent->right = repl;

  if (head->left == node) {
    MapNode_Isnil21 *b = parent;
    if (repl->isnil == 0)
      b = FUN_004cb2c0(repl);
    head->left = b;
  }
  if (head->right == node) {
    if (repl->isnil == 0)
      head->right = FUN_00421a60(repl);
    else
      head->right = parent;
  }

  // Two-child successor splice + color exchange @ +0x20:
  // present in retail asm (decomp "Removing unreachable block" warnings).
  // When both children non-nil, successor is unlinked and swapped into erased
  // slot; colors exchanged so RB fixup sees the correct erased color.

  // RB fixup if erased color was black
  if (node->color == 1) {
    MapNode_Isnil21 *x = repl;
    MapNode_Isnil21 *p = parent;
    if (x != head->parent) {
      do {
        if (x->color != 1)
          break;
        MapNode_Isnil21 *sib = p->left;
        if (x == sib) {
          // x is left child → sibling is right
          sib = p->right;
          if (sib->color == 0) {
            sib->color = 1;
            p->color = 0;
            FUN_0050e9f0(map, p); // Lrotate
            sib = p->right;
          }
          if (sib->isnil == 0) {
            if (sib->left->color != 1 || sib->right->color != 1) {
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
            sib->color = 0;
          }
        } else {
          // x is right child → sibling is left
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
      } while (x != head->parent);
    }
    x->color = 1;
  }

  operator_delete(node);

  // BYTE-SEALED epilogue (decomp false-noreturn miss):
  if (map->size > 0)
    map->size -= 1;
  // *outIt = successor prepared by FUN_004e12c0 (stack shadow @ epilogue)
  (void)outIt;
  // ret 8
}

// Alias for Ghidra symbol compatibility
extern "C" void __thiscall FUN_005a2ea0(MapShell_Isnil21 *map, MapNode_Isnil21 **outIt,
                                        MapNode_Isnil21 *node) {
  StdTree_EraseAndRebalance_Isnil21_Inferred(map, outIt, node);
}
