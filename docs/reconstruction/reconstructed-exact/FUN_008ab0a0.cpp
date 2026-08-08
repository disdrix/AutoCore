// =============================================================================
// FUN_008ab0a0  (twin of Client_NpcMissionDialog_InitRuntimeFields_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_008ab0a0
// Address:   0x008ab0a0 – 0x008ab33d inclusive (670 B / 0x29E)
// Module:    autoassault.exe (image base 0x400000)
// System:    missions-progression
// Dual:      R11-035 2026-08-05 accept-with-gaps
// Exactness: Behavior-preserving rewrite. Bit-for-bit: DEFERRED.
// =============================================================================

#include <cstdint>

extern float g_flOne;       // 0x00a0f2a0 = 1.0f
extern float DAT_00a0f71c;  // 0.6f
extern float DAT_00aaa7e8;  // 0.157f
extern float DAT_00aaa7e4;  // 0.549f

// thiscall ECX=host; plain RET; leaf
void __fastcall FUN_008ab0a0(int param_1)
{
    float fVar1;
    std::uint32_t uVar2;
    std::uint32_t uVar3;

    *(std::uint32_t *)(param_1 + 0x4b8) = 0;
    *(std::uint32_t *)(param_1 + 0x4bc) = 0;
    *(std::uint32_t *)(param_1 + 0x4b4) = 0;
    *(std::uint32_t *)(param_1 + 0x504) = 0;
    *(std::uint32_t *)(param_1 + 0x508) = 0;
    *(std::uint32_t *)(param_1 + 0x680) = 0;
    *(std::uint32_t *)(param_1 + 0x684) = 0;
    *(std::uint32_t *)(param_1 + 0x688) = 0;
    *(std::uint32_t *)(param_1 + 0x690) = 0;
    *(std::uint32_t *)(param_1 + 0x694) = 0;
    *(std::uint32_t *)(param_1 + 0x6d8) = 0;
    *(std::uint32_t *)(param_1 + 0x6dc) = 0;
    *(std::uint32_t *)(param_1 + 0x6e0) = 0;
    *(std::uint32_t *)(param_1 + 0x68c) = 0;
    *(std::uint32_t *)(param_1 + 0x6e4) = 0;
    *(std::uint32_t *)(param_1 + 0x6e8) = 0;
    *(std::uint32_t *)(param_1 + 0x700) = 0;
    *(std::uint32_t *)(param_1 + 0x6ec) = 0;
    *(std::uint32_t *)(param_1 + 0x6f0) = 0;
    *(std::uint32_t *)(param_1 + 0x6f4) = 0;
    *(std::uint32_t *)(param_1 + 0x6f8) = 0;
    *(std::uint32_t *)(param_1 + 0x6fc) = 0;
    *(std::uint32_t *)(param_1 + 0x644) = 0;
    *(std::uint32_t *)(param_1 + 0x558) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x55c) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x6a8) = 0;
    *(std::uint32_t *)(param_1 + 0x6b8) = 0;
    *(std::uint32_t *)(param_1 + 0x6c8) = 0;
    *(std::uint32_t *)(param_1 + 0x698) = 0;
    *(std::uint32_t *)(param_1 + 0x560) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x564) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x6ac) = 0;
    *(std::uint32_t *)(param_1 + 0x6bc) = 0;
    *(std::uint32_t *)(param_1 + 0x6cc) = 0;
    *(std::uint32_t *)(param_1 + 0x69c) = 0;
    *(std::uint32_t *)(param_1 + 0x568) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x56c) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x6b0) = 0;
    *(std::uint32_t *)(param_1 + 0x6c0) = 0;
    *(std::uint32_t *)(param_1 + 0x6d0) = 0;
    *(std::uint32_t *)(param_1 + 0x6a0) = 0;
    *(std::uint32_t *)(param_1 + 0x570) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x574) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x6b4) = 0;
    *(std::uint32_t *)(param_1 + 0x6c4) = 0;
    *(std::uint32_t *)(param_1 + 0x6d4) = 0;
    *(std::uint32_t *)(param_1 + 0x6a4) = 0;
    *(std::uint32_t *)(param_1 + 0x510) = 0;
    *(std::uint32_t *)(param_1 + 0x518) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x51c) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x708) = 0;
    *(std::uint32_t *)(param_1 + 0x520) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x524) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x70c) = 0;
    *(std::uint32_t *)(param_1 + 0x528) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x52c) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x710) = 0;
    *(std::uint32_t *)(param_1 + 0x530) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x534) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x714) = 0;
    *(std::uint32_t *)(param_1 + 0x538) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x53c) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x718) = 0;
    *(std::uint32_t *)(param_1 + 0x540) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x544) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x71c) = 0;
    *(std::uint32_t *)(param_1 + 0x548) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x54c) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x720) = 0;
    *(std::uint32_t *)(param_1 + 0x550) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x554) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x724) = 0;
    *(std::uint32_t *)(param_1 + 0x578) = 0xffffffff;
    *(std::uint32_t *)(param_1 + 0x57c) = 0xffffffff;
    uVar3 = *reinterpret_cast<std::uint32_t *>(&DAT_00aaa7e8);
    uVar2 = *reinterpret_cast<std::uint32_t *>(&DAT_00a0f71c);
    *(std::uint32_t *)(param_1 + 0x594) = 0;
    *(std::uint32_t *)(param_1 + 0x598) = 0;
    *(std::uint32_t *)(param_1 + 0x59c) = 0;
    fVar1 = g_flOne;
    *(std::uint32_t *)(param_1 + 0x5a0) = uVar2;
    *(std::uint32_t *)(param_1 + 0x584) = 0;
    *(float *)(param_1 + 0x588) = fVar1;
    *(std::uint32_t *)(param_1 + 0x58c) = 0;
    *(std::uint32_t *)(param_1 + 0x590) = uVar3;
    *(std::uint32_t *)(param_1 + 0x5a4) = 0;
    *(float *)(param_1 + 0x5a8) = fVar1;
    uVar2 = *reinterpret_cast<std::uint32_t *>(&DAT_00aaa7e4);
    *(std::uint32_t *)(param_1 + 0x5ac) = 0;
    *(std::uint32_t *)(param_1 + 0x5b0) = uVar2;
    *(std::uint8_t *)(param_1 + 0x64c) = 0;
}
