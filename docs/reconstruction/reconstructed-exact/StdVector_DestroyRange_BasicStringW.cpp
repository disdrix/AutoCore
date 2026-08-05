// =============================================================================
// StdVector_DestroyRange_BasicStringW  (aa_004a7aa0)
// -----------------------------------------------------------------------------
// Address:   0x004a7aa0  (autoassault.exe, image base 0x400000)
// Body:      0x004a7aa0 – 0x004a7ac4 exclusive (36 B / 0x24); pad CC
// Wave:      W36-S OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// MSVC basic_string<wchar_t> footprint in this binary (stride sealed by ADD ESI,0x1C).
struct BasicStringW_0x1c {
  uint8_t bytes[0x1c];
};

// IAT [0x009c62ac] → ~basic_string<wchar_t> (thiscall ECX = string*).
extern "C" void __thiscall basic_string_wchar_dtor(BasicStringW_0x1c* self);

// Stack first*, last*; RET 0x08; void.
// Destroy [first, last) of vector<basic_string<wchar_t>> storage (no free of the buffer).
extern "C" void StdVector_DestroyRange_BasicStringW(
    BasicStringW_0x1c* first,
    BasicStringW_0x1c* last)
{
  for (; first != last; first = reinterpret_cast<BasicStringW_0x1c*>(
           reinterpret_cast<uint8_t*>(first) + 0x1c)) {
    basic_string_wchar_dtor(first);
  }
}

// Scaffold / Ghidra alias
extern "C" void FUN_004a7aa0(BasicStringW_0x1c* first, BasicStringW_0x1c* last)
{
  StdVector_DestroyRange_BasicStringW(first, last);
}
