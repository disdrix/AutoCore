// =============================================================================
// FUN_0043cef0  (twin of GuardedVector_RingFillRange)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043cef0
// Address:   0x0043cef0–0x0043cf38  (autoassault.exe, image base 0x400000)
// Dual:      W28-D 2026-07-29
// Prefer:    GuardedVector_RingFillRange.cpp for named plate
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

// Prefer named clean: docs/reconstruction/reconstructed-exact/GuardedVector_RingFillRange.cpp

// Retail: EBX = &fill; stack (container_from, idx_from, container_to, idx_to); plain RET.

void FUN_0043cef0(int container_from, uint32_t idx_from,
                  int container_to, uint32_t idx_to,
                  const uint32_t* fill /*EBX*/)
{
  for (; (container_from != container_to) || (idx_from != idx_to);
       idx_from = idx_from + 1) {
    uint32_t page = idx_from >> 2;
    int page_base_neg = static_cast<int>(page) * -4;
    if (*reinterpret_cast<uint32_t*>(container_from + 8) <= page) {
      page -= *reinterpret_cast<uint32_t*>(container_from + 8);
    }
    int slots = *reinterpret_cast<int*>(container_from + 4);
    int page_ptr = *reinterpret_cast<int*>(slots + page * 4);
    *reinterpret_cast<uint32_t*>(
        page_ptr + (static_cast<int>(idx_from) + page_base_neg) * 4) = *fill;
  }
}
