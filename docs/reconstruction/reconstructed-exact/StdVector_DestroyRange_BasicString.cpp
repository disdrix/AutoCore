// =============================================================================
// StdVector_DestroyRange_BasicString  (aa_00431aa0)
// -----------------------------------------------------------------------------
// Address:   0x00431aa0  (autoassault.exe, image base 0x400000)
// Body:      0x00431aa0 – 0x00431ac2 exclusive (34 B / 0x22); pad CC
// Wave:      W33-H OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// MSVC basic_string footprint in this binary (stride sealed by ADD ESI,0x1C).
struct BasicString_0x1c {
  uint8_t bytes[0x1c];
};

// IAT [0x009c62f4] → ~basic_string (thiscall ECX = string*).
extern "C" void __thiscall basic_string_dtor(BasicString_0x1c* self);

// Stack first*, last*; RET 0x08; void.
// Destroy [first, last) of vector<basic_string> storage (no free of the buffer).
extern "C" void StdVector_DestroyRange_BasicString(
    BasicString_0x1c* first,
    BasicString_0x1c* last)
{
  for (; first != last; first = reinterpret_cast<BasicString_0x1c*>(
           reinterpret_cast<uint8_t*>(first) + 0x1c)) {
    basic_string_dtor(first);
  }
}

// Scaffold / Ghidra alias
extern "C" void FUN_00431aa0(BasicString_0x1c* first, BasicString_0x1c* last)
{
  StdVector_DestroyRange_BasicString(first, last);
}
