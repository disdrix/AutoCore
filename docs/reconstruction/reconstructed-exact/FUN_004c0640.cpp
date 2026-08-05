// =============================================================================
// FUN_004c0640  (twin of ParticleFluidPhase_Ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004c0640
// Address:   0x004c0640–0x004c0706  (autoassault.exe, image base 0x400000)
// Dual:      W34-M 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void* __fastcall FUN_007560d0(void* self /*ECX*/);
extern "C" void __fastcall FUN_0096f530(void* field /*ECX*/);
extern "C" void* PTR_FUN_009cb62c;
extern "C" void* DAT_00b03790;

// Retail: ECX=this; stack parent*; returns this; RET 4.
extern "C" void* __thiscall FUN_004c0640(void* self /*ECX*/, void* parent)
{
  (void)FUN_007560d0(self);

  *reinterpret_cast<void**>(self) = &PTR_FUN_009cb62c;
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
