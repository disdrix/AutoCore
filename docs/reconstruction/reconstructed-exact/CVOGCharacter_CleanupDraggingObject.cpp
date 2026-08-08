// =============================================================================
// CVOGCharacter_CleanupDraggingObject
// -----------------------------------------------------------------------------
// Stable ID: aa_00520dc0
// Address:   0x00520dc0 – 0x00520f39  (autoassault.exe, image base 0x400000)
// Size:      378 B (0x17A)
// System:    inventory-transfer
// Generated: 2026-08-05 MEGA-001 dual seal (assembly-corrected)
// Exactness: Behavior-preserving rewrite of retail CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Product method CVOGCharacter::CleanupDraggingObject (plate string
//   @ 0x009cf0b0). If character has a dragging object at +0xCD0:
//     1) try place into cargo grid *( *(this+0x250)+0x2B0 )
//     2) else try place into locker grid *(this+0xCBC)
//     3) else TryEquip on host *(this+0x250); on select status codes call
//        FUN_00502e90 equip switch
//   Always null +0xCD0 after non-null path. Return false if no drag object.
//
// ABI (sealed):
//   ECX = this (CVOGCharacter*)
//   stack: 4 B present (body never loads); RET 4
//   AL = bool (0 = no drag; 1 = cleaned)
//
// Decompiler traps corrected here:
//   - FindFree/Place use InventoryGrid* in ECX, not the drag item
//   - TryEquip / FUN_00502e90 use host at this+0x250 in ECX
//   - Path A cargo vs Path B locker are distinct ECX sources
//
// =============================================================================

#include <cstdint>

// Prior dual / plate names (bodies not redefined here)
extern "C" {
  std::uint32_t __thiscall Profiler_EnterNamedZone(void* prof, const char* name); // FUN_00786a00
  void          __fastcall Profiler_Leave(void* prof);                            // FUN_00786990
  // InventoryGrid_FindFreeForItem — ret 0x14
  char __thiscall InventoryGrid_FindFreeForItem(
      void* grid, void* item, std::uint8_t* outX, std::uint8_t* outY,
      char allowStackMerge, int pageIndex);                                       // FUN_005714e0
  // InventoryGrid_PlaceItemFootprint — stack item,x,y,qty (see dual)
  char __thiscall InventoryGrid_PlaceItemFootprint(
      void* grid, void* item, std::uint32_t x, std::uint32_t y, std::uint32_t qty); // FUN_00571620
  // Character_TryEquipItem — ret 8
  unsigned __thiscall Character_TryEquipItem(
      void* host, void* item, int* outOpt);                                       // FUN_004fabc0
  void* __thiscall FUN_00502e90(void* host, void* item);                           // menu_equip switch
}

extern void* DAT_00afa27c;   // profiler singleton (thiscall/fastcall target)
extern void* ExceptionList;
extern void* LAB_009a37f7;   // SEH handler plate

// -----------------------------------------------------------------------------
// Retail control flow
// -----------------------------------------------------------------------------

// MSVC thiscall: ECX=this; one unread stack dword; RET 4; AL bool
bool __thiscall CVOGCharacter_CleanupDraggingObject(void* self /*, std::uint32_t unused */)
{
  // SEH frame (LAB_009a37f7) omitted in C form; present in retail.

  Profiler_EnterNamedZone(DAT_00afa27c, "CVOGCharacter::CleanupDraggingObject");

  void* drag = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0xCD0);
  if (drag == nullptr) {
    Profiler_Leave(DAT_00afa27c);
    return false;
  }

  std::uint8_t outX = 0;
  std::uint8_t outY = 0;

  // Path A: cargo grid via host+0x2B0
  void* host = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x250);
  void* cargoGrid = *reinterpret_cast<void**>(reinterpret_cast<char*>(host) + 0x2B0);
  if (InventoryGrid_FindFreeForItem(cargoGrid, drag, &outX, &outY, 1, -1) != 0) {
    auto** vtbl = *reinterpret_cast<void***>(drag);
    using QtyFn = std::uint32_t(__thiscall*)(void*);
    std::uint32_t qty = reinterpret_cast<QtyFn>(vtbl[0x25C / 4])(drag);
    if (InventoryGrid_PlaceItemFootprint(
            cargoGrid, drag,
            static_cast<std::uint32_t>(outX),
            static_cast<std::uint32_t>(outY),
            qty) != 0) {
      goto clear_drag;
    }
  }

  // Path B: personal / locker grid at character+0xCBC
  void* lockerGrid = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0xCBC);
  if (InventoryGrid_FindFreeForItem(lockerGrid, drag, &outX, &outY, 1, -1) != 0) {
    auto** vtbl = *reinterpret_cast<void***>(drag);
    using QtyFn = std::uint32_t(__thiscall*)(void*);
    std::uint32_t qty = reinterpret_cast<QtyFn>(vtbl[0x25C / 4])(drag);
    if (InventoryGrid_PlaceItemFootprint(
            lockerGrid, drag,
            static_cast<std::uint32_t>(outX),
            static_cast<std::uint32_t>(outY),
            qty) != 0) {
      goto clear_drag;
    }
  }

  // Path C: equip fallback
  {
    int outFlag = 0;
    unsigned code = Character_TryEquipItem(host, drag, &outFlag);
    if (outFlag == 0 &&
        (code == 0u || code == 1u || code == 0xAu || code == 0xDu || code == 0xFu)) {
      FUN_00502e90(host, drag);
    }
  }

clear_drag:
  *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0xCD0) = nullptr;
  Profiler_Leave(DAT_00afa27c);
  return true;
}
