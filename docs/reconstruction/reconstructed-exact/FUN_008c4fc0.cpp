// =============================================================================
// FUN_008c4fc0 (scaffold synonym)
// -----------------------------------------------------------------------------
// Stable ID: aa_008c4fc0
// Address:   0x008c4fc0  (autoassault.exe, image base 0x400000)
// Canonical: Client_CastFirstHardpointSkillFlag200_Inferred
// WQ8R-F 2026-08-04: prefer named clean sibling for new work.
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>
#include <windows.h>

extern "C" int DAT_00d1b6d8;
extern "C" void FUN_004294f0(void); // List_TraversalLock (ECX=list)
extern "C" unsigned __thiscall FUN_004022a0(void* list, void** a, void** b);
extern "C" void* __RTDynamicCast(void*, long, void*, void*, int);
extern "C" void Client_CastSkillFromQuickBarSlot(void* /*client via ESI*/, int skillId);
extern "C" char CVOGHBBase_RTTI_Type_Descriptor[];
extern "C" char CVOGHBSkillBase_RTTI_Type_Descriptor[];

void FUN_008c4fc0(void)
{
    int iVar1;
    int iVar2;
    int iVar3;
    int local_8;
    uint32_t local_4;

    if ((DAT_00d1b6d8 != 0) && (*(char*)(DAT_00d1b6d8 + 0x6b8) != '\0')) {
        iVar2 = 0;
        if ((*(char*)(DAT_00d1b6d8 + 0x30c) == '\0') ||
            (iVar3 = *(int*)(DAT_00d1b6d8 + 0x250), iVar3 == 0)) {
            iVar3 = *(int*)(*(int*)(*(int*)(DAT_00d1b6d8 + 4) + 4) + 0xb4 + DAT_00d1b6d8);
        } else {
            iVar3 = *(int*)(*(int*)(*(int*)(iVar3 + 4) + 4) + 0xb4 + iVar3);
        }
        if (iVar3 != 0) {
            local_8 = 0;
            local_4 = 0;
            FUN_004294f0(); // ECX = list host (iVar3)
            iVar1 = (int)FUN_004022a0((void*)iVar3, (void**)&local_4, (void**)&local_8);
            while (iVar1 == 0) {
                if ((((local_8 != 0) && (*(int*)(local_8 + 0x1c) == 1)) &&
                     (iVar1 = (int)__RTDynamicCast(
                          (void*)local_8, 0,
                          CVOGHBBase_RTTI_Type_Descriptor,
                          CVOGHBSkillBase_RTTI_Type_Descriptor, 0),
                      iVar1 != 0)) &&
                    (*(char*)(iVar1 + 0x140) != '\0')) {
                    iVar2 = iVar1 + 0x24;
                    break;
                }
                iVar1 = (int)FUN_004022a0((void*)iVar3, (void**)&local_4, (void**)&local_8);
            }
            if (*(char*)(iVar3 + 0x28) != '\0') {
                *(uint8_t*)(iVar3 + 0x28) = 0;
                LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 4));
            }
            if ((iVar2 != 0) && ((*(uint32_t*)(iVar2 + 0x614) & 0x200) != 0)) {
                // ESI = &DAT_00d1a840 at call site
                Client_CastSkillFromQuickBarSlot(
                    (void*)0x00d1a840,
                    *(uint32_t*)(iVar2 + 0x5fc));
            }
        }
    }
    return;
}
