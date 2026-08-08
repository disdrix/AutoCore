// =============================================================================
// StdMap_InsertOrFind_PairKey_Isnil21_Inferred  (Ghidra FUN_00407060)
// -----------------------------------------------------------------------------
// Stable ID: aa_00407060
// Address:   0x00407060  (autoassault.exe, image base 0x400000)
// Body:      0x00407060–0x00407133 exclusive (211 B / 0xD3)
// System:    MSVC std::map insert-or-find (isnil@+0x21, pair key hi/lo)
// Agent:     WQ9I-C OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving; meaningful names. Not modernization.
// Terminal:  false
// =============================================================================

// PURPOSE:
// Unique insert-or-find by pair key for the isnil@+0x21 / Val16 node family:
// signed hi primary (node+0x14 / value+4), unsigned lo secondary (node+0x10 /
// value+0). Equal hit returns {it,0} without rewriting mapped payload.
// Insert path uses always-insert/rebalance FUN_00407200; left-walk non-begin
// path runs predecessor FUN_005adff0.
//
// Peer: StdMap_InsertOrFind_PairKey_Isnil29_Inferred (0x004cbee0) — same compare
// order, isnil@+0x29 / larger node. Caller: dualed InsertHint 0x00406560.

#include <cstdint>

struct MapNode_PairKey_Isnil21 {
  MapNode_PairKey_Isnil21 *left;    // +0x00
  MapNode_PairKey_Isnil21 *parent;  // +0x04
  MapNode_PairKey_Isnil21 *right;   // +0x08
  // +0x0C unused on this path
  uint32_t key_lo;                 // +0x10  unsigned secondary
  int32_t key_hi;                  // +0x14  signed primary
  // mapped +0x18..+0x1c (Val16 total 0x10 from +0x10)
  uint8_t color;                   // +0x20
  uint8_t isnil;                   // +0x21
};

struct MapShell_Isnil21_Pair {
  // +0x00 vtbl or owner (unused here)
  MapNode_PairKey_Isnil21 *head;   // +0x04
  uint32_t size;                   // +0x08
};

struct InsertPair_Isnil21 {
  MapNode_PairKey_Isnil21 *it;
  uint8_t inserted;                // stored at out+4
};

struct Val_PairKey_Isnil21 {
  uint32_t key_lo;                 // +0x00
  int32_t key_hi;                  // +0x04
  // mapped tail for insert buynode (Val16 total)
};

// Always-insert + rebalance (WQ9I-B OWN residual). RET 0x10 style via out*.
extern "C" MapNode_PairKey_Isnil21 **__thiscall FUN_00407200(
    MapShell_Isnil21_Pair *map,
    MapNode_PairKey_Isnil21 **outIt,
    char addLeft,
    MapNode_PairKey_Isnil21 *where,
    const Val_PairKey_Isnil21 *value);

// Tree predecessor (isnil21 family residual). Updates *pNode.
extern "C" void FUN_005adff0(MapNode_PairKey_Isnil21 **pNode);

// node <= key  (go right / not goLeft)
static inline bool NodeLeKey(const MapNode_PairKey_Isnil21 *n,
                             const Val_PairKey_Isnil21 *k)
{
  if (n->key_hi < k->key_hi) return true;
  if (n->key_hi > k->key_hi) return false;
  return n->key_lo <= k->key_lo; // unsigned
}

// node < key  (strict; miss after lower-bound)
static inline bool NodeLtKey(const MapNode_PairKey_Isnil21 *n,
                             const Val_PairKey_Isnil21 *k)
{
  if (n->key_hi < k->key_hi) return true;
  if (n->key_hi > k->key_hi) return false;
  return n->key_lo < k->key_lo; // unsigned
}

// __thiscall RET 0x8
void __thiscall StdMap_InsertOrFind_PairKey_Isnil21_Inferred(
    MapShell_Isnil21_Pair *map,
    InsertPair_Isnil21 *out,
    const Val_PairKey_Isnil21 *value)
{
  MapNode_PairKey_Isnil21 *head = map->head;
  MapNode_PairKey_Isnil21 *where = head;
  bool goLeft = true;
  char addLeft = 1;

  MapNode_PairKey_Isnil21 *node = head->parent;
  if (node->isnil == 0) {
    MapNode_PairKey_Isnil21 *child = node;
    do {
      where = child;
      if (NodeLeKey(where, value)) {
        child = where->right;
        goLeft = false;
        addLeft = 0;
      } else {
        child = where->left;
        goLeft = true;
        addLeft = 1;
      }
    } while (child->isnil == 0);
  }

  MapNode_PairKey_Isnil21 *hint = where;

  if (goLeft) {
    // head->left is leftmost / begin
    if (where == *reinterpret_cast<MapNode_PairKey_Isnil21 **>(head)) {
      MapNode_PairKey_Isnil21 *tmp = where;
      MapNode_PairKey_Isnil21 **pNew =
          FUN_00407200(map, &tmp, 1, where, value);
      out->it = *pNew;
      out->inserted = 1;
      return;
    }
    FUN_005adff0(&hint);
  }

  if (NodeLtKey(hint, value)) {
    MapNode_PairKey_Isnil21 *tmp = where;
    MapNode_PairKey_Isnil21 **pNew =
        FUN_00407200(map, &tmp, addLeft, where, value);
    out->it = *pNew;
    out->inserted = 1;
    return;
  }

  out->inserted = 0;
  out->it = hint;
}

// Scaffold alias
extern "C" void __thiscall FUN_00407060(
    MapShell_Isnil21_Pair *map,
    InsertPair_Isnil21 *out,
    const Val_PairKey_Isnil21 *value)
{
  StdMap_InsertOrFind_PairKey_Isnil21_Inferred(map, out, value);
}
