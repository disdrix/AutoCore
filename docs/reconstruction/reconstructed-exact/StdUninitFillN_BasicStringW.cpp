// =============================================================================
// StdUninitFillN_BasicStringW  (aa_004a7a70)
// -----------------------------------------------------------------------------
// Address:   0x004a7a70  (autoassault.exe, image base 0x400000)
// Body:      0x004a7a70 – 0x004a7aa0 exclusive (48 B / 0x30)
// Wave:      W36-S OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct BasicStringW_0x1c {
  uint8_t storage[0x1c];
};

static constexpr uint32_t kElemSize = 0x1c;

// Nested fill loop (not dual-owned; W36-R). Prototype matches live formals;
// retail call pushes five dwords: dest, count, value, alloc, value.
extern "C" void FUN_004a74f0(BasicStringW_0x1c* dest, int count,
                             const BasicStringW_0x1c* value, void* alloc,
                             const BasicStringW_0x1c* value_echo);

// thiscall ECX=alloc/host; stack dest*, count, value*; RET 0x0C.
// Returns dest + count * 0x1c.
extern "C" BasicStringW_0x1c* __thiscall StdUninitFillN_BasicStringW(
    void* alloc,
    BasicStringW_0x1c* dest,
    int count,
    const BasicStringW_0x1c* value)
{
  FUN_004a74f0(dest, count, value, alloc, value);
  // retail: ADD ESP, 0x14 after cdecl helper
  return reinterpret_cast<BasicStringW_0x1c*>(
      reinterpret_cast<char*>(dest) + static_cast<uint32_t>(count) * kElemSize);
}

// Scaffold / Ghidra alias
extern "C" BasicStringW_0x1c* __thiscall FUN_004a7a70(
    void* alloc,
    BasicStringW_0x1c* dest,
    int count,
    const BasicStringW_0x1c* value)
{
  return StdUninitFillN_BasicStringW(alloc, dest, count, value);
}
