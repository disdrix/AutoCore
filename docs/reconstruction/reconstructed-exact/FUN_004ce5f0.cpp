// =============================================================================
// FUN_004ce5f0  (scaffold alias → Character_HostModeGateForObjectV210)
// -----------------------------------------------------------------------------
// Stable ID: aa_004ce5f0
// Address:   0x004ce5f0–0x004ce632  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer / equip / hardpoint gates
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W19-F)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Prefer clean plate: reconstructed-exact/Character_HostModeGateForObjectV210.cpp

#include <cstdint>

bool __thiscall FUN_004ce5f0(int param_1, int param_2)
{
  int iVar1;

  if (param_2 != 0) {
    iVar1 = (**(int(__thiscall***)(int, int))(
        *(int*)(*(int*)(*(int*)(param_2 + 4) + 4) + 4 + param_2) + 0x210))(0);
    if (iVar1 != 0) {
      if (*(char*)(param_1 + 0xf5) != '\0') {
        return true;
      }
      return *(char*)(param_1 + 0x7e) != '\0';
    }
  }
  return false;
}
