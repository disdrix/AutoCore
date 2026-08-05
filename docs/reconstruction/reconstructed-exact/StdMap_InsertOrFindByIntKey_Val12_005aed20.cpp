// =============================================================================
// StdMap_InsertOrFindByIntKey_Val12  (FUN_005aed20)
// -----------------------------------------------------------------------------
// Stable ID: aa_005aed20
// Address:   0x005aed20  (autoassault.exe, image base 0x400000)
// Body:      0x005aed20 – 0x005aedd8 exclusive (184 B / 0xB8); pad CC → 0x005aede0
// System:    std map insert-or-find by int key (Val12 node / isnil@+0x19)
// Generated: 2026-07-29 W30-M dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of live decompile CF + byte-sealed RET 8.
// ABI:       __thiscall; ECX=map*; stack (InsertPair* out, Val12* value); RET 8
// Peer:      aa_0053a1a0 (same role; insert helper 0x00539210 — do not merge)
// Insert:    FUN_005ae4e0 StdTree_InsertAndRebalance_Val12 (W27-T)
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
  std::uint8_t inserted; // +4  (retail: mov byte [eax+4], imm)
};

// Callees:
//   FUN_005ae4e0 — StdTree_InsertAndRebalance_Val12 (W27-T); RET 0x10
//   FUN_005ae050 — StdTree_Dec_Val12 / predecessor (W29-E)

extern "C" MapNode_Val12** __thiscall StdTree_InsertAndRebalance_Val12(
    MapShell_Val12* map,
    MapNode_Val12** outIt,
    char addLeft,
    MapNode_Val12* where,
    const Val12* value);

extern "C" void __fastcall StdTree_Dec_Val12(MapNode_Val12** it);

// Retail: FUN_005aed20
void __thiscall StdMap_InsertOrFindByIntKey_Val12(
    MapShell_Val12* map,
    InsertPair* out,
    const Val12* value)
{
  MapNode_Val12* head = map->head;
  MapNode_Val12* where = head;
  bool addLeft = true;

  if (head->parent->isnil == 0) {
    MapNode_Val12* cur = head->parent; // root
    do {
      where = cur;
      addLeft = (value->key < where->key);
      cur = addLeft ? where->left : where->right;
    } while (cur->isnil == 0);
  }

  MapNode_Val12* parent_slot = where;

  if (addLeft) {
    if (where == head->left) {
      // leftmost fast path: insert left of begin
      MapNode_Val12** p = StdTree_InsertAndRebalance_Val12(
          map, &parent_slot, /*addLeft*/1, where, value);
      out->it = *p;
      out->inserted = 1;
      return; // ret 8
    }
    StdTree_Dec_Val12(&where); // predecessor of insert site
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
