// =============================================================================
// InventoryGrid_FindFreeSlot
// -----------------------------------------------------------------------------
// Purpose:  First-fit search for a free rectangle of (sizeX × sizeY) inside the
//           inventory grid. Outer scan is Y (row), inner is X (column). On hit,
//           writes origin (x,y) to out params and returns 1; else returns 0.
//
// Address:  0x005713a0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005713a0
// System:   inventory-transfer
//
// Convention: MSVC __thiscall  (grid in ECX / param_1 in decompiler)
//
// Signature (decompiler-derived):
//   uint32_t InventoryGrid_FindFreeSlot(
//       InventoryGrid* this,
//       uint32_t sizeX,          // low byte used
//       uint32_t sizeY,          // low byte used
//       uint8_t* outX,
//       uint8_t* outY,
//       char     pageIndex);     // -1 = whole grid; else restrict to page
//
// Cell indexing (column-major with height stride):
//   index = height * x + y
//   cell  = cells + index * 8
//   empty iff (lo u32 & hi u32) == 0xFFFFFFFF
//
// CanPlace probe (thiscall; last arg nullable conflict COID out — FindFree passes null):
//   FUN_00570840(this, sizeX, sizeY, x, y, /*conflictOut*/ nullptr)
// Decompiler at call site: FUN_00570840(sizeX,sizeY,x,y,0); param_1 = extraout_ECX
//
// Special: sizeX==0 or sizeY==0 → success at (0,0) without scanning.
// Related: docs/inventory-grid-footprint.md (Y outer, X inner first-fit)
// Exactness: Preserves page-window math and empty-cell AND test.
// Dual: reviews/A|B_aa_005713a0_InventoryGrid_FindFreeSlot.md (strengthened 2026-07-29)
// =============================================================================

#include <cstdint>

static constexpr std::uintptr_t kOffWidth     = 0x08;
static constexpr std::uintptr_t kOffHeight    = 0x0c;
static constexpr std::uintptr_t kOffPageRows  = 0x1c; // rows per page (derived)
static constexpr std::uintptr_t kOffCellArray = 0x28;

static constexpr std::uint32_t kEmptyCellMask = 0xFFFFFFFFu;

struct InventoryGrid;

// FUN_00570840 — CanPlace / footprint fits at (x,y)?
// thiscall: grid in ECX. Optional conflictOut captures first non-empty cell COID pair.
std::uint32_t __thiscall FUN_00570840(InventoryGrid* self,
                                      std::uint8_t sizeX, std::uint8_t sizeY,
                                      std::uint8_t originX, std::uint8_t originY,
                                      std::uint32_t* conflictOut);

/// First-fit free rectangle search.
/// @return 1 on success (outX/outY written), 0 on failure / null outs.
std::uint32_t InventoryGrid_FindFreeSlot(InventoryGrid* self,
                                         std::uint32_t sizeX,
                                         std::uint32_t sizeY,
                                         std::uint8_t* outX,
                                         std::uint8_t* outY,
                                         char pageIndex)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(self);

    if (outX == nullptr || outY == nullptr) {
        return 0;
    }

    // Degenerate footprint → trivial success at origin (0,0).
    if (static_cast<char>(sizeX) == '\0' || static_cast<char>(sizeY) == '\0') {
        *outX = 0;
        *outY = 0;
        return 1;
    }

    std::uint8_t yStart;
    char         yLast; // inclusive upper bound for origin Y

    if (pageIndex == -1) {
        // Whole grid: Y from 0 .. height - sizeY
        yStart = 0;
        yLast  = static_cast<char>(*reinterpret_cast<std::int32_t*>(base + kOffHeight))
               - static_cast<char>(sizeY);
    } else {
        // Single page window: pageRows * pageIndex .. pageRows - sizeY + yStart
        char pageRows = static_cast<char>(
            *reinterpret_cast<std::int32_t*>(base + kOffPageRows));
        yStart = static_cast<std::uint8_t>(pageRows * pageIndex);
        yLast  = static_cast<char>((pageRows - static_cast<char>(sizeY)) + yStart);
    }

    if (yStart >= static_cast<std::uint8_t>(yLast + 1U)) {
        return 0;
    }

    // Y outer, X inner
    std::uint8_t y = yStart;
    do {
        std::uint8_t x = 0;
        // local_c low byte tracks x (decompiler CONCAT31 pattern)
        std::uint32_t xAsDword = 0; // low byte = x

        const std::int32_t width = *reinterpret_cast<std::int32_t*>(base + kOffWidth);
        const std::int32_t xLimit =
            (width - static_cast<std::int32_t>(sizeX & 0xFFu)) + 1;

        if (xLimit > 0) {
            std::uint32_t xU = 0;
            do {
                const std::int32_t height =
                    *reinterpret_cast<std::int32_t*>(base + kOffHeight);
                const std::int32_t cellIndex = height * static_cast<std::int32_t>(xU)
                                            + static_cast<std::int32_t>(y);

                auto* cells = *reinterpret_cast<std::uint8_t**>(base + kOffCellArray);
                auto* cell  = cells + cellIndex * 8;
                const std::uint32_t lo = *reinterpret_cast<std::uint32_t*>(cell);
                const std::uint32_t hi = *reinterpret_cast<std::uint32_t*>(cell + 4);

                // Empty origin cell (both COID halves all-ones).
                if ((lo & hi) == kEmptyCellMask) {
                    // thiscall: self in ECX; conflictOut null. Decomp: extraout_ECX restores this.
                    const auto canPlace = FUN_00570840(
                        self,
                        static_cast<std::uint8_t>(sizeX & 0xFFu),
                        static_cast<std::uint8_t>(sizeY & 0xFFu),
                        static_cast<std::uint8_t>(xAsDword & 0xFFu),
                        y,
                        nullptr);
                    if (canPlace != 0) {
                        *outX = x;
                        *outY = y;
                        return 1;
                    }
                }

                ++x;
                xU = static_cast<std::uint32_t>(x);
                xAsDword = (xAsDword & 0xFFFFFF00u) | x; // CONCAT31 pattern
            } while (static_cast<std::int32_t>(xU) < xLimit);
        }

        ++y;
    } while (y < static_cast<std::uint8_t>(yLast + 1U));

    return 0;
}
