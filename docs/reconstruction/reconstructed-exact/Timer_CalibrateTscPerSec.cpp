// =============================================================================
// Timer_CalibrateTscPerSec
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c270
// Address:   0x0076c270–0x0076c322  (autoassault.exe, image base 0x400000)
// System:    timer / util
// Generated: 2026-07-23 scaffold as FUN_0076c270; dual A/B seal 2026-07-29 (W18-N)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Nullary; plain RET; writes globals only.
 * - QPF + QPC start, rdtsc start; wait until QPC advances by (freq>>4) (~1/16 s).
 * - scale = (Δtsc * freq) / Δqpc via __allmul / __aulldiv → TSC ticks per second.
 * - DAT_00d1a538:53c = scale u64; DAT_00d1a530 = 1 (ready).
 * - Callers: Timer_GetTimeSeconds_Rdtsc (0x0076c330), timer object init (0x0076c500).
 */

#include <cstdint>
#include <windows.h>

// Globals (image zeros until first calibrate)
extern "C" uint8_t  DAT_00d1a530; // ready flag
extern "C" uint32_t DAT_00d1a538; // scale lo
extern "C" uint32_t DAT_00d1a53c; // scale hi

// MSVC 64-bit helpers (retail callees)
extern "C" uint64_t __allmul(uint32_t a_lo, uint32_t a_hi, uint32_t b_lo, uint32_t b_hi);
extern "C" uint64_t __aulldiv(uint64_t num, uint32_t den_lo, uint32_t den_hi);

// Intrinsics stand-ins
// QueryPerformanceFrequency / QueryPerformanceCounter / rdtsc

void Timer_CalibrateTscPerSec(void)
{
  LARGE_INTEGER freq{};
  LARGE_INTEGER qpc0{};
  LARGE_INTEGER qpc1{};

  QueryPerformanceFrequency(&freq);
  QueryPerformanceCounter(&qpc0);

  uint32_t tsc0_lo, tsc0_hi;
  {
    unsigned long long t0 = __rdtsc();
    tsc0_lo = (uint32_t)t0;
    tsc0_hi = (uint32_t)(t0 >> 32);
  }

  // target = qpc0 + (freq >> 4)  — wait ~1/16 second
  uint32_t thr_lo = (freq.LowPart >> 4) | (freq.HighPart << 28);
  uint32_t thr_hi = (freq.HighPart >> 4);
  uint64_t add = ((uint64_t)thr_hi << 32) | thr_lo;
  uint64_t target = (uint64_t)qpc0.QuadPart + add;

  uint32_t tsc1_lo = 0, tsc1_hi = 0;
  do {
    QueryPerformanceCounter(&qpc1);
    unsigned long long t1 = __rdtsc();
    tsc1_lo = (uint32_t)t1;
    tsc1_hi = (uint32_t)(t1 >> 32);
  } while ((uint64_t)qpc1.QuadPart < target);

  // Δtsc
  uint32_t dts_lo = tsc1_lo - tsc0_lo;
  uint32_t dts_hi = tsc1_hi - tsc0_hi - (tsc1_lo < tsc0_lo ? 1u : 0u);

  // Δqpc
  uint32_t dqp_lo = qpc1.LowPart - qpc0.LowPart;
  uint32_t dqp_hi = qpc1.HighPart - qpc0.HighPart - (qpc1.LowPart < qpc0.LowPart ? 1u : 0u);

  uint64_t num = __allmul(dts_lo, dts_hi, freq.LowPart, (uint32_t)freq.HighPart);
  uint64_t scale = __aulldiv(num, dqp_lo, dqp_hi);

  DAT_00d1a538 = (uint32_t)scale;
  DAT_00d1a53c = (uint32_t)(scale >> 32);
  DAT_00d1a530 = 1;
}

// Legacy Ghidra name — see FUN_0076c270.cpp
