// =============================================================================
// FUN_00971700  (twin of AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00971700
// Address:   0x00971700–0x00971795  (autoassault.exe, image base 0x400000)
// Dual:      W33-M 2026-07-29
// Canonical: AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;
  uint32_t capacity;
  uint32_t begin;
  int32_t  size;
};

extern "C" void FUN_0043df90(/* erase/init */);
extern "C" void GuardedVector_InsertRange(
    GuardedVectorHeader* container,
    void* seed_out,
    uint32_t insert_at,
    const uint32_t* first,
    const uint32_t* last,
    uint32_t sixth_residual);
extern "C" void AssPreloader_EnqueueEligibleFromRing_Inferred(
    void* host, GuardedVectorHeader* source);
extern "C" void __fastcall FUN_005b2ba0(GuardedVectorHeader* ring);

uint32_t __fastcall FUN_00971700(void* host /*ECX*/)
{
  GuardedVectorHeader local{};

  void* cache = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(host) + 0x110);
  void* ctx = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(cache) + 0x64);
  const uint32_t* first = *reinterpret_cast<const uint32_t**>(
      reinterpret_cast<uint8_t*>(ctx) + 0x50);
  const uint32_t* last = *reinterpret_cast<const uint32_t**>(
      reinterpret_cast<uint8_t*>(ctx) + 0x54);

  FUN_0043df90();
  GuardedVector_InsertRange(&local, &local, 0, first, last, 0);
  AssPreloader_EnqueueEligibleFromRing_Inferred(host, &local);
  FUN_005b2ba0(&local);
  return 0;
}
