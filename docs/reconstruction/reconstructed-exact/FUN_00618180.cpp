// =============================================================================
// FUN_00618180  — scaffold twin of CVOGHBSkill_Common_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00618180
// Address:   0x00618180  (autoassault.exe, image base 0x400000)
// Body:      0x00618180 – 0x00618265 inclusive (230 B / 0xE6)
// System:    skills-abilities
// Generated: 2026-08-05 R11-014 dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + machine-corrected
//            float store at +0x6c4. Prefer CVOGHBSkill_Common_ctor.cpp.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void *__thiscall CVOGHBSkillBase_ctor(
    void *thisHb, void *p2, void *p3, std::uint32_t p4, void *p5, void *p6,
    std::uint32_t p7);
extern "C" float __fastcall CVOGHBBase_GetRemainingSeconds(void *thisHb);
extern "C" void __thiscall CVOGHBBase_SetPeriodAndCounter(void *thisHb, int a,
                                                          bool b);
extern "C" void *PTR_FUN_009e1f2c;
extern "C" float DAT_00a0f694; // 30.0f

extern "C" void *__thiscall FUN_00618180(
    void *param_1, void *param_2, void *param_3, std::uint32_t param_4,
    void *param_5, void *param_6, std::uint32_t param_7, std::uint8_t param_8,
    float param_9 /* decompiler shows int; bytes are movss float */)
{
  auto *self = static_cast<std::uint8_t *>(param_1);
  auto *dw = static_cast<std::uint32_t *>(param_1);

  CVOGHBSkillBase_ctor(param_1, param_2, param_3, param_4, param_5, param_6,
                       param_7);

  std::uint8_t iVar1 = self[0x44];
  *dw = reinterpret_cast<std::uint32_t>(&PTR_FUN_009e1f2c);
  self[0x6c0] = param_8;
  *reinterpret_cast<float *>(self + 0x6c4) = param_9;
  dw[0x1b2] = 0; // +0x6c8

  if (iVar1 != 0 && param_5 != nullptr) {
    int *pSub = *reinterpret_cast<int **>(static_cast<std::uint8_t *>(param_5) +
                                          0xa4);
    if (pSub != nullptr &&
        *reinterpret_cast<char *>(reinterpret_cast<std::uint8_t *>(pSub) +
                                  0xf6) != 0) {
      float fVar2 = CVOGHBBase_GetRemainingSeconds(param_1);
      if (DAT_00a0f694 < fVar2) {
        if (1 < static_cast<int>(dw[3])) { // +0x0C nPeriodSentinel
          CVOGHBBase_SetPeriodAndCounter(
              param_1, static_cast<int>(30000u / dw[2]), true); // / +0x08
          return param_1;
        }
        dw[2] = 30000; // +0x08 nPeriodMs
      }
    }
  }
  return param_1;
}
