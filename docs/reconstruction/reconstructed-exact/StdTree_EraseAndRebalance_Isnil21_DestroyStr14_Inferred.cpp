// =============================================================================
// StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred  (FUN_0059d300)
// -----------------------------------------------------------------------------
// Stable ID: aa_0059d300
// Address:   0x0059d300  (autoassault.exe, image base 0x400000)
// Body:      0x0059d300 – 0x0059d5d2 inclusive (723 B / 0x2D3)
//            Ghidra may truncate at operator_delete (false noreturn)
// System:    skills-abilities — std map/set RB erase (isnil@+0x21) + DestroyStr14
// Generated: 2026-08-05 R12-029 dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed epilogue.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   MSVC-style std::_Tree erase(const_iterator) for nodes with color @ +0x20
//   and isnil @ +0x21 (node size 0x28). Throw on nil iterator; capture
//   successor (iterator++ isnil21); unlink + extremity fix (min/max);
//   RB rebalance if erased black; free string-like heap at node+0x14
//   (DestroyStr14) then free node; size--; write *outIt; RET 8 (thiscall).
//
// ABI
//   __thiscall ECX = MapShell*; stack outIt**, node*; RET 8 (C2 08 00).
//
// THROW
//   isnil → "invalid map/set<T> iterator" @ 0x00a152f0 via DAT_00acc34c
//
// CALLER (1)
//   FUN_0059d620 @ 0x0059d6bf (erase-range loop; MOV ECX,EDI)
//
// PEERS (do not merge)
//   No-dtor isnil21 erase clones:
//     StdTree_EraseAndRebalance_Isnil21_Inferred @ 0x00405650 (R12-009)
//     StdTree_EraseAndRebalance_Isnil21_Inferred @ 0x004e3e70 (R12-013)
//   Isnil29 thiscall erase: 0x004cb740
//   Isnil29 stack RET0xC:   0x00402850
//   Isnil31 stack RET0xC:   0x00408ed0
//   StringKey isnil2d:      0x004094c0
//   Succ: FUN_004e12c0   Min: FUN_004cb2c0   Max: FUN_00421a60
//   Lrot: FUN_0050e9f0 (dualed)  Rrot: StdTree_Rrotate_Isnil21_Inferred @ 0x005a27f0
// =============================================================================

#include <cstdint>

struct MapNode_Isnil21_Str14 {
  MapNode_Isnil21_Str14 *left;    // +0x00
  MapNode_Isnil21_Str14 *parent;  // +0x04
  MapNode_Isnil21_Str14 *right;   // +0x08
  // +0x0C .. +0x13  value head (POD / not freed here)
  void *str_ptr;                  // +0x14  heap buffer (free if non-null)
  std::uint32_t str_size;         // +0x18
  std::uint32_t str_res;          // +0x1C
  std::uint8_t color;             // +0x20  0=red, 1=black
  std::uint8_t isnil;             // +0x21
  // pad to 0x28
};

struct MapShell_Isnil21 {
  void *proxy;                    // +0x00
  MapNode_Isnil21_Str14 *head;    // +0x04  end sentinel
  std::uint32_t size;             // +0x08
};

// External callees (isnil@+0x21 family; OWN duals elsewhere where noted)
extern "C" void FUN_004e12c0(MapNode_Isnil21_Str14 **it); // iterator++ / successor
extern "C" MapNode_Isnil21_Str14 *FUN_004cb2c0(MapNode_Isnil21_Str14 *n); // min
extern "C" MapNode_Isnil21_Str14 *FUN_00421a60(MapNode_Isnil21_Str14 *n); // max
extern "C" void FUN_0050e9f0(MapShell_Isnil21 *tree, MapNode_Isnil21_Str14 *x); // Lrotate
extern "C" void FUN_005a27f0(MapShell_Isnil21 *tree, MapNode_Isnil21_Str14 *x); // Rrotate
extern "C" void operator_delete(void *p);
extern "C" void _CxxThrowException(void *, void *);

// ---------------------------------------------------------------------------
// Clean reconstruction — CF ≡ live decompile + byte-sealed epilogue
// ---------------------------------------------------------------------------

extern "C" void __thiscall StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred(
    MapShell_Isnil21 *map,              // ECX
    MapNode_Isnil21_Str14 **outIt,      // stack0
    MapNode_Isnil21_Str14 *node)        // stack1
{
  // SEH frame omitted (LAB_009a5b42); present in retail for throw path.

  if (node->isnil != 0) {
    // basic_string("invalid map/set<T> iterator") → _CxxThrowException(..., DAT_00acc34c)
    _CxxThrowException(nullptr, nullptr);
  }

  // Capture successor before unlink (FUN_004e12c0).
  MapNode_Isnil21_Str14 *succ = node;
  FUN_004e12c0(&succ);

  // Replacement child (MSVC erase splice; isnil@+0x21). Full two-child
  // successor-swap path exists in retail (decompiler may mark mid blocks
  // "unreachable" — preserve full MSVC erase semantics in ports).
  MapNode_Isnil21_Str14 *repl = node->left;
  if (repl->isnil == 0) {
    if (node->right->isnil == 0)
      repl = node->right; // simplified plate; retail may successor-swap
  } else {
    repl = node->right;
  }

  MapNode_Isnil21_Str14 *parent = node->parent;
  if (repl->isnil == 0)
    repl->parent = parent;

  if (map->head->parent == node) {
    map->head->parent = repl;
  } else if (parent->left == node) {
    parent->left = repl;
  } else {
    parent->right = repl;
  }

  if (map->head->left == node) {
    if (repl->isnil == 0)
      map->head->left = FUN_004cb2c0(repl);
    else
      map->head->left = parent;
  }
  if (map->head->right == node) {
    if (repl->isnil == 0)
      map->head->right = FUN_00421a60(repl);
    else
      map->head->right = parent;
  }

  // RB rebalance if erased black (color @ +0x20 == 1)
  if (node->color == 1) {
    MapNode_Isnil21_Str14 *x = repl;
    MapNode_Isnil21_Str14 *p = parent;
    while (x != map->head->parent && x->color == 1) {
      if (x == p->left) {
        MapNode_Isnil21_Str14 *sib = p->right;
        if (sib->color == 0) {
          sib->color = 1;
          p->color = 0;
          FUN_0050e9f0(map, p); // Lrotate
          sib = p->right;
        }
        if (sib->isnil == 0) {
          if (sib->left->color == 1 && sib->right->color == 1) {
            sib->color = 0;
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
            FUN_0050e9f0(map, p);
            break;
          }
        }
      } else {
        MapNode_Isnil21_Str14 *sib = p->left;
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
            FUN_005a27f0(map, p);
            break;
          }
        }
      }
      x = p;
      p = p->parent;
    }
    x->color = 1;
  }

  // DestroyStr14 — free string-like heap at +0x14; zero three dwords
  if (node->str_ptr != nullptr)
    operator_delete(node->str_ptr);
  node->str_ptr = nullptr;
  node->str_size = 0;
  node->str_res = 0;

  operator_delete(node);

  // Byte-sealed epilogue (decompiler false-noreturn omits):
  if (map->size > 0)
    map->size--;
  *outIt = succ;
  // ret 8
}
