// =============================================================================
// FUN_004a74f0  (scaffold / Ghidra alias of StdUninitFillN_BasicStringW)
// -----------------------------------------------------------------------------
// Stable ID: aa_004a74f0
// Address:   0x004a74f0  (autoassault.exe, image base 0x400000)
// Wave:      W36-R OWN-ONLY dual 2026-07-29
// =============================================================================

#include <cstdint>

struct BasicStringW_0x1c {
  uint8_t storage[0x1c];
};

extern "C" void StdUninitFillN_BasicStringW(
    BasicStringW_0x1c* dest,
    int count,
    const BasicStringW_0x1c* value);

// Ghidra name alias — prefer StdUninitFillN_BasicStringW.
extern "C" void FUN_004a74f0(
    BasicStringW_0x1c* dest,
    int count,
    const BasicStringW_0x1c* value)
{
  StdUninitFillN_BasicStringW(dest, count, value);
}
