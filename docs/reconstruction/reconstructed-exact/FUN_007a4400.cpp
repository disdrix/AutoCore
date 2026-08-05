// =============================================================================
// FUN_007a4400  (twin of Perf_QpcBeginNamed_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4400
// Address:   0x007a4400 – 0x007a445c
// Dual:      W26-D 2026-07-29
// See:       Perf_QpcBeginNamed_Inferred.cpp for full plate + notes
// =============================================================================

#include <cstdint>
#include <windows.h>

extern "C" std::uint8_t DAT_00b00a74;
extern "C" float        DAT_00afa254;
extern "C" float        g_flOne;

// Ghidra name kept as primary export for FUN_* path consumers
extern "C" LARGE_INTEGER* __thiscall FUN_007a4400(LARGE_INTEGER* slot /*ECX*/, char* label)
{
  if (DAT_00b00a74 != 0) {
    DAT_00b00a74 = 0;
    LARGE_INTEGER freq{};
    QueryPerformanceFrequency(&freq);
    DAT_00afa254 = g_flOne / static_cast<float>(static_cast<long long>(freq.QuadPart));
  }

  char* dst = reinterpret_cast<char*>(slot) + 8;
  char c;
  do {
    c = *label;
    *dst = c;
    ++label;
    ++dst;
  } while (c != '\0');

  QueryPerformanceCounter(slot);
  return slot;
}
