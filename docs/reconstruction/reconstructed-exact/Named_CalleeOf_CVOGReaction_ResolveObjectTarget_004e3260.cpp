// =============================================================================
// Named alias for aa_004e3260 (historical scaffold name)
// Prefer: FUN_004e3260 / HashTable_LookupObjectByCoid_Inferred
// See reconstructed-exact/FUN_004e3260.cpp for image-faithful body.
// Strengthened 2026-07-29 (dual W16-I).
// =============================================================================

#include <cstdint>

extern "C" void *__thiscall FUN_004e23d0(
    void *listHead,
    std::uint32_t coidLo,
    std::uint32_t coidHi,
    void **outPrev);

// Same body as FUN_004e3260 — keep name for parent-seed scan continuity.
extern "C" void *__thiscall Named_CalleeOf_CVOGReaction_ResolveObjectTarget_004e3260(
    void *pTable,
    std::uint32_t coidLo,
    std::uint32_t coidHi)
{
  void *prevScratch = nullptr;
  std::uint32_t mask = *reinterpret_cast<std::uint32_t *>(
      reinterpret_cast<char *>(pTable) + 0x8);
  std::uint32_t bucket = coidLo & mask;
  void **bucketTable = *reinterpret_cast<void ***>(
      reinterpret_cast<char *>(pTable) + 0x10);
  void *listHead = bucketTable[bucket];
  void *node = FUN_004e23d0(listHead, coidLo, coidHi, &prevScratch);
  if (node == nullptr) {
    return nullptr;
  }
  return *reinterpret_cast<void **>(reinterpret_cast<char *>(node) + 0xc);
}
