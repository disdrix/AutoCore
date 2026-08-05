// =============================================================================
// StdString_OperatorPlus_Char
// -----------------------------------------------------------------------------
// Stable ID: aa_00416510
// Address:   0x00416510–0x00416589 (122 B / 0x7A, autoassault.exe base 0x400000)
// System:    MSVC free operator+(basic_string const&, char)
// Generated: 2026-07-29 W34-C dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving CF + ABI. IAT CRT string ops unowned.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00416510
// Reject:    Named_CalleeOf_* scaffold plate
// =============================================================================
//
// PURPOSE:
//   Free binary operator+ for MSVC basic_string + single char. Constructs a
//   temporary copy of lhs, appends rhs via operator+=(char), then
//   copy-constructs the result into the hidden return object.
//
// ABI (bytes):
//   cdecl; stack: out*, lhs*, char rhs; returns out* in EAX
//   SEH LAB_009bc093; temp string 0x1c on stack
//   IAT copy-ctor [0x009c62ec]; IAT +=char [0x009c6294]; IAT dtor [0x009c62f4]
//   Plain RET (C3); caller cleans 0x0C of stack args
//
// Peers:
//   StdString_OperatorPlus_String @ 0x00416410 (+= string IAT)
//   StdString_OperatorPlus_Cstr   @ 0x00416490 (+= cstr IAT)
// Sole caller: BasicString_CopyEnsureTrailingDirSep (aa_009694e0) with '/'
// =============================================================================

#include <cstdint>

struct MsvcBasicString {
  uint8_t raw[0x1c];
};

// Unowned / IAT targets (sealed by read_memory of import slots)
extern "C" MsvcBasicString* basic_string_copy_ctor(MsvcBasicString* self,
                                                   const MsvcBasicString* other);
extern "C" MsvcBasicString* basic_string_op_plus_eq_char(MsvcBasicString* self,
                                                         char rhs);
extern "C" void basic_string_dtor(MsvcBasicString* self);

// Retail cdecl; returns out
extern "C" MsvcBasicString* StdString_OperatorPlus_Char(
    MsvcBasicString* out,
    const MsvcBasicString* lhs,
    char rhs)
{
  // SEH + ExceptionList structure only (LAB_009bc093)
  // EH state = 0xFFFFFFFF at entry

  MsvcBasicString tmp{};
  // EH state = 0 around construction site (compiler frame)
  basic_string_copy_ctor(&tmp, lhs);
  // EH state = 1 (temp owns allocation)
  basic_string_op_plus_eq_char(&tmp, rhs);
  basic_string_copy_ctor(out, &tmp);
  // EH state low-byte cleared before destroy
  basic_string_dtor(&tmp);
  return out;
}

// Scaffold alias
extern "C" MsvcBasicString* FUN_00416510(MsvcBasicString* out,
                                         const MsvcBasicString* lhs,
                                         char rhs)
{
  return StdString_OperatorPlus_Char(out, lhs, rhs);
}
