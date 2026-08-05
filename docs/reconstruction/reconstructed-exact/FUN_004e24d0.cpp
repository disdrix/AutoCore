// =============================================================================
// FUN_004e24d0 — scaffold alias for Mem_MoveDwordRange_ToExclusiveEnd
// -----------------------------------------------------------------------------
// Stable ID: aa_004e24d0
// Address:   0x004e24d0  (autoassault.exe, image base 0x400000)
// System:    stl-helpers
// Generated: 2026-07-29 W20-H dual seal
// Exactness: Behavior-preserving. See Mem_MoveDwordRange_ToExclusiveEnd.cpp.
// =============================================================================

#include <cstring>
#include <cstddef>

// Ghidra scaffold name — prefer Mem_MoveDwordRange_ToExclusiveEnd
void FUN_004e24d0(void *param_1, int param_2, int param_3)
{
  int iVar1;

  iVar1 = param_2 - (int)param_1 >> 2;
  memmove((void *)(param_3 + iVar1 * -4), param_1, (size_t)(iVar1 * 4));
  return;
}
