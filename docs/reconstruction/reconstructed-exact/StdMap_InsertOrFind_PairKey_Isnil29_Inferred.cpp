// =============================================================================
// StdMap_InsertOrFind_PairKey_Isnil29_Inferred  (Ghidra FUN_004cbee0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cbee0
// Address:   0x004cbee0  (autoassault.exe, image base 0x400000)
// Body:      0x004cbee0–0x004cbfb2 exclusive (210 B / 0xD2)
// System:    MSVC std::map insert-or-find (isnil@+0x29, pair key hi/lo)
// Agent:     WQ9F-D OWN-ONLY dual 2026-08-04
// Exactness: Behavior-preserving; meaningful names. Not modernization.
// Terminal:  false
// =============================================================================

// PURPOSE:
// Unique insert-or-find by pair key: signed hi primary (node+0x14), unsigned lo
// secondary (node+0x10). Same isnil29 insert worker as int-key peer.

#include <cstdint>

struct MapNode_PairKey_Isnil29 {
  MapNode_PairKey_Isnil29 *left;    // +0x00
  MapNode_PairKey_Isnil29 *parent;  // +0x04
  MapNode_PairKey_Isnil29 *right;   // +0x08
  uint32_t key_lo;                 // +0x10  unsigned secondary
  int32_t key_hi;                  // +0x14  signed primary
  // mapped +0x18..+0x24
  uint8_t color;                   // +0x28
  uint8_t isnil;                   // +0x29
};

struct MapShell_Isnil29_Pair {
  MapNode_PairKey_Isnil29 *head;    // +0x04
  uint32_t size;                   // +0x08
};

struct InsertPair_Isnil29_Pair {
  MapNode_PairKey_Isnil29 *it;
  uint8_t inserted;
};

struct Val_PairKey_Isnil29 {
  uint32_t key_lo;  // +0x00
  int32_t key_hi;   // +0x04
  // mapped tail for insert buynode
};

extern "C" MapNode_PairKey_Isnil29 **__thiscall
StdTree_InsertAndRebalance_Isnil29_Inferred(
    MapShell_Isnil29_Pair *map,
    MapNode_PairKey_Isnil29 **outIt,
    char addLeft,
    MapNode_PairKey_Isnil29 *where,
    const Val_PairKey_Isnil29 *value);

extern "C" void __fastcall FUN_004cb4f0(MapNode_PairKey_Isnil29 **pNode);

// node <= key  (go right / not goLeft)
static inline bool NodeLeKey(const MapNode_PairKey_Isnil29 *n,
                             const Val_PairKey_Isnil29 *k)
{
  if (n->key_hi < k->key_hi) return true;
  if (n->key_hi > k->key_hi) return false;
  return n->key_lo <= k->key_lo; // unsigned
}

// node < key  (strict; miss after lower-bound)
static inline bool NodeLtKey(const MapNode_PairKey_Isnil29 *n,
                             const Val_PairKey_Isnil29 *k)
{
  if (n->key_hi < k->key_hi) return true;
  if (n->key_hi > k->key_hi) return false;
  return n->key_lo < k->key_lo; // unsigned
}

void __thiscall StdMap_InsertOrFind_PairKey_Isnil29_Inferred(
    MapShell_Isnil29_Pair *map,
    InsertPair_Isnil29_Pair *out,
    const Val_PairKey_Isnil29 *value)
// RET 8
{
  MapNode_PairKey_Isnil29 *head = map->head;
  MapNode_PairKey_Isnil29 *where = head;
  bool goLeft = true;
  char addLeft = 1;

  MapNode_PairKey_Isnil29 *node = head->parent;
  if (node->isnil == 0) {
    MapNode_PairKey_Isnil29 *child = node;
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

  MapNode_PairKey_Isnil29 *hint = where;

  if (goLeft) {
    if (where == *reinterpret_cast<MapNode_PairKey_Isnil29 **>(head)) {
      MapNode_PairKey_Isnil29 *tmp = where;
      MapNode_PairKey_Isnil29 **pNew =
          StdTree_InsertAndRebalance_Isnil29_Inferred(map, &tmp, 1, where, value);
      out->it = *pNew;
      out->inserted = 1;
      return;
    }
    FUN_004cb4f0(&hint);
  }

  if (NodeLtKey(hint, value)) {
    MapNode_PairKey_Isnil29 *tmp = where;
    MapNode_PairKey_Isnil29 **pNew =
        StdTree_InsertAndRebalance_Isnil29_Inferred(map, &tmp, addLeft, where, value);
    out->it = *pNew;
    out->inserted = 1;
    return;
  }

  out->inserted = 0;
  out->it = hint;
}

void __thiscall FUN_004cbee0(
    MapShell_Isnil29_Pair *map,
    InsertPair_Isnil29_Pair *out,
    const Val_PairKey_Isnil29 *value)
{
  StdMap_InsertOrFind_PairKey_Isnil29_Inferred(map, out, value);
}
