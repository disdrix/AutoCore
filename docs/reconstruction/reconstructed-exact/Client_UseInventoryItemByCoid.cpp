// =============================================================================
// Client_UseInventoryItemByCoid
// -----------------------------------------------------------------------------
// Stable ID: aa_00941f50
// Address:   0x00941f50  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer / skills-abilities
// Generated: 2026-08-04 WQ8R-I dual A/B seal
// Exactness: Byte-accurate control flow. Decompiler invalid-COID arm corrected.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Resolve an inventory item by COID on the local character's cargo grid, then
//   activate it via Client_UseInventoryItem_Inferred (equip arm or C2S 0x2045).
//
// ABI
//   EAX = Client*
//   stack: uint32 coidLo, uint32 coidHi, uint32 mode
//   ret 0x0C
//   AL = result of Use, or 0 on hard fail
//
// GRID PATH (sealed, same cargo plate as Collect/Drop type-1)
//   client+0xE98 → character
//   character+0x250 → cargo host
//   host+0x2B0 → InventoryGrid*
//
// CALLERS
//   Static CALL @ 0x0086152C (orphan UI region after FUN_00861280):
//     skill-bit gate on item cloneMeta+0x3F2; EAX = DAT_00D1A840 client.
//
// CALLEES
//   InventoryGrid_FindItemByCoid (0x00571010)
//   Client_UseInventoryItem_Inferred (0x00941d50)  // ESI=client, EDI=item
// =============================================================================

#include <cstdint>

struct Client;
struct Character;
struct InventoryGrid;
struct Item;

extern "C" {
Item *InventoryGrid_FindItemByCoid(InventoryGrid *grid, std::uint32_t coidLo,
                                   std::uint32_t coidHi);
// Register convention: ESI=client, EDI=item*
std::uint32_t Client_UseInventoryItem_Inferred(std::uint32_t mode);
}

// EAX = Client* (register)
std::uint8_t Client_UseInventoryItemByCoid(std::uint32_t coidLo, std::uint32_t coidHi,
                                           std::uint32_t mode)
{
  Client *client = /* EAX */;

  Character *ch =
      *reinterpret_cast<Character **>(reinterpret_cast<char *>(client) + 0xE98);
  if (ch == nullptr)
    return 0;

  void *host = *reinterpret_cast<void **>(reinterpret_cast<char *>(ch) + 0x250);
  if (host == nullptr)
    return 0;

  // Sentinel invalid COID (both halves all-bits when AND'd with each other as pair mask)
  if ((coidLo & coidHi) == 0xFFFFFFFFu)
    return 0;

  InventoryGrid *cargo =
      *reinterpret_cast<InventoryGrid **>(reinterpret_cast<char *>(host) + 0x2B0);
  Item *item = InventoryGrid_FindItemByCoid(cargo, coidLo, coidHi);

  // Image: mov edi, eax; push mode; call Use — no null check on item
  // ESI = client, EDI = item for Use convention
  return static_cast<std::uint8_t>(Client_UseInventoryItem_Inferred(mode));
}
