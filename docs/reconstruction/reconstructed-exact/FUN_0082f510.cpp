// =============================================================================
// FUN_0082f510 (scaffold synonym)
// -----------------------------------------------------------------------------
// Stable ID: aa_0082f510
// Address:   0x0082f510  (autoassault.exe, image base 0x400000)
// Canonical: UI_Window_OnCommand_Class8_Inferred
// WQ8R-F 2026-08-04: prefer named clean sibling for new work.
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

extern "C" int DAT_00d1b6d8;
extern "C" int* DAT_00d1b870;
extern "C" int* DAT_00d1b874;
extern "C" int* DAT_00d1b880;
extern "C" void Client_CastSkillFromQuickBarSlot(void*, int);
extern "C" void FUN_007fca10(void);
extern "C" void FUN_007fef20(int, int, int);
extern "C" uint32_t __thiscall FUN_0082c780(int* self, int, int);
extern "C" void FUN_00888b00(int*, int);
extern "C" void FUN_00889410(int*, int);
extern "C" void FUN_00889fb0(int*, int);

uint32_t __thiscall FUN_0082f510(int* param_1, int param_2, int param_3)
{
    int iVar1;
    int* piVar2;
    int* piVar3;
    int* piVar4;
    char cVar5;
    uint32_t uVar6;

    if ((((param_3 != 10) && (DAT_00d1b6d8 != 0)) &&
         (iVar1 = *(int*)(DAT_00d1b6d8 + 0x250), iVar1 != 0)) &&
        (cVar5 = (**(code**)(*(int*)(*(int*)(*(int*)(iVar1 + 4) + 4) + 4 + iVar1) + 0x194))(),
         cVar5 != '\0')) {
        (**(code**)(*param_1 + 0x47c))();
        uVar6 = FUN_0082c780(param_1, param_2, param_3);
        return uVar6;
    }
    piVar4 = DAT_00d1b880;
    piVar3 = DAT_00d1b874;
    piVar2 = DAT_00d1b870;
    if (param_2 == 8) {
        switch (param_3) {
        case 1:
            Client_CastSkillFromQuickBarSlot((void*)0x00d1a840, 0xed5);
            return 1;
        case 2:
        case 3:
            break;
        case 4:
            cVar5 = (**(code**)(*DAT_00d1b874 + 0x3d8))();
            if ((cVar5 != '\0') && (piVar3[0x14c] == 0)) {
                FUN_007fca10();
                return 1;
            }
            FUN_007fef20(1, 1, 0);
            cVar5 = (**(code**)(*piVar3 + 0x3d8))();
            if (cVar5 != '\0') {
                FUN_00889410(piVar3, 1);
                return 1;
            }
            break;
        case 5:
            cVar5 = (**(code**)(*DAT_00d1b870 + 0x3d8))();
            if ((cVar5 != '\0') && (piVar2[0x14d] == 0)) {
                FUN_007fca10();
                return 1;
            }
            FUN_007fef20(0, 1, 0);
            cVar5 = (**(code**)(*piVar2 + 0x3d8))();
            if (cVar5 != '\0') {
                FUN_00888b00(piVar2, 1);
                return 1;
            }
            break;
        case 6:
            FUN_007fef20(2, 0, 0);
            break;
        case 7:
            FUN_007fef20(0x12, 0, 0);
            return 1;
        case 8:
            FUN_007fef20(0x13, 0, 0);
            return 1;
        case 9:
            FUN_007fef20(0x11, 0, 0);
            return 1;
        case 10:
            FUN_007fef20(0x29, 0, 0);
            return 1;
        case 0xb:
            cVar5 = (**(code**)(*DAT_00d1b880 + 0x3d8))();
            if ((cVar5 != '\0') && (piVar4[0x14a] == 0)) {
                FUN_007fca10();
                return 1;
            }
            FUN_007fef20(4, 1, 0);
            cVar5 = (**(code**)(*piVar4 + 0x3d8))();
            if (cVar5 != '\0') {
                FUN_00889fb0(piVar4, 1);
                return 1;
            }
            break;
        case 0xc:
            FUN_007fef20(3, 0, 0);
            return 1;
        case 0xd:
            FUN_007fef20(5, 0, 0);
            return 1;
        default:
            goto switchD_0082f57c_default;
        }
    } else {
    switchD_0082f57c_default:
        if (param_3 != 70000) {
            uVar6 = FUN_0082c780(param_1, param_2, param_3);
            return uVar6;
        }
    }
    return 1;
}
