// =============================================================================
// FUN_00402b30  — twin of StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00402b30
// Address:   0x00402b30  (autoassault.exe, image base 0x400000)
// Body:      0x00402b30 – 0x00402be6 inclusive (183 B / 0xB7)
// System:    missions-progression host map; unit = MSVC std map insert-or-find
// Generated: 2026-08-05 MEGA-040 dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI.
// Canonical: StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred.cpp
// =============================================================================

#include <cstdint>

// Machine ABI twin — see named clean for layouts and full commentary.
// EAX=map, EBX=value*, stack out pair*, RET 4.

struct Node_00402b30 {
  Node_00402b30 *left;
  Node_00402b30 *parent;
  Node_00402b30 *right;
  uint32_t _pad0c;
  uint32_t key;       // +0x10
  uint8_t color;      // +0x30 (insert callee)
  uint8_t isnil;      // +0x31
};

struct Map_00402b30 {
  void *proxy;
  Node_00402b30 *head;
  uint32_t size;
};

struct Pair_00402b30 {
  Node_00402b30 *it;
  uint8_t inserted;
  uint8_t _pad[3];
};

extern "C" Node_00402b30 *FUN_00403250(Node_00402b30 **hint, char addLeft, const uint32_t *value);
extern "C" void FUN_00404290();

Pair_00402b30 *FUN_00402b30(Map_00402b30 *map /*EAX*/, Pair_00402b30 *out /*stack*/,
                            const uint32_t *value /*EBX*/)
{
  Node_00402b30 *head = map->head;
  Node_00402b30 *node = head->parent;
  bool goLeft = true;

  if (node->isnil == 0) {
    Node_00402b30 *cur = node;
    do {
      node = cur;
      goLeft = *value < node->key;
      cur = goLeft ? node->left : node->right;
    } while (cur->isnil == 0);
  }

  Node_00402b30 *hint = node;

  if (goLeft) {
    if (node == head->left) {
      Node_00402b30 *r = FUN_00403250(&hint, 1, value);
      out->it = r;
      out->inserted = 1;
      return out;
    }
    FUN_00404290();
  }

  if (hint->key < *value) {
    Node_00402b30 *r = FUN_00403250(&hint, (char)goLeft, value);
    out->it = r;
    out->inserted = 1;
    return out;
  }

  out->it = hint;
  out->inserted = 0;
  return out;
}
