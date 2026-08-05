// =============================================================================
// FUN_0074e910  (scaffold alias — prefer AnimSlot_SetTime.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e910
// Address:   0x0074e910  (autoassault.exe, image base 0x400000)
// System:    client visual / animation slot
// Generated: dual A/B seal 2026-07-29 (W21-J)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Anim slot set playhead time + end ref; clamp or fmod by +0x4c.
// Named clean: AnimSlot_SetTime.cpp
//
// BODY span: 0x0074e910–0x0074e9c2 (ret 8). Callee: _CIfmod on wrap path.
// =============================================================================

#include <cmath>
#include <cstdint>

void __thiscall FUN_0074e910(int param_1, float param_2, float param_3)
{
  float* pfVar1 = reinterpret_cast<float*>(param_1 + 0x44);
  *pfVar1 = param_2;
  *reinterpret_cast<float*>(param_1 + 0x40) = param_3;

  if (*reinterpret_cast<char*>(param_1 + 0x4c) == '\0') {
    float* pfVar4 = reinterpret_cast<float*>(param_1 + 0x48);
    if (0.0f < *pfVar1 || *pfVar1 == 0.0f) {
      if (*pfVar1 < *pfVar4 || *pfVar1 == *pfVar4) {
        pfVar4 = pfVar1;
      }
      *pfVar1 = *pfVar4;
    } else {
      *pfVar1 = 0.0f;
    }
  } else {
    float length = *reinterpret_cast<float*>(param_1 + 0x48);
    float fVar2 = static_cast<float>(std::fmod(static_cast<double>(*pfVar1),
                                               static_cast<double>(length)));
    *pfVar1 = fVar2;
    if (fVar2 < 0.0f) {
      *pfVar1 = *reinterpret_cast<float*>(param_1 + 0x48) + fVar2;
    }
  }

  *reinterpret_cast<float*>(param_1 + 0x34) =
      param_3 - *pfVar1 / *reinterpret_cast<float*>(param_1 + 0x3c);
  *reinterpret_cast<std::uint32_t*>(param_1 + 0x50) = 0;
  *reinterpret_cast<std::uint32_t*>(param_1 + 0x68) = 0;
  *reinterpret_cast<float*>(param_1 + 0x6c) = *pfVar1;
}
