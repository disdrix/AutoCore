// =============================================================================
// InventoryGrid_RemoveAllAndReEmptyCells_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Thin InventoryGrid re-empty: drain the embedded list at grid+0x2c
//           via dualed List_RemoveAll, then tail into dualed
//           InventoryGrid_AllocateCellArray_Inferred to free/rebuild a fully
//           empty cell occupancy buffer.
//
// Address:  0x00570f50 – 0x00570f62  (19 B / 0x13)
// Stable:   aa_00570f50
// Ghidra:   FUN_00570f50
// System:   inventory-transfer
// Wave:     R10-013 OWN-ONLY dual (2026-08-05)
//
// Convention: MSVC __fastcall  (InventoryGrid* in ECX); void; tail-JMP (no RET)
// Name:       INFERRED — parallel thin twin of ClearItemsAndReEmptyCells;
//             retail symbol open.
//
// Layout:
//   grid+0x28  cell array*          (rewritten by Allocate)
//   grid+0x2c  embedded List host   (arg to List_RemoveAll)
//
// Twin full path (item walk + detach + RemoveAll + Allocate):
//   InventoryGrid_ClearItemsAndReEmptyCells_Inferred  @ 0x00570f70
//
// Exactness: Control-flow-preserving rewrite of live decompile + assembly-
//            sealed ECX/ESI split. Not modernization. Runtime/bit-exact: DEFERRED.
// =============================================================================

#include <cstdint>

struct InventoryGrid;
struct ListHost;

// Dualed callees
void __fastcall List_RemoveAll(ListHost* list);                             // 0x004bc580
void __fastcall InventoryGrid_AllocateCellArray_Inferred(InventoryGrid* g); // 0x00570720

static constexpr std::uintptr_t kOffEmbeddedList = 0x2c;

/// Drain embedded item list and re-empty cell occupancy (no item walk/detach).
/// @param grid  InventoryGrid* (retail this / ECX).
void __fastcall InventoryGrid_RemoveAllAndReEmptyCells_Inferred(InventoryGrid* grid)
{
    auto* const gridBytes = reinterpret_cast<std::uint8_t*>(grid);
    auto* const list = reinterpret_cast<ListHost*>(gridBytes + kOffEmbeddedList);

    List_RemoveAll(list);
    // Retail uses tail-JMP; call form is behavior-equivalent for reconstruction.
    InventoryGrid_AllocateCellArray_Inferred(grid);
}
