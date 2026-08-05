// =============================================================================
// StdMap_InsertAlways_Val12_IntKey
// -----------------------------------------------------------------------------
// Stable ID: aa_00567860
// Address:   0x00567860  (autoassault.exe, image base 0x400000)
// System:    std red-black map always-insert by signed int key (Val12)
// Wave:      W29-M OWN-ONLY dual (2026-07-29)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE: Walk tree by signed int key (value dword0 / node+0x0c); ALWAYS insert
//          via Map_TreeInsertAndRebalance_Val12 (FUN_00567450). Always out.inserted=1.
//          NOT insert-or-find (no equal short-circuit). Equal keys go right then insert.
//
// ABI: __thiscall ECX=map; stack (InsertPair* out, int* value); RET 8.
// Body: 0x00567860–0x005678c0 exclusive (96 B).
// =============================================================================

#include <cstdint>

struct MapNode_Val12 {
  MapNode_Val12* left;    // +0
  MapNode_Val12* parent;  // +4
  MapNode_Val12* right;   // +8
  std::int32_t key;       // +0x0c (value dword0)
  std::int32_t v1;        // +0x10
  std::int32_t v2;        // +0x14
  std::uint8_t color;     // +0x18
  std::uint8_t isnil;     // +0x19
};

struct MapShell_Val12 {
  // ...
  MapNode_Val12* head;  // +4  (header; head->parent = root, head->left = leftmost)
  std::uint32_t size;   // +8
};

struct InsertPair {
  MapNode_Val12* it;    // +0
  std::uint8_t inserted; // +4
};

// FUN_00567450 — Map_TreeInsertAndRebalance_Val12 (W27-R); ret 0x10
// stack: (outIt*, addLeft, where, value*)  — decompile passes &param_3 as first
extern "C" MapNode_Val12* __thiscall Map_TreeInsertAndRebalance_Val12(
    MapShell_Val12* map,
    void* outItSlot,
    int addLeft,
    MapNode_Val12* where,
    const std::int32_t* value);

// Ghidra: FUN_00567860
void __thiscall StdMap_InsertAlways_Val12_IntKey(
    MapShell_Val12* map,
    InsertPair* out,
    const std::int32_t* value)
{
  MapNode_Val12* parent = map->head;
  bool addLeft = true;

  // head[1] / parent field of header = root under MSVC layout (puVar3[1])
  MapNode_Val12* root = reinterpret_cast<MapNode_Val12*>(
      reinterpret_cast<std::uintptr_t*>(parent)[1]);

  if (root->isnil == 0) {
    MapNode_Val12* n = root;
    do {
      parent = n;
      addLeft = (*value < parent->key); // signed
      if (addLeft) {
        n = parent->left;
      } else {
        n = parent->right; // equal also goes right
      }
    } while (n->isnil == 0);
  }

  // Always insert — no equal-key check
  MapNode_Val12* result =
      Map_TreeInsertAndRebalance_Val12(
          map,
          const_cast<std::int32_t**>(reinterpret_cast<std::int32_t* const*>(&value)),
          addLeft ? 1 : 0,
          parent,
          value);

  // Insert helper returns via out slot; decompile: *param_2 = *puVar3
  out->it = *reinterpret_cast<MapNode_Val12**>(result);
  out->inserted = 1;
}
