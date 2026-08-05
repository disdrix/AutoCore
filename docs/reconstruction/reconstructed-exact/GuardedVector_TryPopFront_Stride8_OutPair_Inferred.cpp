// =============================================================================
// GuardedVector_TryPopFront_Stride8_OutPair_Inferred  (FUN_0043e750)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e750
// Address:   0x0043e750–0x0043e7e2 exclusive (146 B / 0x92)
// System:    GuardedVector ring-deque try pop_front (stride 8, optional CS)
// Wave:      W38-A OWN-ONLY dual (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompiler CF + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// Retail ABI (bytes win over decompiler unaff_* phantoms):
//   ESI = GuardedVectorHeader* container
//   EDI = uint32_t out[2]  (pair; 8-byte element)
//   AL  = 1 if popped, 0 if empty
//   plain RET; no stack formals
//
// Peer: GuardedVector_PopFront @ 0x0040d980 — header-only, no copy/CS, cap×4
// Consumer: AssPreloader_DrainSuccessResultsAndTally (host+0x4c success vec)
// =============================================================================

#include <cstdint>
#include <windows.h>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint8_t** pages;       // +0x04
  int32_t capacity;      // +0x08  page count
  int32_t begin;         // +0x0c  absolute element index of front
  int32_t size;          // +0x10  element count
  CRITICAL_SECTION cs;   // +0x14  (Windows CS; size platform-dependent)
  // lockEnable at absolute +0x2c (byte) — after CS on Win32
};

// Clean signature: register formals explicit (retail keeps ESI/EDI).
// Returns 1 if an element was written to out[0..1] and removed; else 0.
uint8_t GuardedVector_TryPopFront_Stride8_OutPair_Inferred(
    GuardedVectorHeader* container /* ESI */,
    uint32_t out[2] /* EDI */)
{
  CRITICAL_SECTION* cs =
      reinterpret_cast<CRITICAL_SECTION*>(
          reinterpret_cast<uint8_t*>(container) + 0x14);
  const uint8_t lockEnable =
      *(reinterpret_cast<uint8_t*>(container) + 0x2c);

  if (lockEnable != 0) {
    EnterCriticalSection(cs);
  }

  if (container->size == 0) {
    if (lockEnable != 0) {
      LeaveCriticalSection(cs);
    }
    return 0;
  }

  // Resolve front slot: 2 stride-8 elements per page.
  uint32_t begin = static_cast<uint32_t>(container->begin);
  uint32_t pageIdx = begin >> 1;
  uint32_t slot = begin - (pageIdx * 2); // begin & 1
  if (static_cast<uint32_t>(container->capacity) <= pageIdx) {
    pageIdx -= static_cast<uint32_t>(container->capacity);
  }

  uint32_t* slotp = reinterpret_cast<uint32_t*>(
      container->pages[pageIdx] + slot * 8);

  // Odd preserved: skip first dword when out aliases the slot address.
  if (out != slotp) {
    out[0] = slotp[0];
  }
  out[1] = slotp[1];

  // Advance begin / shrink size (header-only pop; no element dtor).
  if (container->size != 0) {
    container->begin = static_cast<int32_t>(begin + 1);
    if (static_cast<uint32_t>(container->capacity * 2) <=
        static_cast<uint32_t>(container->begin)) {
      container->begin = 0;
    }
    container->size -= 1;
    if (container->size == 0) {
      container->begin = 0;
    }
  }

  if (lockEnable != 0) {
    LeaveCriticalSection(cs);
  }
  return 1;
}
