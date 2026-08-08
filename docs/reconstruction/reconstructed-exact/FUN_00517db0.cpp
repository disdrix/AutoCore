// =============================================================================
// FUN_00517db0 — Ghidra symbol alias for StdList_PushBack_DwordFromEcx_Inferred
// Stable ID: aa_00517db0
// Address:   0x00517db0 (autoassault.exe)
// Dual:      R10-032 2026-08-05 accept-with-gaps
// See:       StdList_PushBack_DwordFromEcx_Inferred.cpp for full plate + CF
// =============================================================================

#include <cstdint>

struct StdListNodeDword {
  StdListNodeDword* _Next;
  StdListNodeDword* _Prev;
  std::uint32_t     _Myval;
};

struct StdListHeaderDword {
  void*             _PadOrProxy;
  StdListNodeDword* _Myhead;
  std::uint32_t     _Mysize;
};

extern "C" void* __stdcall FUN_00418700(void* next, void* prev, const std::uint32_t* pValue);
extern "C" void __thiscall FUN_00404840(void* list, std::uint32_t count);

// Decompiler: void FUN_00517db0(int param_1) with "uninit" local_4.
// Bytes: ECX=value dword, stack=list*, RET 4; local is PUSH ECX spill.
void FUN_00517db0(StdListHeaderDword* list /*stack*/, std::uint32_t value_in_ecx /*ECX*/)
{
  StdListNodeDword* head = list->_Myhead;
  std::uint32_t value = value_in_ecx;
  StdListNodeDword* node = reinterpret_cast<StdListNodeDword*>(
      FUN_00418700(head, head->_Prev, &value));
  FUN_00404840(list, 1);
  head->_Prev = node;
  node->_Prev->_Next = node;
}
