// =============================================================================
// FUN_0096e4b0  (twin of LightHost_Ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0096e4b0
// Address:   0x0096e4b0  (autoassault.exe, image base 0x400000)
// Wave:      W37-AB (2026-08-04)
// See:       LightHost_Ctor_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" uint32_t* __cdecl FUN_0096d830(uint32_t* self);
extern "C" void* PTR_FUN_00aa0394[];

// __thiscall via ECX; returns this
extern "C" uint32_t* __fastcall FUN_0096e4b0(uint32_t* self)
{
    FUN_0096d830(self);
    self[0x23] = 0;                 // +0x8C
    self[0x24] = 0;                 // +0x90
    *self = reinterpret_cast<uint32_t>(&PTR_FUN_00aa0394[0]);
    return self;
}
