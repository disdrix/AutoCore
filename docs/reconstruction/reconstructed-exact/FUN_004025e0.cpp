// =============================================================================
// FUN_004025e0  — alias of StdList_PushBack_Val0x28_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004025e0
// Address:   0x004025e0–0x00402611  (autoassault.exe, image base 0x400000)
// System:    shared MSVC std::list
// Generated: 2026-07-23 scaffold; sealed 2026-08-05 MEGA-059
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// Canonical: StdList_PushBack_Val0x28_Inferred.cpp
// =============================================================================

#include <cstdint>

struct ListNode0x30 {
  ListNode0x30 *_Next;
  ListNode0x30 *_Prev;
  std::uint32_t _Val[10];
};

struct StdListShell_Val0x28 {
  void *_Pad0;
  ListNode0x30 *_Myhead;
  std::uint32_t _Mysize;
};

extern "C" ListNode0x30 *FUN_00403560(ListNode0x30 *next, ListNode0x30 *prev, const void *value);
extern "C" void __thiscall FUN_00403600(StdListShell_Val0x28 *list, std::uint32_t count);

void __thiscall FUN_004025e0(StdListShell_Val0x28 *param_1, const void *param_2)
{
  ListNode0x30 *iVar1;
  ListNode0x30 *iVar2;

  iVar1 = param_1->_Myhead;
  iVar2 = FUN_00403560(iVar1, iVar1->_Prev, param_2);
  FUN_00403600(param_1, 1);
  iVar1->_Prev = iVar2;
  iVar2->_Prev->_Next = iVar2;
  return;
}
