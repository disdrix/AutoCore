// =============================================================================
// AnimSlot_SetTime
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e910
// Address:   0x0074e910  (autoassault.exe, image base 0x400000)
// Body:      0x0074e910–0x0074e9c2 (179 B; exclusive end 0x0074e9c3)
// System:    client visual / animation slot
// Generated: dual A/B seal 2026-07-29 (W21-J)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (static seal only).
// =============================================================================
//
// PURPOSE:
//   Apply playhead time + end/duration reference on a 0x78-byte anim slot:
//     +0x44 = time (clamped or fmod-wrapped by +0x4c mode)
//     +0x40 = endOrDuration (param_3)
//     +0x34 = param_3 - time / rate(+0x3c)
//     +0x50 = 0; +0x68 = 0; +0x6c = final time
//
//   Mode at +0x4c:
//     0      → clamp time into [0, +0x48]
//     nonzero → wrap via _CIfmod(time, +0x48); if < 0 add length
//
//   Production callers include Object_LoadOrReplaceAnimSlot (set 0,dur then flag),
//   AnimHost_SelectBlendSlot, and other visual anim tick/load paths (16 xrefs).
//
// ABI: __thiscall ECX=slot; two float stack args; ret 8 (c2 08 00).
// Callee: _CIfmod on wrap path only. g_flZero @ 0x00a0f518.
// =============================================================================

#include <cmath>
#include <cstdint>

// External retail symbols (names structural):
// float g_flZero;  // 0.0f at 0x00a0f518

void __thiscall AnimSlot_SetTime(void* slot /* ECX */, float time, float endOrDuration)
{
  auto* base = reinterpret_cast<std::uint8_t*>(slot);
  float* pTime = reinterpret_cast<float*>(base + 0x44);
  *pTime = time;
  *reinterpret_cast<float*>(base + 0x40) = endOrDuration;

  if (*reinterpret_cast<char*>(base + 0x4c) == 0) {
    float* pLength = reinterpret_cast<float*>(base + 0x48);
    if (*pTime > 0.0f || *pTime == 0.0f) {
      // min(time, length)
      if (!(*pTime < *pLength || *pTime == *pLength)) {
        *pTime = *pLength;
      }
      // else *pTime already <= length
    } else {
      *pTime = 0.0f;
    }
  } else {
    float length = *reinterpret_cast<float*>(base + 0x48);
    // Retail: FPU path via _CIfmod; behavior = fmod(time, length)
    float wrapped = static_cast<float>(std::fmod(static_cast<double>(*pTime),
                                                 static_cast<double>(length)));
    *pTime = wrapped;
    if (wrapped < 0.0f) {
      *pTime = length + wrapped;
    }
  }

  float rate = *reinterpret_cast<float*>(base + 0x3c);
  *reinterpret_cast<float*>(base + 0x34) = endOrDuration - (*pTime / rate);
  *reinterpret_cast<std::uint32_t*>(base + 0x50) = 0;
  *reinterpret_cast<std::uint32_t*>(base + 0x68) = 0;
  *reinterpret_cast<float*>(base + 0x6c) = *pTime;
}

// Ghidra alias
void __thiscall FUN_0074e910(void* slot, float time, float endOrDuration)
{
  AnimSlot_SetTime(slot, time, endOrDuration);
}
