// =============================================================================
// FUN_0059db80  — twin of CVOGObjective_ProbeEligibilityCode_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0059db80
// Address:   0x0059db80  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-08-05 MEGA-091 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Named clean: CVOGObjective_ProbeEligibilityCode_Inferred.cpp
// =============================================================================

#include <cstdint>

int __thiscall FUN_0059db80(int param_1, int param_2)
{
    int *piVar1;
    char cVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    std::uint32_t *puVar6;

    iVar4 = *reinterpret_cast<int *>(param_1 + 0x120);
    if (iVar4 == -1) {
        iVar4 = *reinterpret_cast<int *>(
            *reinterpret_cast<int *>(param_1 + 0x14c) + 0xfc);
    }
    iVar5 = *reinterpret_cast<int *>(
        *reinterpret_cast<int *>(
            *reinterpret_cast<int *>(
                *reinterpret_cast<int *>(param_2 + 0x55c) + 0x10) +
            ((*reinterpret_cast<std::uint32_t *>(
                  *reinterpret_cast<int *>(param_2 + 0x55c) + 8) &
              *reinterpret_cast<std::uint32_t *>(param_1 + 0x10)) *
             4) +
        4);
    if (iVar5 == 0) {
LAB_0059dbda:
        iVar5 = 0;
    } else {
        do {
            if (*reinterpret_cast<std::uint32_t *>(param_1 + 0x10) ==
                *reinterpret_cast<std::uint32_t *>(iVar5 + 0x10)) {
                if (iVar5 == 0) goto LAB_0059dbda;
                iVar5 = *reinterpret_cast<int *>(iVar5 + 8);
                goto LAB_0059dbe1;
            }
            iVar5 = *reinterpret_cast<int *>(iVar5 + 0xc);
        } while (iVar5 != 0);
        iVar5 = 0;
    }
LAB_0059dbe1:
    if (iVar5 == 0) {
        return iVar4;
    }
    puVar6 = *reinterpret_cast<std::uint32_t **>(param_1 + 0x158);
    if (puVar6 != *reinterpret_cast<std::uint32_t **>(param_1 + 0x15c)) {
        while (true) {
            piVar1 = reinterpret_cast<int *>(*puVar6);
            cVar2 = (**(char (**)(int, int))(*piVar1 + 8))(param_2, iVar5);
            if (((cVar2 == '\0') &&
                 (iVar3 = (**(int (**)())(*piVar1 + 0x58))(), iVar3 != -1)) &&
                (iVar3 != 0)) {
                break;
            }
            puVar6 = puVar6 + 1;
            if (puVar6 == *reinterpret_cast<std::uint32_t **>(param_1 + 0x15c)) {
                return iVar4;
            }
        }
        return iVar3;
    }
    return iVar4;
}
