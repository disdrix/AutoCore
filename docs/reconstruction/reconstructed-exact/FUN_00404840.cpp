// =============================================================================
// FUN_00404840 — alias for StdList_Incsize_Thiscall
// -----------------------------------------------------------------------------
// Stable ID: aa_00404840
// Address:   0x00404840–0x004048AE
// See:       StdList_Incsize_Thiscall.cpp  (canonical plate; R10-006 seal 2026-08-05)
// =============================================================================

#include <cstdint>

struct StdListHeader {
  void *_Myhead_or_pad;
  void *_Myhead;
  std::uint32_t _Mysize;
};

extern "C" void __thiscall StdList_Incsize_Thiscall(
    StdListHeader *list,
    std::uint32_t count);

// Ghidra inventory name
extern "C" void __thiscall FUN_00404840(
    StdListHeader *list /*ECX*/,
    std::uint32_t count /*stack*/)
{
  StdList_Incsize_Thiscall(list, count);
}
