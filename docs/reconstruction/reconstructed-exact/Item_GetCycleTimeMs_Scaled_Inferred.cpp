// =============================================================================
// Item_GetCycleTimeMs_Scaled_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0056a680
// Address:   0x0056a680–0x0056a765  (autoassault.exe, image base 0x400000)
// System:    item / weapon combat stats
// Generated: 2026-07-29 W25-L dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler + byte CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Return cycle / fire-interval milliseconds from this+0xD0. When bSkipScale==0
//   and related object (MI +0xB0) yields a non-1.0 float scale via vtbl+0x214 →
//   blob+0x1E8, return max(500, round(scale * baseMs)). Callers use result as
//   DPS and tac-arc time denominator (× g_flMsToSeconds).
//
// ABI:
//   thiscall (ECX=this). Stack char bSkipScale. ret 4. EAX = int ms.
//
// GLOBALS:
//   g_flOne                @ 0x00a0f2a0 = 1.0f
//   g_flMissionXpRoundBias @ 0x00aaa6d0 ≈ 0.5001f  (shared float→int bias)
//
// CALLEES: FUN_0040dab0
// CALLERS: CVOGTacArc_UpdateMesh, UI_BuildItemTooltipStats, FUN_0087d810 (DPS),
//          FUN_005fe6a0, FUN_004f79d0, FUN_00509c70, FUN_00902c40, … (21 xrefs)
// =============================================================================

#include <cstdint>

extern float g_flOne;                 // 0x00a0f2a0
extern float g_flMissionXpRoundBias;  // 0x00aaa6d0
extern "C" int FUN_0040dab0(float x);

// Offsets sealed from live decompile + bytes (product type names open).
// this+0x04 : adj cookie; this+0xD0 : base cycle ms
// related via *(this + *( *(this+4)+4 ) + 0xB0)
// blob from related vtbl+0x214; scale float at blob+0x1E8

int Item_GetCycleTimeMs_Scaled_Inferred(void* this_item, char bSkipScale)
{
  if (bSkipScale == '\0') {
    int adj = *reinterpret_cast<int*>(
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this_item) + 4) + 4);
    int* related = *reinterpret_cast<int**>(
        reinterpret_cast<char*>(this_item) + adj + 0xB0);
    if (related != nullptr) {
      using VFunc = void* (*)(void*);
      void** vtbl = *reinterpret_cast<void***>(related);
      void* blob = reinterpret_cast<VFunc>(vtbl[0x214 / 4])(related);
      if (blob != nullptr) {
        float scale = *reinterpret_cast<float*>(reinterpret_cast<char*>(blob) + 0x1E8);
        if (scale != g_flOne) {
          int baseMs = *reinterpret_cast<int*>(reinterpret_cast<char*>(this_item) + 0xD0);
          float product = scale * static_cast<float>(baseMs);
          float forCmp = (product >= 0.0f)
              ? product + g_flMissionXpRoundBias
              : product - g_flMissionXpRoundBias;
          if (static_cast<int>(forCmp) > 500)
            return FUN_0040dab0(product);
          return 500;
        }
      }
    }
  }
  return *reinterpret_cast<int*>(reinterpret_cast<char*>(this_item) + 0xD0);
}
