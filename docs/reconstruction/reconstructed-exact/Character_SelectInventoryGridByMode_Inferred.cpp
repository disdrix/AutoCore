// =============================================================================
// Character_SelectInventoryGridByMode_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00522020
// Address:   0x00522020  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Ghidra:    FUN_00522020
// Generated: 2026-08-05 MEGA-045 dual seal (raw + disassemble_function + read_memory)
// Exactness: Behavior-preserving; not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: Select a Character-owned InventoryGrid* by inventory mode integer.
//   mode 1 → *(*(ch+0x250)+0x2B0)  cargo (null mid → 0)
//   mode 3 → *(ch+0xCBC)           locker (cross-dual invType 3)
//   mode 5 → *(ch+0xCE0)           trade  (cross-dual invType 5)
//   else   → 0
//
// ABI: __thiscall (ECX = Character*); one stack dword (mode); RET 4; EAX = grid*.
// Leaf — no callees.
//
// REJECT: scaffold Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_00522020

#include <cstdint>

struct Character;
struct InventoryGrid;

// Returns InventoryGrid* or nullptr.
InventoryGrid* __thiscall Character_SelectInventoryGridByMode_Inferred(
    Character* self,
    int mode)
{
  if (mode == 1) {
    auto* mid = *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(self) + 0x250);
    if (mid != nullptr) {
      return *reinterpret_cast<InventoryGrid**>(mid + 0x2B0);
    }
  } else {
    if (mode == 3) {
      return *reinterpret_cast<InventoryGrid**>(reinterpret_cast<uint8_t*>(self) + 0xCBC);
    }
    if (mode == 5) {
      return *reinterpret_cast<InventoryGrid**>(reinterpret_cast<uint8_t*>(self) + 0xCE0);
    }
  }
  return nullptr;
}
