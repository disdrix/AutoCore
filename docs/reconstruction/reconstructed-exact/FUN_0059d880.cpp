// =============================================================================
// FUN_0059d880  (scaffold alias — prefer CVOGObjective_GetCompleteCount.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0059d880
// Address:   0x0059d880  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 scaffold; 2026-07-29 dual residual plate refresh
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Objective CompleteCount getter — return *(this + 0x164).
// Product tag sealed: <CompleteCount> via FUN_005468c0 dump path.
// Named clean: CVOGObjective_GetCompleteCount.cpp
//
// BODY: mov eax,[ecx+0x164]; ret   (hex 8b 81 64 01 00 00 c3)
// =============================================================================

#include <cstdint>

uint32_t /* width from decompiler */ __fastcall FUN_0059d880(int param_1)
{
  return *(uint32_t /* width from decompiler */ *)(param_1 + 0x164);
}
