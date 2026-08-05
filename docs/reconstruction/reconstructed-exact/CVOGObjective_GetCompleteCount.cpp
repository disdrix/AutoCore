// =============================================================================
// CVOGObjective_GetCompleteCount
// -----------------------------------------------------------------------------
// Stable ID: aa_0059d880
// Address:   0x0059d880  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-29 dual residual seal (from raw aa_0059d880)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (static seal only).
// =============================================================================
//
// PURPOSE:
//   Return objective template field CompleteCount at this+0x164.
//   Product English sealed by FUN_005468c0 XML dump:
//     fprintf(..., "\t\t<CompleteCount>%i</CompleteCount>\r\n", GetCompleteCount());
//
//   Production callers:
//     - CVOGReaction_CompleteObjective (0x00533f90) — min required pass gate (dual CALL)
//     - CVOGCharacter_EvaluatePendingObjectives (0x00534920) — collect threshold (dual CALL)
//     - FUN_005468c0 (0x005468c0) — objective XML serialize
//
//   Sibling setter (not this unit): FUN_0059d890 @ 0x0059d890 writes +0x164.
//
// BODY (asm / memory):
//   0059d880  mov eax, [ecx+0x164]     ; 8b 81 64 01 00 00
//   0059d886  ret                     ; c3
//
// ABI: __thiscall (ECX = objective). No stack formals. Return dword in EAX.
// =============================================================================

#include <cstdint>

// Ghidra also presents as __fastcall; single-reg this is equivalent.
std::uint32_t __thiscall CVOGObjective_GetCompleteCount(void* objective /* ECX */)
{
  return *reinterpret_cast<std::uint32_t*>(
      reinterpret_cast<std::uint8_t*>(objective) + 0x164);
}

// FUN_ alias for call-graph fidelity with unrenamed parents:
std::uint32_t __fastcall FUN_0059d880(void* objective)
{
  return CVOGObjective_GetCompleteCount(objective);
}
