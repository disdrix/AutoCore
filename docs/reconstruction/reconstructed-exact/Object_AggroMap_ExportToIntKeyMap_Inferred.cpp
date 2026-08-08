// =============================================================================
// Object_AggroMap_ExportToIntKeyMap_Inferred  (Ghidra FUN_004c9380)
// -----------------------------------------------------------------------------
// Stable ID: aa_004c9380
// Address:   0x004c9380  (autoassault.exe, image base 0x400000)
// Body:      0x004c9380–0x004c9428 exclusive (168 B / 0xA8)
// System:    Object aggro map → int-key insert-or-find export
// Agent:     WQ9G-C OWN-ONLY dual 2026-08-04
// Exactness: Behavior-preserving; meaningful names. Not modernization.
// Terminal:  false (no runtime Confirmed)
// =============================================================================

// PURPOSE:
// Inorder-walk object aggro tree (head @ this+0x158, isnil@+0x29) and
// insert-or-find each entry into a destination map keyed by signed score
// (node+0x20). Used by CVOGHBAIBase_GetTargetFromAggro to build a temp tree.

#include <cstdint>

struct MapNode_Isnil29 {
  MapNode_Isnil29 *left;    // +0x00
  MapNode_Isnil29 *parent;  // +0x04
  MapNode_Isnil29 *right;   // +0x08
  // +0x0C
  uint32_t dwords[6];       // +0x10 value region (TFID+score on aggro; score-key on dest)
  uint8_t  color;           // +0x28
  uint8_t  isnil;           // +0x29
};

struct MapShell_Isnil29 {
  MapNode_Isnil29 *head;    // +0x04  (on object: head lives at object+0x158 → shell @ +0x154)
  uint32_t size;            // +0x08
};

struct ObjectWithAggroMap {
  // ...
  // +0x154 MapShell_Isnil29 aggro; head pointer field at +0x158
  uint8_t  _pad[0x158];
  MapNode_Isnil29 *aggro_head; // +0x158
};

struct InsertPair_Isnil29 {
  MapNode_Isnil29 *it;
  uint8_t inserted;
};

// Dualed WQ9F-D — signed int key @ value[0] / node+0x10; RET 8
extern "C" void __thiscall
StdMap_InsertOrFind_IntKey_Isnil29_Inferred(
    MapShell_Isnil29 *map,
    InsertPair_Isnil29 *out,
    const int32_t *value /* key @ [0]; payload follows */);

// Inorder successor (isnil29) — inlined in body
static MapNode_Isnil29 *InorderSuccessor_Isnil29(MapNode_Isnil29 *node)
{
  if (node->isnil != 0) {
    return node;
  }
  MapNode_Isnil29 *right = node->right;
  if (right->isnil == 0) {
    MapNode_Isnil29 *cur = right;
    MapNode_Isnil29 *left = cur->left;
    while (left->isnil == 0) {
      cur = left;
      left = cur->left;
    }
    return cur;
  }
  MapNode_Isnil29 *parent = node->parent;
  MapNode_Isnil29 *cur = node;
  while (parent->isnil == 0 && cur == parent->right) {
    cur = parent;
    parent = parent->parent;
  }
  return parent;
}

void __thiscall Object_AggroMap_ExportToIntKeyMap_Inferred(
    ObjectWithAggroMap *self,   // ECX
    MapShell_Isnil29 *dest)     // stack +4
// RET 4
{
  MapNode_Isnil29 *head = self->aggro_head;
  MapNode_Isnil29 *node = head->left; // *head == leftmost in MSVC header layout
  // assembly: MOV ESI, [EAX] where EAX = head → leftmost
  if (node == head) {
    return;
  }

  do {
    // value pack (bytes): key=score@+0x20; TFID at value+8; value+4 unwritten
    alignas(4) uint8_t valueBlob[0x18];
    int32_t *asInt = reinterpret_cast<int32_t *>(valueBlob);
    asInt[0] = static_cast<int32_t>(node->dwords[4]); // score @ node+0x20 = dwords[4]
    // asInt[1] intentionally not written (matches image)
    asInt[2] = static_cast<int32_t>(node->dwords[0]); // TFID0 @ +0x10
    asInt[3] = static_cast<int32_t>(node->dwords[1]);
    asInt[4] = static_cast<int32_t>(node->dwords[2]);
    asInt[5] = static_cast<int32_t>(node->dwords[3]);

    InsertPair_Isnil29 outPair;
    StdMap_InsertOrFind_IntKey_Isnil29_Inferred(
        dest, &outPair, reinterpret_cast<const int32_t *>(valueBlob));

    node = InorderSuccessor_Isnil29(node);
  } while (node != head);
}
