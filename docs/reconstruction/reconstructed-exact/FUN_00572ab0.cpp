// =============================================================================
// FUN_00572ab0  (scaffold alias → InventoryGrid_AutoMergePartialStacks_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00572ab0
// Address:   0x00572ab0  (autoassault.exe, image base 0x400000)
// Body:      true exclusive end 0x00572ec7 (1047 B); bare RET; AL dirty
// System:    inventory-transfer / InventoryGrid
// Refined:   2026-07-29 W29-E
// =============================================================================
// See InventoryGrid_AutoMergePartialStacks_Inferred.cpp for structured CF.
// Raw decompile remains authority for full residual/absorb branches.

#include <cstdint>

struct InventoryGrid;

extern "C" uint8_t __fastcall InventoryGrid_AutoMergePartialStacks_Inferred(InventoryGrid* self);

extern "C" uint8_t __fastcall FUN_00572ab0(InventoryGrid* self)
{
    return InventoryGrid_AutoMergePartialStacks_Inferred(self);
}
