// =============================================================================
// StdMap_InsertOrFindByIntKey_Val12  (FUN_005e18d0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005e18d0
// Address:   0x005e18d0  (autoassault.exe, image base 0x400000)
// Body:      0x005e18d0 – 0x005e1988 exclusive (184 B / 0xB8)
// System:    std map insert-or-find by signed int key (Val12 / isnil@+0x19)
// Generated: 2026-07-29 W30-L dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of live decompile CF + byte-sealed RET 8.
// ABI:       __thiscall; ECX=map*; stack (InsertPair* out, Val12* value); RET 8
// =============================================================================
//
// PURPOSE
//   Unique map insert-or-find. Miss → always-insert FUN_005e13b0 (buynode 005ae220).
//   Hit → out{it,0}, no value rewrite.
//
// PEER
//   0x0053a1a0 StdMap_InsertOrFindByIntKey_Val12 (W28-P) — same CF; insert helper 00539210.
//   0x00573810 StdMap_InsertOrFind_Val12_UintKey (W28-T) — unsigned key peer.
//
// SOLE CALLER
//   FUN_005e0610 @ 0x005e06db (mission/reaction domain; map type open)
// =============================================================================

#include <cstdint>

struct MapNode_Val12 {
  MapNode_Val12* left;    // +0x00
  MapNode_Val12* parent;  // +0x04
  MapNode_Val12* right;   // +0x08
  std::int32_t key;      // +0x0C  (node[3]; first dword of Val12 value)
  std::uint32_t val1;    // +0x10
  std::uint32_t val2;    // +0x14
  std::uint8_t color;    // +0x18
  std::uint8_t isnil;    // +0x19
};

struct MapShell_Val12 {
  void* unused0;
  MapNode_Val12* head;   // +0x04
  std::uint32_t size;    // +0x08
};

struct Val12 {
  std::int32_t key;      // +0
  std::uint32_t v1;
  std::uint32_t v2;
};

struct InsertPair {
  MapNode_Val12* it;     // +0
  std::uint8_t inserted; // +4
};

// Callees:
//   FUN_005e13b0 — local StdTree_InsertAndRebalance_Val12 clone; RET 0x10;
//                  max size 0x15555553; buynode FUN_005ae220 color 0
//   FUN_005ae050 — StdTree_Dec_Val12 / predecessor (W29-E)

extern "C" MapNode_Val12** __thiscall FUN_005e13b0(
    MapShell_Val12* map,
    MapNode_Val12** outIt,
    char addLeft,
    MapNode_Val12* where,
    const Val12* value);

extern "C" void __fastcall FUN_005ae050(MapNode_Val12** it);

// Retail: FUN_005e18d0
void __thiscall StdMap_InsertOrFindByIntKey_Val12(
    MapShell_Val12* map,
    InsertPair* out,
    const Val12* value)
{
  MapNode_Val12* head = map->head;
  MapNode_Val12* where = head;
  bool addLeft = true;

  if (head->parent->isnil == 0) {
    MapNode_Val12* cur = head->parent;
    do {
      where = cur;
      // SIGNED: retail setl on cmp value.key, node.key
      addLeft = (value->key < where->key);
      cur = addLeft ? where->left : where->right;
    } while (cur->isnil == 0);
  }

  MapNode_Val12* parent_slot = where;

  if (addLeft) {
    if (where == head->left) {
      MapNode_Val12** p = FUN_005e13b0(
          map, &parent_slot, /*addLeft*/1, where, value);
      out->it = *p;
      out->inserted = 1;
      return; // ret 8
    }
    FUN_005ae050(&where); // predecessor
  }

  // SIGNED: retail jge on cmp node.key, value.key
  if (where->key < value->key) {
    MapNode_Val12** p = FUN_005e13b0(
        map, &parent_slot, static_cast<char>(addLeft), where, value);
    out->it = *p;
    out->inserted = 1;
    return; // ret 8
  }

  out->inserted = 0;
  out->it = where;
  // ret 8 — equal key: no value field write
}
