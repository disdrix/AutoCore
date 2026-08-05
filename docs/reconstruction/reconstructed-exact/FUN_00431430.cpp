// =============================================================================
// FUN_00431430  (scaffold twin → StdVector_UninitializedCopy_BasicString)
// -----------------------------------------------------------------------------
// Stable ID: aa_00431430
// Address:   0x00431430  (autoassault.exe, image base 0x400000)
// Wave:      W33-H OWN-ONLY dual 2026-07-29
// =============================================================================

#include <cstdint>

struct BasicString_0x1c {
  uint8_t bytes[0x1c];
};

struct VectorBasicString {
  void* _unused0;
  BasicString_0x1c* begin;
  BasicString_0x1c* end;
  BasicString_0x1c* cap_end;
};

extern "C" BasicString_0x1c* FUN_0046a2c0(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest,
    VectorBasicString* vec,
    BasicString_0x1c* dest_again);

extern "C" BasicString_0x1c* __fastcall FUN_00431430(
    VectorBasicString* vec,
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest)
{
  return FUN_0046a2c0(first, last, dest, vec, dest);
}
