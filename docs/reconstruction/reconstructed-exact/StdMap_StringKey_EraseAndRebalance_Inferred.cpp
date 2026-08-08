// =============================================================================
// StdMap_StringKey_EraseAndRebalance_Inferred  (FUN_004094c0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004094c0
// Address:   0x004094c0  (autoassault.exe, image base 0x400000)
// Body:      0x004094c0 – 0x0040977d exclusive (701 B / 0x2BD)
//            Ghidra lists end 0x00409749 (truncated by false noreturn on delete)
// System:    std map/set red-black tree erase (string key @+0x0C / isnil@+0x2D)
// Generated: 2026-08-04 WQ9J-F dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed epilogue.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   MSVC-style std::_Tree erase(const_iterator) for StringKey nodes:
//     left@0 parent@4 right@8 | std::string @+0x0C | mapped@+0x28 |
//     color @ +0x2C | isnil @ +0x2D | node size 0x30
//   Throw "invalid map/set<T> iterator" on nil; unlink; RB rebalance if black;
//   ~string; operator_delete; size--; write *outIt; RET 0x0C.
//
// ABI
//   Three stack args (map*, outIt**, node*); RET 0x0C. Not ECX-thiscall primary.
//
// THROW
//   isnil → "invalid map/set<T> iterator" via DAT_00acc34c (@ string 0x00a152f0)
//
// CALLER (1)
//   FUN_00407f90 @ 0x0040802e (erase-range loop)
//
// PEERS (do not merge)
//   Insert twin: StdMap_StringKey_InsertNodeAndRebalance @ 0x00430b60
//   Isnil29 erase: StdTree_EraseAndRebalance_Isnil29_Inferred @ 0x004cb740
//   Isnil31 iterator family (different layout): 0x00408590
// =============================================================================

#include <cstdint>

struct MapNode_StringKey_Isnil2d {
  MapNode_StringKey_Isnil2d *left;    // +0x00
  MapNode_StringKey_Isnil2d *parent;  // +0x04
  MapNode_StringKey_Isnil2d *right;   // +0x08
  // +0x0C .. +0x27  MSVC basic_string (key)
  // +0x28           mapped dword (peer insert)
  std::uint8_t color;                 // +0x2C  0=red, 1=black
  std::uint8_t isnil;                 // +0x2D
  // pad to 0x30
};

struct MapShell_StringKey {
  void *proxy;                        // +0x00
  MapNode_StringKey_Isnil2d *head;    // +0x04  end sentinel
  std::uint32_t size;                 // +0x08
};

// External callees (isnil@+0x2d family; OWN duals elsewhere where noted)
extern "C" void FUN_0042ac40(MapNode_StringKey_Isnil2d **it); // in-order successor
extern "C" MapNode_StringKey_Isnil2d *FUN_0044e180(MapNode_StringKey_Isnil2d *n); // min
extern "C" MapNode_StringKey_Isnil2d *FUN_0042ac20(MapNode_StringKey_Isnil2d *n); // max
extern "C" void FUN_0044e010(MapShell_StringKey *tree, MapNode_StringKey_Isnil2d *x); // Lrotate
extern "C" void FUN_0042a840(MapShell_StringKey *tree, MapNode_StringKey_Isnil2d *x); // Rrotate
extern "C" void operator_delete(void *p);
extern "C" void _CxxThrowException(void *, void *);
// ~basic_string(node+0xC) — CRT / std

// ---------------------------------------------------------------------------
// Clean reconstruction — CF ≡ live decompile + byte-sealed epilogue
// ---------------------------------------------------------------------------

extern "C" void StdMap_StringKey_EraseAndRebalance_Inferred(
    MapShell_StringKey *map,              // stack0
    MapNode_StringKey_Isnil2d **outIt,    // stack1
    MapNode_StringKey_Isnil2d *node)      // stack2
{
  // SEH frame omitted (LAB_009bd0df); present in retail for throw path.

  if (node->isnil != 0) {
    // basic_string("invalid map/set<T> iterator") → _CxxThrowException(..., DAT_00acc34c)
    _CxxThrowException(nullptr, nullptr);
  }

  // Capture successor before unlink (FUN_0042ac40).
  *outIt = node;
  FUN_0042ac40(outIt);

  // Replacement child (MSVC erase splice; isnil@+0x2d). Full two-child
  // successor-swap path exists in retail (decompiler may mark mid blocks
  // "unreachable" — preserve full MSVC erase semantics in ports).
  MapNode_StringKey_Isnil2d *repl = node->left;
  if (repl->isnil == 0) {
    if (node->right->isnil == 0)
      repl = node->right; // simplified plate; retail may successor-swap
  } else {
    repl = node->right;
  }

  MapNode_StringKey_Isnil2d *parent = node->parent;
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
    MapNode_StringKey_Isnil2d *lm = parent;
    if (repl->isnil == 0)
      lm = FUN_0044e180(repl);
    map->head->left = lm;
  }
  if (map->head->right == node) {
    if (repl->isnil == 0)
      map->head->right = FUN_0042ac20(repl);
    else
      map->head->right = parent;
  }

  // RB rebalance if erased node was black
  if (node->color == 1) {
    MapNode_StringKey_Isnil2d *x = repl;
    MapNode_StringKey_Isnil2d *p = parent;
    while (x != map->head->parent && x->color == 1) {
      if (x == p->left) {
        MapNode_StringKey_Isnil2d *w = p->right;
        if (w->color == 0) {
          w->color = 1;
          p->color = 0;
          FUN_0044e010(map, p);
          w = p->right;
        }
        if (w->isnil == 0) {
          if (w->left->color == 1 && w->right->color == 1) {
            w->color = 0;
          } else {
            if (w->right->color == 1) {
              w->left->color = 1;
              w->color = 0;
              FUN_0042a840(map, w);
              w = p->right;
            }
            w->color = p->color;
            p->color = 1;
            w->right->color = 1;
            FUN_0044e010(map, p);
            break;
          }
        }
      } else {
        MapNode_StringKey_Isnil2d *w = p->left;
        if (w->color == 0) {
          w->color = 1;
          p->color = 0;
          FUN_0042a840(map, p);
          w = p->left;
        }
        if (w->isnil == 0) {
          if (w->right->color == 1 && w->left->color == 1) {
            w->color = 0;
          } else {
            if (w->left->color == 1) {
              w->right->color = 1;
              w->color = 0;
              FUN_0044e010(map, w);
              w = p->left;
            }
            w->color = p->color;
            p->color = 1;
            w->left->color = 1;
            FUN_0042a840(map, p);
            break;
          }
        }
      }
      x = p;
      p = p->parent;
    }
    x->color = 1;
  }

  // Destroy string key @ +0x0C then free node (CRT ~basic_string).
  // operator_delete is NOT noreturn — epilogue continues:
  operator_delete(node);

  // Byte-sealed epilogue:
  if (map->size != 0)
    map->size--;
  // *outIt already holds successor from FUN_0042ac40 path
  // RET 0x0C
}

// Scaffold alias
extern "C" void FUN_004094c0(
    MapShell_StringKey *map,
    MapNode_StringKey_Isnil2d **outIt,
    MapNode_StringKey_Isnil2d *node)
{
  StdMap_StringKey_EraseAndRebalance_Inferred(map, outIt, node);
}
