// =============================================================================
// StdMap_InsertOrFindByIntKey_Val12  (FUN_0053a1a0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0053a1a0
// Address:   0x0053a1a0  (autoassault.exe, image base 0x400000)
// Body:      0x0053a1a0 – 0x0053a259 exclusive (185 B / 0xB9)
// System:    std map insert-or-find by int key (Val12 node / isnil@+0x19)
// Generated: 2026-07-29 W28-P dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of live decompile CF + byte-sealed RET 8.
// ABI:       __thiscall; ECX=map*; stack (InsertPair* out, Val12* value); RET 8
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
  // inserted as byte at +4 (retail stores with mov byte [eax+4], imm)
  std::uint8_t inserted; // +4
};

// Callees:
//   FUN_00539210 — StdTree_InsertAndRebalance_Val12 (W27-Q); RET 0x10
//   FUN_005ae050 — tree predecessor (isnil@+0x19)

extern "C" MapNode_Val12** __thiscall StdTree_InsertAndRebalance_Val12(
    MapShell_Val12* map,
    MapNode_Val12** outIt,
    char addLeft,
    MapNode_Val12* where,
    const Val12* value);

extern "C" void __fastcall FUN_005ae050(MapNode_Val12** it);

// Retail: FUN_0053a1a0
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
      addLeft = (value->key < where->key);
      cur = addLeft ? where->left : where->right;
    } while (cur->isnil == 0);
  }

  MapNode_Val12* parent_slot = where;

  if (addLeft) {
    if (where == head->left) {
      MapNode_Val12** p = StdTree_InsertAndRebalance_Val12(
          map, &parent_slot, /*addLeft*/1, where, value);
      out->it = *p;
      out->inserted = 1;
      return; // ret 8
    }
    FUN_005ae050(&where); // predecessor
  }

  if (where->key < value->key) {
    MapNode_Val12** p = StdTree_InsertAndRebalance_Val12(
        map, &parent_slot, static_cast<char>(addLeft), where, value);
    out->it = *p;
    out->inserted = 1;
    return; // ret 8
  }

  out->inserted = 0;
  out->it = where;
  // ret 8
}
