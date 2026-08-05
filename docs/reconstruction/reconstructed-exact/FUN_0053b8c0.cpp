// =============================================================================
// FUN_0053b8c0 / CNDHash_ReclaimAll_NonOwning_009cefdc
// -----------------------------------------------------------------------------
// Stable ID: aa_0053b8c0
// Address:   0x0053b8c0  (autoassault.exe, image base 0x400000)
// System:    container / CNDHash (node stamp 0x009cefdc)
// Generated: 2026-07-29 dual W19-L (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI seals.
// Bit-for-bit vs retail EXE: DEFERRED.
// Prefer named plate: CNDHash_ReclaimAll_NonOwning_009cefdc.cpp
// =============================================================================

#include <cstdint>

extern void *PTR_LAB_009cefdc;

void __fastcall FUN_0053b8c0(int param_1)
{
    std::uint32_t uVar4 = 0;
    do {
        std::uint32_t *puVar3 = *reinterpret_cast<std::uint32_t **>(
            *reinterpret_cast<std::uint8_t **>(
                *reinterpret_cast<std::uint8_t **>(param_1 + 0x10) + uVar4 * 4) +
            4);

        while (puVar3 != nullptr) {
            std::uint32_t *puVar2 = reinterpret_cast<std::uint32_t *>(puVar3[3]);
            *puVar3 = reinterpret_cast<std::uint32_t>(&PTR_LAB_009cefdc);
            *puVar3 = *reinterpret_cast<std::uint32_t *>(param_1 + 0x20);
            *reinterpret_cast<std::uint32_t **>(param_1 + 0x20) = puVar3;
            puVar3 = puVar2;
        }

        *reinterpret_cast<std::uint32_t *>(
            *reinterpret_cast<std::uint8_t **>(
                *reinterpret_cast<std::uint8_t **>(param_1 + 0x10) + uVar4 * 4) +
            4) = 0;

        uVar4 = uVar4 + 1;
    } while (uVar4 <= *reinterpret_cast<std::uint32_t *>(param_1 + 8));
}
