// =============================================================================
// StdMap_InsertOrFind_IntKey_Isnil29_Inferred  (Ghidra FUN_004cbe20)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cbe20
// Address:   0x004cbe20  (autoassault.exe, image base 0x400000)
// Body:      0x004cbe20–0x004cbed8 exclusive (184 B / 0xB8)
// System:    MSVC std::map insert-or-find (isnil@+0x29, signed int key)
// Agent:     WQ9F-D OWN-ONLY dual 2026-08-04
// Exactness: Behavior-preserving; meaningful names. Not modernization.
// Terminal:  false (no runtime Confirmed)
// =============================================================================

// PURPOSE:
// Unique insert-or-find by signed int32 key at value[0] / node+0x10.
// Miss → StdTree_InsertAndRebalance_Isnil29_Inferred; hit → {it, false}, no rewrite.

#include <cstdint>

struct MapNode_Isnil29 {
  MapNode_Isnil29 *left;    // +0x00
  MapNode_Isnil29 *parent;  // +0x04
  MapNode_Isnil29 *right;   // +0x08
  // +0x0C pad/unused in this walk
  int32_t key;              // +0x10  (value dword0)
  // mapped dwords +0x14..+0x24 (copied by insert buynode; not rewritten on hit)
  uint8_t color;            // +0x28
  uint8_t isnil;            // +0x29
};

struct MapShell_Isnil29 {
  // +0x00 unused here
  MapNode_Isnil29 *head;    // +0x04  sentinel; leftmost = *head, root = head->parent
  uint32_t size;            // +0x08
};

struct InsertPair_Isnil29 {
  MapNode_Isnil29 *it;      // +0x00
  uint8_t inserted;         // +0x04 (bool)
};

struct Val_IntKey_Isnil29 {
  int32_t key;              // +0x00 → node+0x10
  // remaining mapped payload for insert (buynode copies 6 dwords into node+0x10)
};

// Dualed always-insert + RB (WQ9E-E): RET 0x10
extern "C" MapNode_Isnil29 **__thiscall
StdTree_InsertAndRebalance_Isnil29_Inferred(
    MapShell_Isnil29 *map,
    MapNode_Isnil29 **outIt,
    char addLeft,
    MapNode_Isnil29 *where,
    const Val_IntKey_Isnil29 *value);

// Tree predecessor (iterator --); residual undualed
extern "C" void __fastcall FUN_004cb4f0(MapNode_Isnil29 **pNode);

void __thiscall StdMap_InsertOrFind_IntKey_Isnil29_Inferred(
    MapShell_Isnil29 *map,             // ECX
    InsertPair_Isnil29 *out,           // stack +4
    const Val_IntKey_Isnil29 *value)   // stack +8
// RET 8
{
  MapNode_Isnil29 *head = map->head;
  MapNode_Isnil29 *where = head;
  bool goLeft = true;

  MapNode_Isnil29 *node = head->parent; // root
  if (node->isnil == 0) {
    MapNode_Isnil29 *child = node;
    do {
      where = child;
      goLeft = (value->key < where->key); // signed SETL
      if (goLeft) {
        child = where->left;
      } else {
        child = where->right;
      }
    } while (child->isnil == 0);
  }

  MapNode_Isnil29 *hint = where;

  if (goLeft) {
    // leftmost of map is *head (sentinel left link)
    if (where == *reinterpret_cast<MapNode_Isnil29 **>(head)) {
      MapNode_Isnil29 *tmp = where;
      MapNode_Isnil29 **pNew =
          StdTree_InsertAndRebalance_Isnil29_Inferred(map, &tmp, 1, where, value);
      out->it = *pNew;
      out->inserted = 1;
      return;
    }
    FUN_004cb4f0(&hint);
  }

  if (hint->key < value->key) {
    MapNode_Isnil29 *tmp = where;
    MapNode_Isnil29 **pNew =
        StdTree_InsertAndRebalance_Isnil29_Inferred(
            map, &tmp, static_cast<char>(goLeft), where, value);
    out->it = *pNew;
    out->inserted = 1;
    return;
  }

  // equal key — keep existing; do not rewrite mapped payload
  out->inserted = 0;
  out->it = hint;
}

// Twin export for Ghidra symbol path
void __thiscall FUN_004cbe20(
    MapShell_Isnil29 *map,
    InsertPair_Isnil29 *out,
    const Val_IntKey_Isnil29 *value)
{
  StdMap_InsertOrFind_IntKey_Isnil29_Inferred(map, out, value);
}
