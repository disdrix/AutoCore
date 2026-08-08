// =============================================================================
// FUN_00522000  (twin of Character_GetEquipTfidTableCount_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00522000
// Address:   0x00522000  (autoassault.exe, image base 0x400000)
// Body:      0x00522000–0x00522016 (23 B)
// System:    inventory-transfer
// Dual:      MEGA-100 2026-08-05
// Exactness: Behavior-preserving rewrite of sealed CF + ABI. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Equip TFID table count for Character (this+0x5a0 array bound).
// Canonical name: Character_GetEquipTfidTableCount_Inferred
// See Character_GetEquipTfidTableCount_Inferred.cpp for full plate.

#include <cstdint>

std::uint8_t __fastcall FUN_00522000(void* character /*ECX*/)
{
  auto* base = static_cast<std::uint8_t*>(character);
  unsigned count = (static_cast<unsigned>(base[0x59a]) >> 1u) + 3u;
  if (count > 7u) {
    count = 8u;
  }
  return static_cast<std::uint8_t>(count);
}
