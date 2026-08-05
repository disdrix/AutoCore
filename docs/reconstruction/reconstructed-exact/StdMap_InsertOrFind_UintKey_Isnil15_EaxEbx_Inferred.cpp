// =============================================================================
// StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred  (FUN_00458510)
// -----------------------------------------------------------------------------
// Stable ID: aa_00458510
// Address:   0x00458510  (autoassault.exe, image base 0x400000)
// Body:      0x00458510 – 0x004585C5 exclusive (181 B / 0xB5)
// System:    std map insert-or-find (Val8 / isnil+0x15 / uint key / reg ABI)
// Generated: 2026-08-04 W37-K dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   MSVC-style unique map insert-or-find: walk by unsigned 32-bit key at
//   value dword0 / node+0x0C, optionally insert via RB helper, write
//   pair{iterator, inserted}. Equal key does NOT rewrite mapped value.
//
// ABI (bytes authority)
//   EAX = MapShell*   (head @ +4, size @ +8)
//   EBX = Val8*       (key = *(uint32_t*)EBX)
//   stack: InsertPair* out
//   returns out in EAX; RET 4
//
// NODE (Val8 / isnil15)
//   left@0 parent@4 right@8 key@0x0C value@0x10 color@0x14 isnil@0x15
//
// CALLEES
//   FUN_00438140 — always-insert + RB rebalance for this map family (unOWN)
//   FUN_004129f0 — tree predecessor (isnil@+0x15)
//
// CALLERS (6)
//   FUN_00444850, FUN_00444880, FUN_0043daf0, FUN_004582e0,
//   FUN_00752d60, FUN_00763620
//
// REJECT
//   Scaffold Named_CalleeOf_*_Palantir_* as product role (map is generic).
// =============================================================================

#include <cstdint>

struct MapNode_Isnil15 {
  MapNode_Isnil15 *left;    // +0x00
  MapNode_Isnil15 *parent;  // +0x04
  MapNode_Isnil15 *right;   // +0x08
  uint32_t key;             // +0x0C
  uint32_t mapped;          // +0x10  (payload dword1; not rewritten on hit)
  uint8_t color;            // +0x14  (used inside insert callee)
  uint8_t isnil;            // +0x15
};

struct MapShell_Isnil15 {
  void *proxy;              // +0x00
  MapNode_Isnil15 *head;    // +0x04
  uint32_t size;            // +0x08
};

struct Val8 {
  uint32_t key;
  uint32_t mapped;
};

struct InsertPair {
  MapNode_Isnil15 *it;
  uint8_t inserted;         // at +4 (byte); high bytes unused
  uint8_t _pad[3];
};

// Unowned helpers (roles sealed by call sites / peer duals)
extern "C" MapNode_Isnil15 *FUN_00438140(
    MapNode_Isnil15 **hintOrOut, char addLeft, MapNode_Isnil15 *where,
    const Val8 *value);
extern "C" void FUN_004129f0(); // predecessor; mutates local node* (isnil15)

// Register ABI: map in EAX, value* in EBX, out on stack — modeled as formals.
InsertPair *StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred(
    MapShell_Isnil15 *map,   // EAX
    InsertPair *out,         // stack
    const Val8 *value)       // EBX
{
  MapNode_Isnil15 *parent = map->head;
  bool goLeft = true;
  MapNode_Isnil15 *node = parent;

  if (map->head->parent->isnil == 0) {
    MapNode_Isnil15 *cur = map->head->parent;
    do {
      node = cur;
      goLeft = value->key < node->key; // unsigned
      cur = goLeft ? node->left : node->right;
    } while (cur->isnil == 0);
  } else {
    node = map->head;
  }

  MapNode_Isnil15 *hint = node;

  if (goLeft) {
    if (node == map->head->left) {
      MapNode_Isnil15 *r =
          FUN_00438140(&hint, /*addLeft*/ 1, node, value);
      out->it = r; // callee writes *outIt into holder; retail copies *r
      out->inserted = 1;
      return out;
    }
    // predecessor(node) → FUN_004129f0 on local node pointer
    FUN_004129f0();
    // after predecessor, hint/node updated (decompiler: param_1 = node)
  }

  if (hint->key < value->key) { // unsigned
    MapNode_Isnil15 *r =
        FUN_00438140(&hint, (char)goLeft, node, value);
    out->it = r;
    out->inserted = 1;
    return out;
  }

  out->it = hint;
  out->inserted = 0; // equal — do not rewrite mapped
  return out;
}
