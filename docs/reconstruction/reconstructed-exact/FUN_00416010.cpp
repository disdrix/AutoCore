// =============================================================================
// FUN_00416010 — alias twin for StdList_Incsize_Max1fffffff
// Stable ID: aa_00416010 | VA 0x00416010 | WQ9I-E 2026-08-04
// Canonical clean: StdList_Incsize_Max1fffffff.cpp
// =============================================================================

#include <cstdint>

struct StdListHeader {
  void *_pad0;
  void *_Myhead;
  std::uint32_t _Mysize;
};

extern "C" void __fastcall StdList_Incsize_Max1fffffff(
    std::uint32_t count, StdListHeader *list);

extern "C" void __fastcall FUN_00416010(
    std::uint32_t count /*ECX*/,
    StdListHeader *list /*EDX*/)
{
  StdList_Incsize_Max1fffffff(count, list);
}
