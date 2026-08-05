// =============================================================================
// FUN_008aa320  (scaffold alias → NpcMissionDialog_TeardownChildWidgetLists)
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa320
// Address:   0x008aa320  (autoassault.exe, image base 0x400000)
// System:    missions-progression / client UI
// Generated: 2026-07-29 W21-T dual seal (supersedes 2026-07-23 auto scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: NpcMissionDialog_TeardownChildWidgetLists.cpp
// =============================================================================

#include <cstdint>

// Retail: ESI=dialog, bare ret
void FUN_008aa320(int* unaff_ESI /*dialog*/)
{
    int iVar1;
    int* piVar2;
    int iVar3;
    int iVar4;

    if (unaff_ESI[0x1cb] == 0)
        iVar4 = 0;
    else
        iVar4 = (unaff_ESI[0x1cc] - unaff_ESI[0x1cb]) >> 2;

    iVar3 = 0;
    if (0 < iVar4) {
        do {
            piVar2 = reinterpret_cast<int*>(unaff_ESI[0x1cb] + iVar3 * 4);
            if (*piVar2 != 0) {
                (**(void (**)())(*(int*)*piVar2 + 0x440))();
                (**(void (**)(std::uint32_t))(*unaff_ESI + 0xb0))(
                    *reinterpret_cast<std::uint32_t*>(unaff_ESI[0x1cb] + iVar3 * 4));
            }
            iVar3 = iVar3 + 1;
        } while (iVar3 < iVar4);
    }

    if (unaff_ESI[0x1cf] == 0)
        iVar4 = 0;
    else
        iVar4 = (unaff_ESI[0x1d0] - unaff_ESI[0x1cf]) >> 2;

    iVar3 = 0;
    if (0 < iVar4) {
        do {
            iVar1 = iVar3 * 4;
            if (*reinterpret_cast<int*>(unaff_ESI[0x1cf] + iVar1) != 0) {
                (**(void (**)())(**reinterpret_cast<int**>(unaff_ESI[0x1cf] + iVar1) + 0x440))();
                (**(void (**)(std::uint32_t))(*unaff_ESI + 0xb0))(
                    *reinterpret_cast<std::uint32_t*>(unaff_ESI[0x1cf] + iVar1));
            }
            iVar3 = iVar3 + 1;
        } while (iVar3 < iVar4);
    }
}
