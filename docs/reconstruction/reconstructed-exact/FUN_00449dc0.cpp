// =============================================================================
// FUN_00449dc0  — scaffold alias of phyBoneSharedData_CreateDefaultAndInstall
// -----------------------------------------------------------------------------
// Stable ID: aa_00449dc0
// Address:   0x00449dc0  (autoassault.exe, image base 0x400000)
// Body:      0x00449dc0 – 0x00449e72 (exclusive end; 178 bytes)
// System:    physics / phy (asset I/O)
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W20-E)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Prefer: reconstructed-exact/phyBoneSharedData_CreateDefaultAndInstall.cpp
// =============================================================================
//
// ABI: EBX = container* (slot at +4). Bare ret.
// Alloc 0x90 default phyBoneSharedData; identity qs + matrix; AddRef/Release install.
//

#include <stdint.h>

extern void *operator_new(uint32_t size);
extern float g_flOne;
extern uint32_t DAT_00d1eac0;
extern uint32_t DAT_00afdf70;
extern void *PTR_FUN_00aa050c;

// Decompiler-shaped CF (unaff_EBX = container)
void FUN_00449dc0(void)
{
    float fVar1;
    int *piVar2;
    int iVar3;
    int unaff_EBX;
    int *piVar4;
    int *piVar5;

    piVar2 = (int *)operator_new(0x90);
    fVar1 = g_flOne;
    if (piVar2 == (int *)0x0) {
        piVar2 = (int *)0x0;
    }
    else {
        piVar2[1] = 0;
        *piVar2 = (int)&PTR_FUN_00aa050c;
        piVar2[2] = DAT_00d1eac0;
        piVar2[3] = 0;
        piVar2[4] = 0;
        piVar2[5] = 0;
        piVar2[6] = *(int *)&fVar1;
        piVar2[7] = 0;
        piVar2[8] = 0;
        piVar2[9] = 0;
        piVar2[10] = *(int *)&fVar1;
        piVar2[0xb] = *(int *)&fVar1;
        piVar2[0xc] = *(int *)&fVar1;
        piVar4 = (int *)&DAT_00afdf70;
        piVar5 = piVar2 + 0x10;
        for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *piVar5 = *piVar4;
            piVar4 = piVar4 + 1;
            piVar5 = piVar5 + 1;
        }
        piVar2[0x20] = 0;
    }
    if ((piVar2 != (int *)0x0) && (piVar2[1] = piVar2[1] + 1, piVar2[1] == 1)) {
        ((void (*)(void))(*(uint32_t *)(*piVar2 + 4)))();
    }
    piVar4 = *(int **)(unaff_EBX + 4);
    if (piVar4 != (int *)0x0) {
        piVar5 = piVar4 + 1;
        *piVar5 = *piVar5 + -1;
        if (*piVar5 == 0) {
            ((void (*)(void))(*(uint32_t *)(*piVar4 + 8)))();
        }
    }
    *(int **)(unaff_EBX + 4) = piVar2;
    return;
}
