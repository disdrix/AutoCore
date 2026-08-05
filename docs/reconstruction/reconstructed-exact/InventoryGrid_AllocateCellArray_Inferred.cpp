// =============================================================================
// InventoryGrid_AllocateCellArray_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Free any existing cell buffer, recompute total cell count and per-
//           page dimensions, allocate width×height cells (8 bytes each), and
//           fill every dword with 0xFFFFFFFF (empty COID half).
//
// Address:  0x00570720  (autoassault.exe, image base 0x400000)
// Stable:   aa_00570720
// System:   inventory-transfer
//
// Convention: MSVC __fastcall  (pGrid in ECX)
// Name:       INFERRED — retail symbol not recovered.
//
// Layout (grid object):
//   +0x08  int32  width
//   +0x0C  int32  height
//   +0x10  int32  totalCells  (= width * height)
//   +0x14  int32  pages
//   +0x18  int32  derived: totalCells / height   (page-related width helper)
//   +0x1C  int32  derived: (totalCells / pages) / width
//   +0x28  ptr    cell array (nTotal * 8 bytes; each cell = two u32 COID halves)
//
// Empty cell sentinel: both halves 0xFFFFFFFF (AND == 0xFFFFFFFF in FindFreeSlot).
// Related:  InventoryGrid_ctor_Inferred, InventoryGrid_FindFreeSlot,
//           InventoryGrid_PlaceItemFootprint, docs/inventory-cargo-wire-re.md
//
// Exactness: Preserves retail control flow including the zero-iteration tail
//            byte fill (MSVC memset-style dword + residual byte loops).
// =============================================================================

#include <cstdint>

// Offsets into the inventory grid object
static constexpr std::uintptr_t kOffWidth      = 0x08;
static constexpr std::uintptr_t kOffHeight     = 0x0c;
static constexpr std::uintptr_t kOffTotalCells = 0x10;
static constexpr std::uintptr_t kOffPages      = 0x14;
static constexpr std::uintptr_t kOffPageDimA   = 0x18; // totalCells / height
static constexpr std::uintptr_t kOffPageDimB   = 0x1c; // (totalCells / pages) / width
static constexpr std::uintptr_t kOffCellArray  = 0x28;

static constexpr std::uint32_t kEmptyCellDword = 0xFFFFFFFFu;
static constexpr int           kBytesPerCell  = 8;

struct InventoryGrid;

// External: retail heap helpers (names as recovered / used by decompiler).
void  operator_delete__(void* p);
void* operator_new__(std::uint32_t nbytes);

/// Allocate (or reallocate) the empty occupancy cell array for an inventory grid.
/// @param pGrid  Inventory grid object (retail `this` / ECX).
void InventoryGrid_AllocateCellArray_Inferred(InventoryGrid* pGrid)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(pGrid);

    // Free previous buffer if present.
    void* const oldCells = *reinterpret_cast<void**>(base + kOffCellArray);
    if (oldCells != nullptr) {
        operator_delete__(oldCells);
    }

    const std::int32_t width  = *reinterpret_cast<std::int32_t*>(base + kOffWidth);
    const std::int32_t height = *reinterpret_cast<std::int32_t*>(base + kOffHeight);
    const std::int32_t pages  = *reinterpret_cast<std::int32_t*>(base + kOffPages);

    std::int32_t nTotalCells = width * height;

    *reinterpret_cast<void**>(base + kOffCellArray)        = nullptr;
    *reinterpret_cast<std::int32_t*>(base + kOffTotalCells) = nTotalCells;

    // Page-derived dimensions (integer division as in retail).
    *reinterpret_cast<std::int32_t*>(base + kOffPageDimB) =
        (nTotalCells / pages) / width;
    *reinterpret_cast<std::int32_t*>(base + kOffPageDimA) =
        nTotalCells / height;

    // nTotal * 8 bytes; each cell is two u32 halves.
    auto* pCell = static_cast<std::uint32_t*>(
        operator_new__(static_cast<std::uint32_t>(nTotalCells * kBytesPerCell)));
    *reinterpret_cast<std::uint32_t**>(base + kOffCellArray) = pCell;

    // Dword fill with 0xFFFFFFFF (covers full cell buffer when size is dword-aligned).
    std::uint32_t nDwordCount =
        static_cast<std::uint32_t>(
            *reinterpret_cast<std::int32_t*>(base + kOffTotalCells) * kBytesPerCell) >> 2;
    for (; nDwordCount != 0; --nDwordCount) {
        *pCell = kEmptyCellDword;
        ++pCell;
    }

    // Residual byte fill — retail always uses 0 iterations when size % 4 == 0
    // (nTotalCells*8 is always dword-aligned). Kept for exact CF parity.
    for (nTotalCells = 0; nTotalCells != 0; --nTotalCells) {
        *reinterpret_cast<std::uint8_t*>(pCell) = 0xFF;
        pCell = reinterpret_cast<std::uint32_t*>(
            reinterpret_cast<std::uint8_t*>(pCell) + 1);
    }
}
