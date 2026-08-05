// =============================================================================
// InventoryGrid_CanPlace
// -----------------------------------------------------------------------------
// Purpose:  Test whether a (sizeX × sizeY) footprint fits at (originX, originY)
//           on an inventory grid: bounds, page non-span, and all cells empty
//           (or single conflict COID when conflictOut is non-null).
//           Does NOT stamp or search free slots.
//
// Address:  0x00570840  (autoassault.exe, image base 0x400000)
// Stable:   aa_00570840
// System:   inventory-transfer
//
// Convention: MSVC __thiscall  (grid in ECX / param_1 in decompiler)
//
// Signature (decompiler-derived):
//   uint32_t InventoryGrid_CanPlace(
//       InventoryGrid* this,
//       uint8_t sizeX,
//       uint8_t sizeY,
//       uint8_t originX,
//       uint8_t originY,
//       uint32_t* conflictOut);  // nullable; two dwords = COID pair
//
// Cell indexing (column-major with height stride) — SEALED 2026-07-29:
//   index = height * x + y
//   cell  = cells + index * 8
//   empty iff (lo u32 & hi u32) == 0xFFFFFFFF
//
// Page non-span rule — SEALED 2026-07-29:
//   (originY % pageH) + sizeY <= pageH
//   pageH = *(i32*)(this + 0x1c)
//
// Degenerate: sizeX==0 or sizeY==0 can still return 1 if bounds/page hold
//   (AutoCore port intentionally rejects size < 1).
// Related: docs/inventory-grid-footprint.md; FindFree 0x005713a0; Place 0x00571620
// Dual: reviews/A|B_aa_00570840_InventoryGrid_CanPlace.md ; residual a_00570840.md
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

static constexpr std::uintptr_t kOffWidth     = 0x08;
static constexpr std::uintptr_t kOffHeight    = 0x0c;
static constexpr std::uintptr_t kOffPageRows  = 0x1c;
static constexpr std::uintptr_t kOffCellArray = 0x28;

static constexpr std::uint32_t kEmptyCellMask = 0xFFFFFFFFu;

struct InventoryGrid;

/// Full-rect can-place gate.
/// @return 1 if footprint may occupy (originX, originY), else 0.
std::uint32_t __thiscall InventoryGrid_CanPlace(InventoryGrid* self,
                                                std::uint8_t sizeX,
                                                std::uint8_t sizeY,
                                                std::uint8_t originX,
                                                std::uint8_t originY,
                                                std::uint32_t* conflictOut)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(self);

    if (conflictOut != nullptr) {
        conflictOut[0] = kEmptyCellMask;
        conflictOut[1] = kEmptyCellMask;
    }

    const auto endX = static_cast<std::uint32_t>(sizeX) + originX;
    const auto width =
        *reinterpret_cast<std::uint32_t*>(base + kOffWidth);
    if (static_cast<std::int32_t>(width) < static_cast<std::int32_t>(endX)) {
        return width & 0xffffff00u; // fail (low byte 0)
    }

    const auto originY32 = static_cast<std::uint32_t>(originY);
    const auto height =
        *reinterpret_cast<std::uint32_t*>(base + kOffHeight);
    const auto endY = originY32 + sizeY;
    const auto pageH =
        *reinterpret_cast<std::int32_t*>(base + kOffPageRows);

    // Y in-bounds AND page non-span: (originY % pageH) + sizeY <= pageH
    if (static_cast<std::int32_t>(endY) <= static_cast<std::int32_t>(height) &&
        static_cast<std::int32_t>(
            static_cast<std::int32_t>(originY32 % static_cast<std::uint32_t>(pageH)) +
            sizeY) <= pageH) {

        std::uint8_t x = originX;
        for (;;) {
            if (endX <= x) {
                return 1; // entire X span accepted
            }

            if (originY32 < endY) {
                auto y = originY32;
                do {
                    // ★ SEALED: column-major height * x + y
                    const auto idx =
                        static_cast<std::int32_t>(height) * static_cast<std::uint32_t>(x) +
                        static_cast<std::int32_t>(y);
                    auto* const cells =
                        *reinterpret_cast<std::uint8_t**>(base + kOffCellArray);
                    const auto lo =
                        *reinterpret_cast<std::uint32_t*>(cells + idx * 8);
                    const auto hi =
                        *reinterpret_cast<std::uint32_t*>(cells + idx * 8 + 4);

                    if ((lo & hi) != kEmptyCellMask) {
                        if (conflictOut == nullptr) {
                            goto fail;
                        }
                        if ((conflictOut[0] & conflictOut[1]) == kEmptyCellMask) {
                            conflictOut[0] = lo;
                            conflictOut[1] = hi;
                        } else if (conflictOut[0] != lo || conflictOut[1] != hi) {
                            goto fail; // second distinct COID
                        }
                        // same COID: multi-cell same item OK
                    }

                    y = static_cast<std::uint32_t>(static_cast<std::uint8_t>(y + 1));
                } while (y < endY);
            }

            x = static_cast<std::uint8_t>(x + 1);
        }
    }

fail:
    return 0;
}
