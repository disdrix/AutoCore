// =============================================================================
// FUN_004a7a70  — scaffold twin of StdUninitFillN_BasicStringW
// -----------------------------------------------------------------------------
// Address:   0x004a7a70  (autoassault.exe, image base 0x400000)
// Wave:      W36-S OWN-ONLY dual 2026-07-29
// Canonical: StdUninitFillN_BasicStringW
// =============================================================================

#include <cstdint>

struct BasicStringW_0x1c {
  uint8_t storage[0x1c];
};

extern "C" void FUN_004a74f0(BasicStringW_0x1c* dest, int count,
                             const BasicStringW_0x1c* value, void* alloc,
                             const BasicStringW_0x1c* value_echo);

extern "C" BasicStringW_0x1c* __thiscall FUN_004a7a70(
    void* alloc,
    BasicStringW_0x1c* dest,
    int count,
    const BasicStringW_0x1c* value)
{
  FUN_004a74f0(dest, count, value, alloc, value);
  return reinterpret_cast<BasicStringW_0x1c*>(
      reinterpret_cast<char*>(dest) + static_cast<uint32_t>(count) * 0x1cu);
}
