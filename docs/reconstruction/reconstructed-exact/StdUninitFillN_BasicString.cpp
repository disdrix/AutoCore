// =============================================================================
// StdUninitFillN_BasicString  (aa_00430390)
// -----------------------------------------------------------------------------
// Address:   0x00430390  (autoassault.exe, image base 0x400000)
// Body:      0x00430390 – 0x004303c0 exclusive (48 B / 0x30)
// Wave:      W33-G OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct BasicString_0x1c {
  uint8_t storage[0x1c];
};

static constexpr uint32_t kElemSize = 0x1c;

// Nested fill loop (not dual-owned). Prototype simplified to live formals;
// retail call pushes five dwords: dest, count, value, alloc, value.
extern "C" void FUN_00431700(BasicString_0x1c* dest, int count,
                             const BasicString_0x1c* value, void* alloc,
                             const BasicString_0x1c* value_echo);

// thiscall ECX=alloc/host; stack dest*, count, value*; RET 0x0C.
// Returns dest + count * 0x1c.
extern "C" BasicString_0x1c* __thiscall StdUninitFillN_BasicString(
    void* alloc,
    BasicString_0x1c* dest,
    int count,
    const BasicString_0x1c* value)
{
  FUN_00431700(dest, count, value, alloc, value);
  // retail: ADD ESP, 0x14 after cdecl helper
  return reinterpret_cast<BasicString_0x1c*>(
      reinterpret_cast<char*>(dest) + static_cast<uint32_t>(count) * kElemSize);
}
