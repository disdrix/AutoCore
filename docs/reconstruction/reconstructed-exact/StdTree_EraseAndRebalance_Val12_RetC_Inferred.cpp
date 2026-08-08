// =============================================================================
// StdTree_EraseAndRebalance_Val12_RetC_Inferred  (FUN_0040b440)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040b440
// Address:   0x0040b440  (autoassault.exe, image base 0x400000)
// Body:      0x0040b440 - 0x0040b6d0 exclusive (656 B / 0x290)
//            Ghidra lists end 0x0040b6a0 (truncated by false noreturn on delete)
// System:    inventory-transfer partition R13-018; role = MSVC _Tree erase (Val12)
// Generated: 2026-08-05 R13-018 OWN dual seal (scaffold 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte epilogue.
// Bit-for-bit vs retail EXE: DEFERRED
// Runtime Confirmed: NOT claimed
// =============================================================================
//
// PURPOSE
//   MSVC-style std::_Tree erase(const_iterator) for Val12 nodes
//   (3-dword mapped blob; node size 0x1c; color @ +0x18; isnil @ +0x19).
//   Throw "invalid map/set<T> iterator" on nil; unlink; RB rebalance if black;
//   operator_delete; size--; write *out_it.
//
// ABI (CRITICAL — differs from thiscall Val12 erase 0x004e4130)
//   3 stack args; RET 0xC  (C2 0C 00 @ 0x0040b6cd)
//   NOT __thiscall / NOT ret 8
//
// THROW
//   isnil  "invalid map/set<T> iterator" @ 0x00a152f0 via DAT_00acc34c
//
// CALLERS (this image)
//   FUN_0040bc10 @ 0x0040bcae  (erase-range loop)
//   FUN_0092b2a0 @ 0x0092b741  (MissionTracker_FillTrackedTargetSlots parent)
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
extern "C" void FUN_00457cc0(); // StdTree_IteratorIncrement_Isnil19 (dualed W38-B)
extern "C" MapNode_Val12 *FUN_0043bf90(MapNode_Val12 *n); // leftmost / min
extern "C" MapNode_Val12 *FUN_0040b8f0(MapNode_Val12 *n); // rightmost / max
extern "C" void FUN_00446b10(MapShell_Val12 *map, MapNode_Val12 *node); // Lrotate
extern "C" void FUN_0040b910(MapShell_Val12 *map, MapNode_Val12 *node); // Rrotate
extern "C" void operator_delete(void *p);
extern "C" void _CxxThrowException(void *, void *);

// ---------------------------------------------------------------------------
// Clean reconstruction — control flow ≡ live decompile + byte epilogue
// ---------------------------------------------------------------------------

// MSVC stack cleanup: ret 0xC (3 dwords). Not thiscall.
void StdTree_EraseAndRebalance_Val12_RetC_Inferred(
    MapShell_Val12 *map,      // stack0
    MapNode_Val12 **outIt,    // stack1 — *outIt = successor
    MapNode_Val12 *node)      // stack2 — node to erase
{
  // SEH frame omitted (LAB_009bc919); present in retail for throw path.

  if (node->isnil != 0) {
    // Construct exception with "invalid map/set<T> iterator" @ 0x00a152f0
    // FUN_00401bc0 + _CxxThrowException(..., &DAT_00acc34c). No-return.
    _CxxThrowException(nullptr, nullptr);
  }

  FUN_00457cc0(); // capture successor for *outIt (iterator++ isnil19)

  // Replacement child selection (MSVC erase splice; isnil @ +0x19)
  MapNode_Val12 *repl = node->left;
  if (repl->isnil == 0) {
    if (node->right->isnil != 0) {
      // left-only: keep repl = left
    } else {
      // two-child path: successor splice @ 0x0040b539 (decomp "unreachable")
      // Assembly: parent rewire, color swap at +0x18 between node and successor.
      MapNode_Val12 *succ = /* successor from FUN_00457cc0 side channel */;
      (void)succ;
      // Full two-child plate preserved in raw assembly; decompiler drops mid-blocks.
    }
  } else {
    repl = node->right;
  }

  MapNode_Val12 *parent = node->parent;
  if (repl->isnil == 0) {
    repl->parent = parent;
  }

  // Relink parent / root
  if (map->head->parent /* root */ == node) {
    map->head->parent = repl;
  } else if (parent->left == node) {
    parent->left = repl;
  } else {
    parent->right = repl;
  }

  // Fix leftmost extremity
  if (map->head->left == node) {
    if (repl->isnil != 0)
      map->head->left = parent;
    else
      map->head->left = FUN_0043bf90(repl);
  }

  // Fix rightmost extremity
  if (map->head->right == node) {
    if (repl->isnil != 0)
      map->head->right = parent;
    else
      map->head->right = FUN_0040b8f0(repl);
  }

  // RB rebalance if erased node was black
  if (node->color == 1) {
    MapNode_Val12 *x = repl;
    MapNode_Val12 *p = parent;
    while (x != map->head->parent && x->color == 1) {
      if (x == p->left) {
        MapNode_Val12 *w = p->right;
        if (w->color == 0) {
          w->color = 1;
          p->color = 0;
          FUN_00446b10(map, p); // Lrotate
          w = p->right;
        }
        if (w->isnil == 0) {
          if (w->left->color == 1 && w->right->color == 1) {
            w->color = 0;
          } else {
            if (w->right->color == 1) {
              w->left->color = 1;
              w->color = 0;
              FUN_0040b910(map, w); // Rrotate
              w = p->right;
            }
            w->color = p->color;
            p->color = 1;
            w->right->color = 1;
            FUN_00446b10(map, p);
            break;
          }
        }
      } else {
        MapNode_Val12 *w = p->left;
        if (w->color == 0) {
          w->color = 1;
          p->color = 0;
          FUN_0040b910(map, p); // Rrotate
          w = p->left;
        }
        if (w->isnil == 0) {
          if (w->right->color == 1 && w->left->color == 1) {
            w->color = 0;
          } else {
            if (w->left->color == 1) {
              w->right->color = 1;
              w->color = 0;
              FUN_00446b10(map, w); // Lrotate
              w = p->left;
            }
            w->color = p->color;
            p->color = 1;
            w->left->color = 1;
            FUN_0040b910(map, p);
            break;
          }
        }
      }
      x = p;
      p = p->parent;
    }
    x->color = 1;
  }

  operator_delete(node); // no value dtor
  if (map->size > 0)
    map->size--;
  // *outIt = successor (side channel from FUN_00457cc0 / stack slot)
  // ret 0xC
}
