// =============================================================================
// FUN_00571b60  — superseded alias stub
// -----------------------------------------------------------------------------
// Stable ID: aa_00571b60
// Address:   0x00571b60
// Prefer:    InventoryGrid_ContainsItem.cpp  (2026-07-29 dual A/B byte seal)
// =============================================================================

// This scaffold file is retained for path stability. Authoritative clean source:
//   docs/reconstruction/reconstructed-exact/InventoryGrid_ContainsItem.cpp
// Dual reviews:
//   docs/reconstruction/reviews/A_aa_00571b60_InventoryGrid_ContainsItem.md
//   docs/reconstruction/reviews/B_aa_00571b60_InventoryGrid_ContainsItem.md

#include <cstdint>

extern "C" std::uint8_t __thiscall InventoryGrid_ContainsItem(void* grid, void* item);

extern "C" std::uint8_t __thiscall FUN_00571b60(void* grid, void* item)
{
    return InventoryGrid_ContainsItem(grid, item);
}
