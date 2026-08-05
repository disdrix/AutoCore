// =============================================================================
// FUN_00480970  (scaffold alias → Mem_Move200B_Blocks_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00480970
// Address:   0x00480970  (autoassault.exe, image base 0x400000)
// Body:      0x00480970–0x004809a0 (49 bytes)
// System:    container / mem / 200-byte record range move
// Dual seal: 2026-07-29 W21-M
// Canonical clean: Mem_Move200B_Blocks_Inferred.cpp
// Exactness: Decompiler-shaped control flow; stride sealed via bytes.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>

// cdecl: (src, srcEnd, dest). Leaf. Callers may push 4th unused arg.
void FUN_00480970(std::uint32_t* param_1, std::uint32_t* param_2, std::uint32_t* param_3)
{
    std::uint32_t* puVar1;
    int iVar2;
    std::uint32_t* puVar3;
    std::uint32_t* puVar4;
    std::uint32_t* puVar5;

    while (param_1 != param_2) {
        puVar3 = param_1 + 0x32; // +200 bytes
        puVar1 = param_3 + 0x32;
        puVar4 = param_1;
        puVar5 = param_3;
        for (iVar2 = 0x32; param_1 = puVar3, param_3 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar5 = *puVar4; // REP MOVSD element
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
        }
    }
    return;
}
