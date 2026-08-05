// =============================================================================
// StdTree_EraseAndRebalance_Val12  (FUN_005e15a0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005e15a0
// Address:   0x005e15a0  (autoassault.exe, image base 0x400000)
// Body:      0x005e15a0 – 0x005e1856 exclusive (694 B / 0x2B6)
//            Ghidra lists end 0x005e1826 (truncated by false noreturn on delete)
// System:    std map/set red-black tree erase (Val12 / node 0x1c)
// Generated: 2026-07-29 W30-L dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte epilogue.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   MSVC-style std::_Tree erase(const_iterator) for Val12 nodes.
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
//   FUN_005e1990 (range erase wrapper; xref 0x005e1a2f)
//
// PEERS (same Val12 erase family; do not merge VAs)
//   0x004e4130 StdTree_EraseAndRebalance_Val12 (W27-Q)
//   0x00573250 StdTree_Erase_Val12 (W27-S)
//   0x005399f0 Map_EraseNode_Val12 (W27-R)
//   0x005ae990 StdTree_EraseNode_Val12 (W27-T)
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
  void *proxy;            // +0x00
  MapNode_Val12 *head;    // +0x04  end sentinel; left/root/right extremities
  uint32_t size;          // +0x08
};

// External callees (roles sealed where dualed)
extern "C" void FUN_005ae0b0(); // StdTree_Inc_Val12 — successor prep
extern "C" MapNode_Val12 *FUN_005adfa0(MapNode_Val12 *n); // min / leftmost
extern "C" MapNode_Val12 *FUN_00418bf0(MapNode_Val12 *n); // max / rightmost
extern "C" void FUN_00573170(MapNode_Val12 *node); // StdTree_Lrotate_Val12
extern "C" void FUN_00418c10(MapNode_Val12 *node); // StdTree_Rrotate_Val12
extern "C" void operator_delete(void *p);
extern "C" void _CxxThrowException(void *, void *);

// ---------------------------------------------------------------------------
// Clean reconstruction — control flow ≡ live decompile + byte epilogue
// ---------------------------------------------------------------------------

void __thiscall StdTree_EraseAndRebalance_Val12(
    MapShell_Val12 *map,      // ECX
    MapNode_Val12 **outIt,    // stack — successor out
    MapNode_Val12 *node)      // stack — node to erase
{
  // SEH frame omitted (LAB_009a7402); present in retail for throw path.

  if (node->isnil != 0) {
    // "invalid map/set<T> iterator" @ 0x00a152f0 / DAT_00acc34c — no-return
    _CxxThrowException(nullptr, nullptr);
  }

  FUN_005ae0b0(); // capture successor for *outIt

  // Replacement child selection (MSVC erase splice; isnil @ +0x19)
  MapNode_Val12 *repl = node->left;
  if (repl->isnil == 0) {
    if (node->right->isnil == 0) {
      // both children present — retail walks right subtree for successor transplant
      repl = node->right;
    }
  } else {
    repl = node->right;
  }

  MapNode_Val12 *parent = node->parent;
  if (repl->isnil == 0) {
    repl->parent = parent;
  }

  // Root / parent rewire (head->parent is root)
  if (map->head->parent == node) {
    map->head->parent = repl;
  } else if (parent->left == node) {
    parent->left = repl;
  } else {
    parent->right = repl;
  }

  // Leftmost extremity
  if (map->head->left == node) {
    MapNode_Val12 *lm = parent;
    if (repl->isnil == 0) {
      lm = FUN_005adfa0(repl);
    }
    map->head->left = lm;
  }

  // Rightmost extremity
  if (map->head->right == node) {
    if (repl->isnil == 0) {
      map->head->right = FUN_00418bf0(repl);
    } else {
      map->head->right = parent;
    }
  }

  // If erased black → RB fixup (L/R rotate Val12 family)
  if (node->color == 1 /* black */) {
    MapNode_Val12 *x = repl;
    MapNode_Val12 *p = parent;
    while (x != map->head->parent && x->color == 1) {
      if (x == p->left) {
        MapNode_Val12 *w = p->right;
        if (w->color == 0) {
          w->color = 1;
          p->color = 0;
          FUN_00573170(p);
          w = p->right;
        }
        if (w->isnil == 0) {
          if (w->left->color == 1 && w->right->color == 1) {
            w->color = 0;
          } else {
            if (w->right->color == 1) {
              w->left->color = 1;
              w->color = 0;
              FUN_00418c10(w);
              w = p->right;
            }
            w->color = p->color;
            p->color = 1;
            w->right->color = 1;
            FUN_00573170(p);
            break;
          }
        }
      } else {
        MapNode_Val12 *w = p->left;
        if (w->color == 0) {
          w->color = 1;
          p->color = 0;
          FUN_00418c10(p);
          w = p->left;
        }
        if (w->isnil == 0) {
          if (w->right->color == 1 && w->left->color == 1) {
            w->color = 0;
          } else {
            if (w->left->color == 1) {
              w->right->color = 1;
              w->color = 0;
              FUN_00573170(w);
              w = p->left;
            }
            w->color = p->color;
            p->color = 1;
            w->left->color = 1;
            FUN_00418c10(p);
            break;
          }
        }
      }
      x = p;
      p = p->parent;
    }
    x->color = 1;
  }

  operator_delete(node);

  // BYTE EPILOGUE (decompiler omits as false noreturn on delete):
  if (map->size > 0) {
    map->size--;
  }
  // *outIt = successor (from FUN_005ae0b0 side channel / stack out holder)
  (void)outIt;
  // ret 8
}
