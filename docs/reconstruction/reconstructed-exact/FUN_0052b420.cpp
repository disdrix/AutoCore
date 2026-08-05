// =============================================================================
// FUN_0052b420 — scaffold alias
// -----------------------------------------------------------------------------
// Stable ID: aa_0052b420
// Canonical: CVOGCharacter_IsMissionTurnInReady
// Address:   0x0052b420
// Sealed:    2026-07-29 — see CVOGCharacter_IsMissionTurnInReady.cpp
// =============================================================================
//
// This unit is retained so bulk inventory paths that resolve FUN_0052b420 still
// find a clean file. Authoritative annotated clean:
//   reconstructed-exact/CVOGCharacter_IsMissionTurnInReady.cpp
// Dual reviews:
//   reviews/A_aa_0052b420_CVOGCharacter_IsMissionTurnInReady.md
//   reviews/B_aa_0052b420_CVOGCharacter_IsMissionTurnInReady.md
//
// Raw CF (authoritative decompile body) lives in:
//   raw/aa_0052b420_FUN_0052b420.md
// =============================================================================

#include <cstdint>

extern "C" char FUN_0052a020(void* character, void* objective, char strictFlag);

// Mirror of sealed clean; names keep Ghidra labels for inventory tools.
std::uint8_t __thiscall FUN_0052b420(int param_1, int param_2, int param_3)
{
    int iVar1;
    char cVar2;
    int iVar3;
    std::uint8_t uVar4;
    int* piVar5;

    // G1 last objective
    iVar1 = *(int*)(*(int*)(param_2 + 0x13c) + -4 +
                    (unsigned)*(unsigned char*)(param_2 + 0x130) * 4);

    // G2 active hash char+0x548
    iVar3 = *(int*)(*(int*)(*(int*)(*(int*)(param_1 + 0x548) + 0x10) +
                            (*(unsigned*)(*(int*)(param_1 + 0x548) + 8) &
                             *(unsigned*)(iVar1 + 0x10)) *
                                4) +
                    4);
    while (true) {
        if (iVar3 == 0) {
            return 0;
        }
        if (*(unsigned*)(iVar1 + 0x10) == *(unsigned*)(iVar3 + 0x10)) {
            break;
        }
        iVar3 = *(int*)(iVar3 + 0xc);
    }
    if (iVar3 == 0) {
        return 0;
    }
    if (*(int*)(iVar3 + 8) == 0) {
        return 0;
    }

    // G3 complete (ECX=param_1 preserved at call site in image)
    cVar2 = FUN_0052a020(reinterpret_cast<void*>(param_1),
                         reinterpret_cast<void*>(iVar1), 1);
    if (cVar2 == '\0') {
        return 0;
    }

    uVar4 = 1;
    // G4 optional NPC type-3 filter
    if ((param_3 != 0) &&
        (piVar5 = *(int**)(iVar1 + 0x158), piVar5 != *(int**)(iVar1 + 0x15c))) {
        while ((iVar3 = (**(int(**)())(*(int*)*piVar5 + 0x50))(), iVar3 != 3 ||
                (*(int*)(*piVar5 + 0x18) ==
                 *(int*)(*(int*)(*(int*)(*(int*)(param_3 + 4) + 4) + 0xac +
                                param_3) +
                         0x34)))) {
            piVar5 = piVar5 + 1;
            if (piVar5 == *(int**)(iVar1 + 0x15c)) {
                return 1;
            }
        }
        uVar4 = 0;
    }
    return uVar4;
}
