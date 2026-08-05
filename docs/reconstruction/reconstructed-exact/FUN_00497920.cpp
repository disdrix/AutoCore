// =============================================================================
// FUN_00497920  (twin of ListTrackedCtx_Ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00497920
// Address:   0x00497920  (autoassault.exe, image base 0x400000)
// Wave:      W32-P 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_00787520(void* sub);
extern "C" std::uint32_t FUN_00788db0(void* dst, unsigned n);
extern "C" void* DAT_00b035cc;
extern "C" void* ExceptionList;
extern "C" std::uint8_t LAB_009a0dbe;

// __thiscall; ret 4; returns this
std::uint8_t* __thiscall FUN_00497920(std::uint8_t* param_1, std::uint32_t param_2)
{
    void* local_c;
    std::uint8_t* puStack_8;
    std::uint32_t local_4;

    local_4 = 0xFFFFFFFF;
    puStack_8 = &LAB_009a0dbe;
    local_c = ExceptionList;
    ExceptionList = &local_c;

    FUN_00787520(param_1 + 0xB8);
    local_4 = 0;

    *param_1 = 1;
    *reinterpret_cast<std::uint32_t*>(param_1 + 0x04) = 0;
    *reinterpret_cast<std::uint32_t*>(param_1 + 0x08) = 0;
    *reinterpret_cast<std::uint32_t*>(param_1 + 0x0C) = 5;
    *reinterpret_cast<std::uint32_t*>(param_1 + 0x10) = 0;
    FUN_00788db0(param_1 + 0x14, 0xA0);
    *reinterpret_cast<std::uint32_t*>(param_1 + 0xB4) = 0;
    *reinterpret_cast<std::uint32_t*>(param_1 + 0xC4) = param_2;
    DAT_00b035cc = param_1;

    ExceptionList = local_c;
    return param_1;
}
