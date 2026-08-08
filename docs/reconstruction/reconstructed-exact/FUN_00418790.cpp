// =============================================================================
// FUN_00418790 — alias twin of StdList_Incsize_00418790
// -----------------------------------------------------------------------------
// Stable ID: aa_00418790
// Address:   0x00418790–0x004187fe  (autoassault.exe, image base 0x400000)
// Canonical: StdList_Incsize_00418790
// System:    shared MSVC std::list
// Generated: 2026-07-23 scaffold; **sealed 2026-08-05** R10-024 dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

// See StdList_Incsize_00418790.cpp for full plate + dual notes.
// This file preserves the Ghidra machine name as a thin alias.

#include <cstdint>

struct StdListHeader {
  void *_Myhead_or_pad;
  void *_Myhead;
  std::uint32_t _Mysize;
};

extern "C" void __fastcall StdList_Incsize_00418790(
    std::uint32_t count /*ECX*/,
    StdListHeader *list /*EDX*/);

extern "C" void __fastcall FUN_00418790(
    std::uint32_t count /*ECX*/,
    StdListHeader *list /*EDX*/)
{
  StdList_Incsize_00418790(count, list);
}
