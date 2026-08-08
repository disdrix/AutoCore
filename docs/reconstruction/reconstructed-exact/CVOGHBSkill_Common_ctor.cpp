// =============================================================================
// CVOGHBSkill_Common_ctor  (FUN_00618180)
// -----------------------------------------------------------------------------
// Stable ID: aa_00618180
// Address:   0x00618180  (autoassault.exe, image base 0x400000)
// Body:      0x00618180 – 0x00618265 inclusive (230 B / 0xE6); Ghidra end 00618267
// System:    skills-abilities
// Generated: 2026-08-05 R11-014 dual seal (decompile_function + read_memory)
//
// Class:     CVOGHBSkill_Common  (RTTI Confirmed ".?AVCVOGHBSkill_Common@@")
// Vtbl:      PTR_FUN_009e1f2c  (COL 0x00ab1820 → type_info 0x00af2918)
// Size:      0x6d0 at direct operator_new callers; Virus subclass 0x6e0
//
// Purpose: Construct shared skill HB "Common":
//   1) CVOGHBSkillBase_ctor(p2..p7)
//   2) Install Common vtbl
//   3) Seed +0x6c0 byte, +0x6c4 float, +0x6c8 = 0
//   4) Optional remaining-time period clamp/rescale when target gate holds
//
// ABI:     __thiscall; 8 stack args; ret 0x20; EAX = this
// Exactness: Behavior-preserving CF (live decompile + read_memory).
// Bit-for-bit / runtime: OPEN.
// =============================================================================

#include <cstdint>

extern "C" void *__thiscall CVOGHBSkillBase_ctor(
    void *thisHb, void *pSourceObj, void *pSkillBlob, std::uint32_t arg4,
    void *pTarget, void *pTfid16, std::uint32_t arg7);
extern "C" float __fastcall CVOGHBBase_GetRemainingSeconds(void *thisHb);
extern "C" void __thiscall CVOGHBBase_SetPeriodAndCounter(void *thisHb,
                                                          int nPeriodSentinel,
                                                          bool bAlsoSetCounter);

// Common vtbl in .rdata
extern "C" void *PTR_FUN_009e1f2c;
// Threshold: remaining seconds must exceed this for period adjust
extern "C" float DAT_00a0f694; // 30.0f

// SEH registration (MSVC) — preserved as opaque for fidelity notes only
extern "C" void *LAB_009a8708;
extern "C" void *ExceptionList;

extern "C" void *__thiscall CVOGHBSkill_Common_ctor(
    void *thisHb, void *pSourceObj, void *pSkillBlob, std::uint32_t arg4,
    void *pTarget, void *pTfid16, std::uint32_t arg7, std::uint8_t commonFlag,
    float commonScale)
{
  auto *self = static_cast<std::uint8_t *>(thisHb);
  auto *dw = static_cast<std::uint32_t *>(thisHb);

  // SEH frame omitted in port body; retail installs LAB_009a8708.

  CVOGHBSkillBase_ctor(thisHb, pSourceObj, pSkillBlob, arg4, pTarget, pTfid16,
                       arg7);

  // Gate snapshot is skill-blob byte at +0x44 (machine: cmp [esi+0x44], 0)
  const std::uint8_t gateBlobFlag = self[0x44];

  *dw = reinterpret_cast<std::uint32_t>(&PTR_FUN_009e1f2c); // vtbl
  self[0x6c0] = commonFlag;
  *reinterpret_cast<float *>(self + 0x6c4) = commonScale; // movss — not int
  dw[0x1b2] = 0;                                          // +0x6c8

  if (gateBlobFlag != 0 && pTarget != nullptr) {
    void *sub = *reinterpret_cast<void **>(static_cast<std::uint8_t *>(pTarget) +
                                           0xa4);
    if (sub != nullptr &&
        *reinterpret_cast<std::uint8_t *>(static_cast<std::uint8_t *>(sub) +
                                          0xf6) != 0) {
      float rem = CVOGHBBase_GetRemainingSeconds(thisHb);
      if (DAT_00a0f694 < rem) {
        int sentinel = static_cast<int>(dw[3]); // +0x0C
        if (1 < sentinel) {
          std::uint32_t periodMs = dw[2]; // +0x08
          CVOGHBBase_SetPeriodAndCounter(
              thisHb, static_cast<int>(30000u / periodMs), true);
          return thisHb;
        }
        dw[2] = 30000; // +0x08 pulse period ms
      }
    }
  }
  return thisHb;
}

// Ghidra alias
extern "C" void *__thiscall FUN_00618180(
    void *thisHb, void *p2, void *p3, std::uint32_t p4, void *p5, void *p6,
    std::uint32_t p7, std::uint8_t p8, float p9)
{
  return CVOGHBSkill_Common_ctor(thisHb, p2, p3, p4, p5, p6, p7, p8, p9);
}
