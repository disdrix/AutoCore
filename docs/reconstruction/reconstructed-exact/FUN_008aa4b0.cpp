// =============================================================================
// FUN_008aa4b0  (clean twin of MissionDialog_SetNpcObjectAndNameCaption_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa4b0
// Address:   0x008aa4b0 – 0x008aa50e inclusive (95 B / 0x5F)
// Module:    autoassault.exe (image base 0x400000)
// System:    missions-progression
// Generated: 2026-08-05 MEGA-058 OWN dual
// Exactness: Ghidra name twin; see MissionDialog_SetNpcObjectAndNameCaption_Inferred.cpp
// =============================================================================

#include <cstdint>

extern char DAT_00a1419b;

// ESI = dialog*, EAX = npcObject* (0 clear); plain RET
void FUN_008aa4b0(void)
{
    int *piVar1;
    int iVar2;
    int in_EAX;
    std::uint32_t uVar3;
    int unaff_ESI;

    piVar1 = *(int **)(unaff_ESI + 0x6d8);
    *(int *)(unaff_ESI + 0x644) = in_EAX;
    if (piVar1 != (int *)0x0) {
        if (in_EAX == 0) {
            (**(void (__thiscall ***)(int *, char *, int, int))(*piVar1 + 0x1d8))(
                piVar1, &DAT_00a1419b, 1, 1);
        } else {
            iVar2 = *piVar1;
            uVar3 = (**(std::uint32_t (__thiscall ***)(int *, int, int))(
                *(int *)(*(int *)(*(int *)(in_EAX + 4) + 4) + 4 + in_EAX) + 0x160))(
                (int *)(*(int *)(*(int *)(in_EAX + 4) + 4) + 4 + in_EAX), 1, 1);
            (**(void (__thiscall ***)(int *, std::uint32_t))(iVar2 + 0x1d8))(
                *(int **)(unaff_ESI + 0x6d8), uVar3);
        }
        // retail: JMP [vtbl+0x34c]
        (**(void (__thiscall ***)(int *))(**(int **)(unaff_ESI + 0x6d8) + 0x34c))(
            *(int **)(unaff_ESI + 0x6d8));
        return;
    }
    return;
}
