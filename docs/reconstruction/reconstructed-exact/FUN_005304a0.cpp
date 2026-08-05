// =============================================================================
// FUN_005304a0 / CVOGCharacter_UpsertSkillRankAndReapply_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005304a0
// Address:   0x005304a0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / character
// Generated: 2026-07-23 scaffold; refined 2026-07-29 W16-R dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI fixes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Walk character skill-bag vector [this+0x550, this+0x554) stride 0xC.
//   Match entry.skill->(+0x5fc) == skillId.
//     HIT:  Skill_SetRankAndReevaluate(skill, rank); entry.meta = param_4;
//           reapply local effects by skillId.
//     MISS: skill = CVOGReaction_ResolveSkillTargets(skillId, rank);
//           if skill: push_back {skill, param_4, flag=1} on vector this+0x54c;
//                     reapply local effects by skillId.
//
// ABI (bytes 2026-07-29):
//   __thiscall ECX=character; 3 stack args; RET 0xC.
//   SetRank: thiscall skill + 1 stack rank (NO unaff_DI — decomp phantom).
//   FUN_0053aea0: thiscall ECX=character+0x54c, arg=&triple (not free fn on triple alone).
//   FUN_00514e70: this-adjust then skillId.
//
// CALLERS: AwardMedalById chain; create-from-packet; FUN_00623960 skill slots.

#include <cstdint>

// Materialize 0x630 skill runtime by id+rank; null on map miss. __cdecl.
extern "C" std::uint32_t* __cdecl CVOGReaction_ResolveSkillTargets(void* skillId, void* rankPacked);
// Vector push_back of 0xC element (capacity or grow). thiscall on bag vector.
extern "C" void __thiscall FUN_0053aea0(void* bagVector /*ECX*/, void* elemRef);
// Set skill+0x5f6 rank word + reevaluate. thiscall; one stack arg; RET 4.
extern "C" void __thiscall Skill_SetRankAndReevaluate(void* skill /*ECX*/, void* rankPacked);
// Re-apply local skill effects by id. thiscall host; one stack skillId.
extern "C" void __thiscall FUN_00514e70(void* host /*ECX*/, void* skillId);

static inline void* host_this_adjust(void* character)
{
  // Bytes: mov eax,[edi+4]; mov ecx,[eax+4]; lea ecx,[ecx+edi+4]
  auto* p = *reinterpret_cast<std::uint8_t**>(reinterpret_cast<char*>(character) + 4);
  auto  delta = *reinterpret_cast<std::int32_t*>(p + 4);
  return reinterpret_cast<void*>(delta + reinterpret_cast<std::intptr_t>(character) + 4);
}

void __thiscall FUN_005304a0(int param_1, void* param_2, void* param_3, int param_4)
{
  int* piVar1;
  std::uint32_t* local_c;
  int local_8;
  std::uint8_t local_4;

  // param_1 is this (character) under thiscall.
  piVar1 = *reinterpret_cast<int**>(param_1 + 0x550);
  while (true) {
    if (piVar1 == *reinterpret_cast<int**>(param_1 + 0x554)) {
      // Miss path: materialize
      local_c = CVOGReaction_ResolveSkillTargets(param_2, param_3);
      if (local_c != nullptr) {
        local_8 = param_4;
        local_4 = 1;
        // Bytes: LEA ECX,[this+0x54c]; PUSH &{local_c,local_8,local_4}
        FUN_0053aea0(reinterpret_cast<void*>(param_1 + 0x54c), &local_c);
        FUN_00514e70(host_this_adjust(reinterpret_cast<void*>(param_1)), param_2);
      }
      return;
    }
    if (*reinterpret_cast<void**>(*piVar1 + 0x5fc) == param_2)
      break;
    piVar1 = piVar1 + 3;
  }

  // Hit path — SetRank(this=skill, rank only). unaff_DI from raw decomp is NOT an arg.
  Skill_SetRankAndReevaluate(reinterpret_cast<void*>(*piVar1), param_3);
  piVar1[1] = param_4;
  FUN_00514e70(host_this_adjust(reinterpret_cast<void*>(param_1)), param_2);
  return;
}
