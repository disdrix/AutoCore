// =============================================================================
// FUN_008ac3f0  (machine twin of Client_NpcMissionDialogHost_Ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_008ac3f0
// Address:   0x008ac3f0  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Dual:      MEGA-107 2026-08-05
// Exactness: Ghidra symbol kept for VA twin; prefer meaningful clean:
//            Client_NpcMissionDialogHost_Ctor_Inferred.cpp
// =============================================================================

#include <cstdint>

extern float g_flOne;
extern std::uint32_t* FUN_0087b890(std::uint32_t* self, std::uint32_t arg1);
extern void FUN_008ab0a0();
extern void NDUIWindow_ReloadInterface(const char* xml_name);
extern void FUN_008ac110(); // UI_MissionDialog_BuildResponseButtons_Inferred

// Ghidra signature form (stack this*; RET 4)
int* FUN_008ac3f0(int* param_1)
{
    float fVar1;
    void* local_c;
    std::uint8_t* puStack_8;
    std::uint32_t local_4;

    local_4 = 0xffffffff;
    puStack_8 = reinterpret_cast<std::uint8_t*>(0x009b645d); // LAB_009b645d
    // local_c = ExceptionList; ExceptionList = &local_c;

    FUN_0087b890(reinterpret_cast<std::uint32_t*>(param_1), 0);
    fVar1 = g_flOne;
    *param_1 = static_cast<int>(0x00a4a51c); // PTR_FUN_00a4a51c

    param_1[0x161] = 0;
    param_1[0x162] = 0;
    param_1[0x163] = 0;
    param_1[0x164] = *reinterpret_cast<int*>(&fVar1);
    param_1[0x165] = 0;
    param_1[0x166] = 0;
    param_1[0x167] = 0;
    param_1[0x168] = *reinterpret_cast<int*>(&fVar1);
    param_1[0x169] = 0;
    param_1[0x16a] = 0;
    param_1[0x16b] = 0;
    param_1[0x16c] = *reinterpret_cast<int*>(&fVar1);

    param_1[0x1cb] = 0;
    param_1[0x1cc] = 0;
    param_1[0x1cd] = 0;
    param_1[0x1cf] = 0;
    param_1[0x1d0] = 0;
    param_1[0x1d1] = 0;

    local_4 = 2;
    param_1[0x13f] = 0xc;
    param_1[0x140] = 1;
    param_1[0x192] = 0;
    param_1[0x143] = 0;
    param_1[399] = 1;
    param_1[400] = 1;
    param_1[0x145] = 0;
    *reinterpret_cast<std::uint8_t*>(param_1 + 0x160) = 0;
    param_1[0x1c1] = 0;
    param_1[0x170] = 0;
    param_1[0x16f] = 0;

    FUN_008ab0a0();
    NDUIWindow_ReloadInterface("i_d_npc.xml");
    FUN_008ac110();
    (**(void(**)())(*param_1 + 0x34c))();

    // ExceptionList = local_c;
    (void)local_c;
    (void)puStack_8;
    (void)local_4;
    return param_1;
}
