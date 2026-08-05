// =============================================================================
// Object_EntityBase_Ctor
// -----------------------------------------------------------------------------
// Purpose:  MSVC most-derived / base constructor for the entity base that sits
//           under Object_EntityMidBase. Optional dual-base cookies + SharedBase
//           at +0xe0; always chains FUN_0053cdc0@+0 and FUN_00581330@+0x40;
//           zeros +0xbc/+0xc0; ORs feature flags 0x40|0x20 at vb+0x180.
//
// Address:  0x005d4830  (autoassault.exe, image base 0x400000)
// Body:     0x005d4830–0x005d48e4 (181 bytes)
// Stable:   aa_005d4830
// System:   object core / entity base ctor
// Ghidra:   FUN_005d4830
//
// ABI:      __thiscall  void* Object_EntityBase_Ctor(void* self, int mostDerivedFlag)
//           ECX=this; stack mostDerivedFlag; EAX=this; RET 4
//
// Exactness: CF mirrors raw + read_memory bytes; decomp this-adjust corrected.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W24-E seal).
// Twin plate: reconstructed-exact/FUN_005d4830.cpp
// =============================================================================

#include <cstdint>

extern "C" void* ExceptionList;
extern std::uint8_t LAB_009a709a[];
extern std::uint8_t DAT_009dd760[];
extern std::uint8_t DAT_009dac4c[];

extern "C" void* __thiscall Object_SharedBase_Ctor(void* self); // 0x00518940
extern "C" void* __thiscall FUN_0053cdc0(void* self, int mostDerivedFlag);
extern "C" void* __thiscall FUN_00581330(void* self, int mostDerivedFlag);

// Ghidra: FUN_005d4830
extern "C" void* __thiscall Object_EntityBase_Ctor(void* self, int mostDerivedFlag)
{
  void* local_c;
  std::uint8_t* puStack_8;
  std::uint32_t local_4;
  std::uint8_t* base = static_cast<std::uint8_t*>(self);

  local_4 = 0xffffffffu;
  puStack_8 = &LAB_009a709a[0];
  local_c = ExceptionList;
  ExceptionList = &local_c;

  if (mostDerivedFlag != 0) {
    ExceptionList = &local_c;
    *reinterpret_cast<void**>(base + 4) = &DAT_009dd760[0];
    *reinterpret_cast<void**>(base + 0x44) = &DAT_009dac4c[0];
    // image: lea ecx, [this+0xe0]
    Object_SharedBase_Ctor(base + 0xe0);
    local_4 = 0;
  }

  // image: push 0; mov ecx, this
  FUN_0053cdc0(self, 0);
  local_4 = 1;
  // image: push 0; lea ecx, [this+0x40]
  FUN_00581330(base + 0x40, 0);

  *reinterpret_cast<std::uint32_t*>(base + 0xbc) = 0;
  *reinterpret_cast<std::uint32_t*>(base + 0xc0) = 0;

  {
    const std::int32_t vbOff =
        *reinterpret_cast<std::int32_t*>(*reinterpret_cast<std::uint8_t**>(base + 4) + 4);
    std::uint32_t* flags =
        reinterpret_cast<std::uint32_t*>(base + vbOff + 0x180);
    *flags |= 0x40u;
    *flags |= 0x20u;
  }

  ExceptionList = local_c;
  return self;
}
