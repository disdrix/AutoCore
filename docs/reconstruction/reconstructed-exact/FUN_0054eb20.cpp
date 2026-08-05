// =============================================================================
// FUN_0054eb20 / SkillElementTypeMap_InsertOrFind
// -----------------------------------------------------------------------------
// Stable ID: aa_0054eb20
// Address:   0x0054eb20  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-29 dual W19-L (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI seals.
// Bit-for-bit vs retail EXE: DEFERRED.
// Prefer named plate: SkillElementTypeMap_InsertOrFind.cpp
// =============================================================================

#include <cstdint>

extern void *FUN_0054de50(void *pOut, char insertLeft, void *parent, const void *pVal);
extern void FUN_005a2850(void);

// void __thiscall — RET 0x8
void __thiscall FUN_0054eb20(int param_1, std::uint32_t *param_2, int *param_3)
{
    int *piVar3 = param_3;
    std::uint32_t *puVar5 = *reinterpret_cast<std::uint32_t **>(param_1 + 4);
    bool bVar2 = true;

    if (*reinterpret_cast<char *>(reinterpret_cast<int>(
            reinterpret_cast<std::uint32_t *>(puVar5)[1]) +
                                  0x15) == '\0') {
        std::uint32_t *puVar4 =
            reinterpret_cast<std::uint32_t *>(reinterpret_cast<std::uint32_t *>(puVar5)[1]);
        do {
            puVar5 = puVar4;
            bVar2 = (*param_3 < static_cast<int>(puVar5[3]));
            if (bVar2) {
                puVar4 = reinterpret_cast<std::uint32_t *>(*puVar5);
            } else {
                puVar4 = reinterpret_cast<std::uint32_t *>(puVar5[2]);
            }
        } while (*reinterpret_cast<char *>(reinterpret_cast<int>(puVar4) + 0x15) == '\0');
    }

    param_3 = reinterpret_cast<int *>(puVar5);

    if (bVar2) {
        if (puVar5 == *reinterpret_cast<std::uint32_t **>(
                          *reinterpret_cast<int **>(param_1 + 4))) {
            puVar5 = reinterpret_cast<std::uint32_t *>(
                FUN_0054de50(&param_3, 1, puVar5, piVar3));
            std::uint32_t uVar1 = *puVar5;
            *reinterpret_cast<std::uint8_t *>(param_2 + 1) = 1;
            *param_2 = uVar1;
            return;
        }
        FUN_005a2850();
    }

    if (param_3[3] < *piVar3) {
        puVar5 = reinterpret_cast<std::uint32_t *>(
            FUN_0054de50(&param_3, static_cast<char>(bVar2), puVar5, piVar3));
        *param_2 = *puVar5;
        *reinterpret_cast<std::uint8_t *>(param_2 + 1) = 1;
        return;
    }

    *reinterpret_cast<std::uint8_t *>(param_2 + 1) = 0;
    *param_2 = reinterpret_cast<std::uint32_t>(param_3);
}
