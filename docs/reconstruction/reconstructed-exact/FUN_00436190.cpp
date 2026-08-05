// =============================================================================
// FUN_00436190 / FourCC_DwordToStdString
// -----------------------------------------------------------------------------
// Stable ID: aa_00436190
// Address:   0x00436190 – 0x0043621f  (autoassault.exe, image base 0x400000)
// System:    util / fourcc
// Generated: 2026-07-29 OWN-ONLY dual seal (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Layout uint32 tag as big-endian 4-char C string + NUL, construct std::string
//   into caller out-parameter; return out.
//
// CALLING CONVENTION: __cdecl
//   arg0 = std::string *out
//   arg1 = uint32_t tag
//   return = out
//
// CALLEES: std::string ctor(const char*), copy-ctor, dtor (imports).
// =============================================================================

#include <cstdint>
#include <string>

// Faithful reconstructed-exact (CF + byte order sealed).
// MSVC retail uses Dinkumware basic_string; std::string here is the semantic stand-in.

std::string *FUN_00436190(std::string *out, uint32_t tag)
{
  char buf[5];
  std::string tmp;

  // Byte order matches live body at 0x00436190 (BE FourCC):
  //   buf[0] = tag>>24; buf[1] = tag>>16; buf[2] = tag>>8; buf[3] = tag; buf[4] = 0
  buf[0] = static_cast<char>((tag >> 24) & 0xffu);
  buf[1] = static_cast<char>((tag >> 16) & 0xffu);
  buf[2] = static_cast<char>((tag >> 8) & 0xffu);
  buf[3] = static_cast<char>(tag & 0xffu);
  buf[4] = '\0';

  tmp = std::string(buf);   // retail: basic_string(const char*)
  *out = tmp;               // retail: copy-construct into out object storage
  // retail: explicit ~basic_string on tmp; SEH frame omitted in clean scaffold
  return out;
}
