// =============================================================================
// FUN_0043ecf0  (twin of PodU32U8_CopyIfNonNull.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ecf0
// Address:   0x0043ecf0–0x0043ecfe  (autoassault.exe, image base 0x400000)
// Dual:      W32-N 2026-07-29 — see PodU32U8_CopyIfNonNull.cpp for named clean.
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct PodU32U8 {
  uint32_t key;
  uint8_t  flag;
};

// Retail: EAX=dest, ECX=src; RET; void
extern "C" void FUN_0043ecf0(uint8_t* dest /*EAX*/, const PodU32U8* src /*ECX*/)
{
  if (dest != nullptr) {
    *reinterpret_cast<uint32_t*>(dest) = src->key;
    dest[4] = src->flag;
  }
}
