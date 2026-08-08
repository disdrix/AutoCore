// =============================================================================
// StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred  (FUN_00402b30)
// -----------------------------------------------------------------------------
// Stable ID: aa_00402b30
// Address:   0x00402b30  (autoassault.exe, image base 0x400000)
// Body:      0x00402b30 – 0x00402be6 inclusive (183 B / 0xB7); pad CC @ 0x00402be7
// System:    missions-progression host map; unit = MSVC std map insert-or-find
// Generated: 2026-08-05 MEGA-040 dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      reviews/A_aa_00402b30_StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred.md
//            reviews/B_aa_00402b30_StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred.md
// =============================================================================
//
// PURPOSE
//   MSVC-style unique map insert-or-find: walk by unsigned 32-bit key at
//   value dword0 / node+0x10 under isnil@+0x31 (node size 0x38), optionally
//   insert via RB helper, write pair{iterator, inserted}. Equal key does NOT
//   rewrite mapped payload.
//
// ABI (bytes authority)
//   EAX = MapShell*   (head @ +4, size @ +8)
//   EBX = Val*        (key = *(uint32_t*)EBX)
//   stack: InsertPair* out
//   returns out in EAX; RET 4
//
// NODE (isnil31 / size 0x38 family)
//   left@0 parent@4 right@8 key@0x10 ... color@0x30 isnil@0x31
//
// CALLEES
//   FUN_00403250 — always-insert + RB rebalance isnil31 (unOWN residual)
//   FUN_00404290 — tree predecessor isnil31 (unOWN)
//
// CALLERS (3 UNCONDITIONAL_CALL)
//   Client_NotifyActiveMissionChanged FUN_00944770 @ 0x00944802, 0x009448bd
//     (map = client + 0xf14)
//   FUN_00933310 @ 0x00933363 (thin wrapper)
//
// REJECT
//   Scaffold Named_CalleeOf_Client_NotifyActiveMissionChanged_00402b30 as
//   product role (helper is generic STL insert-or-find; host is mission UI).
// =============================================================================

#include <cstdint>

struct MapNode_Isnil31 {
  MapNode_Isnil31 *left;    // +0x00
  MapNode_Isnil31 *parent;  // +0x04
  MapNode_Isnil31 *right;   // +0x08
  uint32_t _pad0c;          // +0x0C  (layout pad / non-key payload lead)
  uint32_t key;             // +0x10  (unsigned compare)
  // ... mapped payload through +0x2F ...
  uint8_t color;            // +0x30  (mutated inside insert callee)
  uint8_t isnil;            // +0x31
  // size 0x38
};

struct MapShell_Isnil31 {
  void *proxy;              // +0x00
  MapNode_Isnil31 *head;    // +0x04
  uint32_t size;            // +0x08
};

struct Val_UintKey {
  uint32_t key;             // dword0 — only field compared here
  // further mapped fields consumed by insert buynode (unOWN)
};

struct InsertPair_Isnil31 {
  MapNode_Isnil31 *it;      // +0
  uint8_t inserted;         // +4
  uint8_t _pad[3];
};

// Unowned helpers (roles sealed by call sites / peer duals)
extern "C" MapNode_Isnil31 *FUN_00403250(
    MapNode_Isnil31 **hintOrOut, char addLeft, const Val_UintKey *value);
// Note: retail also passes where-node in ECX / EDI family regs for insert;
// modeled from decompiler + call PUSH order. Full dual of 00403250 is unOWN.
extern "C" void FUN_00404290(); // predecessor; mutates local node* (isnil31)

// Register ABI: map in EAX, value* in EBX, out on stack — modeled as formals.
InsertPair_Isnil31 *StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred(
    MapShell_Isnil31 *map,       // EAX
    InsertPair_Isnil31 *out,     // stack
    const Val_UintKey *value)    // EBX
{
  MapNode_Isnil31 *head = map->head;
  MapNode_Isnil31 *node = head->parent; // root
  bool goLeft = true;

  if (node->isnil == 0) {
    MapNode_Isnil31 *cur = node;
    do {
      node = cur;
      goLeft = value->key < node->key; // unsigned (SETC)
      cur = goLeft ? node->left : node->right;
    } while (cur->isnil == 0);
  }

  MapNode_Isnil31 *hint = node;

  if (goLeft) {
    if (node == head->left) {
      MapNode_Isnil31 *r =
          FUN_00403250(&hint, /*addLeft*/ 1, value);
      out->it = r;
      out->inserted = 1;
      return out;
    }
    // predecessor(node) → FUN_00404290 on local node pointer
    FUN_00404290();
    // after predecessor, hint/node updated (asm: reload [ESP+local])
  }

  if (hint->key < value->key) { // unsigned (CMP/JNC fall-through miss)
    MapNode_Isnil31 *r =
        FUN_00403250(&hint, (char)goLeft, value);
    out->it = r;
    out->inserted = 1;
    return out;
  }

  out->it = hint;
  out->inserted = 0; // equal — do not rewrite mapped
  return out;
}
