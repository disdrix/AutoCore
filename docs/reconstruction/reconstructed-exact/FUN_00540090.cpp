// =============================================================================
// FUN_00540090  (twin of SkillDef_BuildFxMasterName_Inferred)
// -----------------------------------------------------------------------------
// Stable:   aa_00540090
// Address:  0x00540090  (autoassault.exe, image base 0x400000)
// Body:     0x00540090–0x00540282
// Named:    reconstructed-exact/SkillDef_BuildFxMasterName_Inferred.cpp
// Dual A/B: accept (2026-07-29 W24-N)
// =============================================================================

#include <cstdint>
#include <cstring>

// Keep Ghidra-facing symbol for coverage inventory twin.

void FUN_00540090(int param_1, char *param_2, size_t param_3)
{
    char local_400_buf[0x400];
    char *pcVar1;
    char cVar2;
    int iVar3;
    char *pcVar6;
    unsigned int uVar7;
    char *pcVar8;
    char *pcVar12;

    // Seed "skill_" from DAT_009d01bc family
    local_400_buf[0] = 's';
    local_400_buf[1] = 'k';
    local_400_buf[2] = 'i';
    local_400_buf[3] = 'l';
    local_400_buf[4] = 'l';
    local_400_buf[5] = '_';
    local_400_buf[6] = '\0';

    iVar3 = *(int *)(param_1 + 0x180);
    pcVar12 = local_400_buf;
    while (*pcVar12 != '\0') {
        ++pcVar12;
    }
    if (iVar3 == 0) {
        pcVar12[0] = 'h';
        pcVar12[1] = '_';
        pcVar12[2] = '\0';
    } else if (iVar3 == 1) {
        pcVar12[0] = 'm';
        pcVar12[1] = '_';
        pcVar12[2] = '\0';
    } else if (iVar3 == 2) {
        pcVar12[0] = 'c';
        pcVar12[1] = '_';
        pcVar12[2] = '\0';
    } else {
        pcVar12[0] = 'n';
        pcVar12[1] = '_';
        pcVar12[2] = '\0';
    }

    switch (*(int *)(param_1 + 0x17c)) {
    case 0:
        pcVar12 = local_400_buf;
        while (*pcVar12 != '\0') {
            ++pcVar12;
        }
        pcVar12[0] = 'c';
        pcVar12[1] = '_';
        pcVar12[2] = '\0';
        break;
    case 1:
        pcVar12 = local_400_buf;
        while (*pcVar12 != '\0') {
            ++pcVar12;
        }
        pcVar12[0] = 'e';
        pcVar12[1] = '_';
        pcVar12[2] = '\0';
        break;
    case 2:
        pcVar12 = local_400_buf;
        while (*pcVar12 != '\0') {
            ++pcVar12;
        }
        pcVar12[0] = 'o';
        pcVar12[1] = '_';
        pcVar12[2] = '\0';
        break;
    case 3:
        pcVar12 = local_400_buf;
        while (*pcVar12 != '\0') {
            ++pcVar12;
        }
        pcVar12[0] = 'r';
        pcVar12[1] = '_';
        pcVar12[2] = '\0';
        break;
    default:
        pcVar12 = local_400_buf;
        while (*pcVar12 != '\0') {
            ++pcVar12;
        }
        // "fixme_"
        pcVar12[0] = 'f';
        pcVar12[1] = 'i';
        pcVar12[2] = 'x';
        pcVar12[3] = 'm';
        pcVar12[4] = 'e';
        pcVar12[5] = '_';
        pcVar12[6] = '\0';
        break;
    }

    pcVar1 = (char *)(param_1 + 0x5a6);
    pcVar6 = pcVar1;
    do {
        cVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');

    pcVar12 = local_400_buf;
    while (*pcVar12 != '\0') {
        ++pcVar12;
    }
    pcVar8 = pcVar1;
    for (uVar7 = (unsigned int)((int)pcVar6 - (int)pcVar1) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(uint32_t *)pcVar12 = *(uint32_t *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar12 = pcVar12 + 4;
    }
    for (uVar7 = (unsigned int)((int)pcVar6 - (int)pcVar1) & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar12 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar12 = pcVar12 + 1;
    }

    std::strncpy(param_2, local_400_buf, param_3);
}
