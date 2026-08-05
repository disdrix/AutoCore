// =============================================================================
// FourCC_DwordToStdString  (canonical name for aa_00436190)
// -----------------------------------------------------------------------------
// Stable ID: aa_00436190
// Address:   0x00436190 – 0x0043621f  (autoassault.exe, image base 0x400000)
// See also:  FUN_00436190.cpp (same CF)
// Exactness: Behavior-preserving. Not modernization. Bit-for-bit: DEFERRED.
// =============================================================================

#include <cstdint>
#include <string>

// __cdecl: std::string *FourCC_DwordToStdString(std::string *out, uint32_t tag)
// Returns out. Tag bytes written big-endian into a 5-byte C string (4 chars + NUL).

std::string *FourCC_DwordToStdString(std::string *out, uint32_t tag)
{
  char buf[5];
  std::string tmp;

  buf[0] = static_cast<char>((tag >> 24) & 0xffu);
  buf[1] = static_cast<char>((tag >> 16) & 0xffu);
  buf[2] = static_cast<char>((tag >> 8) & 0xffu);
  buf[3] = static_cast<char>(tag & 0xffu);
  buf[4] = '\0';

  tmp = std::string(buf);
  *out = tmp;
  return out;
}
