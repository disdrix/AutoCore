// =============================================================================
// StdString_OperatorPlus_String
// -----------------------------------------------------------------------------
// Stable ID: aa_00416410
// Address:   0x00416410–0x00416489 (122 B / 0x7A, autoassault.exe base 0x400000)
// System:    MSVC free operator+(basic_string const&, basic_string const&)
// Generated: 2026-07-29 W33-F dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving CF + ABI. IAT CRT string ops unowned.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00416410
// Reject:    Named_CalleeOf_Named_effDeviceEffect_00416410 (scaffold)
// =============================================================================
//
// PURPOSE:
//   Free binary operator+ for two MSVC basic_string operands. Constructs a
//   temporary copy of lhs, appends rhs via operator+=(basic_string const&),
//   then copy-constructs the result into the hidden return object.
//
// ABI (bytes):
//   cdecl; stack: out*, lhs*, rhs*; returns out* in EAX
//   SEH LAB_009bc093; temp string 0x1c on stack
//   IAT copy-ctor [0x009c62ec]; IAT +=string [0x009c62a0]; IAT dtor [0x009c62f4]
//   Plain RET (C3); caller cleans 0x0C of stack args
//
// Peer: StdString_OperatorPlus_Cstr @ 0x00416490 (identical except += IAT)
// =============================================================================

#include <cstdint>

struct MsvcBasicString {
  uint8_t raw[0x1c];
};

// Unowned / IAT targets (sealed by read_memory of import slots)
extern "C" MsvcBasicString* basic_string_copy_ctor(MsvcBasicString* self,
                                                   const MsvcBasicString* other);
extern "C" MsvcBasicString* basic_string_op_plus_eq_string(MsvcBasicString* self,
                                                            const MsvcBasicString* rhs);
extern "C" void basic_string_dtor(MsvcBasicString* self);

// Retail cdecl; returns out
extern "C" MsvcBasicString* StdString_OperatorPlus_String(
    MsvcBasicString* out,
    const MsvcBasicString* lhs,
    const MsvcBasicString* rhs)
{
  // SEH + ExceptionList structure only (LAB_009bc093)

  MsvcBasicString tmp{};
  basic_string_copy_ctor(&tmp, lhs);
  // EH state = 1
  basic_string_op_plus_eq_string(&tmp, rhs);
  basic_string_copy_ctor(out, &tmp);
  basic_string_dtor(&tmp);
  return out;
}

// Scaffold alias
extern "C" MsvcBasicString* FUN_00416410(MsvcBasicString* out,
                                         const MsvcBasicString* lhs,
                                         const MsvcBasicString* rhs)
{
  return StdString_OperatorPlus_String(out, lhs, rhs);
}
