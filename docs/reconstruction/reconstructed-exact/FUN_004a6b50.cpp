// =============================================================================
// FUN_004a6b50  (scaffold / Ghidra alias of StdUninitCopy_BasicStringW)
// -----------------------------------------------------------------------------
// Stable ID: aa_004a6b50
// Address:   0x004a6b50  (autoassault.exe, image base 0x400000)
// Wave:      W36-R OWN-ONLY dual 2026-07-29
// =============================================================================

#include <cstdint>

struct BasicStringW_0x1c {
  uint8_t storage[0x1c];
};

extern "C" BasicStringW_0x1c* StdUninitCopy_BasicStringW(
    BasicStringW_0x1c* first,
    BasicStringW_0x1c* last,
    BasicStringW_0x1c* dest);

// Ghidra name alias — prefer StdUninitCopy_BasicStringW.
extern "C" BasicStringW_0x1c* FUN_004a6b50(
    BasicStringW_0x1c* first,
    BasicStringW_0x1c* last,
    BasicStringW_0x1c* dest)
{
  return StdUninitCopy_BasicStringW(first, last, dest);
}
