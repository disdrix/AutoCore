// =============================================================================
// Character_TownInventoryFallback_Inferred  (FUN_004ce5c0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004ce5c0
// Address:   0x004ce5c0–0x004ce5e3  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 MEGA-118 dual A/B seal (raw + live decompile/read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Leaf mode-gate used when inventory free-slot search fails or when
// inventory-move mode 3 (locker / char+0xcbc) is selected.
//   - Null character* → false
//   - Else true if modeHost+0xf5, else (modeHost+0x7e != 0)
// True → parents rebind free-slot / move work to character locker grid +0xcbc.
// Product English for flags and "town" vs "locker" remains open → _Inferred.
//
// ABI: __thiscall — ECX=modeHost, stack character*; ret 4 (c2 04 00).
// Parent-seed Named_CalleeOf_Client_SendInventoryUnequip is incomplete
// (also FUN_008012f0 ×2).
//

#include <cstdint>

bool __thiscall Character_TownInventoryFallback_Inferred(int modeHost, int character)
{
  if (character == 0) {
    return false;
  }
  if (*(char *)(modeHost + 0xf5) != '\0') {
    return true;
  }
  return *(char *)(modeHost + 0x7e) != '\0';
}

// Ghidra alias
bool __thiscall FUN_004ce5c0(int param_1, int param_2)
{
  return Character_TownInventoryFallback_Inferred(param_1, param_2);
}
