// =============================================================================
// LightHost_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0096e4b0
// Address:   0x0096e4b0  (autoassault.exe, image base 0x400000)
// System:    client / effect light host
// Wave:      W37-AB (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompiler + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher).
// Ghidra:    FUN_0096e4b0
// =============================================================================
//
// PURPOSE:
//   Ctor for light-host objects of size 0x94.
//   1) Base gfx-effect host ctor FUN_0096d830 (vtable PTR_FUN_00aa0824 + POD defaults).
//   2) Zero effect-core slots +0x8C and +0x90.
//   3) Install derived vtable PTR_FUN_00aa0394.
//
// CALLERS (context):
//   - PalantirEnv_RebuildDefaultLights_Inferred (0x0048f370): new(0x94)+ctor → env+0x108 / +0x104
//   - FUN_0058f780: new(0x94)+ctor → geom+0x91c (Point light path)
//
// REJECT: Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCa_0096e4b0
// =============================================================================

#include <cstdint>

// Unowned base ctor (body not owned this wave).
extern "C" uint32_t* __cdecl FUN_0096d830(uint32_t* self);

// Vtable installed by this ctor (slot0 scalar dtor 0x004493d0).
extern "C" void* PTR_FUN_00aa0394[];

struct LightHost {
    void*    vtbl;          // +0x00 → PTR_FUN_00aa0394 after this ctor
    uint8_t  base_pad[0x88];
    void*    effect_core;   // +0x8C — zeroed here; callers bind effect params
    void*    related_90;    // +0x90 — zeroed here
    // total alloc size 0x94
};

// __thiscall: ECX = self; returns self in EAX; bare RET
extern "C" LightHost* __fastcall LightHost_Ctor_Inferred(LightHost* self)
{
    FUN_0096d830(reinterpret_cast<uint32_t*>(self));
    self->effect_core = nullptr;   // +0x8C
    self->related_90  = nullptr;   // +0x90
    self->vtbl        = &PTR_FUN_00aa0394[0];
    return self;
}

// Twin Ghidra name
extern "C" LightHost* __fastcall FUN_0096e4b0(LightHost* self)
{
    return LightHost_Ctor_Inferred(self);
}
