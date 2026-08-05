// =============================================================================
// FUN_00430390  — twin of StdUninitFillN_BasicString (aa_00430390)
// -----------------------------------------------------------------------------
// Address:   0x00430390  (autoassault.exe, image base 0x400000)
// Body:      0x00430390 – 0x004303c0 exclusive (48 B / 0x30)
// Wave:      W33-G OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite; Ghidra name retained as twin.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct BasicString_0x1c {
  uint8_t storage[0x1c];
};

static constexpr uint32_t kElemSize = 0x1c;

extern "C" void FUN_00431700(BasicString_0x1c* dest, int count,
                             const BasicString_0x1c* value, void* alloc,
                             const BasicString_0x1c* value_echo);

// Ghidra: FUN_00430390 — thiscall fill_n wrapper; RET 0x0C.
extern "C" BasicString_0x1c* __thiscall FUN_00430390(
    void* param_1,                 // alloc / ECX
    BasicString_0x1c* param_2,     // dest
    int param_3,                   // count
    const BasicString_0x1c* param_4) // value
{
  FUN_00431700(param_2, param_3, param_4, param_1, param_4);
  return reinterpret_cast<BasicString_0x1c*>(
      reinterpret_cast<char*>(param_2) + static_cast<uint32_t>(param_3) * kElemSize);
}
