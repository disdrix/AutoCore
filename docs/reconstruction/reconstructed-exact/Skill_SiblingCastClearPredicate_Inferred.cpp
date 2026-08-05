// =============================================================================
// Skill_SiblingCastClearPredicate_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00512bb0
// Address:   0x00512bb0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: inventory gap plate; dual A/B body seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler + asm CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   List-predicate for Skill_SiblingCastClear / FUN_00517400 inline walk.
//   Type-1 CVOGHBSkillBase: skillId @+0x620 + partial source TFID @+0x658.
//   Type-8 CVOGHBOKToCastAgain (ctx.flag≠0): skillId via hb+0x24 → +0x5fc.
//   On match: thiscall hb.vtbl+0x18(1,0); return 1 (remove). Else 0 (keep).
//
// ABI (asm sealed):
//   __stdcall; RET 0x0C; formals (pHb, pCtx, pStopUnused)
//   pStopUnused never written → list utility removes ALL matches
//
// See: reviews/A|B_aa_00512bb0_Skill_SiblingCastClearPredicate.md
//      parent aa_00514e20 Skill_SiblingCastClear.cpp
// =============================================================================

#include <cstdint>

struct SiblingCastClearCtx {
  std::uint32_t skillId;           // +0x00
  std::uint32_t _padUnset;         // +0x04 never written by packers
  std::uint32_t tfid0;             // +0x08
  std::uint32_t tfid1;             // +0x0c
  std::uint32_t tfid2;             // +0x10  (only low byte compared)
  std::uint32_t tfid3;             // +0x14  unused by predicate
  std::uint8_t  alsoOkToCastAgain; // +0x18
};

// MSVC RTTI helpers (retail calls __RTDynamicCast)
extern "C" void *__cdecl __RTDynamicCast(void *in, long vfDelta,
                                         void *srcType, void *targetType,
                                         int isReference);

// type_info descriptors (image constants)
extern "C" void CVOGHBBase_RTTI_Type_Descriptor;           // VA 0x00af8d98
extern "C" void CVOGHBSkillBase_RTTI_Type_Descriptor;      // VA 0x00af8cec
extern "C" void CVOGHBOKToCastAgain_RTTI_Type_Descriptor;  // VA 0x00b0015c

// int __stdcall — return 0 keep / 1 remove
extern "C" int __stdcall Skill_SiblingCastClearPredicate_INFERRED(
    void *pHb,
    SiblingCastClearCtx *pCtx,
    void * /*pStopUnused*/)
{
  const int type = *reinterpret_cast<int *>(reinterpret_cast<char *>(pHb) + 0x1c);
  void *hbCast = nullptr;
  bool match = false;

  if (type == 1) {
    hbCast = __RTDynamicCast(
        pHb, 0,
        &CVOGHBBase_RTTI_Type_Descriptor,
        &CVOGHBSkillBase_RTTI_Type_Descriptor,
        0);
    auto *b = reinterpret_cast<char *>(hbCast);
    if (*reinterpret_cast<int *>(b + 0x620) != static_cast<int>(pCtx->skillId)) {
      return 0;
    }
    if (*reinterpret_cast<std::uint32_t *>(b + 0x658) != pCtx->tfid0) {
      return 0;
    }
    if (*reinterpret_cast<std::uint32_t *>(b + 0x65c) != pCtx->tfid1) {
      return 0;
    }
    // asm: cmp dl, [ctx+0x10] — low byte of third TFID dword only
    match = (*reinterpret_cast<std::uint8_t *>(b + 0x660) ==
             static_cast<std::uint8_t>(pCtx->tfid2 & 0xff));
  } else {
    if (pCtx->alsoOkToCastAgain == 0) {
      return 0;
    }
    if (type != 8) {
      return 0;
    }
    hbCast = __RTDynamicCast(
        pHb, 0,
        &CVOGHBBase_RTTI_Type_Descriptor,
        &CVOGHBOKToCastAgain_RTTI_Type_Descriptor,
        0);
    void *pSkill =
        *reinterpret_cast<void **>(reinterpret_cast<char *>(hbCast) + 0x24);
    match = (*reinterpret_cast<int *>(reinterpret_cast<char *>(pSkill) + 0x5fc) ==
             static_cast<int>(pCtx->skillId));
  }

  if (!match) {
    return 0;
  }

  // thiscall vtbl+0x18(1, 0) — Stop/End family (product English open)
  using StopFn = void(__thiscall *)(void *self, int a, int b);
  auto **vtbl = *reinterpret_cast<StopFn ***>(hbCast);
  vtbl[0x18 / sizeof(void *)](hbCast, 1, 0);
  return 1;
}
