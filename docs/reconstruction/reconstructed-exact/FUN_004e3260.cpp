// =============================================================================
// FUN_004e3260 — HashTable_LookupObjectByCoid_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004e3260
// Address:   0x004e3260 – 0x004e328b  (autoassault.exe, image base 0x400000)
// System:    object-resolve / id-hash
// Generated: 2026-07-23 scaffold; **strengthened 2026-07-29** from read_memory body
// Exactness: Behavior-preserving. Decompiler dropped thiscall table/bucket setup;
//            clean follows image (mask @ table+0x8, buckets @ table+0x10).
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes (2026-07-29 seal):
 * - __thiscall: ECX = hash table object; stack = coidLo, coidHi; ret 8.
 * - bucket = coidLo & *(u32*)(table + 0x8)
 * - listHead = *(void**)(*(void**)(table + 0x10) + bucket * 4)
 * - FUN_004e23d0(listHead, coidLo, coidHi, &prevOut) walks chain:
 *     start cur = *(listHead + 4); match node+0x18/+0x1c; next node+0x10
 * - return *(node + 0xc) object* on hit; 0 on miss.
 * - No stores to table; pure lookup.
 * - Primary consumer: CVOGReaction_ResolveObjectTarget (dual-table select).
 */

#include <cstdint>

// Chain walk (not owned): returns matching node* or null; writes prev to *outPrev.
extern "C" void *__thiscall FUN_004e23d0(
    void *listHead,
    std::uint32_t coidLo,
    std::uint32_t coidHi,
    void **outPrev);

// Image-faithful thiscall (Ghidra decompile incorrectly presents free-function shape).
extern "C" void *__thiscall FUN_004e3260(
    void *pTable,
    std::uint32_t coidLo,
    std::uint32_t coidHi)
{
  // Scratch for chain-walk prev out-arg (image: lea eax,[esp+4]; push — reuses coidLo slot).
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
