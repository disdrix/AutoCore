// =============================================================================
// FUN_00522020  (machine twin of Character_SelectInventoryGridByMode_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00522020
// Address:   0x00522020  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 MEGA-045 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Canonical named: Character_SelectInventoryGridByMode_Inferred
// =============================================================================

#include <cstdint>

// __thiscall: ECX = this (Character*); stack mode; RET 4; EAX = InventoryGrid* or 0
uint32_t __thiscall FUN_00522020(int param_1 /* Character* this */, int param_2 /* mode */)
{
  if (param_2 == 1) {
    if (*reinterpret_cast<int*>(param_1 + 0x250) != 0) {
      return *reinterpret_cast<uint32_t*>(
          *reinterpret_cast<int*>(param_1 + 0x250) + 0x2B0);
    }
  } else {
    if (param_2 == 3) {
      return *reinterpret_cast<uint32_t*>(param_1 + 0xCBC);
    }
    if (param_2 == 5) {
      return *reinterpret_cast<uint32_t*>(param_1 + 0xCE0);
    }
  }
  return 0;
}
