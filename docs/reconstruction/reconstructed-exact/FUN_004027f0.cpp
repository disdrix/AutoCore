// =============================================================================
// FUN_004027f0  (Ghidra twin of StdList_PushFront_DwordFromEax_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004027f0
// Address:   0x004027f0  (autoassault.exe, image base 0x400000)
// System:    missions-progression (partition) + multi-system list host
// Generated: 2026-08-05 MEGA-089 dual A/B seal (refreshed from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical named unit: StdList_PushFront_DwordFromEax_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" int FUN_00418700(int prev, int next, const uint32_t *val);
extern "C" void __fastcall FUN_00418790(uint32_t delta, int list);

// Stack list*; EAX = const dword* (modeled as second param).
void FUN_004027f0(int param_1, const uint32_t *in_EAX)
{
  int iVar1;
  int iVar2;

  iVar1 = *(int *)(param_1 + 4);
  iVar2 = FUN_00418700(iVar1, *(uint32_t *)(iVar1 + 4), in_EAX);
  FUN_00418790(1u, param_1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}
