// =============================================================================
// ParticleFluidPhase_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004c0640
// Address:   0x004c0640–0x004c0706  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_004c0640
// System:    client / particle fluid phase (env+0xCC host, size 0xC8)
// Dual:      W34-M 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ECX = this; stack parent*; returns this; RET 0x4.
// Sequence: HostBase_DefaultCtor → derived vtbl → field inits → parent wiring
// → DAT_00b03790 = this → (+0x78)=0.
// Sole caller: PalantirEnv_InitPhases (new(0xC8) then this ctor → env+0xCC).
// Name structural from W33-S ParticleFluidPhase_Init_Inferred peer.
// Reject scaffold Named_CalleeOf_Drive_NDRiver_fx_004c0640.
// =============================================================================

#include <cstdint>

extern "C" void* __fastcall HostBase_DefaultCtor_Inferred(void* self /*ECX*/);
// Also linked as FUN_007560d0
extern "C" void* __fastcall FUN_007560d0(void* self /*ECX*/);

// 8-byte field zero-init pattern (dword 0 + 3 flag bytes); unowned product type.
extern "C" void __fastcall FUN_0096f530(void* field /*ECX*/);

// Derived vtbl pointer (image absolute).
extern "C" void* PTR_FUN_009cb62c;

// Global singleton of constructed phase instance.
extern "C" void* DAT_00b03790;

struct ParticleFluidPhase {
  void*    vtbl;           // +0x00  (HostBase then replaced)
  // HostBase body through ~+0x78 …
  // Derived:
  // +0x78 uint8  enable-ish (set 0 here; HostBase left 1)
  // +0x80 uint8  = 1
  // +0x84, +0x8c  FUN_0096f530 slots
  // +0x94..+0x9c  zeros
  // +0xa0 parent*
  // +0xa4 copy parent+0xe4e8
  // +0xa8 copy parent+0xe894
  // +0xac..+0xb4 zeros; +0xbc..+0xc4 zeros  (sizeof object 0xC8)
  uint8_t  _pad[0xC4];
};

extern "C" ParticleFluidPhase* __thiscall ParticleFluidPhase_Ctor_Inferred(
    ParticleFluidPhase* self /*ECX*/,
    void* parent)
{
  // SEH frame omitted (MSVC FS:[0] / LAB_009a19c6).
  (void)FUN_007560d0(self);

  self->vtbl = &PTR_FUN_009cb62c;
  reinterpret_cast<uint8_t*>(self)[0x80] = 1;

  FUN_0096f530(reinterpret_cast<uint8_t*>(self) + 0x84);
  FUN_0096f530(reinterpret_cast<uint8_t*>(self) + 0x8c);

  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x94) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x98) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x9c) = 0;

  *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(self) + 0xa0) = parent;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0xa4) =
      *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(parent) + 0xe4e8);
  const uint32_t parent_e894 =
      *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(parent) + 0xe894);

  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0xac) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0xb0) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0xb4) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0xbc) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0xc0) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0xc4) = 0;

  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0xa8) = parent_e894;

  DAT_00b03790 = self;
  reinterpret_cast<uint8_t*>(self)[0x78] = 0;

  return self;
}

extern "C" ParticleFluidPhase* __thiscall FUN_004c0640(ParticleFluidPhase* self /*ECX*/,
                                                       void* parent)
{
  return ParticleFluidPhase_Ctor_Inferred(self, parent);
}
