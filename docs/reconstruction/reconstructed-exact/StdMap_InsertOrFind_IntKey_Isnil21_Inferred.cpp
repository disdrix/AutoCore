// =============================================================================
// StdMap_InsertOrFind_IntKey_Isnil21_Inferred  (Ghidra FUN_00511b40)
// -----------------------------------------------------------------------------
// Stable ID: aa_00511b40
// Address:   0x00511b40  (autoassault.exe, image base 0x400000)
// Body:      0x00511b40–0x00511bf8 inclusive (185 B / 0xB9)
// System:    skills-abilities partition / MSVC std::map insert-or-find
//            (isnil@+0x21, signed int key@node+0x0C, Node24 family)
// Agent:     R13-031 OWN-ONLY dual 2026-08-05 (dual start 2686)
// Parent:    0x00511950 StdTree_InsertAndRebalance_Node24_Isnil21_Inferred (R12-014)
// Exactness: Behavior-preserving; meaningful names. Not modernization.
// Terminal:  false (no runtime Confirmed)
// =============================================================================

// PURPOSE:
// Unique insert-or-find by signed int32 key at value[0] / node+0x0C.
// Miss → StdTree_InsertAndRebalance_Node24_Isnil21_Inferred; hit → {it, false},
// no rewrite of mapped payload.

#include <cstdint>

struct MapNode_Isnil21_Node24 {
  MapNode_Isnil21_Node24 *left;    // +0x00
  MapNode_Isnil21_Node24 *parent;  // +0x04
  MapNode_Isnil21_Node24 *right;   // +0x08
  int32_t key;                     // +0x0C  (value dword0)
  // mapped payload +0x10 .. (vector-like; copied by insert buynode)
  uint8_t color;                   // +0x20
  uint8_t isnil;                   // +0x21
  // node size 0x24 (from dualed buynode 005118b0)
};

struct MapShell_Isnil21_Node24 {
  // +0x00 unused here
  MapNode_Isnil21_Node24 *head;    // +0x04  sentinel; leftmost = *head, root = head->parent
  uint32_t size;                   // +0x08
};

struct InsertPair_Isnil21 {
  MapNode_Isnil21_Node24 *it;      // +0x00
  uint8_t inserted;                // +0x04 (bool)
};

struct Val_IntKey_Isnil21 {
  int32_t key;                     // +0x00 → node+0x0C
  // remaining mapped payload for insert (buynode copies into node+0x10..)
};

// Dualed always-insert + RB (R12-014): RET 0x10
extern "C" MapNode_Isnil21_Node24 **__thiscall
StdTree_InsertAndRebalance_Node24_Isnil21_Inferred(
    MapShell_Isnil21_Node24 *map,
    MapNode_Isnil21_Node24 **outIt,
    char addLeft,
    MapNode_Isnil21_Node24 *where,
    const Val_IntKey_Isnil21 *value);

// Tree predecessor (iterator --); residual undualed isnil21 family
extern "C" void __fastcall FUN_005adff0(MapNode_Isnil21_Node24 **pNode);

void __thiscall StdMap_InsertOrFind_IntKey_Isnil21_Inferred(
    MapShell_Isnil21_Node24 *map,             // ECX
    InsertPair_Isnil21 *out,                 // stack +4
    const Val_IntKey_Isnil21 *value)         // stack +8
// RET 8
{
  MapNode_Isnil21_Node24 *head = map->head;
  MapNode_Isnil21_Node24 *where = head;
  bool goLeft = true;

  MapNode_Isnil21_Node24 *node = head->parent; // root
  if (node->isnil == 0) {
    MapNode_Isnil21_Node24 *child = node;
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

  MapNode_Isnil21_Node24 *hint = where;

  if (goLeft) {
    // leftmost of map is *head (sentinel left link)
    if (where == *reinterpret_cast<MapNode_Isnil21_Node24 **>(head)) {
      MapNode_Isnil21_Node24 *tmp = where;
      MapNode_Isnil21_Node24 **pNew =
          StdTree_InsertAndRebalance_Node24_Isnil21_Inferred(
              map, &tmp, 1, where, value);
      out->it = *pNew;
      out->inserted = 1;
      return;
    }
    FUN_005adff0(&hint);
  }

  if (hint->key < value->key) {
    MapNode_Isnil21_Node24 *tmp = where;
    MapNode_Isnil21_Node24 **pNew =
        StdTree_InsertAndRebalance_Node24_Isnil21_Inferred(
            map, &tmp, static_cast<char>(goLeft), where, value);
    out->it = *pNew;
    out->inserted = 1;
    return;
  }

  // equal key — keep existing; do not rewrite mapped payload
  out->inserted = 0;
  out->it = hint;
}
