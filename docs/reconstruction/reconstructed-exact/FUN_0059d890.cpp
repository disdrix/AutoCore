// =============================================================================
// FUN_0059d890  (scaffold alias — prefer CVOGObjective_SetCompleteCount.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0059d890
// Address:   0x0059d890  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: dual A/B seal 2026-07-29 (W21-J)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Objective CompleteCount setter — *(this + 0x164) = arg.
// Product tag sealed: <CompleteCount> via getter sibling + FUN_005468c0 dump path.
// Named clean: CVOGObjective_SetCompleteCount.cpp
//
// BODY: mov eax,[esp+4]; mov [ecx+0x164],eax; ret 4
//       (hex 8b 44 24 04 89 81 64 01 00 00 c2 04 00)
// =============================================================================

#include <cstdint>

void __thiscall FUN_0059d890(int param_1, std::uint32_t param_2)
{
  *reinterpret_cast<std::uint32_t*>(param_1 + 0x164) = param_2;
}
