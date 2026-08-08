// =============================================================================
// MissionReqHost_LazyFillMatchRefFromSkill_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0060c3c0
// Address:   0x0060c3c0–0x0060c3fc  (autoassault.exe, image base 0x400000)
// Body:      60 B / 0x3C; terminal plain RET (C3); pad CC
// System:    skills-abilities (materialize harvest) / missions-progression (reqHost)
// Generated: 2026-08-05 R11-010 dual (decompile + disassemble_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI/bytes.
// Verdict:   accept-with-gaps
// Terminal:  false
// Bit-for-bit / runtime / differential: DEFERRED / OPEN
// =============================================================================
//
// PURPOSE:
//   Lazy-fill mission requirement-host match-ref fields from a temporary
//   ranked skill runtime when reqHost+0x44 is still the unset sentinel (−1).
//
//   On hit:
//     reqHost+0x44 ← skillRuntime+0x14c   (template / match id)
//     reqHost+0x48 ← (skillRuntime+0x22 != 0)  (match-by-obj-ref / template mode)
//     operator_delete(skillRuntime)
//   On miss or already-set: no write (miss leaves +0x44 as −1).
//
// ABI:    MSVC __thiscall (ECX = reqHost); no stack args; plain RET; void.
//
// SOLE CALLER (sealed):
//   CVOGHBMissionEscort_ctor (0x006507c0) @ 0x00650835
//     MOV ECX,EDI  ; reqHost
//     CALL 0060c3c0
//     then copies reqHost+0x44 → escort+0x2c, reqHost+0x48 → escort+0x30
//
// CALLEES:
//   CVOGReaction_ResolveSkillTargets (0x0054c570) — dualed aa_0054c570; cdecl
//   operator_delete (0x00489822) — free temporary 0x630 runtime
//
// DECOMPILER CORRECTIONS:
//   - Not __fastcall multi-arg; thiscall ECX only
//   - in_EAX / CONCAT22 phantom → MOV AX,[ESI+0x14]; PUSH EAX (rank word)
//   - operator_delete DOES return (ADD ESP,4; POP ESI; RET)
//   - puVar1[0x53] ≡ skill+0x14c
//
// GAPS:
//   - Product/PDB English for reqHost class
//   - Full skill+0x14c product name beyond dualed "template id"
//   - Runtime / bit-exact
// =============================================================================

#include <cstdint>

// Dualed aa_0054c570: map-lookup skillId, clone 0x630 runtime, apply rank word.
// Returns null on map miss (end sentinel). Caller owns free.
extern "C" void* __cdecl CVOGReaction_ResolveSkillTargets(int skillId, int rankPacked);
extern "C" void  __cdecl operator_delete(void* p);

// reqHost layout (fields touched by this unit only)
//   +0x10  int32  skillId
//   +0x14  uint16 rank
//   +0x44  int32  targetMatchRef   (−1 = unset)
//   +0x48  uint8  matchByObjRefMode

void __thiscall MissionReqHost_LazyFillMatchRefFromSkill_Inferred(void* reqHost /* ECX */)
{
  if (*reinterpret_cast<std::int32_t*>(reinterpret_cast<char*>(reqHost) + 0x44) != -1) {
    return;
  }

  const int skillId =
      *reinterpret_cast<std::int32_t*>(reinterpret_cast<char*>(reqHost) + 0x10);
  // Image: MOV AX,[ESI+0x14]; PUSH EAX  — rank word in low 16 of pushed dword
  const int rankPacked = static_cast<int>(
      *reinterpret_cast<std::uint16_t*>(reinterpret_cast<char*>(reqHost) + 0x14));

  void* skill = CVOGReaction_ResolveSkillTargets(skillId, rankPacked);
  if (skill == nullptr) {
    return; // leave +0x44 = -1
  }

  *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(reqHost) + 0x44) =
      *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(skill) + 0x14c);

  *reinterpret_cast<std::uint8_t*>(reinterpret_cast<char*>(reqHost) + 0x48) =
      (*reinterpret_cast<std::uint8_t*>(reinterpret_cast<char*>(skill) + 0x22) != 0)
          ? static_cast<std::uint8_t>(1)
          : static_cast<std::uint8_t>(0);

  operator_delete(skill);
}
