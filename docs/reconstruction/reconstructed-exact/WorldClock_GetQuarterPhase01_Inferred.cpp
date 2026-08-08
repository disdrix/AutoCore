// =============================================================================
// WorldClock_GetQuarterPhase01_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00553dd0
// Address:   0x00553dd0  (autoassault.exe, image base 0x400000)
// System:    environment / world clock
// Generated: 2026-08-04 WQ9D-J dual seal (from live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Return a normalized [0,1] phase for the current 15-minute quarter of
// the hour on a world-clock object. Cached at this+0x24 unless sentinel -1.0.
//
// ABI: ECX = clock; x87 ST0 = float result; bare ret.
//

#include <cstdint>
#include <ctime>

// Named globals (image).
extern float DAT_00aaa668;              // -1.0f sentinel
extern float DAT_009cca58;              // 900.0f
extern float DAT_009d25a4;              // 1800.0f
extern float DAT_009d25a0;              // 2700.0f
extern float DAT_00aaace0;              // 1/900
extern float DAT_00aaa5dc;              // 2^32 as float (tick wrap)
extern float g_flMsToSeconds_Inferred;  // 0.001f @ 0x00a0f72c
extern float g_flOne;                   // 1.0f @ 0x00a0f2a0
extern uint32_t g_dwClientTickMs;       // @ 0x00b041cc
extern float DAT_00b04750;              // last secOfHour sample
extern uint32_t DAT_00b0474c;           // last tick at sample

// CRT
extern "C" void _time64(__time64_t* t);
extern "C" tm* _localtime64(const __time64_t* t);

float __fastcall WorldClock_GetQuarterPhase01_Inferred(int clock /*ECX*/) {
  float cached = *reinterpret_cast<float*>(clock + 0x24);
  if (cached != DAT_00aaa668) { // != -1.0f
    return cached;
  }

  __time64_t now{};
  _time64(&now);

  uint32_t baseLo = *reinterpret_cast<uint32_t*>(clock + 0x160);
  int32_t baseHi = *reinterpret_cast<int32_t*>(clock + 0x164);
  uint32_t nowLo = static_cast<uint32_t>(now);
  int32_t nowHi = static_cast<int32_t>(now >> 32);

  bool borrow = nowLo < baseLo;
  nowLo = nowLo - baseLo;
  nowHi = (nowHi - baseHi) - static_cast<int32_t>(borrow);

  __time64_t adj = (static_cast<__time64_t>(nowHi) << 32) | nowLo;
  tm* pt = _localtime64(&adj);

  float secOfHour = static_cast<float>(pt->tm_sec + pt->tm_min * 60);
  float phase = 0.0f;
  uint32_t mode = *reinterpret_cast<uint32_t*>(clock + 0x154);

  switch (mode) {
  case 0:
    phase = secOfHour;
    break;
  case 1:
    phase = secOfHour - DAT_009cca58; // -900
    break;
  case 2:
    phase = secOfHour - DAT_009d25a4; // -1800
    break;
  case 3:
    phase = secOfHour - DAT_009d25a0; // -2700
    break;
  default:
    goto after_scale;
  }
  phase = phase * DAT_00aaace0; // * (1/900)

after_scale:
  if (DAT_00b04750 == secOfHour) {
    float dt = static_cast<float>(static_cast<int32_t>(g_dwClientTickMs - DAT_00b0474c));
    if (static_cast<int32_t>(g_dwClientTickMs - DAT_00b0474c) < 0) {
      dt = dt + DAT_00aaa5dc; // + 2^32
    }
    phase = dt * g_flMsToSeconds_Inferred * DAT_00aaace0 + phase;
  } else {
    DAT_00b0474c = g_dwClientTickMs;
    DAT_00b04750 = secOfHour;
  }

  if (g_flOne <= phase) {
    return g_flOne;
  }
  if (0.0f <= phase) {
    return phase;
  }
  return 0.0f;
}
