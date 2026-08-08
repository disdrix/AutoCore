// =============================================================================
// StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred  (FUN_0040b890)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040b890
// Address:   0x0040b890  (autoassault.exe, image base 0x400000)
// Body:      0x0040b890 – 0x0040b8eb inclusive (92 B / 0x5C); pad CC @ 0x0040b8ec
// System:    inventory-transfer residual partition; unit = MSVC tree always-insert
// Generated: 2026-08-05 R13-019 dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      reviews/A_aa_0040b890_StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred.md
//            reviews/B_aa_0040b890_StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred.md
// =============================================================================
//
// PURPOSE
//   MSVC-style tree always-insert by signed 32-bit key under isnil@+0x19
//   (node size 0x1C). Walk root with goLeft flag, then buy+link+RB via
//   FUN_0040bcd0. Writes pair{iterator, inserted=true}. NO equal-key
//   early-out (not InsertOrFind).
//
// ABI (bytes authority)
//   EAX = MapShell*   (head @ +4, size @ +8)
//   EBX = Val*        (key = *(int32_t*)EBX)
//   stack: InsertPair* out
//   returns out in EAX; RET 4
//   At CALL 0040bcd0: EDI=map, ECX=where-parent
//
// NODE (isnil19 / size 0x1C family)
//   left@0 parent@4 right@8 key@0x0C value@0x10 color@0x18 isnil@0x19
//
// CALLEE
//   FUN_0040bcd0 — insert + RB rebalance isnil19 (unOWN residual)
//     buy FUN_0040c060 (operator_new 0x1C) / ctor FUN_0040c210
//     Lrot FUN_0040b910 / Rrot FUN_00446b10
//
// CALLERS (1 UNCONDITIONAL_CALL)
//   MissionTracker_FillTrackedTargetSlots_Inferred FUN_0092b2a0 @ 0x0092b4fc
//     (stack temp map for secondary multi-target ranking)
//
// REJECT
//   Inventory item-move product name (partition system only).
//   InsertOrFind / unique-map equal-key claims.
//   thiscall ECX=map; unsigned key; isnil29/31 merge.
// =============================================================================

#include <cstdint>

struct MapNode_Isnil19 {
  MapNode_Isnil19 *left;    // +0x00
  MapNode_Isnil19 *parent;  // +0x04
  MapNode_Isnil19 *right;   // +0x08
  int32_t key;              // +0x0C  (signed compare SETL)
  uint32_t val0;            // +0x10  (mapped lead; host-filled)
  uint32_t val1;            // +0x14
  uint8_t color;            // +0x18
  uint8_t isnil;            // +0x19
  // size 0x1C
};

struct MapShell_Isnil19 {
  void *proxy;              // +0x00
  MapNode_Isnil19 *head;    // +0x04
  uint32_t size;            // +0x08
};

struct Val_IntKey_Isnil19 {
  int32_t key;              // +0  — only field compared here
  uint32_t val0;            // +4  — copied by buynode/ctor (unOWN)
  uint32_t val1;            // +8
};

struct InsertPair_Isnil19 {
  MapNode_Isnil19 *it;      // +0
  uint8_t inserted;         // +4
  uint8_t _pad[3];
};

// Unowned insert+RB helper. Retail: EDI=map, ECX=where, stack (out*, goLeft, val*).
// Modeled from call PUSH order + decompiler; full dual of 0040bcd0 is unOWN.
extern "C" InsertPair_Isnil19 *FUN_0040bcd0(
    MapNode_Isnil19 *where,   // ECX
    InsertPair_Isnil19 *tmpOut,
    char goLeft,
    const Val_IntKey_Isnil19 *value);

// Register ABI: map in EAX, value* in EBX, out on stack — modeled as formals.
InsertPair_Isnil19 *StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred(
    MapShell_Isnil19 *map,              // EAX
    InsertPair_Isnil19 *out,            // stack
    const Val_IntKey_Isnil19 *value)    // EBX
{
  MapNode_Isnil19 *head = map->head;
  MapNode_Isnil19 *cur = head->parent; // root
  MapNode_Isnil19 *where = head;
  bool goLeft = true;

  if (cur->isnil == 0) {
    const int32_t key = value->key;
    do {
      where = cur;
      goLeft = key < cur->key; // signed (SETL)
      cur = goLeft ? cur->left : cur->right;
    } while (cur->isnil == 0);
  }

  // Always insert — no equal-key inserted=0 path in this unit.
  InsertPair_Isnil19 *tmp =
      FUN_0040bcd0(where, /*tmpOut via stack local*/ out, (char)goLeft, value);
  // Bytes: CALL returns pair*; MOV EAX,[EAX]; MOV [out],EAX; MOV [out+4],1
  out->it = tmp->it;
  out->inserted = 1;
  return out;
}
