// =============================================================================
// AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00971700
// Address:   0x00971700–0x00971795  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00971700
// System:    assPreloader / asset preload pipeline
// Dual:      W33-M 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI:
//   ECX = AssPreloader* host
//   bare RET; returns 0 in EAX
//
// Snapshot dword key span [*(ctx+0x50), *(ctx+0x54)) where
//   ctx = *(*(host+0x110)+0x64)
// into a local GuardedVector (erase/init + GuardedVector_InsertRange), then
// AssPreloader_EnqueueEligibleFromRing(host, local), then destroy local.
//
// No per-key dependency expand (contrast FUN_009717a0 / FUN_00971820).
// Name is structural (_Inferred). Zero static call xrefs in Ghidra.
// Nested FUN_0043df90 / FUN_005b2ba0 not dual-owned here.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;  // +0x04
  uint32_t capacity; // +0x08
  uint32_t begin;    // +0x0c
  int32_t  size;     // +0x10
};

// Nested helpers (owned elsewhere; signatures as used here).
extern "C" void FUN_0043df90(/* erase/init range args; ECX-related */);
extern "C" void GuardedVector_InsertRange(
    GuardedVectorHeader* container,
    void* seed_out,
    uint32_t insert_at,
    const uint32_t* first,
    const uint32_t* last,
    uint32_t sixth_residual);
extern "C" void AssPreloader_EnqueueEligibleFromRing_Inferred(
    void* host /*stack*/, GuardedVectorHeader* source /*ESI*/);
extern "C" void __fastcall FUN_005b2ba0(GuardedVectorHeader* ring /*ECX*/);

uint32_t AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred(
    void* host /*ECX*/)
{
  GuardedVectorHeader local{};
  // Retail: pages/cap/begin/size zeroed; SEH LAB_009afe03 around body.

  void* cache = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(host) + 0x110);
  void* ctx = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(cache) + 0x64);
  const uint32_t* first = *reinterpret_cast<const uint32_t**>(
      reinterpret_cast<uint8_t*>(ctx) + 0x50);
  const uint32_t* last = *reinterpret_cast<const uint32_t**>(
      reinterpret_cast<uint8_t*>(ctx) + 0x54);

  // Erase/init local + iterator out (FUN_0043df90) — empty local path.
  FUN_0043df90();

  // Insert [first, last) at insert_at (zeroed begin path). 6 stack formals.
  GuardedVector_InsertRange(&local, &local, /*insert_at*/ 0, first, last,
                            /*sixth*/ 0);

  // ESI = &local; stack host.
  AssPreloader_EnqueueEligibleFromRing_Inferred(host, &local);

  FUN_005b2ba0(&local);
  return 0;
}
