// =============================================================================
// Character_HostModeGateForObjectV210  (FUN_004ce5f0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004ce5f0
// Address:   0x004ce5f0–0x004ce632  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer / equip / hardpoint gates
// Generated: 2026-07-29 W19-F dual A/B seal (from raw + live decompile/read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Leaf gate used by vehicle/equip and hardpoint paths.
//   - Null object → false
//   - Object MI-adjusted this → vtbl+0x210(0); null result → false
//   - Else true if host+0xf5, else (host+0x7e != 0)
// Product English for host flags and vfunc+0x210 open.
//
// ABI: __thiscall — ECX=host, stack object*; ret 4 (c2 04 00).
// Parent-seed Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem is incomplete.
//

#include <cstdint>

bool __thiscall Character_HostModeGateForObjectV210(int host, int object)
{
  int iVar1;

  if (object != 0) {
    // Bytes: lea ecx, [*( *(object+4)+4 ) + object + 4]; push 0; call [vtbl+0x210]
    iVar1 = (**(int(__thiscall***)(int, int))(
        *(int*)(*(int*)(*(int*)(object + 4) + 4) + 4 + object) + 0x210))(0);
    if (iVar1 != 0) {
      if (*(char*)(host + 0xf5) != '\0') {
        return true;
      }
      return *(char*)(host + 0x7e) != '\0';
    }
  }
  return false;
}

// Ghidra alias
bool __thiscall FUN_004ce5f0(int param_1, int param_2)
{
  return Character_HostModeGateForObjectV210(param_1, param_2);
}
