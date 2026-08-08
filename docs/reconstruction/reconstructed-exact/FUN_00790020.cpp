// =============================================================================
// FUN_00790020  (Ghidra name twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_00790020
// Address:   0x00790020  (autoassault.exe, image base 0x400000)
// Named:     Client_Input_KeyDown_UiGateAndForward_Inferred
// System:    input-drive-control
// Generated: 2026-08-05 MEGA-094 (CF ≡ live decompile; twin of named clean)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: UI-gate + focused-UI key forward + ESC cancel/modal dispatch.
// See: reconstructed-exact/Client_Input_KeyDown_UiGateAndForward_Inferred.cpp

#include <cstdint>

uint32_t __thiscall FUN_00790020(int *param_1, int param_2, uint32_t param_3)
{
  char cVar1;
  uint32_t uVar2;

  cVar1 = (**(code **)(*param_1 + 0x3d8))();
  if (cVar1 == '\0') {
    return 0;
  }
  if (param_1[0x12f] != 0) {
    (**(code **)(*(int *)param_1[0x12f] + 0x358))(param_2, param_3);
  }
  if (param_2 == 0x1b) {
    if (param_1[0x12f] != 0) {
      (**(code **)(*param_1 + 0x3bc))(0);
      return 1;
    }
    if (-1 < param_1[0x127]) {
      uVar2 = (**(code **)(*param_1 + 0x338))(8, param_1[0x127]);
      return uVar2;
    }
  }
  return 1;
}
