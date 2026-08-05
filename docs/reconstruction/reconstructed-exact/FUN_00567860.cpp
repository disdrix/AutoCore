// =============================================================================
// FUN_00567860  (scaffold alias → StdMap_InsertAlways_Val12_IntKey)
// -----------------------------------------------------------------------------
// Stable ID: aa_00567860
// Address:   0x00567860  (autoassault.exe, image base 0x400000)
// System:    std map Val12 always-insert signed int key
// Wave:      W29-M (2026-07-29) — refined from 2026-07-23 scaffold
// Exactness: Behavior-preserving rewrite of decompiler CF. Bit-for-bit: DEFERRED.
// =============================================================================
// Named clean: docs/reconstruction/reconstructed-exact/StdMap_InsertAlways_Val12_IntKey.cpp
//
// ALWAYS inserts (inserted=1). Equal keys go right. NOT insert-or-find.
// Callee: FUN_00567450 (Map_TreeInsertAndRebalance_Val12, W27-R).
// ABI: __thiscall; stack (outPair*, value*); RET 8.
// Body: 0x00567860–0x005678c0 exclusive (96 B).
// =============================================================================

#include <cstdint>

// FUN_00567450
extern "C" void* __thiscall FUN_00567450(
    void* map, void* outSlot, int addLeft, void* where, const int* value);

void __thiscall FUN_00567860(std::uint8_t* map /* ECX */, std::uint32_t* outPair, int* value)
{
  std::uint32_t* parent = *reinterpret_cast<std::uint32_t**>(map + 4); // head
  bool addLeft = true;

  if (*reinterpret_cast<char*>(static_cast<int>(parent[1]) + 0x19) == '\0') {
    std::uint32_t* n = reinterpret_cast<std::uint32_t*>(parent[1]);
    do {
      parent = n;
      addLeft = (*value < static_cast<int>(parent[3]));
      if (addLeft) {
        n = reinterpret_cast<std::uint32_t*>(*parent);
      } else {
        n = reinterpret_cast<std::uint32_t*>(parent[2]);
      }
    } while (*reinterpret_cast<char*>(reinterpret_cast<int>(n) + 0x19) == '\0');
  }

  void* result = FUN_00567450(map, &value, addLeft ? 1 : 0, parent, value);
  *outPair = *reinterpret_cast<std::uint32_t*>(result);
  *reinterpret_cast<std::uint8_t*>(outPair + 1) = 1;
}
