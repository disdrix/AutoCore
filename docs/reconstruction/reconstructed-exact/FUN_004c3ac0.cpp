// =============================================================================
// FUN_004c3ac0  (alias of CVOGObject_GetActivePositionPtr_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004c3ac0
// Address:   0x004c3ac0  (autoassault.exe, image base 0x400000)
// System:    object pose
// Generated: 2026-07-23 scaffold; 2026-07-29 W20-O dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual A/B: accept — see CVOGObject_GetActivePositionPtr_Inferred.cpp
// =============================================================================

#include <cstdint>

// PURPOSE: Leaf three-way active position pointer selector.
// See named clean: CVOGObject_GetActivePositionPtr_Inferred.cpp

int __fastcall FUN_004c3ac0(int param_1)
{
  int iVar1;

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
  if ((*(unsigned char *)(iVar1 + 0xb8 + param_1) & 7) == 0) {
    return param_1 + 0x240;
  }
  if (*(int *)(param_1 + 8) != 0) {
    return *(int *)(*(int *)(param_1 + 8) + 0x3c) + 0xb0;
  }
  return iVar1 + param_1 + 0x84;
}
