// =============================================================================
// Object_EntityMidBase_Ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_005c82a0
// Address:   0x005c82a0–0x005c83a1  (257 B; autoassault.exe, image base 0x400000)
// System:    object core / entity mid-base ctor
// Ghidra:    FUN_005c82a0
// Dual seal: W23-K 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving; not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
//   MSVC most-derived / base constructor for the entity mid-base shared by
//   CVOGCreature and Vehicle (0x00501970). Optional dual-base cookies when
//   mostDerivedFlag!=0 (Object_SharedBase at +0x110); always chains parent
//   FUN_005d4830(0); installs mid-base vtbls; vb adjustor -0x10c; defaults
//   fields +0xD0..+0xF8 including 500 at +0xE4.
//
// ABI (image-sealed)
//   __thiscall void* Ctor(this, int mostDerivedFlag);  RET 4; EAX=this
// =============================================================================

#include <cstdint>

extern "C" void* ExceptionList;
extern uint8_t LAB_009a6eff[];
extern uint32_t DAT_009da754, DAT_009de778;
extern void* PTR_FUN_009da70c;
extern void* PTR_FUN_009da6d0;
extern void* PTR_LAB_009da40c;

extern "C" void* __thiscall Object_SharedBase_Ctor(void* self); // 0x00518940
extern "C" void* __thiscall FUN_005d4830(void* self, int mostDerivedFlag);

// Ghidra: FUN_005c82a0
extern "C" uint32_t* __thiscall Object_EntityMidBase_Ctor(uint32_t* self, int mostDerivedFlag)
{
  void* local_c;
  uint8_t* puStack_8;
  uint32_t local_4;

  local_4 = 0xffffffffu;
  puStack_8 = &LAB_009a6eff[0];
  local_c = ExceptionList;
  ExceptionList = &local_c;

  if (mostDerivedFlag != 0) {
    ExceptionList = &local_c;
    self[1] = reinterpret_cast<uint32_t>(&DAT_009da754);
    self[0x11] = reinterpret_cast<uint32_t>(&DAT_009de778);
    // image: lea ecx, [this+0x110]
    Object_SharedBase_Ctor(reinterpret_cast<uint8_t*>(self) + 0x110);
    local_4 = 0;
  }

  FUN_005d4830(self, 0);

  *self = reinterpret_cast<uint32_t>(&PTR_FUN_009da70c);
  self[0x10] = reinterpret_cast<uint32_t>(&PTR_FUN_009da6d0);

  {
    const int vbOff = *reinterpret_cast<int*>(self[1] + 4);
    *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(self) + vbOff + 4) =
        &PTR_LAB_009da40c;
    *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + vbOff) =
        vbOff + -0x10c;
  }

  self[0x34] = 0;                                       // +0xD0
  self[0x35] = 0;                                       // +0xD4
  *reinterpret_cast<uint16_t*>(self + 0x36) = 0;        // +0xD8
  self[0x37] = 0;                                       // +0xDC
  self[0x38] = 0;                                       // +0xE0
  *reinterpret_cast<uint8_t*>(self + 0x3c) = 0;         // +0xF0
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0xF1) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0xF5) = 0;
  self[0x3e] = 0;                                       // +0xF8
  self[0x39] = 500;                                     // +0xE4
  self[0x3a] = 1;                                       // +0xE8
  self[0x3b] = 0xffffffffu;                             // +0xEC
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0xF2) = 1;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0xF3) = 1;
  *reinterpret_cast<uint8_t*>(self + 0x3d) = 1;         // +0xF4

  ExceptionList = local_c;
  return self;
}

// Ghidra twin
extern "C" uint32_t* __thiscall FUN_005c82a0(uint32_t* param_1, int param_2)
{
  return Object_EntityMidBase_Ctor(param_1, param_2);
}
