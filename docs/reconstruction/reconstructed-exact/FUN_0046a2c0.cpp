// =============================================================================
// FUN_0046a2c0  — twin of StdUninitCopy_BasicString (aa_0046a2c0)
// -----------------------------------------------------------------------------
// Address:   0x0046a2c0  (autoassault.exe, image base 0x400000)
// Body:      0x0046a2c0 – 0x0046a34c exclusive (140 B / 0x8C)
// Wave:      W33-G OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite; Ghidra symbol retained as twin.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct BasicString_0x1c {
  uint8_t storage[0x1c];
};

static constexpr uint32_t kElemSize = 0x1c;

extern "C" void __thiscall basic_string_copy_ctor(BasicString_0x1c* self,
                                                    const BasicString_0x1c* other);

// Ghidra: FUN_0046a2c0 — cdecl uninit_copy stride 0x1c.
extern "C" BasicString_0x1c* FUN_0046a2c0(
    BasicString_0x1c* param_1,  // first
    BasicString_0x1c* param_2,  // last
    BasicString_0x1c* param_3)  // dest
{
  // SEH LAB_009bcce1
  for (; param_1 != param_2;
       param_1 = reinterpret_cast<BasicString_0x1c*>(
           reinterpret_cast<char*>(param_1) + kElemSize)) {
    if (param_3 != nullptr) {
      basic_string_copy_ctor(param_3, param_1);
    }
    param_3 = reinterpret_cast<BasicString_0x1c*>(
        reinterpret_cast<char*>(param_3) + kElemSize);
  }
  return param_3;
}
