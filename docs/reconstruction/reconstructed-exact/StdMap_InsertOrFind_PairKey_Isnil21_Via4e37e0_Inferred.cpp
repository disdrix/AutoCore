// =============================================================================
// StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred  (Ghidra FUN_004e48b0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e48b0
// Address:   0x004e48b0  (autoassault.exe, image base 0x400000)
// Body:      0x004e48b0–0x004e4983 exclusive (211 B / 0xD3)
// System:    skills-abilities / MSVC std::map insert-or-find
// Agent:     R13-005 OWN-ONLY dual 2026-08-05 (dual start 2686)
// Parent:    0x004e37e0 StdTree_InsertAndRebalance_Val16_Isnil21_Inferred
// Exactness: Behavior-preserving; meaningful names. Not modernization.
// Terminal:  false — never Runtime Confirmed
// =============================================================================

// PURPOSE:
// Unique insert-or-find by pair key for the isnil@+0x21 / Val16 node family:
// signed hi primary (node+0x14 / value+4), unsigned lo secondary (node+0x10 /
// value+0). Equal hit returns {it,0} without rewriting mapped payload.
// Insert path uses dualed always-insert/rebalance FUN_004e37e0; left-walk
// non-begin path runs residual predecessor FUN_005adff0.
//
// Peer clone (do NOT merge): StdMap_InsertOrFind_PairKey_Isnil21_Inferred
// (0x00407060) — same CF/size/compare; insert via FUN_00407200.
// Peer family: StdMap_InsertOrFind_PairKey_Isnil29_Inferred (0x004cbee0).
// Callers: CVOGReaction_UpdateRepairStationPosition; residual FUN_004da160.

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
  // +0x00 unused here
  MapNode_PairKey_Isnil21 *head;   // +0x04
  uint32_t size;                   // +0x08 (owned by insert worker)
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

// Dualed R12-012: always-insert + rebalance Val16 / isnil21. RET 0x10.
extern "C" MapNode_PairKey_Isnil21 **__thiscall FUN_004e37e0(
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
void __thiscall StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred(
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
          FUN_004e37e0(map, &tmp, 1, where, value);
      out->it = *pNew;
      out->inserted = 1;
      return;
    }
    FUN_005adff0(&hint);
  }

  if (NodeLtKey(hint, value)) {
    MapNode_PairKey_Isnil21 *tmp = where;
    MapNode_PairKey_Isnil21 **pNew =
        FUN_004e37e0(map, &tmp, addLeft, where, value);
    out->it = *pNew;
    out->inserted = 1;
    return;
  }

  out->inserted = 0;
  out->it = hint;
}
