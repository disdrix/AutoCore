// =============================================================================
// Skill_SiblingCastClear
// -----------------------------------------------------------------------------
// Stable ID: aa_00514e20
// Address:   0x00514e20  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 scaffold; dual strengthen 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler + asm CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Clear matching cast heartbeats from host HB list at +0xB0.
//   Type-1 CVOGHBSkillBase: skillId + partial source TFID.
//   Type-8 CVOGHBOKToCastAgain (flag≠0): skillId via hb+0x24 → +0x5fc.
//   On match: hb.vtbl+0x18(1,0) then list node remove.
//
// ABI (asm sealed):
//   __thiscall; RET 0x18; list = *(this+0xB0)
//
// Callers:
//   Skill_ApplyStatusEffectLocal (flag 0)
//   FUN_00514e70 (flag 0; skill+0x615 path)
//   FUN_0052db50 (flag 1; also OKToCastAgain)
//
// See: reviews/A|B_aa_00514e20_Skill_SiblingCastClear.md

#include <cstdint>

// Forward (named elsewhere)
void CNDDoubleList_InvokePredicateAndRemove_Inferred(
    void *list, void *predicate, void *ctx, char nullPayloadFlag);

// Predicate VA 0x00512bb0 — Ghidra: Skill_SiblingCastClearPredicate_INFERRED
extern "C" int Skill_SiblingCastClearPredicate_INFERRED(void *payload, void *ctx /*, char *stop */);

struct SiblingCastClearCtx {
  std::uint32_t skillId;     // +0x00
  std::uint32_t _padUnset;   // +0x04 never written by body
  std::uint32_t tfid0;       // +0x08
  std::uint32_t tfid1;       // +0x0c
  std::uint32_t tfid2;       // +0x10
  std::uint32_t tfid3;       // +0x14
  std::uint8_t  alsoOkToCastAgain; // +0x18
};

// __thiscall
void Skill_SiblingCastClear(
    void *pHost,
    std::uint32_t nSkillId,
    std::uint32_t tfid0,
    std::uint32_t tfid1,
    std::uint32_t tfid2,
    std::uint32_t tfid3,
    std::uint8_t bAlsoOkToCastAgain)
{
  SiblingCastClearCtx ctx{};
  ctx.skillId = nSkillId;
  ctx.tfid0 = tfid0;
  ctx.tfid1 = tfid1;
  ctx.tfid2 = tfid2;
  ctx.tfid3 = tfid3;
  ctx.alsoOkToCastAgain = bAlsoOkToCastAgain;

  void *list = *reinterpret_cast<void **>(reinterpret_cast<char *>(pHost) + 0xB0);

  CNDDoubleList_InvokePredicateAndRemove_Inferred(
      list,
      reinterpret_cast<void *>(&Skill_SiblingCastClearPredicate_INFERRED),
      &ctx,
      /*nullPayloadFlag=*/0);
}
