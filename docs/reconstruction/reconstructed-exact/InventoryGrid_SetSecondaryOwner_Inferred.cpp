// =============================================================================
// InventoryGrid_SetSecondaryOwner_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00573900
// Address:   0x00573900–0x00573909 inclusive (10 B / 0x0A)
// Module:    autoassault.exe (image base 0x400000)
// System:    inventory-transfer / InventoryGrid
// Generated: 2026-08-05 MEGA-092 dual A/B
// Exactness: Behavior-preserving rewrite of live decompile + read_memory CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// Terminal:  false (no runtime Confirmed)
// =============================================================================
//
// PURPOSE:
//   InventoryGrid vtbl+0x14: store secondary owner / character link pointer at
//   grid+0x58. Leaf setter — no list walk, no item rebind, no owner-flag write.
//
// ABI (byte-sealed):
//   __thiscall  ECX = InventoryGrid*
//   stack: secondaryOwner*
//   ret 0x04
//   return void (EAX undefined at RET)
//
// SEALED formulas / offsets:
//   *(grid+0x58) = secondaryOwner
//
// Vtbl:
//   PTR_FUN_009d3390 + 0x14 @ 0x009d33a4 = 0x00573900
//
// Parent call site (dualed, not owned):
//   Vehicle_CreateCargoInventoryFromPageCount (0x004f3a30):
//     after SetOwnerFlag(1) and vfunc+0x18(owner):
//       (grid.vtbl+0x14)( character_expr_from_vehicle_MI )
//
// Distinct from:
//   InventoryGrid_SetOwner_Inferred      (0x005718a0) — +0x24 + item rebind
//   InventoryGrid_SetOwnerFlag_Inferred  (0x00570600) — +0x4 flag
//
// Dual: reviews/A_aa_00573900_InventoryGrid_SetSecondaryOwner_Inferred.md
//       reviews/B_aa_00573900_InventoryGrid_SetSecondaryOwner_Inferred.md
// =============================================================================

#include <cstdint>

struct InventoryGrid;

void __thiscall InventoryGrid_SetSecondaryOwner_Inferred(
    InventoryGrid* self,
    void* secondaryOwner)
{
    auto* base = reinterpret_cast<std::uint8_t*>(self);
    *reinterpret_cast<void**>(base + 0x58) = secondaryOwner;
}
