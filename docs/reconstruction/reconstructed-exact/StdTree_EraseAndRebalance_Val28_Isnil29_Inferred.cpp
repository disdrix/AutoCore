// =============================================================================
// StdTree_EraseAndRebalance_Val28_Isnil29_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00603830
// Address:   0x00603830  (autoassault.exe, image base 0x400000)
// Body:      0x00603830 – 0x00603b03 exclusive (**723 B** / 0x2D3)
//            Ghidra lists end ~0x00603acf (truncated by false noreturn on delete)
// System:    MSVC std::_Tree erase + RB rebalance (Val28 / isnil@+0x29)
// Generated: 2026-08-04 WQ9E-F dual (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher / not run).
// =============================================================================
//
// PURPOSE:
//   MSVC-style `_Tree::erase(const_iterator)` for nodes with:
//     left@0 parent@4 right@8 | Val28 @+0x0C | color@+0x28 | isnil@+0x29
//     node size **0x2C** (buynode twin FUN_00603b10).
//   Throw "invalid map/set<T> iterator" on nil; advance out-iterator;
//   unlink; rebalance if erased black; destroy mapped heap (vector-like @+0x14);
//   operator_delete(node); size-- (if size>0); *outIt = successor.
//
// ABI:
//   __thiscall; ECX = MapShell* (head@+4, size@+8)
//   stack: (Node** outIt, Node* node); **RET 8**
//
// CALLEES (Isnil29 family dualed peers where noted):
//   FUN_004cb270          — iterator++ / successor into *outIt (isnil@+0x29)
//   StdTree_Min_Isnil29   — FUN_0051b5d0 (leftmost)
//   StdTree_Max_Isnil29   — FUN_00421b50 (rightmost)
//   StdTree_Lrotate_Isnil29 — FUN_004192a0
//   StdTree_Rrotate_Isnil29_Inferred — FUN_004192f0
//   operator_delete
//
// SOLE CALLER: FUN_00604280 (erase-range) @ xref 0x0060431f
//
// Dual: reviews/A|B_aa_00603830_StdTree_EraseAndRebalance_Val28_Isnil29_Inferred.md
// =============================================================================

#include <cstdint>

struct MapNode_Val28_Isnil29 {
  MapNode_Val28_Isnil29* left;    // +0x00
  MapNode_Val28_Isnil29* parent;  // +0x04
  MapNode_Val28_Isnil29* right;   // +0x08
  // Val28 payload @ +0x0C .. +0x27:
  std::int32_t key;               // +0x0C  (int key; compare site FUN_00603f00)
  std::uint32_t mapped0;          // +0x10  (vector-ish prefix / pad)
  void* mapped_heap;              // +0x14  (vector begin*; deleted if non-null)
  std::uint32_t mapped2;          // +0x18
  std::uint32_t mapped3;          // +0x1C
  std::uint32_t mapped4;          // +0x20
  std::uint32_t mapped5;          // +0x24
  std::uint8_t color;             // +0x28  0=red, 1=black
  std::uint8_t isnil;             // +0x29
};

struct MapShell_Val28_Isnil29 {
  void* proxy;                      // +0x00
  MapNode_Val28_Isnil29* head;      // +0x04 sentinel
  std::uint32_t size;               // +0x08
};

// External callees (roles sealed elsewhere / Isnil29 duals)
extern "C" void FUN_004cb270(MapNode_Val28_Isnil29** it); // successor / iterator++
extern "C" MapNode_Val28_Isnil29* FUN_0051b5d0(MapNode_Val28_Isnil29* n); // Min
extern "C" MapNode_Val28_Isnil29* FUN_00421b50(MapNode_Val28_Isnil29* n); // Max
extern "C" void __thiscall FUN_004192a0(void* tree, MapNode_Val28_Isnil29* x); // Lrotate
extern "C" void __thiscall FUN_004192f0(void* tree, MapNode_Val28_Isnil29* x); // Rrotate
extern "C" void operator_delete(void* p);
extern "C" void _CxxThrowException(void*, void*);

// __thiscall
extern "C" void __thiscall StdTree_EraseAndRebalance_Val28_Isnil29_Inferred(
    MapShell_Val28_Isnil29* map,       // ECX
    MapNode_Val28_Isnil29** outIt,     // stack
    MapNode_Val28_Isnil29* node)       // stack
{
  // SEH frame (LAB_009a7ef2) present in retail for throw path — omitted here.

  if (node->isnil != 0) {
    // basic_string("invalid map/set<T> iterator") @ 0x00a152f0
    // + length_error/out_of_range vtbl chain → _CxxThrowException(..., DAT_00acc34c)
    _CxxThrowException(nullptr, nullptr);
  }

  // Capture successor into *outIt before unlink (FUN_004cb270 on outIt holder).
  *outIt = node;
  FUN_004cb270(outIt);

  // Replacement child (MSVC erase splice; isnil@+0x29)
  MapNode_Val28_Isnil29* repl = node->left;
  if (repl->isnil == 0) {
    if (node->right->isnil == 0)
      repl = node->right;
  } else {
    repl = node->right;
  }
  MapNode_Val28_Isnil29* parent = node->parent;
  if (repl->isnil == 0)
    repl->parent = parent;

  MapNode_Val28_Isnil29* head = map->head;
  if (head->parent == node)
    head->parent = repl; // root
  else if (parent->left == node)
    parent->left = repl;
  else
    parent->right = repl;

  // leftmost / rightmost bookkeeping
  if (head->left == node) {
    MapNode_Val28_Isnil29* b = parent;
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

  // If erased node was black → RB fixup while walking to root
  if (node->color == 1) {
    if (repl != head->parent) {
      MapNode_Val28_Isnil29* x = repl;
      MapNode_Val28_Isnil29* p = parent;
      do {
        if (x->color != 1)
          break;
        MapNode_Val28_Isnil29* w;
        if (x == p->left) {
          w = p->right;
          if (w->color == 0) {
            w->color = 1;
            p->color = 0;
            FUN_004192a0(map, p); // Lrotate
            w = p->right;
          }
          if (w->isnil == 0) {
            if (w->left->color != 1 || w->right->color != 1) {
              if (w->right->color == 1) {
                w->left->color = 1;
                w->color = 0;
                FUN_004192f0(map, w); // Rrotate
                w = p->right;
              }
              w->color = p->color;
              p->color = 1;
              w->right->color = 1;
              FUN_004192a0(map, p);
              break;
            }
            w->color = 0; // both children black → recolor and ascend
          }
        } else {
          w = p->left;
          if (w->color == 0) {
            w->color = 1;
            p->color = 0;
            FUN_004192f0(map, p);
            w = p->left;
          }
          if (w->isnil == 0) {
            if (w->right->color == 1 && w->left->color == 1) {
              w->color = 0;
            } else {
              if (w->left->color == 1) {
                w->right->color = 1;
                w->color = 0;
                FUN_004192a0(map, w);
                w = p->left;
              }
              w->color = p->color;
              p->color = 1;
              w->left->color = 1;
              FUN_004192f0(map, p);
              break;
            }
          }
        }
        x = p;
        p = p->parent;
      } while (x != head->parent);
    }
    repl->color = 1;
  }

  // Destroy mapped heap blob (vector begin @ +0x14) then free node
  if (node->mapped_heap != nullptr)
    operator_delete(node->mapped_heap);
  node->mapped_heap = nullptr;
  node->mapped2 = 0;
  node->mapped3 = 0;
  operator_delete(node);

  // size-- if size > 0 (byte seal: cmp size,0 / jbe / add eax,-1 / store)
  if (map->size > 0)
    map->size = map->size - 1;

  // *outIt already holds successor from FUN_004cb270
  (void)outIt;
}

// Legacy symbol alias.
extern "C" void __thiscall FUN_00603830(
    MapShell_Val28_Isnil29* map,
    MapNode_Val28_Isnil29** outIt,
    MapNode_Val28_Isnil29* node)
{
  StdTree_EraseAndRebalance_Val28_Isnil29_Inferred(map, outIt, node);
}
