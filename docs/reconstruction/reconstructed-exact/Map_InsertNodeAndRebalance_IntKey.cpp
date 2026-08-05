// =============================================================================
// Map_InsertNodeAndRebalance_IntKey
// -----------------------------------------------------------------------------
// Stable ID: aa_005d20b0
// Address:   0x005d20b0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities (NPC AI post-cast timer map insert core)
// Generated: 2026-07-29 W17-Q dual A/B seal; supersedes scaffold FUN_005d20b0.cpp
// Exactness: Behavior-preserving rewrite of decompiler + body bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   MSVC std::map/set-style tree insert + red-black rebalance for the int-key
//   node family (node size 0x18, color +0x14, isnil +0x15).
//   Always allocates; does NOT walk/compare keys (front: Map_InsertOrFind_IntKey
//   @ 0x005d2360). Throws length_error-style "map/set<T> too long" when
//   size >= 0x1FFFFFFE (decompiler: size > 0x1FFFFFFD).
//
// ABI: __thiscall map; four stack args; RET 0x10.
// Sole static caller: Map_InsertOrFind_IntKey (two sites).
//
// Dual: reviews/A|B_aa_005d20b0_Map_InsertNodeAndRebalance_IntKey.md
// =============================================================================

#include <cstdint>
#include <string>
#include <stdexcept>

struct MapNode18 {
  MapNode18* left;    // +0x00
  MapNode18* parent;  // +0x04
  MapNode18* right;   // +0x08
  std::int32_t key;   // +0x0C
  std::int32_t mapped;// +0x10
  std::uint8_t color; // +0x14  0=red, 1=black
  std::uint8_t isnil; // +0x15
  // pad to 0x18
};

struct MapShell {
  void* unused0;       // +0x00 (allocator / pad — not touched here)
  MapNode18* head;     // +0x04 header/end
  std::uint32_t size;  // +0x08
};

struct IntPair {
  std::int32_t key;
  std::int32_t mapped;
};

// Node ctor @ 0x006173a0 — operator_new(0x18); color arg; isnil=0
extern "C" MapNode18* FUN_006173a0(
    MapNode18* leftHint,
    MapNode18* parent,
    MapNode18* rightHint,
    const IntPair* value,
    std::uint8_t color);

// Rotates (isnil family +0x15)
extern "C" void __thiscall FUN_004e22d0(MapShell* map, MapNode18* node); // left-rotate
extern "C" void __thiscall FUN_006753b0(MapShell* map, MapNode18* node); // right-rotate

void __thiscall Map_InsertNodeAndRebalance_IntKey(
    MapShell* map,
    MapNode18** outNode,
    char insertLeft,
    MapNode18* parent,
    const IntPair* value)
{
  // Size guard — throw path builds std::string("map/set<T> too long") then
  // _CxxThrowException. Threshold from body: cmp [map+8], 0x1FFFFFFE / jb past.
  if (map->size > 0x1FFFFFFDu) {
    throw std::length_error("map/set<T> too long");
  }

  MapNode18* head = map->head;
  // Alloc: color=0 (red). Links seeded from (header, parent, header) like MSVC tree.
  MapNode18* node = FUN_006173a0(head, parent, head, value, /*color*/ 0);
  map->size += 1;

  if (parent == head) {
    // First element: root = leftmost = rightmost = node
    head->parent = node;
    head->left = node;
    head->right = node;
  } else if (insertLeft == 0) {
    parent->right = node;
    if (parent == head->right) {
      head->right = node;
    }
  } else {
    parent->left = node;
    if (parent == head->left) {
      head->left = node;
    }
  }

  // RB fixup while parent is red (color==0). Root forced black at exit.
  MapNode18* cur = node;
  while (cur->parent->color == 0) {
    MapNode18* p = cur->parent;
    MapNode18* gp = p->parent;
    MapNode18* uncle = gp->left;
    if (p == uncle) {
      // parent is left of grandparent → uncle is right
      uncle = gp->right;
      if (uncle->color == 0) {
        p->color = 1;
        uncle->color = 1;
        gp->color = 0;
        cur = gp;
      } else {
        if (cur == p->right) {
          FUN_004e22d0(map, p); // left-rotate parent
          cur = p;
          p = cur->parent;
        }
        p->color = 1;
        p->parent->color = 0;
        FUN_006753b0(map, p->parent); // right-rotate grandparent
      }
    } else {
      // parent is right of grandparent → uncle is left
      if (uncle->color == 0) {
        p->color = 1;
        uncle->color = 1;
        gp->color = 0;
        cur = gp;
      } else {
        if (cur == p->left) {
          FUN_006753b0(map, p); // right-rotate parent
          cur = p;
          p = cur->parent;
        }
        p->color = 1;
        p->parent->color = 0;
        // Inlined left-rotate of grandparent (body mirrors FUN_004e22d0)
        MapNode18* g = p->parent;
        MapNode18* r = g->right;
        g->right = r->left;
        if (r->left->isnil == 0) {
          r->left->parent = g;
        }
        r->parent = g->parent;
        if (g == map->head->parent) {
          map->head->parent = r;
        } else {
          MapNode18* ggf = g->parent;
          if (g == ggf->left) {
            ggf->left = r;
          } else {
            ggf->right = r;
          }
        }
        r->left = g;
        g->parent = r;
      }
    }
  }

  map->head->parent->color = 1; // root black
  *outNode = node;
}
