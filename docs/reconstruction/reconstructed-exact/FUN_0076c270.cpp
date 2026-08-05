// =============================================================================
// FUN_0076c270 / Timer_CalibrateTscPerSec
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c270
// Address:   0x0076c270–0x0076c322  (autoassault.exe, image base 0x400000)
// System:    timer / util
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W18-N)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Prefer: reconstructed-exact/Timer_CalibrateTscPerSec.cpp
// =============================================================================

/*
 * Behavioral notes:
 * - Decompiler-faithful plate matching raw capture CF.
 * - Globals: DAT_00d1a538/53c scale u64; DAT_00d1a530 ready flag.
 * - Callees: QPF/QPC IAT, rdtsc, __allmul, __aulldiv.
 */

#include <cstdint>
#include <windows.h>

extern "C" int DAT_00d1a538;
extern "C" int DAT_00d1a53c;
extern "C" char DAT_00d1a530;

extern "C" unsigned long long __allmul(unsigned, unsigned, unsigned, unsigned);
extern "C" unsigned long long __aulldiv(unsigned long long, unsigned, unsigned);
extern "C" unsigned long long rdtsc(void);

void FUN_0076c270(void)
{
  uint32_t uVar1;
  uint32_t uVar2;
  unsigned long long uVar3;
  LARGE_INTEGER local_28;
  LARGE_INTEGER local_20;
  LARGE_INTEGER local_18;
  uint32_t local_10;
  int local_c;
  uint32_t local_8;
  int local_4;

  QueryPerformanceFrequency(&local_28);
  QueryPerformanceCounter(&local_20);
  uVar3 = rdtsc();
  local_4 = (int)(uVar3 >> 0x20);
  local_8 = (uint32_t)uVar3;
  uVar1 = local_28.LowPart >> 4 | local_28.HighPart << 0x1c;
  uVar2 = uVar1 + local_20.LowPart;
  uVar1 = ((uint32_t)local_28.HighPart >> 4) + local_20.HighPart +
          (uint32_t)(uVar1 + local_20.LowPart < uVar1); // CARRY4
  do {
    do {
      QueryPerformanceCounter(&local_18);
      uVar3 = rdtsc();
      local_c = (int)(uVar3 >> 0x20);
      local_10 = (uint32_t)uVar3;
    } while ((uint32_t)local_18.HighPart < uVar1);
  } while ((local_18.HighPart == (int)uVar1) && (local_18.LowPart < uVar2));

  uVar3 = __allmul(local_10 - local_8,
                   (local_c - local_4) - (uint32_t)(local_10 < local_8),
                   local_28.LowPart, local_28.HighPart);
  uVar3 = __aulldiv(uVar3,
                    local_18.LowPart - local_20.LowPart,
                    (local_18.HighPart - local_20.HighPart) -
                        (uint32_t)(local_18.LowPart < local_20.LowPart));
  DAT_00d1a538 = (int)uVar3;
  DAT_00d1a53c = (int)(uVar3 >> 0x20);
  DAT_00d1a530 = 1;
}
