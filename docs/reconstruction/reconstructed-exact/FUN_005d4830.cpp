// =============================================================================
// FUN_005d4830  (canonical: Object_EntityBase_Ctor)
// -----------------------------------------------------------------------------
// Stable ID: aa_005d4830
// Address:   0x005d4830 – 0x005d48e4  (181 B; autoassault.exe, image base 0x400000)
// System:    object core / entity base ctor
// Generated: 2026-07-29 W24-E dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named plate: reconstructed-exact/Object_EntityBase_Ctor.cpp
// =============================================================================

#include <cstdint>

extern "C" void* ExceptionList;
extern std::uint8_t LAB_009a709a[];
extern std::uint8_t DAT_009dd760[];
extern std::uint8_t DAT_009dac4c[];

extern "C" void* __thiscall Object_SharedBase_Ctor(void* self);
extern "C" void* __thiscall FUN_0053cdc0(void* self, int mostDerivedFlag);
extern "C" void* __thiscall FUN_00581330(void* self, int mostDerivedFlag);
extern "C" void* __thiscall Object_EntityBase_Ctor(void* self, int mostDerivedFlag);

// Ghidra twin — delegates to named plate
extern "C" void* __thiscall FUN_005d4830(void* param_1, int param_2)
{
  return Object_EntityBase_Ctor(param_1, param_2);
}
