// =============================================================================
// FUN_008a0210  (scaffold alias → QuickBar_CycleSelectValidColumn)
// -----------------------------------------------------------------------------
// Stable ID: aa_008a0210
// Address:   0x008a0210  (autoassault.exe, image base 0x400000)
// System:    client UI / quickbar
// Generated: 2026-07-29 W21-T dual seal (supersedes 2026-07-23 auto scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow + live byte
//            fix for SetSelected this-pointer pair. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: QuickBar_CycleSelectValidColumn.cpp
// =============================================================================

#include <cstdint>

// Sealed sibling
extern void __fastcall UI_QuickBarSlotButton_SetSelected(int* columnWidget, int, char fSelected);
extern void FUN_0089fef0(void);
extern "C" void* __cdecl __RTDynamicCast(void* obj, long vfDelta, void* srcType, void* targetType, int isRef);
extern void* gfxUIWindow_RTTI_Type_Descriptor;
extern void* CDlgQuickBar_RTTI_Type_Descriptor;
extern std::uint32_t DAT_00d1da38[];

// Retail: EBX=host, stack char param_1, ret 4, AL=0
std::uint32_t FUN_008a0210(int* host /*EBX / unaff_EBX*/, char param_1)
{
    int* piVar4 = reinterpret_cast<int*>(reinterpret_cast<char*>(host) + 0x63c);
    int iVar6 = 0;
    int* piVar3 = piVar4;
    int iVar5;
    int iVar1;

    do {
        if ((*piVar3 != 0) && (*reinterpret_cast<char*>(*piVar3 + 0x4fc) != '\0')) {
            iVar5 = iVar6;
            if (param_1 == '\0')
                goto joined_r0x008a027f;
            goto joined_r0x008a024b;
        }
        iVar6 = iVar6 + 1;
        piVar3 = piVar3 + 1;
    } while (iVar6 < 10);
    goto LAB_008a02c9;

    while (true) {
        if (9 < iVar5)
            iVar5 = 0;
        iVar1 = *reinterpret_cast<int*>(reinterpret_cast<char*>(host) + 0x63c + iVar5 * 4);
        piVar3 = nullptr;
        if (((iVar1 != 0) &&
             (piVar3 = *reinterpret_cast<int**>(iVar1 + 0x548), piVar3 != nullptr)) &&
            (piVar3 != reinterpret_cast<int*>(6)))
            break;
    joined_r0x008a024b:
        iVar5 = iVar5 + 1;
        if (iVar5 == iVar6)
            goto LAB_008a02c9;
    }
    goto LAB_008a02ad;

    while (true) {
        if (iVar5 < 0)
            iVar5 = 9;
        iVar1 = *reinterpret_cast<int*>(reinterpret_cast<char*>(host) + 0x63c + iVar5 * 4);
        piVar3 = nullptr;
        if (((iVar1 != 0) &&
             (piVar3 = *reinterpret_cast<int**>(iVar1 + 0x548), piVar3 != nullptr)) &&
            (piVar3 != reinterpret_cast<int*>(6)))
            break;
    joined_r0x008a027f:
        iVar5 = iVar5 + -1;
        if (iVar5 == iVar6)
            goto LAB_008a02c9;
    }

LAB_008a02ad:
    // LIVE bytes (decompiler gap): ECX = cols[iVar6] then cols[iVar5]
    UI_QuickBarSlotButton_SetSelected(
        *reinterpret_cast<int**>(reinterpret_cast<char*>(host) + 0x63c + iVar6 * 4), 0, 0);
    UI_QuickBarSlotButton_SetSelected(
        *reinterpret_cast<int**>(reinterpret_cast<char*>(host) + 0x63c + iVar5 * 4), 0, 1);

LAB_008a02c9:
    if (iVar6 == 10) {
        unsigned uVar2 = 0;
        while (((*piVar4 == 0) ||
                (iVar6 = *reinterpret_cast<int*>(*piVar4 + 0x548), iVar6 == 0)) ||
               (iVar6 == 6)) {
            uVar2 = uVar2 + 1;
            piVar4 = piVar4 + 1;
            if (9 < static_cast<int>(uVar2))
                return uVar2 & 0xffffff00u;
        }
        iVar6 = *reinterpret_cast<int*>(reinterpret_cast<char*>(host) + 0x63c + uVar2 * 4);
        piVar3 = *reinterpret_cast<int**>(iVar6 + 0x548);
        if ((piVar3 != nullptr) && (piVar3 != reinterpret_cast<int*>(6))) {
            __RTDynamicCast(*reinterpret_cast<void**>(iVar6 + 0x88), 0,
                            &gfxUIWindow_RTTI_Type_Descriptor,
                            &CDlgQuickBar_RTTI_Type_Descriptor, 0);
            FUN_0089fef0();
            if (*reinterpret_cast<int**>(iVar6 + 0x56c) != nullptr) {
                int* hl = *reinterpret_cast<int**>(iVar6 + 0x56c);
                (**(void (**)(int))(*hl + 4))(1);
            }
            DAT_00d1da38[*reinterpret_cast<int*>(iVar6 + 0x504)] =
                *reinterpret_cast<std::uint32_t*>(iVar6 + 0x500);
            *reinterpret_cast<std::uint8_t*>(iVar6 + 0x4fc) = 1;
        }
    }
    return 0;
}
