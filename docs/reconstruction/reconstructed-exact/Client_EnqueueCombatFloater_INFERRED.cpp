// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: Client_EnqueueCombatFloater_INFERRED, CombatFloaterType::XP, FUN_00402e20, FUN_00404600.
//  - Return sites: 2.

// =============================================================================
// Client_EnqueueCombatFloater_INFERRED
// -----------------------------------------------------------------------------
// Purpose:  Append one combat-floater entry to a growable vector-like queue.
//           Callers include kill-award / session XP paths that set floater
//           type CombatFloaterType::XP (= 3). Full 0x38-byte element layout
//           is not fully typed yet (INFERRED name).
//
// Address:  0x00402620  (autoassault.exe, image base 0x400000)
// Stable:   aa_00402620
// System:   missions-progression  (XP / kill-award combat feedback UI)
//
// Queue object layout (this):
//   +0x04  T* begin
//   +0x08  T* end        (write cursor)
//   +0x0C  T* capacity   (end of storage)
//   element size = 0x38
//
// Flow:
//   if begin != null && size < capacity:
//     construct-in-place at *end via FUN_00404600(dst, 1, value, this, value)
//     end += 0x38
//   else:
//     grow / push path FUN_00402e20(&value, end, value)
//
// Related: kill-award success path; session XP RE dependency.
// Exactness: Behavior-preserving decompiler CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
// Human-refined: 2026-07-23 (named_hl_000)
// =============================================================================

#include <cstdint>

// In-place construct / assign one 0x38-byte floater slot (count=1).
// Signature recovered only as call shape from decompiler.
extern "C" void FUN_00404600(void* dst, int count, std::uint32_t value,
                             void* queue, std::uint32_t value2);

// Grow-and-push when size == capacity (or begin is null).
extern "C" void FUN_00402e20(std::uint32_t* pValue, void* end,
                             std::uint32_t value);

/// @param queue  Floater queue host (this).
/// @param value Opaque floater payload / type blob ref (undefined4 in decomp).
void Client_EnqueueCombatFloater_INFERRED(void* queue, std::uint32_t value)
{
    auto* base = reinterpret_cast<std::uint8_t*>(queue);
    auto* begin = *reinterpret_cast<std::uint8_t**>(base + 0x04);
    auto* end = *reinterpret_cast<std::uint8_t**>(base + 0x08);
    auto* capacity = *reinterpret_cast<std::uint8_t**>(base + 0x0c);

    constexpr std::uint32_t kElemSize = 0x38u;

    if (begin != nullptr) {
        const auto size = static_cast<std::uint32_t>((end - begin) / kElemSize);
        const auto cap = static_cast<std::uint32_t>((capacity - begin) / kElemSize);
        if (size < cap) {
            // Fast path: room remains - construct at write cursor and bump end.
            FUN_00404600(end, 1, value, queue, value);
            *reinterpret_cast<std::uint8_t**>(base + 0x08) = end + kElemSize;
            return;
        }
    }

    // Slow path: empty storage or full - reallocate / push via grow helper.
    FUN_00402e20(&value, end, value);
}
